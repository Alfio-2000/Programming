#Contare quanti elementi di una lista si ripetono

lista=[]
print("Creazione lista:\n")
n=int(input("Inserisci il numero di elementi della tua lista:"))
for elemento in range(n):
    elemento=int(input(f"Inserisci il {elemento+1}° elemento della tua lista:"))
    lista.append(elemento)
    count_elemento=lista.count(elemento)
print(f"La tua lista è: {lista}\n")
print(f"Nella tua lista l'elemento {elemento} è presente {count_elemento} volte\n")
