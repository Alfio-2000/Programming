# Write a script that it can count the number of vocals inside a string entered by user from keyboard

string=input("Enter a sentence: ")
vocals="aeiou"
count_vocals=0

for letter in string:
    if letter.lower() in vocals:
        count_vocals+=1
print(f"'{string}' contains {count_vocals} vocals.")

            