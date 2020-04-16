from cs50 import get_float

def main():
    change = -5
    
    while change < 0:
        change = get_float("What is the change?")
    quaters = 0
    dimes = 0
    nickels = 0
    pennies = 0
    
    while change >= 0.25:
        change -= 0.25
        quaters += 1
        print("q", quaters)

    while change >= 0.10:
        change -= 0.10
        dimes += 1
        print("d", dimes)
    
    while change >= 0.05:
        change -= 0.05
        nickels += 1
        print("n", nickels)
        
    while change >= 0.01:
        change -= 0.01
        pennies += 1
        print("p", pennies)
        
    print(quaters + dimes + nickels + pennies)
    
if __name__ == "__main__":
    main()