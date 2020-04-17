import os

from datetime import datetime
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    user_id = session["user_id"]
    cash_dict = db.execute("SELECT cash FROM users WHERE id == ?",
                          user_id)
    cash = cash_dict[0]['cash']
    cash = format(cash, ".2f")
    cash = float(cash)
    
    stocks = db.execute("SELECT name, amount FROM stocks WHERE user_id == ?",
                        user_id)
    print(stocks)
    names = list()
    
    grand_total = 0

    for stock in stocks:
        name = lookup(stock["name"])
        print(name)
        stock['price'] = usd(name['price'])
        stock['symbol'] = name['symbol']
        stock['name'] = name['name']
        stock['total'] = usd(name['price'] * stock['amount'])
        grand_total += name['price'] * stock['amount']
    
    print(stocks)
    return render_template("index.html", stocks = stocks, cash = cash, grand_total = grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        user_id = session["user_id"]
        
        
        if stock == None:
            return apology("Stock does not exist", 403)
        
        price = stock['price']
        name = stock["name"]
        official_symbol = stock["symbol"]
        amount = request.form.get("shares")
        cash_dict = db.execute("SELECT cash FROM users WHERE id == ?",
                          user_id)
        cash = cash_dict[0]['cash']
        print(price, amount)
        
        if (price * float(amount)) > int(cash):
            return apology("You don't have enough cash", 403)
        else:
            db.execute("INSERT INTO stocks (name, amount, user_id, time, value) VALUES (?, ?, ?, ?, ?)",
                       official_symbol, amount, user_id, datetime.now(), price)
            cash -= price * float(amount)
            db.execute("UPDATE users SET cash = ? WHERE id == ?",
                       cash, user_id)
        
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        
        if stock == None:
            return apology("Stock does not exist", 403)
        
        return render_template("quoted.html", stock = stock)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        user_name = request.form.get('username')
        password = generate_password_hash(request.form.get('password'))
        
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))
        
        if len(rows) == 1:
            return apology("Username already taken", 403)
        
        if (request.form.get('password') != request.form.get('conformation')):
            return apology("Passwords do not match", 403)
        
        db.execute("INSERT INTO users (username, hash, cash) VALUES(?, ?, ?)",
                   user_name, password, 10000)
        redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
