#pylint: disable=all 

def checking_errors_name(str): #It checks if the user enter a valid input name
    while True:
        if str!="":
            break
        else:
            str=input("Invalid name. Try again: ").strip().title()

def building_dataSets():
    while True: 
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
        while number_elements<=0:
            number_elements=int(input("Error. Try again: ", end=" "))
        
        for element in range(1,number_elements+1):
            print(f"\nEntering data for element {element}: ")
            element_data={} #Dictionary to store (key-value) couples for one element
            couples=int(input("How many data's couples do you want enter (integer positive number): "))
            while couples<=0:
                couples=int(input("Error. Try again: ", end=" "))
            
            for j in range(1,couples+1):
                key=input("Enter a key: ").title()
                key_value=input("Enter a value of your key: ").title()
                element_data[key]=key_value

            storage_elements.append(element_data)
    
        dictionaries.append( {"Name": name_set, "Data": storage_elements} )
        print("\n")

    #Now, I'm printing each of the data-sets
    for i in range(len(dictionaries)):
        print(f"{i+1}° data-sets: {dictionaries[i]['Name']}")
        for item in dictionaries[i]['Data']:
            print(item)
        print("\n")


print("Hello, I can create Data-Sets.")
building_dataSets()
