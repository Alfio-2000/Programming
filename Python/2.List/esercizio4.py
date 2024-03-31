#Stampare il massimo e il minimo tra gli elementi di una lista
lista=[]
print("Costruisci la tua lista:\n")
n=int(input("Inserisci il numero di elementi della tua lista:"))
for elemento in range(n):
    elemento=int(input(f"Inserisci il {elemento+1}° elemento della tua lista:"))
    lista.append(elemento)

#Adesso individuo il massimo e il minimo
massimo=max(lista)
minimo=min(lista)
print(f"\nLa tua lista è {lista}")

print(f"\nIl massimo degli elementi è: {massimo}.\nIl minimo degli elementi è: {minimo}\n")
