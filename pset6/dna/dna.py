import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()
    else:
        csvName = sys.argv[1]
        txtName = sys.argv[2]
        STRs = dict()
        with open(csvName, 'r') as csvFile:
            lines1 = csvFile.readlines()
            names = lines1[0].split(",")
            names.remove(names[0])
            print(names)
            
            lines1.remove(lines1[0])
            for line in lines1:
                amount = line.split(",")
        
        with open(txtName, 'r') as txtFile:
            lines2 = txtFile.read()


def calculateOccurrences(string, substring):
    while True:
        string.find(substring)
    
    
if __name__ == "__main__":
    main()