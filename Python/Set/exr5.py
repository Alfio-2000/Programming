# You have 2 sets: first_set={5,10,15,20}, second_set={10,20,30,40}. Write a script that it can do: 
#1. Union
#2. Intersection
#3. Difference
# 4. Simmetric Difference 

FIRST_SET={5,10,15,20}
SECOND_SET={10,20,30,40}

print(f"Hello, you have these sets: {FIRST_SET}, {SECOND_SET}. I can do these operations:\n")
print("1.Union\n2.Intersection\n3.Difference\n4.Simmetric Difference ")

VALID_CHOICES=["Union", "Intersection", "Difference", "Simmetric Difference"]
while True:
    while True:
        choice=input("\nEnter your choice: ")
        if choice.title() in VALID_CHOICES:
            print(f"\nUnion: {FIRST_SET|SECOND_SET}")
            break

        if choice.title() in VALID_CHOICES:
            print(f"\nIntersection: {FIRST_SET&SECOND_SET}")
            break

        if choice.title() in VALID_CHOICES:
            print(f"\nDifference {FIRST_SET}-{SECOND_SET}: {FIRST_SET-SECOND_SET}")
            print(f"\nDifference {SECOND_SET}-{FIRST_SET}: {SECOND_SET-FIRST_SET}")
            break

        if choice.title() in VALID_CHOICES:
            print(f"\nSimmetric Difference: {FIRST_SET}^{SECOND_SET}: {FIRST_SET^SECOND_SET}")
            break

        elif choice.title() not in VALID_CHOICES:
            print("Your choice is not available. Try again.",end=" ") 
    
    next_choice=input("\nDo you want continue? Press (yes/no): ")
    
    if next_choice.lower()=="yes":
        print("\nGreat! Let's do it again.")
    if next_choice.lower()=="no":
        print("\nThank you, see you soon!")
        break

