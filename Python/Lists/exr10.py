# Write a script that it can create a list with a strings. In addition, this list needs to be sorted in ascending or descending order 

print("Hello, I can create a list with your words and I can to sort it in ascending or descending order.")
while True:
    while True:
        length=int(input("How many words do you want enter? "))
        if length>0:
            break
        else: 
            print("Wrong value! Try again:", end=" ")
    list=[]    
    for i in range(length):
        word=input(f"Enter {i+1}th word: ").capitalize()
        list.append(word)

    print(list)
    choice=input("\nHow do you want order your list? Press (a) for ascending order, press (d) for descending order: ")
    if choice.lower()=="a":
        list.sort(key=len) # In this way I'm sorting my word by  words' length
        print(f"Your sorted list is {list}")

    elif choice.lower()=="d":
        list.sort(reverse=True,key=len)
        print(f"Your sorted list is {list}")

    else: 
        print("Your choice is not available")

    choice1=input("\nDo you want repeat again this script? Press (yes/no):")
    if choice1.lower()=="no":
        print("Thanks you, see you soon.")
        break
    elif choice1.lower()=="yes":
        print("It's amazing. Let's do it again!\n")
    else:
        print("Your choice is not available")