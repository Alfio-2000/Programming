# List's operations: 
# 1) Create a list with the following elements: 10,20,30,40,50
# 2) Add numbers at the end of the list
# 3) Add and Remove a number in a user favourite position of the list
print("Hello, I can do the following requests:")

while True:
    print("1) I can create a list with your favourite numbers. ") # Solution of the first point
    print("2) I can add other numbers in your list.") #Solution of the second point
    print("3) I can add and remove a number that it is in a specifically position. ") #Solution of the third point

    choice=input("Which operation do you want to do? Press 1,2 or 3: ")

    if choice=="1":
        print("You've choosen to create a list.")
        while True: 
            length=int(input("Enter your list's length (It must be an integer positive number): "))
            if length>0:
                break
            else:
                print("Invalid number! Try again.")
        list=[]
        for i in range(length):
            element=int(input(f"Enter {i+1}th number: "))
            list.append(element)
        print(f"Your list is {list}")

    if choice=="2":
        print("You've choosen to add a numbers in a list that you can create")
        while True: 
            length=int(input("Enter your list's length (It must be an integer positive number): "))
            if length>0:
                break
            else:
                print("Invalid number! Try again.")
        list=[]
        for i in range(length):
            element=int(input(f"Enter {i+1}th number: "))
            list.append(element)
        print(f"Your list is {list}")
        numberNewelement=int(input("How many elements do you want add? "))
        for i in range(numberNewelement):
            new_element=int(input(f"New {i+1}th element: "))
            list.append(new_element)
        print(f"This is your new list: {list}")

    if choice=="3":
        print("You've choosen to remove a numbers in a list that you can create")
        while True: 
            length=int(input("Enter your list's length (It must be an integer positive number): "))
            if length>0:
                break
            else:
                print("Invalid number! Try again.")
        list=[]
        for i in range(length):
            element=int(input(f"Enter {i+1}th number: "))
            list.append(element)
        print(f"Your list is {list}")
        numberNewelement=int(input("How many elements do you want add? "))
        for i in range(numberNewelement):
            new_element=int(input(f"New {i+1}th element: "))
            list.append(new_element)
        print(f"This is your new list: {list}")
        new_choice=input("Do you want add (A) number or remove (R) it? Press (A/R): ")
        if new_choice.upper()=="A":
            index=int(input("In which position do you want add a number? "))
            new_number=int(input("Enter your new number: "))
            list.insert(index-1,new_number)
            print(f"This is your new list: {list}")
        if new_choice.upper()=="R":
            index=int(input("In which position do you want add a number? "))
            list.pop(index-1,new_number)
            print(f"This is your new list: {list}")
    final_choice=input("Do you want to continue this script? Press (yes/no): ")
    if final_choice.lower()=="no":
        print("\nThanks, see you soon!")
        break
    if final_choice.lower()=="yes":
        print("\nAmazing! Let's do it again")
    





