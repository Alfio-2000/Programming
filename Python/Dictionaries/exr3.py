# You have this dictionary: person={"Name":"Alfio","Surname":"Lo Castro","Age":"25"}
#You must change one of the keys' value and update it with a new key with a new value entered by keyboard

person={"Name":"Alfio",
        "Surname":"Lo Castro",
        "Age":"25"} # I can use this syntax too

print("You can change this dictionary:")

for key,value in person.items(): #This function allows me to print (key-value)
    print(f"{key}:{value}")

key=input("\nWhat do you want change? ").title()

if key in person: 
    person[key]=input("Enter a new value: ").title()
    print(person)
else: 
    print("Your key isn't in the dictionary.")

choice=input("\nDo you want add another couple (key-value)? Press (yes/no): ").lower()
if choice=="yes":
    new_key=input("Enter your new key: ").title()
    new_value=input("Enter its new value: ").title()
    person[new_key]=new_value
    print(f"The new dictionary is: {person}")

if choice=="no":
    print("\nOk, thank you. See you soon.")    
