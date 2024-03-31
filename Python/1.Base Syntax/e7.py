

numeri=[1,3,3,4] #questa è una lista --> NON È UN ARRAY
somma=0 #Dichiaro una variabile inizializzata che mi servirà per poter sommare gli elementi di numeri.

print("Stampo gli elementi di una lista già nota.")

for elemento in numeri: #Stampo e sommo gli elementi di una lista
    print("Elemento: ", elemento) #Non per stampare nella stessa riga l'elemento e la frase che scriviamo tra "".
    somma+=elemento

print("\nLa somma della prima sequenza di numeri è:",somma)

print("\nAdesso genero una sequenza di numeri:") #Uguale al C -> serve per generare uno spazio.

for number in range(11): #Stampo una sequenza di numeri
    print(number)

print("\nGenero 10 numeri e stampo solo quelli pari.\n")

for contatore in range(11): #Stampo solo i numeri pari di una sequenza di 10 numeri.
    if contatore%2==0:
        print(contatore)


