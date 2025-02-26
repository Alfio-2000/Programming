# Write a script that it can print in descending order three numbers that user enter by keyboard

first_number= int(input("Enter the first number: "))
second_number= int(input("Enter the second number: "))
third_number= int(input("Enter the third number: "))

if first_number>second_number and first_number>third_number and second_number>third_number:
    print(f"The number's order is: {first_number},{second_number},{third_number}")

elif first_number>second_number and first_number>third_number and second_number<third_number:
    print(f"The number's order is: {first_number},{third_number},{second_number}")

elif second_number>first_number and second_number>third_number and first_number>third_number:
    print(f"The number's order is: {second_number},{first_number},{third_number}")

elif second_number>first_number and second_number>third_number and first_number<third_number:
    print(f"The number's order is: {second_number},{third_number},{first_number}")

elif third_number>first_number and third_number>second_number and first_number>second_number:
    print(f"The number's order is: {third_number},{first_number},{second_number}")

elif third_number>first_number and third_number>second_number and first_number<second_number:
    print(f"The number's order is: {third_number},{second_number},{first_number}")

