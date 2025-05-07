/*
Aufgabe 1: Ermittle die Länge des Strings.

Aufgabe 2: Ermittle die Anzahl der Buchstaben.

Aufgabe 3: Ermittle die Anzahl der Sätze.
           (Unterscheidungsmerkmal: Punkt)

Aufgabe 4: Ermittle die Anzahl der Worte.

Aufgabe 5: Gebe den String über einen Iterator aus.

Aufgabe 6. Gebe den String rückwärts aus, ohne ihn zu verändern.

Aufgabe 7: Ermittle die Anzahl des Worts "Lorem" unabhängig
           von Groß- und Kleinschreibweise.

Aufgabe 8: Ersetze das Wort "Lorem"/"lorem" mit seiner Umkehrung.
           (also "Merol"/"merol")

Aufgabe 9: Entferne das Wort "et" und setze die Kapazität des 
           Strings auf seine neue Länge.

Aufgabe 10: Füge am Index 10 des Strings die Zeichenkette '10' ein.

*/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){

    string lorem1 = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.";

    // 100 Wörter
    string lorem = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr," 
                   "sed diam nonumy eirmod tempor invidunt ut labore et dolore"
                   "magna aliquyam erat, sed diam voluptua... At vero eos et" 
                   "accusam et justo duo dolores et ea rebum. Stet clita kasd" 
                   "gubergren, no sea takimata sanctus est lorem ipsum dolor" 
                   "sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing" 
                   "elitr, sed diam nonumy eirmod tempor invidunt ut labore et" 
                   "dolore magna aliquyam erat, sed diam voluptua. At vero eos" 
                   "et accusam et justo duo dolores et ea rebum. Stet clita kasd" 
                   "gubergren, no sea takimata sanctus est lorem ipsum dolor sit amet.";

    //cout << lorem << endl;

    cout << "\nAufgabe 1" << endl;
    cout << "Länge des Strings: " << lorem.size() << endl;
    
    cout << "\nAufgabe 2" << endl;
    int charsOnly = 0;
    for (auto i : lorem ){
        if(((i >= 65 && i <= 90) || (i >= 97 && i <= 122))){
            charsOnly++;
        }
    }
    cout << "Anzahl der Buchstaben: " << charsOnly << endl;

    cout << "\nAufgabe 3" << endl;
    int dots = 0;
    for(int i = 0; i < lorem.size(); i++){
        if (lorem[i] == '.' && lorem[i-1] != '.'){
            dots++;
        }
    }
    cout << "Anzahl der Sätze: " << dots << endl;

    cout << "\nAufgabe 4" << endl;
    istringstream iss(lorem1);
    string wort;
    int wordCount = 0;

    // Den String in Wörter aufteilen und zählen
    while (iss >> wort) {
        if(isalnum(wort[0])){
        wordCount++;}
    }

    cout << "Anzahl der Worte: " << wordCount << endl;

    cout << "\nAufgabe 5" << endl;
    for(auto it = lorem.begin(); it != lorem.end(); it++){
        cout << *it << "";
    }

    cout << "\n\nAufgabe 6" << endl;
    for(auto it = lorem.rbegin(); it != lorem.rend(); it++){
        cout << *it << "";
    }

    cout << "\n\nAufgabe 7" << endl;
    int cntLorem = 0;
    istringstream iss1(lorem);
    string word="";
    while(iss1 >> word){
        if (word == "lorem" || word == "Lorem")
        cntLorem++;
    }

    cout << "Anzahl des Worts 'Lorem': " << cntLorem << endl;
    
    cout << "\nAufgabe 8" << endl;
    string wordToReplace = "lorem";
    string reversedWord = "merol";

    size_t pos1 = 0;
    while ((pos1 = lorem.find(wordToReplace, pos1)) != string::npos) {
        // Überprüfen, ob "lorem" ein eigenständiges Wort ist
        bool isWord = ((pos1 == 0 || !isalnum(lorem[pos1 - 1])) &&
                       (pos1 + wordToReplace.length() == lorem.length() || !isalnum(lorem[pos1 + wordToReplace.length()])));
        if (isWord) {
            // Ersetzen im ursprünglichen Text
            lorem.replace(pos1, wordToReplace.length(), reversedWord);
            // Pos um die Länge des ersetzten Wortes erhöhen
            pos1 += reversedWord.length();
        } else {
            // Pos um die Länge des gefundenen Wortes erhöhen
            pos1 += wordToReplace.length();
        }
    }

    // Für "Lorem" (Großbuchstabe am Anfang)
    wordToReplace = "Lorem";
    reversedWord = "Merol";
    pos1 = 0;
    while ((pos1 = lorem.find(wordToReplace, pos1)) != string::npos) {
        // Überprüfen, ob "Lorem" ein eigenständiges Wort ist
        bool isWord = ((pos1 == 0 || !isalnum(lorem[pos1 - 1])) &&
                       (pos1 + wordToReplace.length() == lorem.length() || !isalnum(lorem[pos1 + wordToReplace.length()])));
        if (isWord) {
            // Ersetzen im ursprünglichen Text
            lorem.replace(pos1, wordToReplace.length(), reversedWord);
            // Pos um die Länge des ersetzten Wortes erhöhen
            pos1 += reversedWord.length();
        } else {
            // Pos um die Länge des gefundenen Wortes erhöhen
            pos1 += wordToReplace.length();
        }
    }

    cout << "Text nach Ersetzung von 'Lorem'/'lorem' mit 'Merol'/'merol': " << lorem << endl;

    cout << "\nAufgabe 9" << endl;

    string wordToRemove = "et";
    size_t pos = lorem.find(wordToRemove);

    // Alle Vorkommen von "et" entfernen
    while (pos != string::npos) {
        // Überprüfen, ob "et" ein eigenständiges Wort ist
        bool isWord1 = (pos == 0 || !isalnum(lorem[pos - 1])) && (pos + wordToRemove.length() == lorem.length() || !isalnum(lorem[pos + wordToRemove.length()]));
        if (isWord1) {
            lorem.erase(pos, wordToRemove.length());
        } else {
            pos += wordToRemove.length(); // Weiter zum nächsten Vorkommen, wenn es kein eigenständiges Wort ist
        }
        pos = lorem.find(wordToRemove, pos);
    }

    // Kapazität des Strings auf seine neue Länge setzen
    cout << "Kapazität des Strings vor Shrink: " << lorem.capacity() << endl;
    lorem.shrink_to_fit();

    cout << "Text nach Entfernung von 'et': " << lorem << endl;
    cout << "Neue Länge des Strings: " << lorem.length() << endl;
    cout << "Kapazität des Strings: " << lorem.capacity() << endl;

    cout << "\nAufgabe 10" << endl;

    lorem.insert(10,"10"s);
    cout << lorem << endl;

    return 0;
}