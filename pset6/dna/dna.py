import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()
    else:
        csvName = sys.argv[1]
        txtName = sys.argv[2]
        with open(csvName, 'r') as csvFile:
            names = csvFile.readlines()
            STRs = names[0].split(",")
            STRs.remove(STRs[0])
            
        with open(txtName, 'r') as txtFile:
            string = txtFile.read()
                
        names.remove(names[0])
        dna = "No match"
            
        for line in names:
            count = 1
            single = line.split(",")
            for i in range(len(STRs) - 1):
                amount = calculateOccurrences(string, STRs[i].strip("\n"))
                if amount == int(single[i + 1]):
                    dna = single[0]
                    count += 1
                    if count == len(STRs):
                        dna2 = dna
                        print(dna2)
                        sys.exit()
                else:
                    break
        print(dna)



def calculateOccurrences(string, substring):
    occurrences = 0
    highest = 0
    place = 0
    while string.find(substring) != -1:
        string = string[place:]
        if string.find(substring, 0, len(substring)) == 0:
            occurrences += 1
            string = string[len(substring):]
        else:
            occurrences = 0
            string = string[1:]
        if occurrences > highest:
                highest = occurrences
    return highest
    
    
if __name__ == "__main__":
    main()