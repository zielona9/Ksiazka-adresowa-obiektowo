#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer= new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer= NULL;
}
void KsiazkaAdresowa::zmianaHasla()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()==TRUE)
    adresatMenedzer->dodajAdresata();
    else
    {
        cout<<"Aby dodac adresata, nalezy najpierw sie zalogowac"<< endl;
        system("PAUSE");
    }

}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}
