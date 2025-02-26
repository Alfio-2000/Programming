# Create n dictionaries by keyboard

print("Hello, I can create n dictionaries.\n")

# I'm creating the dictionaries
while True:
    n=int(input("How many dictionaries do you want create? "))
    if n>0: 
        break
    else:
        print("Wrong value. Try again:", end=" ")

list_dictionaries=[]#Thi is necessary to save each dicionary the user creates
for i in range(1,n+1):
    name=input(f"Enter the name of the {i}° dictionary: ")
    name={} # Empty dicionary to save each dicionary that user creates in each item
    while True: 
        key=input("Enter a key: ").title()
        value=input("Enter a value: ").title()
        name[key]=value #I'm adding (key-value) couple
        choice=input("Do you want enter another (key-value)? Press (yes/no): ").lower() # I want ask to user if he wants enter another couple
        if choice=="no" or choice!="yes":
            print("\n")
            break
    list_dictionaries.append(name)

print("You have created these dicionaries:")
for i in range(len(list_dictionaries)):
    print(f"{i+1}° dictionary: {list_dictionaries[i]}")
        
while True:
    index=int(input("Which dictionary do you want change?Press an integer positive number: "))
    if index>0 and index<=len(list_dictionaries):
        print(f"\nYou want change {list_dictionaries[index-1]}")
        dictionary=dict(list_dictionaries[index-1])
        choice=input("Press 'd' which (key-value) to delete\nPress 'a' which (key-value) to add.\nYour choice: ").lower()
        
        if choice=="d":#I'm deleting a (key-value)
            input_key=input("Which key do you want delete? ").title()
            if input_key in dictionary:
                dictionary.pop(input_key)
                print(f"Your new dictionary is: {dictionary}")
            else:
                print(f"{input_key} is not in {dictionary}")
        
        if choice=="a": #I'm adding a (key-value)
            input_key=input("Which key do you want add? ").title()
            if input_key in dictionary:
                input_value=input("Enter its new value: ")
                dictionary[input_key]=input_value
                print(f"Your new dictionary is: {dictionary}")
            else:
                print(f"{input_key} is not in {dictionary}")

        elif (choice=="a" and choice=="d"):
            print("Error: your choice is not available.")
            
        break

    elif index<=0 or index>len(list_dictionaries):
        print("Wrong value.Try again:",end=" ")

