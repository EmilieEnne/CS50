from cs50 import get_string


def main():
    # get text input from user
    text = get_string("Text: ")

# get number of letters in text
    let = cnt_let(text)
# get number of words
    wrd = cnt_wrd(text)
# get number of sentences
    snt = cnt_snt(text)
# put score through formula
    l = (let/wrd) * 100
    s = (snt/wrd) * 100
    lvl = round(0.0588 * l - 0.296 * s - 15.8)
# output readability level
    if lvl < 1:
        print("Before Grade 1")
    elif lvl > 16:
        print("Grade 16+")
    else:
        print(f"Grade {lvl}")


def cnt_let(text):
    score = 0
    for l in text:
        if l.isalpha():
            score += 1
    return score


def cnt_wrd(text):
    score = 0
    for w in text:
        if w.isspace():
            score += 1
    return score + 1


def cnt_snt(text):
    score = 0
    for s in text:
        if s == "." or s == "!" or s == "?":
            score += 1
    return score


main()
