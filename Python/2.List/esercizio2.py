#Ordinare una lista creata da tastiera.

lista=[]
print("Creazione lista:\n")
n=int(input("Inserisci il numero di elementi della tua lista:"))
for elemento in range(n):
    elemento=int(input(f"Inserisci il {elemento+1}° elemento della tua lista:"))
    lista.append(elemento)
print(f"La tua lista è: {lista}\n")

lista.sort(reverse=False) #1
print(f"La lista in ordine crescente è: {lista}\n")
lista.sort(reverse=True) #2
print(f"\nLa lista in ordine decrescente è: {lista}\n")

#1: La funzione .sort serve per ordinare una lista: se viene seguita dal reverse=False, significa che sarà ordinata
    #in ordine crescente, perché stiamo dicendo proprio che il "reverse" è falso.
    #Infatti, guarda la #2

