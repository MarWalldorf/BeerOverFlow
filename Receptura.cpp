#include "Receptura.h"
#include <iostream>
using namespace std;

Receptura::Receptura(string nazwa) : nazwa(move(nazwa)) {}

void Receptura::dodajSkladnik(const Skladnik& skladnik) 
{
    skladniki.push_back(skladnik);
}

void Receptura::dodajEtap(const EtapProdukcji& etap) 
{
    etapy.push_back(etap);
}

void Receptura::wypiszRecepture() const 
{
    cout << "Receptura: " << nazwa << "\n\nSk³adniki:\n";
    for (const auto& s : skladniki)
        cout << " - " << s.pobierzOpis() << '\n';

    cout << "\nEtapy produkcji:\n";
    for (const auto& e : etapy)
        cout << " - " << e.pobierzOpis() << '\n';
}

string Receptura::pobierzNazwe() const 
{
    return nazwa;
}
