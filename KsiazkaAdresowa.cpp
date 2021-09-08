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
    char wybor;
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer= new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
     wybor = uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                dodajAdresata();
                break;
            case '2':
               // wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
               // wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            case '5':
                 usunAdresata();
                break;
            case '6':
               edytujAdresata();
                break;
            case '7':
                zmianaHasla();
                break;
            case '8':
                wylogowanieUzytkownika();
                break;
            }


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
void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}
void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenedzer->edytujAdresata();
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}


void KsiazkaAdresowa::wyborOpcjiMenuPoczatkowym()
{
    char wybor;
    wybor = uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
     switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
}
