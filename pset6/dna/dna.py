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
            lines = csvFile.readlines()
            names = lines[0].split(",")
            names.remove(names[0])
            print(names)
            
            lines.remove(lines[0])
            for line in lines:
                amount = line.split(",")
        
        with open(txtName, 'r') as txtFile:
            string = txtFile.read()
    #print(string, names[0])
    print(string.count(names[0]))
    print(calculateOccurrences(string, names[0]))


def calculateOccurrences(string, substring):
    occurrences = 0
    highest = 0
    while string.find(substring) != -1:
        place = string.find(substring)
        string = string[place:]
        if string.find(substring, 0, len(substring)) == 0:
        #if substring in string[place:place + len(substring)]:
            occurrences += 1
            print(occurrences)
            print("here")
        else:
            occurrences = 0
        if occurrences > highest:
                print(highest, occurrences)
                highest = occurrences
        string = string[1:]
    return highest
    
    
if __name__ == "__main__":
    main()