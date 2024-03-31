#Secondo esercizio in Python: inserisci da tastiera il tuo nome

x=input("Inserisci il tuo nome:") #[1]
print(x)
print(type(x)) #in questo modo sto stampando il tipo di variabile che sto usando


# [1]: La funzione input ci permette di inserire qualcosa da tastiera: tuttavia, il compilatore pensa che
#stiamo inserendo delle STRINGHE!! NON NUMERI. Quindi, dovremmo fare un casting.
#Per capire meglio questo concetto vedi l'esercizio 3.
