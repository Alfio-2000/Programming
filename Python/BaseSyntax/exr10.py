# pylint: disable=all
# Write a script that it can say if a string that an user enter by keyboard is a palindrome or not. 

string= input("Enter a word: ")

palindrome=string[::-1] # This is the slicing: see tablet's notes. 

if palindrome==string: 
     print(f" '{string}' is palindrome.")

else: 
     print(f" '{string}' is not palindrome.")

