
stringa="alessandra"
count=0
for caratteri in stringa:
    count+=1
print(f"La stringa '{stringa}' contiene {count} lettere")
a_count=0 #Questo contatore mi serve per poter contare il numero di caratteri uguali in una parola
s_count=0
for carattere in stringa:
    if carattere =="a":
        a_count+=1 #[1]
    if carattere=="s":
        s_count+=1
print(f"\nLa lettera 'a' è presente {a_count} volte") #Questo mi permette di poter inserire le variabili all'interno del print
print(f"La lettera 's' è presente {s_count} volte")

print("\nAdesso calcoliamo la media di una lista di numeri.")
somma=0.0 #Contatore somma

while True: #[2]
    x=int(input("Inserisci il numero di elementi: "))
    if x<=0:
        print("Errore! Hai inserito un numero NON valido! RIPROVA!")
    else:
        break

lista_numeri=[float(input(f"{i+1}° elemento: "))for i in range(x)]
print(f"La lista creata è {lista_numeri}")

for elemento in lista_numeri:
        somma+=elemento
        media=somma/x

print(f"La media dei numeri inseriti è: {media:.2f}")#[3]






#[1]: In python un contatore va incrementato così. SCRIVERE count++ in python è ERRATO.

#[2]: Dalla riga 20 alla 25 ho implementato un controllo sul numero x.
#questo è necessario perché in Python NON esiste il do-while.
#Il True significa che il codice fin quando tutto ciò che porta all'if risulta vero.
#altrimenti esce dal ciclo e continua il codice.

#[3]: media:.2f significa che sto dando alla variabile solo 2 cifre dopo la virgola in output
