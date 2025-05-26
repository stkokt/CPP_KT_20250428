/*

Aufgabe 1:

    Verknüpfe zwei Integer- Variablen so miteinander,
    dass eine Wertänderung an der einen Variablen auch
    bei der anderen wirksam wird.

Aufgabe 2:

   Erstelle ein Array mit 10 Integer-Werten
   und initialisiere es mit den Zahlen von 1 bis 10.
   Verwende einen Zeiger, um die Werte des Arrays auszugeben.

Aufgabe 3:

   Schreibe ein Programm, das zwei Integer-Arrays
   mit jeweils 5 Elementen enthält. Verwende Zeigerarithmetik,
   um die Summe der Elemente beider Arrays zu berechnen und auszugeben.
   (Kann mit Aufgabe 5 verknüpft werden.)

Aufgabe 4:

   Erstelle ein Programm, das ein Array von 5 Integer-Werten
   enthält. Verwende einen Zeiger auf einen Zeiger, um auf die
   Elemente des Arrays zuzugreifen und diese zu ändern.

Aufgabe 5:

   Schreibe ein Programm, das ein dynamisches Array von
   Integer-Werten erstellt. Der Benutzer soll die Größe
   des Arrays und die Werte eingeben können. Verwende Zeiger,
   um die Werte des Arrays auszugeben.

Aufgabe 6:

   Schreibe ein Programm, das einen dynamischen Vektor von
   Integer-Werten erstellt. Der Benutzer soll die Größe des Vektors
   und die Werte eingeben können. Verwende Zeiger, um die Werte
   des Vektors auszugeben.

Aufgabe 7:

   Erstelle eine Map, die Schlüssel-Wert-Paare von Integern enthält.
   Verwende Zeiger, um auf die Werte der Map zuzugreifen und diese auszugeben.

Aufgabe 8:

   Schreibe ein Programm, das eine Map von Integer-Schlüsseln und String-Werten
   enthält. Verwende Zeiger, um die Werte der Map zu ändern und die geänderten
   Werte auszugeben.

Aufgabe 9:

    Schreibe ein Programm, das eine dynamische Map von Integer-Schlüsseln
    und String-Werten erstellt. Der Benutzer soll die Anzahl der
    Elemente und die Schlüssel-Wert-Paare eingeben können.
    Verwende Zeiger, um die Werte der Map auszugeben.

Aufgabe 10: Zeiger auf Arrays und Zeiger auf Zeiger

    10.1. Erstelle drei dynamische Arrays von Integern,
    jedes mit 5 Elementen. -> new

    10.2. Erstelle ein Array von Zeigern, das auf die ersten Elemente
    der drei dynamischen Arrays zeigt.

    10.3. Erstelle einen Zeiger, der auf das Array von Zeigern zeigt.

    10.4. Verwende eine Schleife, um über das Array von Zeigern zu
    iterieren und die Elemente der dynamischen Arrays auszugeben.
    Verwende dabei den Zeiger auf das Array von Zeigern.

    10.5. Gebe anschließend den Heapspeicher wieder frei.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    /*
     Das Schlüsselwort 'const':

     Absicherung gegen versehentliches Ändern.
     Sollte bei Lesevorgängen immer benutzt werden!

     Bezieht sich auf den Ausdruck, der links davon steht,
     es sei denn, links davon steht nichts mehr.
     Dann bezieht es sich auf den Ausdruck rechts davon.

     */

    int a = 10;
    int b = 11;
    int& c = a;     // Alias
    int *aptr = &a, *bptr = &b;

    cout << "Werte von c und a: " << c << " " << a << endl;
    a = 50;
    cout << "Werte von c und a: " << c << " " << a << endl;

    int const * ptr1 = &a;
    //*ptr1 += 10; // Funktioniert nicht, weil Wert(!) konstant
    ptr1 = &b;  // Zeiger umhängen möglich

    int * const ptr2 = &a; // Wertänderung möglich
    *ptr2 += 10; // Wertänderung möglich
    //ptr2 = &b; // Funktioniert nicht, weil Zeiger konstant

    int const * const ptr3 = &a;
    // Nur Ausgabe möglich, Wert und Pointer hierüber unveränderbar

    const int* const ptr4 = &a;
    // Selbe Funktionalität wie ptr3, nur andere Schreibweise


    {   // Aufgabe 1
        cout<< "\nAufgabe 1" << endl;

       
    }

    {   // Aufgabe 2
        cout<< "\nAufgabe 2" << endl;

       
    }

    {   // Aufgabe 3
        cout<< "\nAufgabe 3" << endl;

        

        
    }

    {   // Aufgabe 4
        cout<< "\nAufgabe 4" << endl;

    }

    {   // Aufgabe 5
        cout<< "\nAufgabe 5" << endl;

    }

    {   // Aufgabe 6
        cout<< "\nAufgabe 6" << endl;

        
    }

    {   // Aufgabe 7
        cout<< "\nAufgabe 7" << endl;

    }

    {   // Aufgabe 9
        cout<< "\nAufgabe 9" << endl;

    }

    {   // Aufgabe 10
        cout<< "\nAufgabe 10" << endl;

        

    }

    return 0;
}
