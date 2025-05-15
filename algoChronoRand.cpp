#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <numeric>
#include <iomanip>

int main() {
/*
// Aufgabe 1: Vergleiche die Zeit, die benötigt wird, um einen großen 
//            Vektor mit `std::sort` und `std::stable_sort` zu sortieren.
    {
    std::cout << "\nAufgabe 1\n" << std::endl;

    std::vector<int> vec(1000000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        vec[i] = dis(gen);
    }

    auto vec_copy = vec;

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "std::sort Zeit: " << elapsed.count() << " Sekunden\n";

    start = std::chrono::high_resolution_clock::now();
    std::stable_sort(vec_copy.begin(), vec_copy.end());
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "std::stable_sort Zeit: " << elapsed.count() << " Sekunden\n";
    }

// Aufgabe 2: Generiere Zufallszahlen mit verschiedenen Verteilungen 
//            (gleichmäßig, normal, exponentiell) und vergleiche sie.

    {
    std::cout << "\nAufgabe 2\n" << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> uniform_dis(1, 100);
    std::normal_distribution<> normal_dis(50, 10);
    std::exponential_distribution<> exp_dis(1.0);

    std::vector<int> uniform_nums;
    std::vector<double> normal_nums;
    std::vector<double> exp_nums;

    for (int i = 0; i < 10; ++i) {
        uniform_nums.push_back(uniform_dis(gen));
        normal_nums.push_back(normal_dis(gen));
        exp_nums.push_back(exp_dis(gen));
    }

    std::cout << "Gleichmäßig verteilte Zahlen: ";
    for (int num : uniform_nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "Normal verteilte Zahlen: ";
    for (double num : normal_nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "Exponentiell verteilte Zahlen: ";
    for (double num : exp_nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    }

// Aufgabe 3: Miss die Zeit, die benötigt wird, um ein Element 
//            in einem großen Vektor mit `std::binary_search` zu finden.

    {
    std::cout << "\nAufgabe 3\n" << std::endl;

    std::vector<int> vec(1000000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        vec[i] = dis(gen);
    }

    std::sort(vec.begin(), vec.end());

    int target = dis(gen);

    auto start = std::chrono::high_resolution_clock::now();
    bool found = std::binary_search(vec.begin(), vec.end(), target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Zeit für binäre Suche: " << elapsed.count() << " Sekunden\n";
    std::cout << "Element " << (found ? "gefunden" : "nicht gefunden") << "\n";

    }

// Aufgabe 4: Vergleiche die Zeit, die benötigt wird, um einen großen 
//            Vektor mit `std::sort`, `std::partial_sort` und 
//            `std::nth_element` zu sortieren.

    {   
    std::cout << "\nAufgabe 4\n" << std::endl;

    std::vector<int> vec(1000000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        vec[i] = dis(gen);
    }

    auto vec_copy1 = vec;
    auto vec_copy2 = vec;

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "std::sort Zeit: " << elapsed.count() << " Sekunden\n";

    start = std::chrono::high_resolution_clock::now();
    std::partial_sort(vec_copy1.begin(), vec_copy1.begin() + 1000000, vec_copy1.end());
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "std::partial_sort Zeit: " << elapsed.count() << " Sekunden\n";

    start = std::chrono::high_resolution_clock::now();
    std::nth_element(vec_copy2.begin(), vec_copy2.begin() + 1000000, vec_copy2.end());
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "std::nth_element Zeit: " << elapsed.count() << " Sekunden\n";
    }

// Aufgabe 5: Generiere Zufallszahlen mit einer benutzerdefinierten 
//            Verteilung (z.B. Poisson-Verteilung).

    {  
    std::cout << "\nAufgabe 5\n" << std::endl;  
    std::random_device rd;
    std::mt19937 gen(rd());
    std::poisson_distribution<> pois_dis(4.1);

    std::vector<int> pois_nums;

    for (int i = 0; i < 10; ++i) {
        pois_nums.push_back(pois_dis(gen));
    }

    std::cout << "Poisson verteilte Zahlen: ";
    for (int num : pois_nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    }

// Aufgabe 6: Vergleiche die Zeit, die benötigt wird, um ein 
//            Element in einem großen Vektor mit `std::find` und 
//            `std::binary_search` zu finden.

    {
    std::cout << "\nAufgabe 6\n" << std::endl;

    std::vector<int> vec(1000000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        vec[i] = dis(gen);
    }

    std::sort(vec.begin(), vec.end());

    int target = dis(gen);

    auto start = std::chrono::high_resolution_clock::now();
    auto it = std::find(vec.begin(), vec.end(), target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "std::find Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Element " << (it != vec.end() ? "gefunden" : "nicht gefunden") << "\n";

    start = std::chrono::high_resolution_clock::now();
    bool found = std::binary_search(vec.begin(), vec.end(), target);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "std::binary_search Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Element " << (found ? "gefunden" : "nicht gefunden") << "\n";
    }

// Aufgabe 7: Vergleiche die Zeit, die benötigt wird, um das 
//            Maximum in einem großen Vektor mit `std::max_element` und 
//            einer manuellen Schleife zu finden.

    {
    std::cout << "\nAufgabe 7\n" << std::endl;

    std::vector<int> vec(1000000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        vec[i] = dis(gen);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto max_it = std::max_element(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "std::max_element Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Maximum: " << *max_it << "\n";

    start = std::chrono::high_resolution_clock::now();
    int max = vec[0];
    for (int num : vec) {
        if (num > max) {
            max = num;
        }
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Manuelle Schleife Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Maximum: " << max << "\n";
    }

// Aufgabe 8: Vergleiche die Zeit, die benötigt wird, um den 
//            Durchschnitt in einem großen Vektor mit `std::accumulate` 
//            und einer manuellen Schleife zu berechnen.

    {
    std::cout << "\nAufgabe 8\n" << std::endl;

    std::vector<int> vec(1000000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        vec[i] = dis(gen);
    }

    auto start = std::chrono::high_resolution_clock::now();
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    double average = sum / vec.size();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "std::accumulate Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Durchschnitt: " << average << "\n";

    start = std::chrono::high_resolution_clock::now();
    sum = 0.0;
    for (int num : vec) {
        sum += num;
    }
    average = sum / vec.size();
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Manuelle Schleife Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Durchschnitt: " << average << "\n";
    }

// Aufgabe 9:  Vergleiche die Zeit, die benötigt wird, um den 
//             Median in einem großen Vektor mit `std::nth_element` 
//             und einer manuellen Sortierung zu berechnen.

    {
    std::cout << "\nAufgabe 9\n" << std::endl;
    std::vector<int> vec(1000000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        vec[i] = dis(gen);
    }

    auto vec_copy = vec;

    auto start = std::chrono::high_resolution_clock::now();
    std::nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
    int median = vec[vec.size() / 2];
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "std::nth_element Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Median: " << median << "\n";

    start = std::chrono::high_resolution_clock::now();
    std::sort(vec_copy.begin(), vec_copy.end());
    median = vec_copy[vec_copy.size() / 2];
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Manuelle Sortierung Zeit: " << elapsed.count() << " Sekunden\n";
    std::cout << "Median: " << median << "\n";
    }

*/
// Aufgabe 10: (Zusatz) Vergleiche ein C- Array mit einem Vector, indem
//             du die Zeit misst für das Befüllen mit 1.000.000 int- Werten,
//             2 Wege für den Vector:
//             a) ohne reserve()
//  	       b) mit reserve()
    {
        std::cout << "\nAufgabe 10\n" << std::setprecision(30) << std::endl;
        int arr[500000] = {};
        std::vector<int> v1;
        std::vector<int> v2;

        v2.reserve(500000);

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 500000; i++){
            arr[i] = i;
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Zeitmessung Array: " << elapsed.count() << std::endl; 

        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 500000; i++){
            v1.push_back(i);
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;

        std::cout << "Zeitmessung Vector(unreserviert): " << elapsed.count() << std::endl; 

        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 500000; i++){
            v2.push_back(i);
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;

        std::cout << "Zeitmessung Vector(reserviert): " << elapsed.count() << std::endl; 

    }

    return 0;
}
