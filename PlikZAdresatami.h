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
    bool czyPlikJestPusty();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){};
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata(vector <Adresat> adresaci);
};
#endif
