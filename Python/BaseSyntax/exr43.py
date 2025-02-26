# Reverse Fortune teller: thinks a number and PC tries to guess it
# pylint: disable=all

print("Think of a number within a range you will choose.\n")

min=int(input("Enter the lower limit of your range: "))
max=int(input("Enter the higher limit of your range: "))
max_attempts=int(input("Enter the max number of allowed attempts: "))

print(f"\nThink a number between {min} and {max}. I'll try to guess it in {max_attempts} attempts")
input("Press 'ENTER' when you want to start the game ")

attempt=0 # Counter for attempts
found= False #This is useful to print a message in that case the script can't guess the number

while attempt<max_attempts and min<=max:
    
    guess=(min+max)//2 # (1)
    attempt+=1 #I'm increasing my attempt
    reply=input(f"{attempt}° attempt: Is {guess} your number? Reply with 'yes', 'higher' or 'lower': ")
    
    if reply.lower()=="yes":
        print(f"AMAZING! I've guessed your number {guess} in {attempt} attempts")
        found= True
        break
    elif reply.lower()=="higher":
        min=guess

    elif reply.lower()=="lower":
        max=guess
    else:
        print("Wrong selection! Try again.")
        attempt-=1

if not found:
    print("Oh no! I couldn't guess the number within the allowed attempts.")




#(1): The logic is this: i'm calculating the average of the range because in this way i can to ignore half of the numbers