#In python non posso scrive sulla stessa riga più istruzioni come si fa in C

x=input("Inserisci il primo numero: ")
y=input("Inserisci il secondo numero: ")
z=input("Inserisci il terzo numero: ")
print(int(x)+int(y)+int(z))) #[1]


#[1]: In virtù  dell'esercizio precedente, per poter dire al compilatore di considerare numeri, piuttosto che stringhe
#bisgogna castare le variabili.
#Quindi, se scrivessimo print(x+y+z) il compilatore concatenerebbe le stringhe.
#Ad esempio, se x=5,y=4,z=2, in output troveremo 542 e non 11!


#Nel prossimo esercizio vediamo come e se è possibile ottimizzare tale codice.


