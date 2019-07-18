from cs50 import get_float

def main():
    change = get_float("What is the change?")
    quaters = 0
    dimes = 0
    nickels = 0
    pennies = 0
    
    while change >= 0.25:
        change -= 0.25
        quaters += 1

    while change >= 0.10:
        change -= 0.10
        dimes += 1
    
    while change >= 0.05:
        change -= 0.05
        nickels += 1
        
    while change >= 0.01:
        change -= 0.01
        pennies += 1
        
    print(quaters + dimes + nickels + pennies)
    
if __name__ == "__main__":
    main()