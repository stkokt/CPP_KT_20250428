// Aufgabe 1: Schreibe ein Programm, das die Größe der 
//            grundlegenden Datentypen in C++ ausgibt.

// Aufgabe 2: Schreibe Programm, das demonstriert,
//            wie ein Integer-Überlauf auftritt.
//            Verwende dazu die Bibliothek "Limits"

// Aufgabe 3: Schreibe ein Programm, das eine implizite und
//            eine explizite Typumwandlung zeigt.

// Aufgabe 4: Schreibe ein Programm, das die minimalen und 
//            maximalen Werte der Basisdatentypen ausgibt. (Limits)
 
// Aufgabe 5: Schreibe ein Programm, das die Genauigkeit 
//            von Gleitkommazahlen demonstriert.

// Aufgabe 6: Schreibe ein Programm, das die ganzzahlige 
//            Division und den Rest demonstriert.

// Aufgabe 7: Schreibe ein Programm, das den ASCII-Wert 
//            eines Zeichens (char) ausgibt.

// Aufgabe 8: Kann man mit Chars rechnen? Wenn ja, nenne
//            Vor- und Nachteile.

// Aufgabe 9: Schreibe ein Programm, das die Summe der ersten 
//            100 ganzen Zahlen berechnet. Verwende dazu einen Loop.

// Aufgabe 10: Schreibe ein Programm, das die Summe der ungeraden Zahlen in 
//             den ersten 100 ganzen Zahlen berechnet.
//             Verwende dazu einen Loop und eine Bedingung.

#include <iostream>
#include <limits>
#include <iomanip>
#include <typeinfo>
using namespace std;

int main() {

    // Aufgabe 1
    cout << "\nAufgabe 1\n" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " byte" << endl;

    // Aufgabe 2
    cout << "\nAufgabe 2\n" << endl;
    int maxInt = numeric_limits<int>::max();
    cout << "Max int Wert: " << maxInt << endl;
    cout << "Max int Wert + 1: " << maxInt + 1 << endl; // Demonstriert Überlauf

    // Aufgabe 3
    cout << "\nAufgabe 3\n" << endl;
    int a = 10;
    int b = 3;

    // Implizite Typumwandlung
    
    cout << "Implizite Typumwandlung: " << typeid(a/b).name() << endl;
    cout << "Wert von a/b: " << a/b << endl;

    // Explizite Typumwandlung
    cout << "Explizite Typumwandlung (typecasting) über C- Syntax: " << typeid((double)b).name() << endl;
    cout << "Explizite Typumwandlung (typecasting) über CPP- Syntax: " << typeid(static_cast<double>(b)).name() << endl;
    cout << "Wert von a/b: " << (double)(a/b) << endl; // Nützt nichts, weil die int- Konvertierung in (a/b) schon stattfindet.
    cout << "Wert von a/b: " << (double)(a)/b << endl;

    // Aufgabe 4
    cout << "\nAufgabe 4\n" << endl;
    cout << "Min int Wert: " << numeric_limits<int>::min() << endl;
    cout << "Max int Wert: " << numeric_limits<int>::max() << endl;
    cout << "Min float Wert: " << numeric_limits<float>::lowest() << endl;
    cout << "Max float Wert: " << numeric_limits<float>::max() << endl;

    // Aufgabe 5
    cout << "\nAufgabe 5\n" << endl;
    float e = 1.1;
    double f = 1.1;

    cout << "Float Wert: " << e << endl;
    cout << "Double Wert: " << f << endl;

    cout << "Float Wert: " << std::setprecision(20) << e << endl;
    cout << "Double Wert: " << std::setprecision(20) << f << endl;

    // Aufgabe 6
    cout << "\nAufgabe 6\n" << endl;
    int g = 10;
    int h = 3;

    double quotient = (double)(g) / h;
    int rest = g % h;

    cout << "Quotient: " << quotient << endl;
    cout << "Rest: " << rest << endl;

    // Aufgabe 7
    cout << "\nAufgabe 7\n" << endl;
    char ch = 'A';
    cout << "ASCII - Wert von " << ch << " ist " << static_cast<int>(ch) << endl;

    // Aufgabe 8
    cout << "\nAufgabe 8\n" << endl;
    char ch1 = 'a';
    cout << "Summe von ch und ch1: " << ch + ch1 << endl;

    // Aufgabe 9:
    cout << "\nAufgabe 9\n" << endl;
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    cout << "Summe der ersten 100: " << sum << endl;

    // Aufgabe 10:
    cout << "\nAufgabe 10\n" << endl;
    int sum_odd = 0;
    for (int i = 1; i <= 100; ++i) {
        if (i % 2 == 1){
            sum_odd += i;
        }
        
    }
    cout << "Summe der Ungeraden: " << sum_odd << endl;

    return 0;
}
