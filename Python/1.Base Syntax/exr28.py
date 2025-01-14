# How many capital letters are there in a string entered by user from keyboard?

string=input("Enter a word:")

count_capital_letters=0

for letter in string:
    if letter.isupper():
        count_capital_letters+=1

print(f"'{string}' contains {count_capital_letters} capital letters")

