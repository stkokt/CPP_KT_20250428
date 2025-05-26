// Aufgabe 1: Schreibe eine Funktion countCalls(), 
//            die bei jedem Aufruf eine statische Variable 
//            um 1 hochzählt und rufe diese in jeder 
//            weiteren Funktion auf. 

// Aufgabe 2: Schreibe eine Funktion, die in einem String 
//            die Vokale zählt. String darf nicht verändert werden.

// Aufgabe 3: Schreibe eine inline-Funktion square(), 
//            die das Quadrat einer Zahl berechnet.

// Aufgabe 4: Schreibe eine eine Funktion subtract() 
//            mit Defaultparametern, die bis zu vier 
//            int-Werte subtrahieren kann.

// Aufgabe 5: Schreibe eine überladene Funktion multiply(), 
//            die zwei int-Werte, zwei double-Werte oder 
//            drei int-Werte multiplizieren kann.

// Aufgabe 6: Schreibe eine Funktion multiply_list(), die eine 
//            beliebige Anzahl von int-Werten multipliziert.
//            Nutze dazu eine Initializer- List und 'accumulate'.

// Aufgabe 7: Schreibe eine Funktion mit Rückgabetyp bool, 
//            die als Argument einen Vektor von Floats übernimmt.
//            Von diesen Werten soll das Reziproke gebildet werden (z.B. 8 -> 1/8)
//            Ist der Wert 0, soll er übersprungen werden und die Rückgabe auf 
//            'False' wechseln.

// Aufgabe 8:
/*
Implementiere den Luhn-Algorithmus zur Überprüfung der 
Gültigkeit einer Kreditkartennummer. 
Der Algorithmus funktioniert wie folgt:

Beginne mit der rechten Ziffer und bewege dich nach links. 
Verdopple die Wertigkeit jeder zweiten Ziffer.
Falls das Verdoppeln einer Ziffer zu einer Zahl größer als 9 führt, 
subtrahiere 9 von dieser Zahl.
Addiere alle Ziffern zusammen.
Wenn die Summe durch 10 teilbar ist, ist die Kreditkartennummer gültig.


Beispiel:
Für die Kreditkartennummer 4532 0151 1283 0366:

Verdopple jede zweite Ziffer von rechts: 
4*2, 5, 3*2, 2, 0*2, 1, 5*2, 1, 1*2, 2, 8*2, 3, 0*2, 3, 6*2, 6

Ergebnis: 
8, 5, 6, 2, 0, 1, 10, 1, 2, 2, 16, 3, 0, 3, 12, 6

Subtrahiere 9 von den Zahlen größer als 9: 
8, 5, 6, 2, 0, 1, 1, 1, 2, 2, 7, 3, 0, 3, 3, 6

Summiere alle Ziffern: 
8+5+6+2+0+1+1+1+2+2+7+3+0+3+3+6 = 50

Da 50 durch 10 teilbar ist, ist die Kreditkartennummer gültig.

*/

// Aufgabe 9:
/*
Eine ID soll erstellt werden. Sie soll die Form haben (exemplarisch)

1000-A12-0001-1

Regeln:

Der erste Zahlenblock soll Werte von 1000 - 9999 enthalten.
Wenn der Höchstwert überschritten ist, soll im nächsten Block 
der nächste Buchstabe im Alphabet gewählt werden und der Wert 
des ersten Blocks wieder auf 1000 gesetzt werden.

Die Zahlen im zweiten Block sollen von 01 - 99 gehen. 

Die Zahlen im dritten Block sollen von 0001 - 9999 gehen.
Wenn die 9999 überschritten wird, soll die letzte Ziffer der ID
um eins erhöht werden und der Block resettet werden.

Die letzte Ziffer der ID soll von 0 bis 9 gehen. Wird die 9
überschritten, beginnt die Zählung von vorn.

*/

// Aufgabe 10: Lagere all deine Funktionen in eine eigene 
//             Header- Datei aus, binde diese in deine 
//             'main' ein und rufe die Funktionen von dort auf. 

// # include <iostream>
// # include <vector>
// # include <string>
// # include <numeric>
# include "myFunc.h"

