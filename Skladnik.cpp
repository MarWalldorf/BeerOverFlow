#include "Skladnik.h"
#include <sstream>
using namespace std;

Skladnik::Skladnik(string nazwa, double ilosc, string jednostka)
    : nazwa(move(nazwa)), ilosc(ilosc), jednostka(move(jednostka)) {
}

string Skladnik::pobierzOpis() const {
    ostringstream oss;
    oss << ilosc << " " << jednostka << " " << nazwa;
    return oss.str();
}
