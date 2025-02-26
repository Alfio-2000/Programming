# Create a set and remove a number that you've choosen. 

while True:
    length=int(input("How many numbers do you want enter? Please, enter an integer positive number: "))
    if length>0: 
        break
    else:
        print("\nWrong value. Try again:", end=" ")

numbers_list=[]
for i in range(1,length+1):
    element=int(input(f"Enter the {i}° number: "))
    numbers_list.append(element)

numbers=set(numbers_list) #I'm converting the list in a set. 
print(f"Your set is: {numbers}\n")

while True:
    remove_number=int(input("What number do you want remove? Please, enter an integer positive number: ")) 
    if remove_number>0: 
        break
    else:
        print("Wrong value. Try again:", end=" ")

if remove_number in numbers: 
    numbers.discard(remove_number) #Function that can remove a set's element 
    print(f"I removed {remove_number}. Your new set is {numbers} ")

else:
    print(f"{remove_number} isn't contained in {numbers}") 


