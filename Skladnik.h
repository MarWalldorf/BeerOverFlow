#pragma once
#include <string>
using namespace std;

class Skladnik {
public:
    Skladnik(string nazwa, double ilosc, string jednostka);
    string pobierzOpis() const;

private:
    string nazwa;
    double ilosc;
    string jednostka;
};
