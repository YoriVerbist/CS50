from sys import argv
from cs50 import SQL

def main():
    if len(argv) != 2:
        print("Usage: Python roster.py house")
        exit()
    else:
        db = SQL("sqlite:///students.db")
        
        house = argv[1]
        
        people = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last", house)
        for person in people:
            first_name = person["first"]
            middle_name = person["middle"]
            last_name = person["last"]
            birth = person["birth"]
            if middle_name == "NULL":
                print(f"{first_name} {last_name}, born {birth}")
            else:
                print(f"{first_name} {middle_name} {last_name}, born {birth}")
            
    
if __name__ == "__main__":
    main()