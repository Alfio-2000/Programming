# Write a script to create a calculator. 

first_number=float(input("Enter first number: "))
second_number=float(input("Enter second number: "))

# Now, i want to ask which operation the user wants to do
print("\nChoice which operation want to do:")
print("1. Press '+' for the sum;\n2. Press '-' for the sottraction;")
print("3. Press '/' for the division;\n4. Press '*' for the multiplication.")

choice=input("Enter your choice: ")

if choice=='+':
    print("The sum of your numbers is:",first_number+second_number)

if choice=='-':
    print("The sottraction of your numbers is:",first_number-second_number)

if choice=='/':
    print(f"Do u want to do ({first_number}/{second_number}) or ({second_number}/{first_number})?")
    print("Press '1' for the first or '2' for the second. Make your choice:" )
    second_choice=input("Enter your choice ('1' or '2'):")
    if second_choice=='1':
        if second_number==0:
            print("The division isn't possible.")
        else:
            first_division=first_number/second_number
            print(f"The division is:{first_division:.3f}")
    if second_choice=='2':
        if first_number==0:
            print("The division isn't possible.")
        else:
            second_division= second_number/first_number
            print(f"The division is:{second_division:.3f}")

if choice=='*':
    multiplication=first_number*second_number
    print(f"The multiplication is: {multiplication:.3f}")

        
        
        
        
