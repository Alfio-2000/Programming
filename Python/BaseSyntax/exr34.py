#Write a script that it can to converte a number in a word.
#Example: "3"-> three

number = int(input("Enter un number tra 0 e 9: "))

if number == 0:
    print("Word: zero")
elif number == 1:
    print("Word: one")
elif number == 2:
    print("Word: two")
elif number == 3:
    print("Word: three")
elif number == 4:
    print("Word: four")
elif number == 5:
    print("Word: five")
elif number == 6:
    print("Word: six")
elif number == 7:
    print("Word: seven")
elif number == 8:
    print("Word: eight")
elif number == 9:
    print("Word: number")
else:
    print("Error: the number isn't in [0,9]")

#This exercise has a better version, but it is necessary to use the lists and at the moment i don't study them. Anyway, the version is this:
# words=["zero","one","two","three","four","five","six","seven","eight","nine"]
# number=int(input(f"Enter a number in [0,9]: "))
# for i in range(10):
#     if number==i:
#         print(f"{number} -> '{words[i]}'")
#         break
