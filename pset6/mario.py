# Program that prints mario pyramid

height = -5

# While loop to check if the value is between 1 and 8
while 1 > height < 9:
    height = int(input("How high do you want your pyramid?"))

x = height - 1
hashes = 1
y = 0

while height > 0:
    while x > 0:
        print(" ", end = "")
        x -= 1
    while y < hashes:
        print("#", end = "")
        y += 1
    print("  ")
    while y < hashes:
        print("#")
    hashes += 1
    height -= 1
    print("\n")
