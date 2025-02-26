#pylint: disable=all 

print("Hello, I can create data-sets.\n")

while True: 
    numbers_dictionaries=int(input("Data-sets' number (integer positive number): "))
    if numbers_dictionaries>0:
        break
    else:
        print("Error. Try again:",end=" ")

dictionaries=[] 
for i in range(1,numbers_dictionaries+1):
    name_set=input(f"Enter the name of the {i}° data-set: ").strip().title()
    while True:
        if name_set!="":
            break
        else:
            name_set=input("Invalid name. Try again: ").strip().title()
    
    name={}
    couples=int(input("How many data's couples do you want enter (integer positive number): "))
    while couples<=0:
        couples=int(input("Error. Try again: "))
    storage_elements=[]
    for j in range(1,couples+1):
        key=input("Enter a key: ").title()
        key_value=input("Enter a value of your key: ").title()
        name[key]=key_value

    dictionaries.append( {"Name": name_set, "Data": name} )
    print("\n")

for i in range(len(dictionaries)):
    print(f"{i+1}° data-sets: {dictionaries[i]['Name']}\n{dictionaries[i]['Data']}\n")
