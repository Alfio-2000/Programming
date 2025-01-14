# Write a script that it asks to user 3 numbers a,b,c by keyboard and to print the biggest of them

first_number= int(input("Enter the first number: "))
second_number= int(input("Enter the second number: "))
third_number= int(input("Enter the third number: "))

if first_number>=second_number and  first_number>=third_number:
    biggest_number= first_number
    print(f"The biggest number is: {biggest_number}")

elif second_number>=first_number and second_number>=third_number:
    biggest_number= second_number
    print(f"The biggest number is: {biggest_number}")

else: 
    biggest_number=third_number
    print(f"The biggest number is: {biggest_number}")






















