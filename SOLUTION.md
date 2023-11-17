# Übung 5 - Lösung

## 1. BigInt (src/bigint/)

### Lösungsidee
1. Constructor - explicit BigInt(bool is_negative,  unsigned long length, long num);
   ein BigInt wird erstellt von einem long int. das Vorzeichen und die Länge werden gespeichert.
2. Destructor - ~BigInt();
    Dynamische Feld wird freigegeben.
3. void print() const;
    Gibt die Feld aus.
4. BigInt(const BigInt& b);  // copy constructor
   Automatisch erzeugter (impliziter) Kopierkonstruktor kopiert Datenkomponenten elementweise.
5. BigInt& operator=(const BigInt& b); // assignment
   Zuweisungsoperator weist Datenkomponenten elementweise zu. Neue Feld wird erstellt und Feld das THIS zeigt, wird gelöscht. This dann zeigt neues Feld und alle elemente werden kopiert.
6. short cmp(const BigInt &b) const;
    Ein BigInt wird mit anderenvergleicht und wird ausgegeben: BigInt kleiner, größer oder gleich dem anderen BigInt b ist.
7. BigInt& operator+= (const BigInt& b);
   Zuerst wird vorzeichenlose Addition - unsigned short* addition() implementiert. Dann wird diese Function in Methode „operator +=“ verwendet. Wenn beide Vorzeichen gleich sind, dann wird addition aufgerufen. Wenn beide verschiedene Vorzeichen haben, dann wird mit Methode compare grösser Zahl defieniert und von diesem Zahl die andere subtrahiert.
8. BigInt& operator-= (const BigInt& b);
    Hier wird auch vorzeichenlose subtraction implementiert. Dann wird diese Function in Methode „operator -=“ verwendet. Wenn beide Vorzeichen gleich sind, dann wird subtraction aufgerufen. Wenn beide verschiedene Vorzeichen haben, dann wird addition aufgerufen.
9. BigInt& operator/= (long divisor);
 Wenn divisor 0 ist, dann wird Fehlermeldung ausgegeben. Neue Feld wird erstellt, um die Ergebnis zu speichern. Dividend wird um long umgewandelt und division ausgeführt. 
10. BigInt& operator*= (const BigInt& b);
    Neue Feld wird erstellt, um die Ergebnis zu speichern. Jede ergebnis von multiplikation wird modulo berechnet und in neuem Feld gespeichert. 
11. friend std::ostream& operator<<(std::ostream& os, const BigInt& b);
    ein BigInt wird auf einen beliebigen Ausgabestrom (ostream) geschrieben.

in division konnte ich nicht reverse machen. Leider hatte ich nicht genug Zeit.
   

### Testfälle
/Users/shahinm/Documents/SWO/Ubung7/ue05-ulkerm/src/cmake-build-debug/bin/bigint
The second BigInt [6, 7, 6]is greater than the first one[5, 4, 5].
~BigInt destructed
~BigInt destructed
545
BigInt::operator=(const BigInt &b)
BigInt: [6, 7, 6]
BigInt [6, 7, 6] *  BigInt [5, 4, 5] = [3, 6, 8, 4, 2, 0]
BigInt [3, 6, 8, 4, 2, 0] +  BigInt [5, 4, 5] = [3, 6, 8, 9, 6, 5]
BigInt [3, 6, 8, 9, 6, 5] -  BigInt [5, 4, 5] = [3, 6, 8, 4, 2, 0]
BigInt [5, 4, 5] /  100  = [0, 0, 0, 5]
~BigInt destructed
~BigInt destructed
~BigInt destructed
The first BigInt [1, 1, 1, 2, 3] is greater than the second one [2, 6] .
~BigInt destructed
~BigInt destructed

