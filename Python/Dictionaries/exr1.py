# Write a script that it can create a dictionary

print("Hello, I can create a dictionary.")

name=input("Enter the name of your dictionary: ")
name={}

while True:
    key=input("Enter a key: ").title()
    key_value=input("Enter a value of your key: ").title()
    choice=input("\nDo you want continue? Press (yes/no): ")
    name[key]=key_value
    if choice.lower()=='yes':
        print("\nThank you, see you soon.")
        break

print(f"\nYour dictionary is: {name}")

