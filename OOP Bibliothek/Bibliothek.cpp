#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <sstream>
#include <typeinfo>

# define BUCH 0b10000
# define JOURNAL 0b01000
# define CD 0b00100
# define DVD 0b00010
# define AVAIL 0b00001

using namespace std;

class media{

    public:

    string mediaID, author, titel, date, backAt, lastUser;
    short state;

    media(string id, string a, 
        string t, string d, 
        short f, string b, 
        string u) :
        mediaID(id), author(a),
        titel(t), date(d), state(f),
        backAt(b), lastUser(u)
        {

    }

};

class customer{

    public:

    string name, sex, address, cID, loanMedia;
    bool loan;


    customer(string n, 
            string s, 
            string a, 
            string id, 
            bool l, string lm):
            name(n), sex(s), address(a),
            cID(id), loan(l), loanMedia(lm)
            {

            }

};

class Bibliothek{

    public:
    vector<media> med{};
    vector<customer> cust{};

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

    void addSingleMedia(media m){

        this -> med.push_back(m);
    }

    void addMedia(tuple<string, string, string, string, short, string, string> m){

        this -> med.push_back(media(get<0>(m), get<1>(m),
                            get<2>(m), get<3>(m),
                            get<4>(m), get<5>(m), get<6>(m)));
    }

    void addMediaFromVector(vector<tuple<string, string, string, string, short, string, string>> vm){
        
        for( auto m : vm){
            this -> addMedia(m);
        }
    }

    void addMediaFromCSV(){

    std::ifstream inputFile("media1.csv");
    
    if(inputFile.is_open()){

        std::string line;

        // Kopfzeile überspringen
        if (std::getline(inputFile, line)) {
            //cout << "Vorhandene Medien:\n" << endl;
        }
        while(std::getline(inputFile, line)){
            std::stringstream ss(line);
            std::string field;
            std::vector<std::string> fields;
            while(std::getline(ss, field, ';')){
                fields.push_back(field);
            }
            // Test über Ausgabe
            // for(const auto& f : fields){
            //     std::cout << f << " ";
            // }
            // std::cout << std::endl;

            if (fields.size() >= 7) {
                // Create a tuple with the fields
                auto aTuple = std::make_tuple(
                    fields[0], // string
                    fields[1], // string
                    fields[2], // string
                    fields[3], // string
                    short(stoi(fields[4])), // short
                    fields[5], // string
                    fields[6]  // string
                );

                this -> addMedia(aTuple);
            }
            

        }
        inputFile.close();
    }
    else {
        std::cerr << "Fehler beim Öffnen der Datei zum Lesen.\n";
    }

    }

    string detectMediaType(media m){
        if(m.state & BUCH){
            return "Buch";
        }
        else if(m.state & JOURNAL){
            return "Zeitschrift";
        }
        else if(m.state & CD){
            return "CD";
        }
        else if(m.state & DVD){
            return "DVD";
        }
        else return "Konnte nicht ermittelt werden";
    }

    string detectMediaAvail(media m){
        if (m.state & AVAIL){
            return "Verfügbar";
        }
        else return "Nicht verfügbar";
    }

    void showMedia(media m){
        cout << "Medien ID: " << m.mediaID << endl;
        cout << "Autor: " << m.author << endl;
        cout << "Titel : " << m.titel << endl;
        cout << "Erschienen : " << m.date << endl;
        cout << "Medientyp : " << detectMediaType(m) << endl;
        cout << "Status : " << detectMediaAvail(m) << endl;
        cout << "Rückgabe am: " << m.backAt << endl;
        cout << "Letzter Nutzer: " << m.lastUser << endl;
        cout << "----------------------------------------" << endl;
        cout << endl;
    }

    void showAllMedia(){
        cout << "\nVorhandene Medien:\n" << endl;
        for (auto m : this -> med){
            this -> showMedia(m);
        }
    }

