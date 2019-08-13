from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    line_a = a.split("\n")
    line_b = b.split("\n")
    return [line_a, line_b]


def sentences(a, b):
    """Return sentences in both a and b"""

    sentence_a = sent_tokenize(a)
    sentence_b = sent_tokenize(b)
    return [sentence_a, sentence_b]


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    return []