#Dati due numeri in input: stabilire quale dei due sia più grande.

print("Sono il programma in grado di stabilire quale numero risulta più grande tra i numeri da te inseriti.\n")

#1° modo:

x=float(input("Inserisci il primo numero:"))
y=float(input("Inserisci il secondo numero:"))
if x>y:
    print(f"Il maggiore tra i due numeri è {x}")
elif x<y:
    print(f"Il maggiore tra i due numeri è {y}")
else:
    print("I due numeri sono uguali.\n")

#2° modo:

x=float(input("Inserisci il primo numero:"))
y=float(input("Inserisci il secondo numero:"))

c=max(x,y) #Questa funzione mi permette di determinare il massimo tra due elementi.
print(f"Il maggiore è {c}")



print("\n\n")




