#include <iostream>
#include <bitset>
using namespace std;

// Aufgabe 1: Addition negativer Zahlen
// https://www.youtube.com/watch?v=a57Cg_mwwQ0

/*
8 + (-7)                 1000
1000    ~7 1000     ~7+1 1001   0001 = 1

12 + (-3)                1100
1100    ~3 1100     ~3+1 1101   1001 = 9

15 + (-5)                1111
1111    ~5 1010     ~5+1 1011   1010 = 10

9 + (-4)                 1001
1001    ~4 1011     ~4+1 1100   0101 = 5

13 + (-8)                1101
1101    ~8 0111     ~8+1 1000   0101 = 5

11 + (-9)                1011
1011    ~9 0110     ~9+1 0111   0010 = 2

10 + (-2)                1010
1010    ~2 1101     ~2+1 1110   1000 = 8

7 + (-6)                 0111
0111    ~6 1001     ~6+1 1010   0001 = 1

15 + (-10)                1111
1111    ~10 0101    ~10+1 0110  0101 = 5

11 + (-4)                 1011
1011    ~4 1011     ~4+1  1100  0111 = 7

12 + (-6)                 1100
1100    ~6 1001     ~6+1  1010  0110 = 6

13 + (-9)                 1101
1101    ~9 0110     ~9+1  0111  0100 = 4

14 + (-7)                 1110
1110    ~7 1000     ~7+1  1001  0111 = 7

*/


// Aufgabe 2: Zähle die gesetzten Bits einer Zahl.

int countSetBits(int n) {
    int count = 0;
    // Solange n nicht null ist, überprüfen wir das niedrigste Bit
    while (n) {
        // Wenn das niedrigste Bit gesetzt ist, erhöhen wir den Zähler
        count += n & 1; // 0001
        // Verschieben wir n um ein Bit nach rechts
        n >>= 1;
    }
    return count;
}

// Aufgabe 3: Berechne ausgehend von einer Zahl die nächsthöhere 2er- Potenz.

int nextPowerOf2(int n) {
    n--;
    // Setzen aller Bits rechts des höchsten gesetzten Bits
    // 6                                = 0110
    // 6-1                              = 0101
    // 5 |= 5 >> 1 = 0101 | 0010 = 0111 = 7
    // 7+1                              = 8
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

// Aufgabe 4: Setze ein bitset<32> mit einer Zahl und kehre es um (reverse).

bitset<32> reverseBits(int n) {
    bitset<32> b(n); // Erstellen eines bitset mit 32 Bits
    // Tauschen der Bits von beiden Enden zur Mitte hin
    for (int i = 0; i < 16; ++i) {
        bool temp = b[i];
        b[i] = b[31 - i];
        b[31 - i] = temp;
        // Beispiel an 8 Bit
        // Ursprung: 1001 1110
        // 1. 0001 1111
        // 2. 0101 1101
        // 3. 0111 1001
        // 4. 0111 1001 bleibt gleich, weil nur 2 1en getauscht werden.
    }
    return b; // Konvertieren des bitset zurück zu einem unsigned long
}

// Aufgabe 5: Zähle die führenden Nullen bei einer Zahl in der Binärdarstellung.

int countLeadingZeros(int n) {
    int count = 0;
    // Solange das höchste Bit nicht gesetzt ist, erhöhen wir den Zähler
    while (!(n & (1 << (31 - count)))) {
        count++;
    }
    // Beipiel an 1 auf 4 Bit
    // (1 << (3 - count))   n&(1 << (3 - count))   !(n & (1 << (3 - count)))    count
    // 0001 -> 1000         0001 & 1000   -> 0000           True                  1
    // 0001 -> 0100         0100 & 0001   -> 0000           True                  2
    // 0001 -> 0010         0010 & 0001   -> 0000           True                  3
    // 0001 -> 0001         0001 & 0001   -> 0001           False                 3
    return count;
}

// Aufgabe 6: Zähle die nachfolgenden Nullen bei einer Zahl in der Binärdarstellung.

int countTrailingZeros(int n) {
    int count = 0;
    // Solange das niedrigste Bit nicht gesetzt ist, erhöhen wir den Zähler
    while (!(n & 1)) {
        count++;
        n >>= 1;
    }
    // Am Beispiel 4:
    // 0100 & 0001 -> False -> count = 1
    // 0010 & 0001 -> False -> count = 2
    // 0001 & 0001 -> True  -> count = 2
    return count;
}

// Aufgabe 7: Zähle die gesetzten Bits in einem bestimmten Bereich.
// Also z.B. Zahl:23 , Bereich zwischen 1 und 4: 00010111 -> 3

int countSetBitsInRange(int n, int start, int end) {
    int count = 0;
    // Überprüfen der Bits im Bereich von start bis end
    for (int i = start; i <= end; ++i) {
        // Wenn das Bit gesetzt ist, erhöhen wir den Zähler
        if (n & (1 << i)) {
            count++;
        }
    }
    // Beispiel 29:
    // 29                           = 11101
    // betrachteter Bereich 3 bis 0:   1101
    // count = 3
    return count;
}

int main() {
    // Aufgabe 2
    cout << "Aufgabe 2\n";
    cout << "Anzahl gesetzter Bits: " << countSetBits(5) << endl;
    // Aufgabe 3
    cout << "Aufgabe 3\n";
    cout << "Nächste Zweierpotenz: " << nextPowerOf2(6) << endl;
    // Aufgabe 4
    cout << "Aufgabe 4\n";                  // 0111
    cout << "Umgekehrte Bitreihenfolge: " << reverseBits(7) << endl;
    // Aufgabe 5
    cout << "Aufgabe 5\n";
    cout << "Anzahl führender Nullen: " << countLeadingZeros(1) << endl;
    // Aufgabe 6
    cout << "Aufgabe 6\n";
    cout << "Anzahl nachfolgender Nullen: " << countTrailingZeros(8) << endl;
    // Aufgabe 7
    cout << "Aufgabe 7\n";
    cout << "Anzahl Bits in Range: " << countSetBitsInRange(23, 1, 4);
    return 0;
}
