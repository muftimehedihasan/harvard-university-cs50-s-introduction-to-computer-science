import re

def main():
    # Get credit card number from user
    card_number = input("Number: ")

    # Validate credit card number
    if is_valid_card(card_number):
        print_card_type(card_number)
    else:
        print("INVALID")

def is_valid_card(card_number):
    # Check if the card number consists of only digits and has a valid length
    if not re.match("^\d+$", card_number) or len(card_number) < 13 or len(card_number) > 16:
        return False

    # Reverse the card number and double every second digit
    reversed_card = card_number[::-1]
    doubled_digits = [int(reversed_card[i]) * 2 if i % 2 == 1 else int(reversed_card[i]) for i in range(len(reversed_card))]

    # Sum up the digits of the doubled numbers and the unaffected numbers
    total = sum([(n // 10) + (n % 10) for n in doubled_digits])

    # Check if the total modulo 10 equals 0
    return total % 10 == 0

def print_card_type(card_number):
    # Determine the card type based on the first few digits of the card number
    if re.match("^3[47]", card_number) and len(card_number) == 15:
        print("AMEX")
    elif re.match("^5[1-5]", card_number) and len(card_number) == 16:
        print("MASTERCARD")
    elif re.match("^4", card_number) and (len(card_number) == 13 or len(card_number) == 16):
        print("VISA")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