    void searchMedia(){
        string searchString;
        bool found = false;
        cout << "Suchbegriff eingeben: " << endl;
        cin >> searchString;
    // Durchsuche Medium nach dem Subegriff
        cout << "\nSuche nach: '" << searchString << "'\n" << endl;
        for(media m : this -> med){
            if ((m.mediaID.find(searchString)) != std::string::npos) {
                this -> showMedia(m);
                found = true;
            } 
            else if ((m.author.find(searchString)) != std::string::npos) {
                this -> showMedia(m);
                found = true;
            } 
            else if ((m.titel.find(searchString)) != std::string::npos) {
                this -> showMedia(m);
                found = true;
            }
        }
        
        if (!found){
            cout << "Suche nach '" << searchString << "' nicht erfolgreich" << endl;
        }
    }

    bool detectBool(string b){
        if (b=="true"){
            return true;
        }
        else return false;
    }

    void addCustomerFromCSV(){
        std::ifstream inputFile("customer.csv");
    
        if(inputFile.is_open()){

        std::string line;

        // Kopfzeile überspringen
        if (std::getline(inputFile, line)) {
            // Mach nichts
        }

        while(std::getline(inputFile, line)){
            std::stringstream ss(line);
            std::string field;
            std::vector<std::string> fields;
            while(std::getline(ss, field, ';')){
                fields.push_back(field);
            }
            // Test über Ausgabe
            // for(const auto& f : fields){
            //     std::cout << f << " ";
            // }
            // std::cout << std::endl;

            if (fields.size() >= 6) {
                // Create a tuple with the fields
                auto aTuple = std::make_tuple(
                    fields[0], // string
                    fields[1], // string
                    fields[2], // string
                    fields[3], // string
                    fields[4], // short
                    fields[5] // string
                );

                this -> cust.push_back(customer(fields[0],fields[1],fields[2],fields[3],detectBool(fields[4]),fields[5]));
            }
        }
        inputFile.close();
    }
    else {
        std::cerr << "Fehler beim Öffnen der Datei zum Lesen.\n";
    }
    }
};

