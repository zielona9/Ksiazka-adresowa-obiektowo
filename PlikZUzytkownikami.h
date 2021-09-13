#ifndef _PLIKZUZYTKOWNIKAMI_H
#define _PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "PlikTekstowy.h"
#include <fstream>

using namespace std;

class PlikTekstowy;
class PlikZUzytkownikami : public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
    private:
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    PlikZUzytkownikami(string nazwaPliku):PlikTekstowy(nazwaPliku) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};
#endif
