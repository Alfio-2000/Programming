# Write a script that it can calculate a numbers' average
# pylint: disable=all
while True:
    print("\nHi, i can calculate the average of your numbers\n")
    numbers=int(input("How many numbers do u want to enter? "))
    sum=0 # This counter is necessary to calculate the average
    for i in range(numbers):
        number=int(input(f"Enter {i+1}° number: "))
        sum+=number
    print(f"The average of your numbers is: {float(sum/numbers):.2f}")

    choice= input("\nDo you want restart this script? Press y/n ")
    if choice.lower()!="y":
        print("\nThanks, see you soon!")
        break

