from cs50 import get_int

# Program that prints mario pyramid


def main():
    height = 0

    # While loop to check if the value is between 1 and 8
    while 0 >= int(height) or int(height) > 8:
        height = get_int("How high do you want your pyramid?")

    height = int(height)

    # Print the pyramid
    for i in range(height):
        print(" " * (height - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))


if __name__ == "__main__":
    main()