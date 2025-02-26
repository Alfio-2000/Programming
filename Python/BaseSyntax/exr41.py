# Write a script python that it can print, with a while loop, the firt n numbers entered by keyboard. 

while True:
    total_numbers=int(input("How many numbers do you want enter? "))
    if total_numbers<0:
        print("Error: you've entered a negative number!")
        break
    sum=0 #this is a counter
    i=1
    while i<=total_numbers:
        sum+=i
        i+=1 # This is necessary to restart while loop with different i value 
    print("The sum of the first",total_numbers, "numbers is: ", sum )
    
    #Now, it starts the part to restart the script
    choice=input("\nDo you want continue this script? Press (y/n): ")
    if choice.lower()=="y":
        print("\nPerfect! We can restart!\n")
    elif choice.lower()!="y":
        print("Thanks, see you soon!")
        break










 
    
        
        
    