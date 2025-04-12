#pragma once
#include <string>
using namespace std;

class EtapProdukcji {
public:
    EtapProdukcji(string opis, int czasMinut);
    string pobierzOpis() const;

private:
    string opis;
    int czasMinut;
};
