// Aufgabe 1: Wo liegen die Daten eines STL- Containers (Stack oder Heap)?
//            Versuche das im Code zu zeigen und finde eine mögliche 
//            Begründung dafür. Wo liegt der Unterschied zu einem C- Array?

// Aufgabe 2: Implementiere einen leeren Vector von Integern. Fülle ihn 
//            anschließend mit 100 Werten. Zeige, wie sich die Kapazität
//            des Vectors und seine Lage im Arbeitsspeicher ändert. Wie wirkt
//            sich diese Veränderung auf die Performance aus und wie erzielt 
//            man bessere Performance- Ergebnisse?


// Aufgabe 3: Vergleiche die Methoden von Vector, Deque und einfach verketteter 
//            Liste. Wann würdest du welchen Container bevorzugen?


// Aufgabe 4: Erstelle eine Preisliste für drei Artikel je als 'pair', 
//            fülle damit einen Vector und gebe die Preisliste anschließend aus.


// Aufgabe 5: Erweitere die Preisliste um eine Anzahl pro Artikel, indem du ein
//            Tupel nutzt. Gebe diese Liste aus.


// Aufgabe 6: Implementiere die Preisliste als Map und als Multimap und gebe sie aus.



#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <tuple>
#include <map>
#include <deque>
#include <forward_list>


using namespace std;

int main(){

    cout << "\nAufgabe 1\n" << endl;

    vector<int> v{};
    cout << "Hier liegt der Zeiger: " << (int)&v << endl;
    // v.reserve(100); // Einkommentieren für Performance- Gewinn
    cout << "\nAufgabe 2\n" << endl;

    for (int i = 1; i < 101; i++){

        v.push_back(i);
        cout << "Fassungsvermögen: " << v.capacity() << " RAM- Adresse: " << (int)&v[0] << endl;

    }

    cout << "\nAufgabe 3\n" << endl;

    // Vector, wenn schnell über Indizes zugegriffen werden soll.
    // Beispielsweise, wenn ein Spieler über eine angezeigte Liste
    // schnell auf Spiele- Missionen zugreifen möchte.

    std::vector<string> spielmissionen;
    spielmissionen.push_back("Ballermap");
    spielmissionen.push_back("Autorennen");
    spielmissionen.push_back("Bankraub");

    // Deque, wenn schnelle Zufügung oder Löschung an beiden Enden möglich sein soll.

    deque<string> warteschlange_beim_arzt;
    warteschlange_beim_arzt.push_back("GK-Patient 1");
    warteschlange_beim_arzt.push_back("GK-Patient 2");
    warteschlange_beim_arzt.push_front("PK-Patient");
    warteschlange_beim_arzt.pop_front(); // Bediene erst den Privatkassen- Kunden
    warteschlange_beim_arzt.pop_back(); // GK-Patient 2 haut ab, dauert ihm zu lange...

    // Einfach verkettete Liste, wenn Zugriff über Indizes unnötig, aber Zugriff auf
    // ein Ende des Containers schnell gehen soll. Z.B. TODO- Liste.

    forward_list<string> aufgaben;
    aufgaben.push_front("Aufräumen");
    aufgaben.push_front("Abwaschen");
    aufgaben.push_front("Einkaufen");
    aufgaben.pop_front(); // Erledige die Aufgabe "Einkaufen" und entferne sie.
    aufgaben.pop_front(); // Erledige die Aufgabe "Abwaschen" und entferne sie.
    aufgaben.pop_front(); // Erledige die Aufgabe "Aufräumen" und entferne sie.

    cout << "\nAufgabe 4\n" << endl;

    auto socken = make_pair("Socken", 3.5);
    auto schuhe = make_pair("Schuhe", 30.0);
    auto hose = make_pair("Hose", 12.5);
    cout << typeid(socken).name() << endl;
    vector<pair<std::string,float>> preisliste{};
    preisliste.push_back(socken);
    preisliste.push_back(schuhe);
    preisliste.push_back(hose);
    for (auto i : preisliste){
        cout << i.first << ": " << i.second << endl;
    }

    cout << "\nAufgabe 5\n" << endl;
    auto socken_n = make_tuple("Socken", 3.5, 5);
    auto schuhe_n = make_tuple("Schuhe", 30.0, 4);
    auto hose_n = make_tuple("Hose", 12.5, 3);

    vector<tuple<std::string,float, int>> preisliste_n{};

    preisliste_n.push_back(socken_n);
    preisliste_n.push_back(schuhe_n);
    preisliste_n.push_back(hose_n);

    for (auto i : preisliste_n){
        cout << get<2>(i) << " Stück " << get<0>(i) << " für je " << get<1>(i) << endl;
    }

    cout << "\nAufgabe 6\n" << endl;
    cout << "\nmit Map\n" << endl;

    map<std::string, float> preisliste_m{{"Socken", 3.5}, {"Schuhe", 30.0}, {"Hose", 12.5}};
    preisliste_m.insert({"Hemd", 5.0});

    for (auto i : preisliste_m){
        cout << "Artikel: " << i.first << ", Preis: " << i.second << endl;
    }

    cout << "\nmit Multimap\n" << endl;

    multimap<std::string, float> preisliste_mm{{"Socken", 3.5}, {"Schuhe", 30.0}, {"Hose", 12.5}};
    preisliste_mm.insert({"Socken", 5.0});

    for (auto i : preisliste_mm){
        cout << "Artikel: " << i.first << ", Preis: " << i.second << endl;
    }


    return 0;
}