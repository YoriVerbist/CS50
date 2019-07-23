from sys import argv
import sys


def main():
    if len(argv) != 2:
        print("Usage: python caesar.py k")
        sys.exit()
    elif not argv[1].isdigit():
        print("Usage: python caesar.py k")
        sys.exit()
         
    k = argv[1]
        
    encryp = []
        
    p = input("Give a string:")
    
    for char in p:
        if char.islower():
            encryp.append(chr((ord(char) + int(k) - 97) % 26 + 97))
        elif char.isupper():
            encryp.append(chr((ord(char) + int(k) - 65) % 26 + 65))
        else:
            encryp.append(char)
    print("ciphertext:", "".join(encryp))
    
    
if __name__ == "__main__":
    main()
