#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Keyboard {
public:

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int forward(char letter) {
        return alphabet.find(letter);
    }

    char backward(int signal) {
            return alphabet[signal];
        }
};

class Plugboard {
    public:

    string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string right = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    Plugboard(){};
    Plugboard(const vector<string> plugs)
    {
        for (auto i=0; i< plugs.size(); i++){
            char A = plugs[i][0];
            char B = plugs[i][1];
            short pos_A = this->left.find(A);
            short pos_B = this->left.find(B);
            this->left.replace(pos_A, 1,1, B);
            this->left.replace(pos_B, 1,1, A);
            };
    };

    short forward(short signal){
        char letter = this->right[signal];
/*         short signal1 = this->left.find(letter);
        return signal1; */
        return this->left.find(letter); // Zusammenfassung Zeile 44 + Zeile 45
    }

    short backward(short signal){
        char letter = this->left[signal];
        return this->right.find(letter);
    }

};

class Rotor{
    public:

    string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string right = "";
    char notch;

    Rotor(){};
    Rotor(string wiring, char anotch)
    :right(wiring), notch(anotch){};

    short forward(short signal){
        char letter = this->right[signal];
        return this->left.find(letter);;
    }

    short backward(short signal){
        char letter = this->left[signal];
        return this->right.find(letter);
    }

    void show(){
        cout<<this->left<<"\n"<<this->right<<"\n"<<endl;
    }

    void rotate(short n = 1, bool forward = true){
        for (short i=0; i < n; i++){
            if (forward){
                this->left.push_back(this->left[0]);
                this->left.erase(0,1);
                this->right.push_back(this->right[0]);
                this->right.erase(0,1);
            }
            else{
                this->left=this->left[25]+this->left;
                this->left.pop_back();
                this->right=this->right[25]+this->right;
                this->right.pop_back();
            }
        }
    }

    void rotate_to_letter(char letter){
        string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short n = abc.find(letter);
        this->rotate(n);
    }

    void set_ring(short n){
        string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        this->rotate(n-1,false);
        short n_notch = abc.find(this->notch);
        this->notch = abc[(n_notch-n)%26];
    }
};

class Reflector{
    public:

    string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string right = "";

    Reflector(){};
    Reflector(string wiring)
    :right(wiring){};

    short reflect(short signal){
        char letter = this->right[signal];
        return this->left.find(letter);
    }
};

class Enigma{
    public:

    Reflector re;
    Rotor r1;
    Rotor r2;
    Rotor r3;
    Plugboard pb;
    Keyboard kb;

    Enigma(){};
    Enigma(Reflector re, Rotor r1, Rotor r2, Rotor r3, Plugboard pb, Keyboard kb)
    :re(re), r1(r1),r2(r2),r3(r3),pb(pb),kb(kb){};

    void set_rings(short one, short two, short three){
        this->r1.set_ring(one);
        this->r2.set_ring(two);
        this->r3.set_ring(three);
    }

    void set_key(string key){
        this->r1.rotate_to_letter(key[0]);
        this->r2.rotate_to_letter(key[1]);
        this->r3.rotate_to_letter(key[2]);
    }

    char encipher(char letter){
        if (char(this->r2.left[0]) == this->r2.notch && this->r3.left[0] == this->r3.notch){
            this->r1.rotate();
            this->r2.rotate();
            this->r3.rotate();
        }
        else if(this->r2.left[0] == this->r2.notch){
            this->r1.rotate();
            this->r2.rotate();
            this->r3.rotate();
        }
        else if (this->r3.left[0] == this->r3.notch){
            this->r2.rotate();
            this->r3.rotate();
        }
        else{
            this->r3.rotate();
        }

        short signal = this->kb.forward(letter);
        signal = this->pb.forward(signal);
        signal = this->r3.forward(signal);
        signal = this->r2.forward(signal);
        signal = this->r1.forward(signal);
        signal = this->re.reflect(signal);
        signal = this->r1.backward(signal);
        signal = this->r2.backward(signal);
        signal = this->r3.backward(signal);
        signal = this->pb.backward(signal);
        letter = this->kb.backward(signal);
        return letter;
    };
};

int main() {
    Keyboard KB;
    Plugboard PB = Plugboard({"AB", "CD", "EF"});
    Rotor I = Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');
    Rotor II = Rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');
    Rotor III = Rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');
    Rotor IV = Rotor("ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');
    Rotor V = Rotor("VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');
    Reflector A = Reflector("EJMZALYXVBWFCRQUONTSPIKHGD");
    Reflector B = Reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    Reflector C = Reflector("FVPJIAOYEDRZXWGCTKUQSBNMHL");

    Enigma ENIGMA{B,IV, II, I, PB, KB};
    ENIGMA.set_rings(5,26,2);
    ENIGMA.set_key("CAT");

    string message = "TESTINGTESTINGTESTINGTESTING";
    // message = "IHNZGVPHIYBRFNUFQMXHROBXELBN";
    string cypher_text ="";

    for (auto i : message){
        cypher_text += ENIGMA.encipher(i);
    }

    cout<<cypher_text<<endl;

    return 0;
}
