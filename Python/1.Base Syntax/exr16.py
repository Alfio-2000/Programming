# Write a script that it controls if a password has:
# 1) Lenght of at least 8 characters
# 2) It contains at least a capital letter
# 3) It contains at least a number

print("Hi, i'm a software that help you to choice a password.")
print("It must contains:\n 1. Lenght: 8 characters\n 2. It must contains at least one capital\n 3. It must contains at least one number\n")

MIN_LENGHT_PASSWORD=8 # 
password=input("Enter a password: ")
has_upper=False
has_digit=False

for letter in password:
    if letter.isupper():
        has_upper= True
    if letter.isdigit():
        has_digit=True 

if len(password)>=MIN_LENGHT_PASSWORD and has_upper and has_digit:
    print("Your password has been accepted.")

else: 
    print("Your password hasn't been accepted.")

# Explanation of code. 
# Logic:i declare 2 boolean variables, because they're useful to control all string's characters. 
# Infact, the text says to control AT LEAST capital character or number. 
# FOR cycle is important because control every element in the string. In addition, function .isupper()
# controls if an element is upper or not (this is what we want). In the same way, the function .isdigit()
# controls if an element is a number or not (also this is what we want)
# The if inside for are important, because they change the boolean variables when the string contains capital letter or number.
# In the end, the last if controls if all requirements are satisfied 