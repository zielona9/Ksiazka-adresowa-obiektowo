#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "UzytkownikMenedzer.h"
#include "Adresat.h"
#include <fstream>

using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    string nazwaTymczasowegoPlikuZAdresatami;

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);


public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI)
    {
        nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    };
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata(vector <Adresat> adresaci);
    int pobierzZPlikuIdOstatniegoAdresata();
    void edytujWybranaLinieWPliku(int idAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    void usunWybranaLinieWPliku(int idAdresata);
};
#endif
