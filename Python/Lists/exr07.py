# Create a list with the first n numbers multiplied by 3 but they must be bigger than 15 

import re # This library is ncessary to use regulare expressions (I've not studied yet)

BIG_NUMBER=15 # This is the biggest number that we want surpass 

print("Hello, I can create a list with the first n numbers that they multiplied by 3 and bigger than 15.")

while True:
    user_input=input("\nHow many numbers do you want print?")
    digits = "".join(re.findall(r'\d+', user_input))  # Extracts only digits from input
    if digits:  # If it finds at least one numeric sequence
        numbers= int(digits)  # This join all numbers and it converts them into an integer 
    else: 
        numbers=None  # If it doesn't find no numbers, it gives back None
    if numbers is not None and numbers>0: 
        break
    else:
        print("Wrong value: Try again!")

list=[element*3 for element in range(1,numbers+1) if element*3>BIG_NUMBER]
print(list)


