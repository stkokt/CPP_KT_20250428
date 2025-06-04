#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

class media;

class customer{

    public:

    string name, sex, address, cID;
    bool loan;
    vector<media> loanMedia;

};

class media{

    string mediaID, author, titel, date, backAt;
    bool state;

};

class Bibliothek{
    public:
    vector<tuple<string, string, string, string, short, string, string>> medien{};
    vector<tuple<string, string, string, string, bool, vector<string>>> kunden{};

    void dialog(){
        char decision = '0';
        while (decision != 'x'){
            cout << "Was soll gemacht werden?" << endl;
            cout << "1 = Bearbeiten Medienkatalog\n"
                 << "2 = Suchen im Medienkatalog\n"
                 << "3 = Bearbeiten Kundenregister\n"
                 << "4 = Suchen im Kundenregister\n" << endl;
            cin >> decision;
        }


    }

};

int main(){

    Bibliothek bib;

   // Bücher
    bib.medien.push_back(make_tuple("978-3-16-148410-0","Stefan Zweig","Die Welt von Gestern","1942", 0b10001,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("978-3-423-12345-6", "Thomas Mann", "Der Zauberberg", "1924", 0b10000, "2025-06-15","AS25Q20002"));
    bib.medien.push_back(make_tuple("978-3-596-29490-1", "Hermann Hesse", "Siddhartha", "1922", 0b10001, "", "MM25Q20001"));
    bib.medien.push_back(make_tuple("978-3-442-73456-7", "Franz Kafka", "Der Prozess", "1925",  0b10000, "2025-06-10","PM25Q20003"));
    bib.medien.push_back(make_tuple("978-3-257-23456-8", "Friedrich Nietzsche", "Also sprach Zarathustra", "1883", 0b10000, "", "LW25Q20004"));
    bib.medien.push_back(make_tuple("978-3-15-009999-9", "Bertolt Brecht", "Die Dreigroschenoper", "1928", 0b10000, "2025-06-20", "LR25Q20010"));
    bib.medien.push_back(make_tuple("978-3-458-34567-8", "Theodor Fontane", "Effi Briest", "1895", 0b10001,"", "TB25Q20005"));
    bib.medien.push_back(make_tuple("978-3-463-45678-9", "Johann Wolfgang von Goethe", "Faust", "1808", 0b10001,"", "SS25Q20006"));
    bib.medien.push_back(make_tuple("978-3-426-56789-0", "Friedrich Schiller", "Die Räuber", "1781", 0b10000, "2025-06-05", "LR25Q20010"));
    bib.medien.push_back(make_tuple("978-3-499-67890-1", "E.T.A. Hoffmann", "Der Sandmann", "1816", 0b10001,"", "DW25Q20009"));
    
    // Zeitschriften
    bib.medien.push_back(make_tuple("977-1234-56789-0", "Verschiedene", "Der Spiegel", "01/2023", 0b01001,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("977-2345-67890-1", "Verschiedene", "National Geographic", "03/2022", 0b01001,"2025-06-12", "AS25Q20002"));
    bib.medien.push_back(make_tuple("977-3456-78901-2", "Verschiedene", "Focus", "05/2023", 0b01001,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("977-4567-89012-3", "Verschiedene", "Stern", "02/2022", 0b01000,"2025-06-18","PM25Q20003"));
    bib.medien.push_back(make_tuple("977-5678-90123-4", "Verschiedene", "Geo", "07/2023", 0b01001,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("977-6789-01234-5", "Verschiedene", "Zeit Wissen", "04/2022", 0b01001,"", "TB25Q20005"));
    bib.medien.push_back(make_tuple("977-7890-12345-6", "Verschiedene", "Spektrum der Wissenschaft", "08/2023", 0b01000,"2025-06-22", "LR25Q20010"));
    bib.medien.push_back(make_tuple("977-8901-23456-7", "Verschiedene", "PM", "12/2022", 0b01001,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("977-9012-34567-8", "Verschiedene", "Mare", "10/2023", 0b01001,"", "DW25Q20009"));
    bib.medien.push_back(make_tuple("977-0123-45678-9", "Verschiedene", "Brigitte", "11/2022", 0b01000,"2025-06-25", "LR25Q20010"));
    
    // CDs
    bib.medien.push_back(make_tuple("5012345678901", "Beethoven", "Symphonien", "2020", 0b00101,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("5023456789012", "Mozart", "Klavierkonzerte", "2019", 0b00100, "2025-06-14", "AS25Q20002"));
    bib.medien.push_back(make_tuple("5034567890123", "Bach", "Brandenburgische Konzerte", "2021", 0b00101,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("5045678901234", "Brahms", "Ungarische Tänze", "2020", 0b00100, "2025-06-16", "PM25Q20003"));
    bib.medien.push_back(make_tuple("5056789012345", "Schubert", "Winterreise", "2022", 0b00101,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("5067890123456", "Chopin", "Nocturnes", "2019", 0b00101,"", "TB25Q20005"));
    bib.medien.push_back(make_tuple("5078901234567", "Tchaikovsky", "Schwanensee", "2021", 0b00100, "2025-06-19", "LR25Q20010"));
    bib.medien.push_back(make_tuple("5089012345678", "Vivaldi", "Die vier Jahreszeiten", "2020", 0b00101,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("5090123456789", "Handel", "Messiah", "2022", 0b00101,"", "JH25Q20008"));
    bib.medien.push_back(make_tuple("5001234567890", "Haydn", "Die Schöpfung", "2019", 0b00100, "2025-06-21", "LR25Q20010"));
    
    // DVDs
    bib.medien.push_back(make_tuple("4001234567890", "Christopher Nolan", "Inception", "2010", 0b00011,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("4002345678901", "Quentin Tarantino", "Pulp Fiction", "1994", 0b00010,"2025-06-13", "MM25Q20001"));
    bib.medien.push_back(make_tuple("4003456789012", "Stanley Kubrick", "2001: Odyssee im Weltraum", "1968", 0b00011,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("4004567890123", "Martin Scorsese", "The Departed", "2006", 0b00010,"2025-06-17", "LW25Q20004"));
    bib.medien.push_back(make_tuple("4005678901234", "Francis Ford Coppola", "Der Pate", "1972", 0b00011,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("4006789012345", "Steven Spielberg", "Schindlers Liste", "1993", 0b00011,"", "SS25Q20006"));
    bib.medien.push_back(make_tuple("4007890123456", "Ridley Scott", "Blade Runner", "1982", 0b00010, "2025-06-23", "LR25Q20010"));
    bib.medien.push_back(make_tuple("4008901234567", "Alfred Hitchcock", "Psycho", "1960", 0b00011,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("4009012345678", "James Cameron", "Titanic", "1997", 0b00011,"", "LR25Q20010"));
    bib.medien.push_back(make_tuple("4010123456789", "Peter Jackson", "Der Herr der Ringe: Die Rückkehr des Königs", "2003", 0b00011,"2025-06-24", "JH25Q20008"));

    // Kunden
    bib.kunden.push_back(make_tuple("Max Mustermann", "Herr", "Musterstraße 1, 10115 Berlin", "MM25Q20001", true, vector<string>{"978-3-423-12345-6", "977-2345-67890-1", "5023456789012"}));
    bib.kunden.push_back(make_tuple("Anna Schmidt", "Frau", "Hauptstraße 42, 80331 München", "AS25Q20002", true, vector<string>{"978-3-596-29490-1", "4002345678901"}));
    bib.kunden.push_back(make_tuple("Peter Müller", "Herr", "Bahnhofstraße 7, 20095 Hamburg", "PM25Q20003", false, vector<string>{}));
    bib.kunden.push_back(make_tuple("Lisa Wagner", "Frau", "Gartenweg 15, 60325 Frankfurt", "LW25Q20004", true, vector<string>{"978-3-442-73456-7", "977-4567-89012-3", "5045678901234"}));
    bib.kunden.push_back(make_tuple("Thomas Bauer", "Herr", "Waldstraße 23, 50667 Köln", "TB25Q20005", true, vector<string>{"978-3-257-23456-8", "4004567890123"}));
    bib.kunden.push_back(make_tuple("Sarah Schulz", "Frau", "Seeufer 8, 81379 München", "SS25Q20006", false, vector<string>{}));
    bib.kunden.push_back(make_tuple("Michael Becker", "Herr", "Bergweg 11, 70173 Stuttgart", "MB25Q20007", true, vector<string>{"978-3-458-34567-8", "977-6789-01234-5", "5067890123456"}));
    bib.kunden.push_back(make_tuple("Julia Hoffmann", "Frau", "Feldstraße 3, 30159 Hannover", "JH25Q20008", true, vector<string>{"978-3-463-45678-9", "4006789012345"}));
    bib.kunden.push_back(make_tuple("David Weber", "Herr", "Flussweg 19, 40210 Düsseldorf", "DW25Q20009", false, vector<string>{}));
    bib.kunden.push_back(make_tuple("Laura Richter", "Frau", "Hügelstraße 5, 69115 Heidelberg", "LR25Q20010", true, vector<string>{"978-3-499-67890-1", "977-9012-34567-8", "5090123456789", "4010123456789"}));


    
    return 0;
}
