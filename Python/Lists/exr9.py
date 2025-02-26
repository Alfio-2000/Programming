# Write a script that it can create a list with the first n numbers. 
# Then, the script must to print the string "even number" when we find an even element

print("Hello, I can create a list and I can print 'even number' when I find it. ")

while True: 
    numbers=int(input("\nHow many numbers do you want enter?Please, enter an integer positive number: "))
    if numbers>0: 
        break
    else:
        print("Wrong value: Try again!")

EVEN_STRING="Even Number"
ODD_STRING="Odd Number"

list=[element for element in range(1,numbers+1)]

for i in range(len(list)):
    if list[i]%2==0: 
        print(f"{list[i]}: ",EVEN_STRING)
    else: 
        print(f"{list[i]}: ",ODD_STRING)

print(f"\nNow, I can replace an even number with the string '{EVEN_STRING}'.")
for i in range(len(list)):
    if list[i]%2==0:
        list[i]=EVEN_STRING
        print(list[i])
    else: 
        list[i]=ODD_STRING
        print(list[i])