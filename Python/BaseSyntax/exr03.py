# Write a script that ask to user to enter a password that it needs to soddisfy these conditions: 
    # 1. It needs to contain an almost number
    # 2. It doesn't need to contain a free tab " "
    # 3. The password's lenght needs to be of 10 characters
    # 4. If all conditions are soddisfy , print  "Password accepted". Otherwise, the script needs to print the problem.

password= input("Enter a password: ")
LENGHT_PASSWORD= 10
number_condition=True
tab_condition= True

if  password.isalnum() and " " not in password and len(password)==LENGHT_PASSWORD: 
    print("Your password has been accepted.")

else: 
    print("Your password doesn't soddisy the requirements:")
    if password.isalnum()!=number_condition: 
        print("It doesn't contain almost a number.")
    if (" " not in password)!= tab_condition:
        print("It contains ' '.")
    if len(password)!=LENGHT_PASSWORD: 
        print(f"Your password has a wrong lenght: It needs to be of {LENGHT_PASSWORD} characters.")