using namespace std;
/*
// Aufgabe 1
void countCalls() {
    static int count{ 0 };
    cout << "Anzahl der Aufrufe: " << ++count << endl;
}

// Aufgabe 2
int cntVokale(const std::string &str) {
    countCalls();
    int count = 0;
    for (char ch : str) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Aufgabe 3
inline int square(const int &x) {
    countCalls();
    return x * x;
}

// Aufgabe 4
int subtract(const int &a = 0, const int &b = 0, const int &c = 0, const int &d = 0) {
    countCalls();
    return a - b - c - d;
}

// Aufgabe 5
int multiply(const int &x, const int &y) {
    countCalls();
    cout << "2 x int :";
    return x * y;
}

double multiply(const double &x, const double &y) {
    countCalls();
    cout << "2 x double :";
    return x * y;
}

int multiply(const int &x, const int &y, const int &z) {
    countCalls();
    cout << "3 x int :";
    return x * y * z;
}

// Aufgabe 6
int multiply_list(const initializer_list<int> &x) {
    countCalls();
    return accumulate(begin(x), end(x), 1, multiplies<int>());
}

// Aufgabe 7
bool reziproke(std::vector<float>& vec){
    countCalls();
    bool all_done = true;
    for (auto it = vec.begin(); it != vec.end(); it++){
        if (*it > 0){
            *it = double(1)/(*it);
        }
        else{
            all_done = false;
            continue;
        }
    }

    return all_done;
};

// Aufgabe 8
bool luhnAlgorithm(const std::string& cardNumber) {
    countCalls();
    int sum = 0;
    bool alternate = false;

    // Iterate over the digits in reverse order
    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        int n = cardNumber[i] - '0';

        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }

        sum += n;
        alternate = !alternate;
    }

    // If the total modulo 10 is zero, the number is valid
    return (sum % 10 == 0);
}

// Aufgabe 9
string ID(){
    countCalls();
    static int firstBlock = 9995;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static short letter = 0;
    static int secondBlock = 95;
    static int thirdBlock = 9995;
    static int fourthBlock = 0;

    if (firstBlock > 9999){
        firstBlock = 1000;
        letter++;
    }

    if(secondBlock > 99){
        secondBlock = 1;
    }

    if(thirdBlock > 9999){
        thirdBlock = 1;
        fourthBlock++;
    }

    string fstB = to_string(firstBlock);
    string sndB = secondBlock<10?'0'+to_string(secondBlock):to_string(secondBlock);
    string trdB = "";
    if (thirdBlock < 10){
        trdB = "000"+ to_string(thirdBlock);
    }
    else if(thirdBlock>9 && thirdBlock<100){
        trdB = "00"+ to_string(thirdBlock);
    } 
    else if(thirdBlock>99 && thirdBlock<1000){
        trdB = "0"+ to_string(thirdBlock);
    }
    else trdB = to_string(thirdBlock);

    string fthB = to_string(fourthBlock);

    firstBlock++;
    secondBlock++;
    thirdBlock++;

    return fstB + "-" + abc[letter] + sndB +"-"+ trdB + "-" + fthB;
}

*/
int main(){
    std::cout << "Aufgabe 2" << std::endl;
    std::string str = "Hello World";
    std::cout << "Anzahl der Vokale: " << cntVokale(str) << std::endl;

    std::cout << "Aufgabe 3" << std::endl;
    cout << square(10) << endl;

    std::cout << "Aufgabe 4" << std::endl;
    cout << subtract(10,3) << endl;

    std::cout << "Aufgabe 5" << std::endl;
    multiply(5 , 8);

    std::cout << "Aufgabe 6" << std::endl;
    cout << multiply_list({1,2,3,4,5}) << endl;

    std::cout << "Aufgabe 7" << std::endl;
    std::vector<float> rezip = {1,2,5,8,6,0,4,7};
    std::vector<float> rezip1 = {1,2,5,8,6,9,4,7};   
    bool result_reziproke = reziproke(rezip);
    bool result_reziproke1 = reziproke(rezip1);

    // Wegen 0 im Vector sollte hier 'Nein' rauskommen.
    std::cout << "Alle Elemente konnten reziproken Wert bilden: " << (result_reziproke?"Ja":"Nein") << std::endl;    

    // Ausgabe der reziproken Werte von rezip
    for (auto element : rezip){
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    // Hier sollte 'Ja' rauskommen
    std::cout << "Alle Elemente konnten reziproken Wert bilden: " << (result_reziproke1?"Ja":"Nein") << std::endl;    

    // Ausgabe der reziproken Werte von rezip1
    for (auto element : rezip1){
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Aufgabe 8" << std::endl;
    string cardNr = "4532015112830366";
    if(luhnAlgorithm(cardNr)){cout << "Karte gültig" << endl;}
    else cout << "Karte ungültig" << endl;

    std::cout << "Aufgabe 9" << std::endl;
    for(int i = 0; i < 10; i++){cout << ID() << endl;}

    return 0;

}
