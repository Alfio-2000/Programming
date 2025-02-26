# The script of the fortune teller: the user must to guess a random number that it thought by PC

import random #This is the library that allows me to import a random number in a range. (1)

while True:
    print("Hi, i'm thinking a number between 1 and 10: try to guess it!")
    number=random.randint(1,10) # I'm creating a random number between 1 and 10 (2)
    guess=int(input("Enter your attempt: "))
    while guess!=number:
        guess=int(input("Wrong! Try again: "))

    print("Nice try! You've guess it!")

    choice=input("Do you want to restart this game? Press (y/n): ")
    if choice.lower()=="y":
        print("\nit's great! Let's game again.\n")
    elif choice.lower()!="y":
        print("Thanks!See you soon!")
        break






#(1): In that moment didn't study that library/module. So, i researchered it on internet
#(2): random.uniform(1.3,2.4) allows me to create a random float number