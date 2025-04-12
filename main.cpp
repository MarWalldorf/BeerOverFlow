#include "Receptura.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

void utworzReceptury(vector<shared_ptr<Receptura>>& receptury) 
{
    auto ipa = make_shared<Receptura>("Cierpka IPA");
    ipa->dodajSkladnik(Skladnik("słód pilzneński", 5.0, "kg"));
    ipa->dodajSkladnik(Skladnik("chmiel Cascade", 50, "g"));
    ipa->dodajSkladnik(Skladnik("drożdże US-05", 11, "g"));
    ipa->dodajEtap(EtapProdukcji("Zacieranie w 67°C", 60));
    ipa->dodajEtap(EtapProdukcji("Gotowanie z chmielem", 90));
    ipa->dodajEtap(EtapProdukcji("Fermentacja w 18°C", 10080));
    receptury.push_back(ipa);

    auto stout = make_shared<Receptura>("Czarny Stout");
    stout->dodajSkladnik(Skladnik("słód monachijski", 4.5, "kg"));
    stout->dodajSkladnik(Skladnik("słód czekoladowy", 0.5, "kg"));
    stout->dodajSkladnik(Skladnik("chmiel Fuggle", 40, "g"));
    stout->dodajEtap(EtapProdukcji("Zacieranie w 68°C", 60));
    stout->dodajEtap(EtapProdukcji("Gotowanie", 90));
    stout->dodajEtap(EtapProdukcji("Fermentacja w 19°C", 10080));
    receptury.push_back(stout);

    auto lager = make_shared<Receptura>("Złoty Lager");
    lager->dodajSkladnik(Skladnik("słód pilzneński", 4.8, "kg"));
    lager->dodajSkladnik(Skladnik("chmiel Saaz", 60, "g"));
    lager->dodajEtap(EtapProdukcji("Zacieranie w 66°C", 60));
    lager->dodajEtap(EtapProdukcji("Gotowanie", 70));
    lager->dodajEtap(EtapProdukcji("Fermentacja w 10°C", 20160));
    receptury.push_back(lager);

    auto porter = make_shared<Receptura>("Angielski Porter");
    porter->dodajSkladnik(Skladnik("słód pale ale", 5.2, "kg"));
    porter->dodajSkladnik(Skladnik("słód karmelowy", 0.4, "kg"));
    porter->dodajSkladnik(Skladnik("chmiel East Kent Goldings", 45, "g"));
    porter->dodajEtap(EtapProdukcji("Zacieranie w 67°C", 60));
    porter->dodajEtap(EtapProdukcji("Gotowanie", 90));
    porter->dodajEtap(EtapProdukcji("Fermentacja w 18°C", 10080));
    receptury.push_back(porter);

    auto witbier = make_shared<Receptura>("Belgijski Witbier");
    witbier->dodajSkladnik(Skladnik("słód pszeniczny", 2.5, "kg"));
    witbier->dodajSkladnik(Skladnik("słód pilzneński", 2.5, "kg"));
    witbier->dodajSkladnik(Skladnik("skórka pomarańczy", 10, "g"));
    witbier->dodajSkladnik(Skladnik("kolendra", 5, "g"));
    witbier->dodajEtap(EtapProdukcji("Zacieranie w 65°C", 60));
    witbier->dodajEtap(EtapProdukcji("Gotowanie", 60));
    witbier->dodajEtap(EtapProdukcji("Fermentacja w 20°C", 10080));
    receptury.push_back(witbier);

    auto pszeniczne = make_shared<Receptura>("Pszeniczne Weizen");
    pszeniczne->dodajSkladnik(Skladnik("słód pszeniczny", 3.0, "kg"));
    pszeniczne->dodajSkladnik(Skladnik("słód pilzneński", 2.0, "kg"));
    pszeniczne->dodajSkladnik(Skladnik("chmiel Tettnanger", 35, "g"));
    pszeniczne->dodajEtap(EtapProdukcji("Zacieranie w 66°C", 60));
    pszeniczne->dodajEtap(EtapProdukcji("Gotowanie", 70));
    pszeniczne->dodajEtap(EtapProdukcji("Fermentacja w 20°C", 10080));
    receptury.push_back(pszeniczne);

    auto pils = make_shared<Receptura>("Pils z Żateckim");
    pils->dodajSkladnik(Skladnik("słód pilzneński", 5.0, "kg"));
    pils->dodajSkladnik(Skladnik("chmiel Żatecki", 60, "g"));
    pils->dodajEtap(EtapProdukcji("Zacieranie w 65°C", 60));
    pils->dodajEtap(EtapProdukcji("Gotowanie", 90));
    pils->dodajEtap(EtapProdukcji("Fermentacja w 9°C", 20160));
    receptury.push_back(pils);

    auto apa = make_shared<Receptura>("Amerykańska APA");
    apa->dodajSkladnik(Skladnik("słód pale ale", 5.0, "kg"));
    apa->dodajSkladnik(Skladnik("chmiel Citra", 50, "g"));
    apa->dodajSkladnik(Skladnik("chmiel Amarillo", 50, "g"));
    apa->dodajEtap(EtapProdukcji("Zacieranie w 67°C", 60));
    apa->dodajEtap(EtapProdukcji("Gotowanie", 75));
    apa->dodajEtap(EtapProdukcji("Fermentacja w 19°C", 10080));
    receptury.push_back(apa);
}
// mozna dodawac swoje pozycje wedle uznania
//rozbudowa do 16 pozycji 
int main() 
{
    setlocale(LC_ALL, "");
    cout << "Beer Overflow – Spowolnienie do perfekcji\n\n";

    vector<shared_ptr<Receptura>> receptury;
    utworzReceptury(receptury);

    cout << "Wybierz styl piwa:\n";
    for (size_t i = 0; i < receptury.size(); i++) 
    {
        cout << i + 1 << ". " << receptury[i]->pobierzNazwe() << '\n';
    }

    size_t wybor;
    cout << "\nPodaj numer stylu: ";
    cin >> wybor;

    if (wybor >= 1 && wybor <= receptury.size()) 
    {
        cout << "\nWybrana receptura:\n\n";
        receptury[wybor - 1]->wypiszRecepture();
    }
    else 
    {
        cout << "Niepoprawny wybór.\n";
    }

    return 0;
}
