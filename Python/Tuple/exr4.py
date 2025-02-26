# Create a tuple with cities' name: your tuple's length needs to enter by keyboard
# Print the first and the last city of the tuple
# Change the name of the cities with lists' help

print("Hello, I can create a tuple with the name of your favourite cities. ")

while True: 
    length=int(input("\nPlease, enter your tuple's length: "))
    if length>0:
        break
    else:
        print("Wrong value. Try again:",end=" ")

list_names=[] #This is an empty list. It helps me to create a tuple. Infact, after that, I will make a casting to declare user's tuple

for i in range(length):
    name=input(f"Enter the {i+1}° city name: ").title() #Every first letter of every word is capital
    list_names.append(name) #I'm uploanding every city name in the list

cities=tuple(list_names)
print(f"Your tuple is: {cities}.",end="\n")
print("In the reversal order:",cities[::-1])

while True:
    sliceNumber=int(input(f"\nNow, which elements do you want print? Enter a number smaller than {length}: "))
    if sliceNumber<=len(cities):
        print(f"These are the first {sliceNumber} cities: {cities[:sliceNumber]}")
        print(f"These are the last {sliceNumber} cities: {cities[-sliceNumber:]}")
        break
    else: 
        print("\nYou've entered a wrong value.Try again:",end=" ")
 
print("\nNow, we are sorting you tuple by words's length: ",end=" ")

temporary_list=list(cities)

temporary_list.sort(reverse=True,key=len)
new_cities=tuple(temporary_list)
print(new_cities)
