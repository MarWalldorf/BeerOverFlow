#include "EtapProdukcji.h"
#include <sstream>
using namespace std;

EtapProdukcji::EtapProdukcji(string opis, int czasMinut)
    : opis(move(opis)), czasMinut(czasMinut) {
}

string EtapProdukcji::pobierzOpis() const {
    ostringstream oss;
    oss << opis << " (" << czasMinut << " minut)";
    return oss.str();
}
