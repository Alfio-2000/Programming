#Stampa elementi pari e dispari

lista=[]
pari=[]
dispari=[]
count_pari=0
count_dispari=0
print("Costruisci la tua lista:\n")
n=int(input("Inserisci il numero di elementi della tua lista:"))
for elemento in range(n):
    elemento=int(input(f"Inserisci il {elemento+1}° elemento della tua lista:"))
    lista.append(elemento)
    if (elemento%2==0):
        pari.append(elemento)
        count_pari=count_pari+1 #1
    elif (elemento%2!=0):
        dispari.append(elemento)
        count_dispari=count_dispari+1
print(f"Ci sono {count_pari} numeri pari e {count_dispari} numeri dispari.\n")
print(f"\nLa tua lista è {lista}\n")
print(f"La tua lista presenta questi numeri pari: {pari}\n")

print(f"La tua lista presenta questi numeri dispari: {dispari}\n")

#1: Gli incrementi si fanno così. In Python NON È LECITO scrivere count++
