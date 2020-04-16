def main():
    text = input("Text: ")
    l = len(text)
    
    letters = 0
    sentences = 0
    words = 1
    
    for i in range(l):
        if text[i].isalpha():
            letters += 1
        elif text[i] == " ":
            words += 1
        elif text[i] == "." or text[i] == "?" or text[i] == "!":
            sentences += 1
    
    index = calculateIndex(letters, words, sentences)
    
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")
    
    
def calculateIndex(letters, words, sentences) -> int:
    L = float(100 / words * letters)
    S = float(100 / words * sentences)
    index = round(0.0588 * L - 0.296 * S - 15.8)
    
    return index
    
if __name__ == "__main__":
    main()