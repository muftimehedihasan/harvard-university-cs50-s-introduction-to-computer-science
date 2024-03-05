# Import the cs50 library for user input
from cs50 import get_int

# Function to check if the input is a valid integer
def is_valid_integer(n):
    return n > 0 and n <= 8

# Get user input for height
while True:
    height = get_int("Height: ")
    if is_valid_integer(height):
        break
    else:
        print("Invalid input. Please enter a positive integer between 1 and 8 inclusive.")

# Print the pyramid
for i in range(height):
    # Print spaces before the hashes
    print(" " * (height - i - 1), end="")

    # Print the hashes
    print("#" * (i + 1))
