# Ask to user if in a string there're only elements or not

vocals='aeiou'

string=input("Enter a word:")
count_vocals=0

for letter in string:
    if letter in vocals:
        count_vocals+=1
if count_vocals==len(string):
    print(f"'{string}' contains only vocals")
else:
    print(f"'{string}' doesn't contain only vocals ")


