## 1. Big Integer

Erstellen Sie eine C++ Klasse `BigInt`, um mit beliebig großen Ganzzahlen zu rechnen. Bei dieser Implementierung geht es mehr um die Korrektheit als um die Geschwindigkeit oder Kompaktheit der Darstellung. Daher kann folgende, sehr einfache, Darstellungsform gewählt werden. Jede ganze Zahl soll als beliebig großes Feld von kurzen vorzeichenlosen Ganzzahlen (`short unsigned int`) dargestellt werden, wobei jede dieser Ganzzahlen genau eine Dezimalstelle repräsentiert. Die Zahl „33290“ wird also durch ein Feld `a` der Länge 5 mit den Elementen beginnend beim least significant digit `a[0]=0, a[1]=9, a[2]=2, a[3]=3, und a[4]=3` repräsentiert. Dazu kommt noch das Vorzeichen, das einfach als boolescher Wert (`sign`) als Datenkomponente gespeichert werden soll. Als Komplikation kommt noch hinzu, dass Zeiger auf dynamische Felder in C++, technisch gesehen, zwar ihre eigene Größe kennen, diese aber nicht von außen abgefragt werden kann. Deshalb wird auch noch eine weitere Datenkomponente `length` benötigt, in der die Anzahl der Stellen gespeichert werden soll.

Die Grundstruktur dieser Klasse könnte also z.B. so aussehen:

```cpp
class BigInt {
private:
  bool is_negative;
  unsigned long length;
  unsigned short *digits;
  /* ... */
};
```

Dabei muss die Länge des Feldes variabel sein und sich nach der Anzahl der Stellen der darzustellenden Zahl richten. Bei arithmetischen Operationen muss daher immer schon im Vorhinein berechnet werden, wie viele Stellen die Zahl maximal bekommen kann.

**a.** Implementieren Sie alle notwendigen Konstruktoren, einen Destruktor einen Kopierkonstruktor und einen Zuweisungsoperator um mindestens folgende Funktionalität zu ermöglichen:

* Das Erstellen eines `BigInt` von einem `long int`.
* Das Erstellen eines `BigInt` von einem beliebig großen Feld von `unsigned short int`.

**b.** Implementieren Sie eine Vergleichsfunktion `cmp`, die einen `BigInt` mit einem anderen `BigInt` vergleichen kann, und entweder eine Zahl kleiner, größer oder gleich 0 zurückliefert, je nachdem ob der BigInt kleiner, größer oder gleich dem anderen BigInt b ist.

```c
short cmp(const BigInt &b) const;
```

Verwenden Sie Ihre Implementierung von cmp, um alle andere Vergleichsoperatoren (`„<“, „<=“, „==“, „!=“, „>=“, „>“`) zu implementieren.

**c.** Implementieren Sie einen Ausgabeoperator (`operator <<`) um einen `BigInt` auf einen beliebigen Ausgabestrom (`ostream`) zu schreiben.

**d.** Implementieren Sie die arithmetischen Operationen Addition und Subtraktion. Einmal als Methoden `„operator +=“` und `„operator -=“`, die das Objekt verändern und einmal als Funktionen (`„operator +“` und `„operator -“`).

**Hinweis:** Am besten Sie implementieren zwei Funktionen (keine Methoden): Eine die die vorzeichenlose Addition implementiert sowie eine, die die vorzeichenlose Subtraktion einer kleineren Zahl von einer größeren bewerkstelligt und verwenden diese dann, um beliebige ganze Zahlen (also mit Vorzeichen) zu addieren und zu subtrahieren. Die beiden Basisfunktionen lassen sich dann leicht der „Volkschul“-Addition und Subtraktion nachempfinden.

**e.** Implementieren Sie die arithmetischen Operationen Multiplikation und Division, wieder zuerst als Methoden `„operator *=“`  und `„operator /=“`, die das Objekt verändern und, darauf aufbauend, dann als Funktionen (`„operator *“` und `„operator /“`).  Sie können dabei den Rest der Division verwerfen, so wie bei einer ganzzahligen Division üblich.

**Hinweis zur Multiplikation:** Auch hier kommt wieder „Volkschul“-Technologie zum Einsatz: Überlegen Sie welche Stellen ausmultipliziert werden und an welche Stellen im Ergebnis sie fließen, wie im folgenden Beispiel dargestellt:

![multiplication](/doc/multiplication.PNG)

**Hinweis zur Division:** Überlegen Sie sich auch hier, wie Sie bei einer Division auf Papier vorgehen würden und implementieren Sie dieses Vorgehen nach. Anstatt zu probieren, wie oft der Divisor im entsprechenden Präfix des Dividenden steckt, dürfen Sie ihn einfach wiederholt abziehen. Zum Beispiel bei der Berechnung von „3210“ dividiert durch „123“, betrachten wir zunächst den ersten Präfix, der groß genug ist, also „321“. Davon ziehen wird „123“ ab und erhalten „198“. Da „198“ größer ist als „123“ ziehen wir noch einmal „123“ ab und erhalten „75“. Da „75“ nicht mehr größer als „123“ ist, ergibt sich für die höchste Stelle des Resultats „2“, da wir zweimal subtrahieren konnten. Jetzt bauen wir „75“ wieder an die richtige Stelle des Dividenden ein und erhalten statt „3210“ nur mehr „0750“. Wir extrahieren nun den nächstgrößten Präfix, in diesem Fall den kompletten Dividenden und ziehen „123“ wieder so oft wie möglich ab. Hier erhalten wir nach sechs Wiederholungen „12“, was nicht mehr groß genug ist. Damit ist das Ergebnis „26“ mit Rest „12“.

![division](/doc/division.PNG)

Testen Sie ihre Implementierung **ausführlich**: Testen Sie Randfälle der Implementierung, z.B. mit Übertrag und ohne Übertrag. Vergleichen Sie Ihre Ergebnisse auch mit zufällig generierten Werten mit der Integer Arithmetik von z.B. `long int`.
