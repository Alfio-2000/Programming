#pylint: disable=all 

import string #It's useful to use some string's functions   

def checking_errors_name(input_string): # It checks if the user enters a valid input name
    no_wanted_characters = string.whitespace + "-." + string.punctuation
    
    while True:
        # It checks if the input_string isn't empty, starts with unwanted characters 
        if input_string != "" and (input_string[0] not in no_wanted_characters) and not (input_string[0].isdigit()):            
            if any(char.isdigit() for char in input_string): # I'm checking if the input_string has a number in itselves
                input_string = input("Error: The string should not contain numbers. Try again: ")
            else:
                print("Your name has been accepted")
                break

        elif input_string == "": # I'm checking if the input_string is empty
            input_string = input("Error: Don't enter an empty string. Try again: ")
        
        elif input_string[0] in no_wanted_characters:
            input_string = input("Error: Don't enter string with special characters like spaces, dashes, or punctuation. Try again: ")
        
        elif input_string[0].isdigit():
            input_string = input("Error: The first character should not be a number. Try again: ")

def building_dataSets():

    while True: #Checks on input user
        numbers_dictionaries=int(input("Data-sets' number (integer positive number): "))
        if numbers_dictionaries>0:
            break
        else:
            print("Error. Try again:",end=" ")
    
    dictionaries=[] 
    
    for i in range(1,numbers_dictionaries+1):
        name_set=input(f"Enter the name of the {i}° data-set: ").strip().title()
        checking_errors_name(name_set) #This function allow me to check user's input 
        storage_elements=[] #This list is useful to store how many elements the user wants to enter.
       
        number_elements=int(input(f"Elements's number (>0): "))
        while number_elements<=0: #Checks on input user
            number_elements=int(input("Error. Try again: ", end=" "))
        
        for element in range(1,number_elements+1):
            print(f"\nEntering data for element {element}: ")
            element_data={} #Dictionary to store (key-value) couples for one element
            
            couples=int(input("How many data's couples do you want enter (integer positive number): "))
            while couples<=0: #Checks on input user
                couples=int(input("Error. Try again: ", end=" "))
            
            for j in range(1,couples+1):
                key=input("Enter a key: ").title()
                key_value=input("Enter a value of your key: ").title()
                element_data[key]=key_value

            storage_elements.append(element_data)
    
        dictionaries.append( {"Name": name_set, "Data": storage_elements} )
        print("\n")

    
    for i in range(len(dictionaries)): # I'm printing each of the data-sets
        print(f"{i+1}° data-sets: {dictionaries[i]['Name']}")
        for idx, item in enumerate(dictionaries[i]['Data'], start=1):
            print(f"{idx}.{item}")
        print("\n")

    return dictionaries

def add_elements(dataset):
    while True: #Checks on input user
        number_new_elements=int(input("\nHow many elements do you want add? "))
        if number_new_elements>0:
            break
        else: 
            print("Invalid input. Enter an integer positive number.", end=" ")

    for i in range(number_new_elements):
        storage_elements={}
        while True: #Checks on input user
            couples=int(input("How many data's couples do you want enter (integer positive number): "))
            if couples>0:
                break
            else: 
                print("Invalid input. Try again.", end=" " )

        for j in range(couples):
            key=input("Enter a key: ").title()
            key_value=input("Enter a value of your key: ").title()
            storage_elements[key]=key_value   
        
    dataset["Data"].append(storage_elements)
    # print(f"New {dataset['Name']}:\n{dataset['Data']}")
    print(f"\n{dataset['Name']} Updated:\n")
    for idx, element in enumerate(dataset["Data"], start=1):
        print(f"{idx}. {element}")
    print("\n")
    
def remove_elements(dataset):
    number_removed_elements=int(input("\nHow many elements do you want remove? "))
    for i in range(number_removed_elements):
        while True:
            index=int(input("Which element do you want remove? "))
            
            if index>0 and index<=len(dataset["Data"]):
                deleted_element=dataset["Data"].pop(index-1)
                print(f"Removed: {deleted_element}")
                break #I'm getting out of the cycle

            elif index<=0 or index>len(dataset["Data"]):
                print(f"Error: Enter a number among [1,{len(dataset["Data"])}].",end=" ")

    print(f"\n{dataset['Name']} Updated:\n")
    for idx, element in enumerate(dataset["Data"], start=1):
        print(f"{idx}. {element}")
    print("\n")


# It's starting the main script's structure
print("Hello, I can create Data-Sets.")
management=building_dataSets()

while True:
    first_choice=input("Do you want change something in your Data-Sets? Press yes/no: ").lower()
    if first_choice=="yes":
        while True:
            try:
                index=int(input("\nWhich Data-Set do you want change? "))
                if index>0 and index<=len(management):
                    break
                
                else: # Checking index input
                    print(f"Error: Enter a number among [1,{len(management)}].", end=" ")
                    
            except ValueError:
                print("Invalid input! Enter an integer number", end=" ")

        print("\nMenù:")
        print("1.Add elements\n2.Remove elements")
        choiches=["add","remove","replace"]
        second_choice=input(f"Make your choice among {choiches}: ").strip().lower()

        if second_choice==choiches[0]: # Add elements
            print(f"\nYou want add elements in: {management[index-1]['Name']}")
            add_elements(management[index-1])

        elif second_choice==choiches[1]: # Remove elements
            print(f"\nYou want remove elements in {management[index-1]['Name']}")
            remove_elements(management[index-1])
    
    elif first_choice=="no": #Breaking the script
        print("\nThanks for your time, see you soon.")
        break        
    



    #The any() function in Python is a built-in function that returns True if at least one element of an iterable 
    # (such as a list, string, or other sequence) evaluates to true.
    #  If all elements of the iterable evaluate to false, it returns False.