# Import the cs50 library for user input
from cs50 import get_string

# Function to count the number of letters in a text
def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters

# Function to count the number of words in a text
def count_words(text):
    words = len(text.split())
    return words

# Function to count the number of sentences in a text
def count_sentences(text):
    sentences = text.count(".") + text.count("!") + text.count("?")
    return sentences

# Get user input
text = get_string("Text: ")

# Count letters, words, and sentences
letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

# Calculate Coleman-Liau index
L = 100 * letters / words
S = 100 * sentences / words
index = 0.0588 * L - 0.296 * S - 15.8

# Round the index and print the grade level
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")
