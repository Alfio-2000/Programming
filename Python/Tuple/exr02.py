# Write a script that it can find the first index of a numbers choiced by you

print("Hello, I can find any number of a tuple you want enter.")
while True:
    while True: 
        length=int(input("How many numbers do you want enter? "))
        if length>0:
            break
        else: 
            print("Wrong value. Try again:", end=" ")

    first_list=[]

    for i in range(length):
        element=int(input(f"Enter the {i+1}° element of your tuple: "))
        first_list.append(element)

    first_tuple=tuple(first_list)
    print(f"Your tuple is {first_tuple}")

    print(f"\nNow, we can start a number's research of {first_tuple}")
    founded_number=int(input("Which number do you want find? "))
    
    for i in range(len(first_tuple)):
        if first_tuple[i]==founded_number:
            print(f"{founded_number} is located in the {i+1}° position.") #I put i+1, because the PC starts to counting from 0 
            break

    counted_number=int(input("\nWhich number do you want count? "))
    counter=0
    for i in range(len(first_tuple)):
        if first_tuple[i]==counted_number:
            counter+=1
    print(f"{counted_number} is counted {counter} times.")
    
    choice=input("\nDo you want repeat this script? Press (yes/no): ")
    if choice.lower()=="yes":
        print("Great! Let's do it again.\n")
    elif choice.lower()=="no":
        print("Thank you for your time. See you soon.")
        break
