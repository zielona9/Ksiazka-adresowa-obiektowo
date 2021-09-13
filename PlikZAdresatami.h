#ifndef _PLIKZADRESATAMI_H
#define _PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "UzytkownikMenedzer.h"
#include "Adresat.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    private:
    string nazwaTymczasowegoPlikuZAdresatami;

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);


public:
    PlikZAdresatami(string nazwaPliku):PlikTekstowy(nazwaPliku)
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
