print("Hello, I can calculate a number's factorial.\n")

def get_number(): # (1)
    prompt="Enter a number: "
    while True:
        user_input = input(prompt)
        if user_input.strip():
            try:
                return int(user_input)  # Try with int
            except ValueError:
                try:
                    return float(user_input)  # If the number isn't an int, try with float
                except ValueError:
                    print("Error!", end=" ")

def number_factorial(n):
    if n==0:
        return 1
    elif n>0:
        result=n*number_factorial(n-1)
        return result
    else:
        print("The factorial of a negative number isn't definied!")
        return None

number=get_number()
factorial=number_factorial(number)
print(f"{number}! is: {factorial} ")

# (1): This function is useful for checking the right user's input. 
# In fact, the logic is this: the function converts user's input in a int or float number. 
# This function is useful to  replace the functions int(input()) or float(input()), because in those cases if the user enter
# for example a float number the script will crash and this is very bad for programmer. 
 
