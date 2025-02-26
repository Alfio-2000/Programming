#Write a script that it can create a management of a class's students. 

print("Hello, I can create a management of class' students")

while True: 
    name=input("Enter the name of your management: ").strip()
    if name!="":
        name={}
        break
    else:
        print("Enter a valid name. Try again: ",end=" ")

while True:
    key=input("Enter a key: ").title()
    key_value=input("Enter a value of your key: ").title()
    choice=input("\nDo you want continue? Press (yes/no): ")
    name[key]=key_value
    if choice.lower()=='no':
        break

print(f"\nYour management is: {name}")

first_choice=input("\nDo you want update your management? Press yes/no: ")

if first_choice.lower()=="yes":
    for key in name:# In this way I can change all keys of management
        print(f"New {key}:", end=" ")
        name[key]=input("").title()

if first_choice.lower()=="no":
    print(f"Your management is {name}.")


print(f"\nYour new management is: {name}")
