from sys import argv
import sys


def main():
    # If the program is not correctly run, exit
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        sys.exit(1)
        
    ban = set()
    
    with open(argv[1], 'r') as f:
        for line in f:
            ban.add(line.strip())

    # Ask for the message to check    
    message = input("What message would you like to censor?")
    
    msg_words = message.split(" ")

    msg_censor = ""
    # censor banned words
    for word in msg_words:
        if word.lower() in ban:
            msg_censor += ("*" * len(word)) + " "
        else:
            msg_censor += word + " "

        # print censored msg
        print(msg_censor.strip())

if __name__ == "__main__":
    main()