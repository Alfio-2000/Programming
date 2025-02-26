# 1. Get from keyboard name, surname and age making sure that are no white spaces around
# 2. Send to screen a person's descriptive sentence with the last 3 surname's characters in uppercase
# 3. Making sure that the name has the first letter upper and send to screen it with the first 3 letters
# 4. Age plus surname's lenght with 4 decimal points 
# 5. Send to screen name, surname and age splitted by  "-"


name= input("Enter your name: ").strip() #in 8-10 statements i put .strip() to remove spaces enter by keyboard by user
surname=input("Enter your surname: ").strip()
age=int(input("Enter your age: ").strip()) 

string1=f"Hi, i'm {name[:3].capitalize()} {surname[-3:].upper()} and i'm {age+len(surname):.4f} y.o "
print(string1)
 
# In this way i'm sure that the first letter is upper, because the function capitalize() made it-> See theory (B.C.1:)

# print( f"{age+ float(len(surname)):.4f}" ) Len return int, so, i must do casting float and to use f"" to write .nf (B.C.2:)

string2=f"{name} {surname} {age}"
print(string2.replace(" ","-")) # (B.C.3:)

# (B.C.1:) The statement print(name.startswith(name[0].upper)) is wrong, because startswith() wants strinngs or tuples, not functions. 
# (B.C.2:) The .nf to establish the numbers after , is necessary to use f-strings, that is f"string"
# (B.C.3:) I can't use split(), because this one must be use to divide strings in lists