int main(){

    // vector<tuple<string, string, string, string, short, string, string>> medien{};
    // vector<tuple<string, string, string, string, bool, vector<string>>> kunden{};

    Bibliothek bib;

    // Test media- Konstruktor
    // media b1("978-3-16-148410-0","Stefan Zweig","Die Welt von Gestern","1942", 0b10001,"", "LR25Q20010");
    // cout << b1.author << endl;
    // bib.addSingleMedia(b1);
    // cout << bib.med[0].state << endl;

   // Bücher
    // medien.push_back(make_tuple("978-3-16-148410-0","Stefan Zweig","Die Welt von Gestern","1942", 0b10001,"", "LR25Q20010"));
    // medien.push_back(make_tuple("978-3-423-12345-6", "Thomas Mann", "Der Zauberberg", "1924", 0b10000, "2025-06-15","AS25Q20002"));
    // medien.push_back(make_tuple("978-3-596-29490-1", "Hermann Hesse", "Siddhartha", "1922", 0b10001, "", "MM25Q20001"));
    // medien.push_back(make_tuple("978-3-442-73456-7", "Franz Kafka", "Der Prozess", "1925",  0b10000, "2025-06-10","PM25Q20003"));
    // medien.push_back(make_tuple("978-3-257-23456-8", "Friedrich Nietzsche", "Also sprach Zarathustra", "1883", 0b10000, "", "LW25Q20004"));
    // medien.push_back(make_tuple("978-3-15-009999-9", "Bertolt Brecht", "Die Dreigroschenoper", "1928", 0b10000, "2025-06-20", "LR25Q20010"));
    // medien.push_back(make_tuple("978-3-458-34567-8", "Theodor Fontane", "Effi Briest", "1895", 0b10001,"", "TB25Q20005"));
    // medien.push_back(make_tuple("978-3-463-45678-9", "Johann Wolfgang von Goethe", "Faust", "1808", 0b10001,"", "SS25Q20006"));
    // medien.push_back(make_tuple("978-3-426-56789-0", "Friedrich Schiller", "Die Räuber", "1781", 0b10000, "2025-06-05", "LR25Q20010"));
    // medien.push_back(make_tuple("978-3-499-67890-1", "E.T.A. Hoffmann", "Der Sandmann", "1816", 0b10001,"", "DW25Q20009"));
    
    // Zeitschriften
    // medien.push_back(make_tuple("977-1234-56789-0", "Verschiedene", "Der Spiegel", "01/2023", 0b01001,"", "LR25Q20010"));
    // medien.push_back(make_tuple("977-2345-67890-1", "Verschiedene", "National Geographic", "03/2022", 0b01001,"2025-06-12", "AS25Q20002"));
    // medien.push_back(make_tuple("977-3456-78901-2", "Verschiedene", "Focus", "05/2023", 0b01001,"", "LR25Q20010"));
    // medien.push_back(make_tuple("977-4567-89012-3", "Verschiedene", "Stern", "02/2022", 0b01000,"2025-06-18","PM25Q20003"));
    // medien.push_back(make_tuple("977-5678-90123-4", "Verschiedene", "Geo", "07/2023", 0b01001,"", "LR25Q20010"));
    // medien.push_back(make_tuple("977-6789-01234-5", "Verschiedene", "Zeit Wissen", "04/2022", 0b01001,"", "TB25Q20005"));
    // medien.push_back(make_tuple("977-7890-12345-6", "Verschiedene", "Spektrum der Wissenschaft", "08/2023", 0b01000,"2025-06-22", "LR25Q20010"));
    // medien.push_back(make_tuple("977-8901-23456-7", "Verschiedene", "PM", "12/2022", 0b01001,"", "LR25Q20010"));
    // medien.push_back(make_tuple("977-9012-34567-8", "Verschiedene", "Mare", "10/2023", 0b01001,"", "DW25Q20009"));
    // medien.push_back(make_tuple("977-0123-45678-9", "Verschiedene", "Brigitte", "11/2022", 0b01000,"2025-06-25", "LR25Q20010"));
    
    // Test bib.addMedia
    // bib.addMedia(medien[1]);
    // cout << bib.med[1].author << endl;

    // CDs
    // medien.push_back(make_tuple("5012345678901", "Beethoven", "Symphonien", "2020", 0b00101,"", "LR25Q20010"));
    // medien.push_back(make_tuple("5023456789012", "Mozart", "Klavierkonzerte", "2019", 0b00100, "2025-06-14", "AS25Q20002"));
    // medien.push_back(make_tuple("5034567890123", "Bach", "Brandenburgische Konzerte", "2021", 0b00101,"", "LR25Q20010"));
    // medien.push_back(make_tuple("5045678901234", "Brahms", "Ungarische Tänze", "2020", 0b00100, "2025-06-16", "PM25Q20003"));
    // medien.push_back(make_tuple("5056789012345", "Schubert", "Winterreise", "2022", 0b00101,"", "LR25Q20010"));
    // medien.push_back(make_tuple("5067890123456", "Chopin", "Nocturnes", "2019", 0b00101,"", "TB25Q20005"));
    // medien.push_back(make_tuple("5078901234567", "Tchaikovsky", "Schwanensee", "2021", 0b00100, "2025-06-19", "LR25Q20010"));
    // medien.push_back(make_tuple("5089012345678", "Vivaldi", "Die vier Jahreszeiten", "2020", 0b00101,"", "LR25Q20010"));
    // medien.push_back(make_tuple("5090123456789", "Handel", "Messiah", "2022", 0b00101,"", "JH25Q20008"));
    // medien.push_back(make_tuple("5001234567890", "Haydn", "Die Schöpfung", "2019", 0b00100, "2025-06-21", "LR25Q20010"));
    
    // DVDs
    // medien.push_back(make_tuple("4001234567890", "Christopher Nolan", "Inception", "2010", 0b00011,"", "LR25Q20010"));
    // medien.push_back(make_tuple("4002345678901", "Quentin Tarantino", "Pulp Fiction", "1994", 0b00010,"2025-06-13", "MM25Q20001"));
    // medien.push_back(make_tuple("4003456789012", "Stanley Kubrick", "2001: Odyssee im Weltraum", "1968", 0b00011,"", "LR25Q20010"));
    // medien.push_back(make_tuple("4004567890123", "Martin Scorsese", "The Departed", "2006", 0b00010,"2025-06-17", "LW25Q20004"));
    // medien.push_back(make_tuple("4005678901234", "Francis Ford Coppola", "Der Pate", "1972", 0b00011,"", "LR25Q20010"));
    // medien.push_back(make_tuple("4006789012345", "Steven Spielberg", "Schindlers Liste", "1993", 0b00011,"", "SS25Q20006"));
    // medien.push_back(make_tuple("4007890123456", "Ridley Scott", "Blade Runner", "1982", 0b00010, "2025-06-23", "LR25Q20010"));
    // medien.push_back(make_tuple("4008901234567", "Alfred Hitchcock", "Psycho", "1960", 0b00011,"", "LR25Q20010"));
    // medien.push_back(make_tuple("4009012345678", "James Cameron", "Titanic", "1997", 0b00011,"", "LR25Q20010"));
    // medien.push_back(make_tuple("4010123456789", "Peter Jackson", "Der Herr der Ringe: Die Rückkehr des Königs", "2003", 0b00011,"2025-06-24", "JH25Q20008"));

    // Test bib.addMediaFromVector
    // bib.addMediaFromVector(medien);
    // for(auto m : bib.med){
    //     cout << m.mediaID << endl;
    // }

    // Test biTypedetectMediaType
    // cout << biTypedetectMediaType(bib.med[0]) << endl;

    
    // Kunden
//    kunden.push_back(make_tuple("Max Mustermann", "Herr", "Musterstraße 1, 10115 Berlin", "MM25Q20001", true, vector<string>{"978-3-423-12345-6", "977-2345-67890-1", "5023456789012"}));
//     kunden.push_back(make_tuple("Anna Schmidt", "Frau", "Hauptstraße 42, 80331 München", "AS25Q20002", true, vector<string>{"978-3-596-29490-1", "4002345678901"}));
//     kunden.push_back(make_tuple("Peter Müller", "Herr", "Bahnhofstraße 7, 20095 Hamburg", "PM25Q20003", false, vector<string>{}));
//     kunden.push_back(make_tuple("Lisa Wagner", "Frau", "Gartenweg 15, 60325 Frankfurt", "LW25Q20004", true, vector<string>{"978-3-442-73456-7", "977-4567-89012-3", "5045678901234"}));
//     kunden.push_back(make_tuple("Thomas Bauer", "Herr", "Waldstraße 23, 50667 Köln", "TB25Q20005", true, vector<string>{"978-3-257-23456-8", "4004567890123"}));
//     kunden.push_back(make_tuple("Sarah Schulz", "Frau", "Seeufer 8, 81379 München", "SS25Q20006", false, vector<string>{}));
//     kunden.push_back(make_tuple("Michael Becker", "Herr", "Bergweg 11, 70173 Stuttgart", "MB25Q20007", true, vector<string>{"978-3-458-34567-8", "977-6789-01234-5", "5067890123456"}));
//     kunden.push_back(make_tuple("Julia Hoffmann", "Frau", "Feldstraße 3, 30159 Hannover", "JH25Q20008", true, vector<string>{"978-3-463-45678-9", "4006789012345"}));
//     kunden.push_back(make_tuple("David Weber", "Herr", "Flussweg 19, 40210 Düsseldorf", "DW25Q20009", false, vector<string>{}));
//     kunden.push_back(make_tuple("Laura Richter", "Frau", "Hügelstraße 5, 69115 Heidelberg", "LR25Q20010", true, vector<string>{"978-3-499-67890-1", "977-9012-34567-8", "5090123456789", "4010123456789"}));

    bib.addCustomerFromCSV();
    cout << bib.cust[0].loanMedia << endl;
    bib.addMediaFromCSV();
    //bib.showAllMedia();
    //bib.searchMedia();
      
    return 0;
}
