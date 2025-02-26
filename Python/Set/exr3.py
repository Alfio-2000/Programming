# Create a script that can built n sets

while True: 
    number_sets=int(input("How many sets do you want built? Please, enter an integer positive number: "))
    if number_sets>0:
        break
    else: 
        print("\nWrong value. Try again.", end=" ")

sets_list=[]

for i in range(1,number_sets+1):
    current_set=set()
    while True: 
        length=int(input("\nHow many numbers do you want enter in every set? Please, enter an integer positive number: "))
        if length>0:
            break
        else:
            print("\nWrong value. Try again.", end=" ")
    
    for j in range(1,length+1):
        element=int(input(f"Enter the {j}° element: "))
        current_set.add(element)
   
    sets_list.append(current_set)
print("\nYour sets are:")
for i in range(len(sets_list)):
    print(f"{i+1}° set: {sets_list[i]}")
