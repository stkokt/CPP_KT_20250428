# pragma once
# include <iostream>
# include <vector>
# include <string>
# include <numeric>

using namespace std;

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
        if (*it != 0){
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
