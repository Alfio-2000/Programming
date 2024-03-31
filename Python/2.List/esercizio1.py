#In Python non abbiamo i vettori come in C, ma le liste. Questo è un esempio di come crearle.

#Creo una lista da tastiera

lista=[] #1
print("Ciao, io sono in grado di costruire una lista.\n")
n=int(input("Inserisci il numero di elementi della tua lista:"))

for elemento in range(n):#2
    elemento=int(input(f"Inserisci il {elemento+1}° elemento della tua lista:")) #3
    lista.append(elemento) #4

print(f"{lista}")

#Spiegazione del codice:

#1: Creo una lista vuota: se non lo facessi avrei un errore: non verrebbe riconosciuta la lista.
    #Ricorda che in Python bisogna sempre assegnare qualcosa nel momento in cui dichiaro qualcosa

#2: Questo mi permette di generare degli elementi in un range: (0,n)

#3: Chiedo all'utente di inserire un elemento da tastiera. {elemento+1} serve per identificare la posizione dell'elemento
    #inserito

#4: Questa funzione mi serve per inserire ogni elemento all'interno della lsita.

#5: RICORDA DI CASTARE SEMPRE: in #3 se non mettessi int(input..) gli elementi inseriti verrebbero visti come stringhe
    #e non come numeri, avendo quindi dei problemi durante l'esecuzione.
