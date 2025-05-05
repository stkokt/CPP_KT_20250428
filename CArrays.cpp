// C- Arrays

// Aufgabe 1: Initialisiere ein Array mit 5 
//            ganzen Zahlen und gib die Elemente des Arrays aus.

// Aufgabe 2: Berechne die Summe der Elemente eines 
//            Arrays mit 10 ganzen Zahlen.

// Aufgabe 3: Suche nach einem bestimmten Element in 
//            einem Array und gib dessen Index zurück. Wenn das Element 
//            nicht gefunden wird, gib -1 zurück.

// Aufgabe 4: Kehre die Reihenfolge der Elemente in einem Array um.

// Aufgabe 5: Finde das größte und das 
//            kleinste Element in einem Array.

// Aufgabe 6: Berechne den Durchschnitt der Elemente eines Arrays.

// Aufgabe 7: Verschiebe die Elemente eines Arrays 
//            um eine Position nach links.

// Aufgabe 8: Entferne Duplikate aus einem Array.


// Aufgabe 9: Führe zwei sortierte Arrays zu 
//            einem einzigen sortierten Array zusammen.

// Aufgabe 10: Bestimme die Größe eines Arrays
//             (also die Anzahl der Elemente) dynamisch.

#include <iostream>
using namespace std;

int main() {

    cout<<"\nAufgabe 1\n\n";

    int arr1[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    for (int i : arr1){
        cout << i << " ";
    }

    cout<<"\nAufgabe 2\n\n";

    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum2 = 0;
    for (int i = 0; i < 10; i++) {
        sum2 += arr2[i];
    }
    cout << "Summe: " << sum2 << endl;

    cout<<"\nAufgabe 3\n\n";

    int arr3[7] = {10, 20, 30, 40, 50, 60, 70};
    int target = 40;
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (arr3[i] == target) {
            index = i;
            break;
        }
    }
    cout << "Index von " << target << ": " << index << endl;

    cout<<"\nAufgabe 4\n\n";

    int arr4[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    for (int i = 0; i < n / 2; i++) {
        int temp = arr4[i];
        arr4[i] = arr4[n - i - 1];
        arr4[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << arr4[i] << " ";
    }

    cout<<"\nAufgabe 5\n\n";

    int arr5[8] = {12, 45, 78, 23, 56, 89, 34, 67};
    int max = arr5[0];
    int min = arr5[0];
    for (int i = 1; i < 8; i++) {
        if (arr5[i] > max) {
            max = arr5[i];
        }
        if (arr5[i] < min) {
            min = arr5[i];
        }
    };
    cout << "Größtes Element: " << max << endl;
    cout << "Kleinstes Element: " << min << endl;

    cout<<"\nAufgabe 6\n\n";

    int arr6[5] = {10, 20, 30, 40, 50};
    int sum6 = 0;
    for (int i = 0; i < 5; i++) {
        sum6 += arr6[i];
    }
    double avg = static_cast<double>(sum6) / 5; // (double)sum6
    cout << "Durchschnitt: " << avg << endl;

    cout<<"\nAufgabe 7\n\n";

    int arr7[6] = {1, 2, 3, 4, 5, 6};
    int n7 = 6;
    int first = arr7[0];
    for (int i = 0; i < n7 - 1; i++) {
        arr7[i] = arr7[i + 1];
    }
    arr7[n7 - 1] = first;
    for (int i = 0; i < n7; i++) {
        cout << arr7[i] << " ";
    }    

    cout<<"\nAufgabe 8\n\n";

    int arr8[10] = {1, 2, 2, 3, 4, 4, 5, 6, 7, 7};
    int n8 = 10;
    for (int i = 0; i < n8; i++) {
        for (int j = i + 1; j < n8;) {
            if (arr8[i] == arr8[j]) {
                for (int k = j; k < n8 - 1; k++) {
                    arr8[k] = arr8[k + 1];
                }
                n8--;
            } else {
                j++;
            }
        }
    }
    for (int i = 0; i < n8; i++) {
        cout << arr8[i] << " ";
    }

    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        cout << arr8[i] << " ";
    }

    cout<<"\nAufgabe 9\n\n";

    int arr9_1[5] = {1, 3, 5, 7, 9};
    int arr9_2[5] = {2, 4, 6, 8, 10};
    int merged[10];
    int i = 0, j = 0, k = 0;

    while (i < 5 && j < 5) {
        if (arr9_1[i] < arr9_2[j]) {
            merged[k++] = arr9_1[i++];
            cout << "k ist: " << k << " i ist: " << i << endl;
        } else {
            merged[k++] = arr9_2[j++];
            cout << "k ist: " << k << " j ist: " << j << endl;
        }
    }

    while (i < 5) {
        merged[k++] = arr9_1[i++];
    }

    while (j < 5) {
        merged[k++] = arr9_2[j++];
    }

    for (int l = 0; l < 10; l++) {
        cout << merged[l] << " ";
    }

    cout<<"\nAufgabe 10\n\n";

    int arr10[] = { 1, 2, 3, 4, 5, 6, 7 };

    int size = sizeof(arr10) / sizeof(arr10[0]);

    cout << "Die Größe des Arrays ist: " << sizeof(arr10) << endl;
    cout << "Die Größe des ersten Elements ist: " << sizeof(arr10[0]) << endl;
    cout << "Die Größe des Arrays ist: " << size << endl;
 

    return 0;

}
