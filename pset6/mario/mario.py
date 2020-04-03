import sys

def main():
    while True:
        try:
            height = int(input("Height: "))
            if height < 9 and height > 0:
                break
        except:
            pass
    
    for i in range(0, height):
        print(" " * (height - 1 - i) + "#" * (i + 1))
        
        
if __name__ == "__main__":
    main()