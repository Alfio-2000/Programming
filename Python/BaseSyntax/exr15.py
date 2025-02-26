# Write a script that it can create strings by one that it is entered by keyboard. In particular: 

# 1) String needs to has e lenght of 20 characters
# 2) Create a new string by the first with the first 10 characters
# 3) Create a new string by the first with the last 10 characters   
# 4) Create a new string by the first with the characters between the tenth and twentyth

LENGHT_STRING= 20

user_string=input("Enter a word at least 20 characters of lenght: ")

if len(user_string)< LENGHT_STRING:
    print("You enter a wrong string's lenght.")

else:
    first_string= user_string[:10] 
    print(f"The first string that it's built by the first 10 items is: '{first_string}'.")
    second_string=user_string[-10:]
    print(f"The second string that it's built by items beetwen the tenth and twentyth is: '{second_string}'.")
    third_string=user_string[10:]
    print(f"The second string that it's built by last 10 items is: '{third_string}'.")
    