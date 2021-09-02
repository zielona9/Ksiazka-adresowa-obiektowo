#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Adresat.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{

    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami):plikZAdresatami(nazwaPlikuZAdresatami)
    {
    idOstatniegoAdresata=0;

    };

    Adresat podajDaneNowegoAdresata();
    void dodajAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZPliku();
};
#endif
