#pragma once
#include <string>
#include <vector>
#include "Skladnik.h"
#include "EtapProdukcji.h"
using namespace std;

class Receptura {
public:
    Receptura(string nazwa);
    void dodajSkladnik(const Skladnik& skladnik);
    void dodajEtap(const EtapProdukcji& etap);
    void wypiszRecepture() const;
    string pobierzNazwe() const;

private:
    string nazwa;
    vector<Skladnik> skladniki;
    vector<EtapProdukcji> etapy;
};
