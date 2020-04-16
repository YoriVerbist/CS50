from sys import argv, exit
import csv

from cs50 import SQL

def main():
    if len(argv) != 2:
        print("Usage: python import.py characters.csv")
        exit()
    else:
        
        db = SQL("sqlite:///students.db")
        
        csv_name = argv[1]
        with open(csv_name, 'r') as file:
            reader = csv.DictReader(file)
            
            for row in reader:
                name = row["name"]
                house = row["house"]
                birth = row["birth"]
                
                full_name = name.split(" ")
                first_name = full_name[0]
                if len(full_name) == 2:
                    middle_name = None
                    last_name = full_name[1]
                else:
                    middle_name = full_name[1]
                    last_name = full_name[2]
                
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                            first_name, middle_name, last_name, house, birth) 
        

if __name__ == "__main__":
    main()