The second BigInt is greater than the first one.
~BigInt destructed
~BigInt destructed
-3333
BigInt::operator=(const BigInt &b)
BigInt: -[3, 2, 3]
BigInt -[3, 2, 3] *  BigInt -[3, 3, 3, 3] = [1, 0, 7, 6, 5, 5, 9]
BigInt [1, 0, 7, 6, 5, 5, 9] +  BigInt -[3, 3, 3, 3] = [1, 0, 7, 3, 2, 2, 6]
BigInt [1, 0, 7, 3, 2, 2, 6] -  BigInt -[3, 3, 3, 3] = [1, 0, 7, 6, 5, 5, 9]
BigInt -[3, 3, 3, 3] /  -10  = -[0, 0, 3, 3, 3]
~BigInt destructed
~BigInt destructed
~BigInt destructed

The first BigInt [1, 1, 1, 2, 3] is greater than the second one [2, 6] .
~BigInt destructed
~BigInt destructed
11123
BigInt::operator=(const BigInt &b)
BigInt: [2, 6]
BigInt [1, 1, 1, 2, 3] *  BigInt [1, 1, 1, 2, 3] = [0, 1, 2, 3, 7, 2, 1, 1, 2, 9]
BigInt [2, 6] +  BigInt [1, 1, 1, 2, 3] = [1, 1, 1, 4, 9]
BigInt [1, 1, 1, 4, 9] -  BigInt [1, 1, 1, 2, 3] = [0, 0, 0, 2, 6]
BigInt [1, 1, 1, 2, 3] /  100  = [0, 0, 0, 3, 2, 1]     // reverse
~BigInt destructed
~BigInt destructed
~BigInt destructed

Process finished with exit code 0

-[6, 6, 6, 5, 7, 5, 8, 8, 4, 5, 6, 5, 1, 1, 1, 2, 3]
[3, 5, 4, 3, 5, 5, 6, 5, 6, 7, 9, 9, 2, 6]
[3, 4, 3, 4, 3, 4, 3, 4, 3, 5, 5, 6, 6, 6]
[9, 8, 7, 6, 5, 4, 3, 8, 7, 6, 5, 4, 3, 6]
~BigInt destructed
~BigInt destructed
~BigInt destructed
~BigInt destructed

/Users/shahinm/Documents/SWO/Ubung7/ue05-ulkerm/src/cmake-build-debug/bin/bigint
The second BigInt [6]is greater than the first one-[4, 2, 7, 4].
~BigInt destructed
~BigInt destructed
-4274
BigInt::operator=(const BigInt &b)
BigInt: [6]
BigInt [6] *  BigInt -[4, 2, 7, 4] = -[2, 5, 6, 4, 4]
BigInt -[2, 5, 6, 4, 4] +  BigInt -[4, 2, 7, 4] = -[2, 9, 9, 1, 8]
BigInt -[2, 9, 9, 1, 8] -  BigInt -[4, 2, 7, 4] = -[2, 5, 6, 4, 4]
~BigInt destructed
~BigInt destructed
~BigInt destructed
The first BigInt [9, 6, 3] is greater than the second one -[3, 6] .
~BigInt destructed
~BigInt destructed
963
BigInt::operator=(const BigInt &b)
BigInt: -[3, 6]
BigInt [9, 6, 3] *  BigInt [9, 6, 3] = [9, 2, 7, 3, 6, 9]
BigInt -[3, 6] +  BigInt [9, 6, 3] = [9, 2, 7]
~BigInt destructed
~BigInt destructed
~BigInt destructed
-[6, 6, 6, 5, 7, 5, 8, 8, 4, 5, 6, 5, 1, 1, 1, 2, 3]
[3, 5, 4, 3, 5, 5, 6, 5, 6, 7, 9, 9, 2, 6]
[3, 4, 3, 4, 3, 4, 3, 4, 3, 5, 5, 6, 6, 6]
[9, 8, 7, 6, 5, 4, 3, 8, 7, 6, 5, 4, 3, 6]
~BigInt destructed
~BigInt destructed
~BigInt destructed
~BigInt destructed

Process finished with exit code 0

