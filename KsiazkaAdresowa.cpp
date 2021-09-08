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
    bool logowanie=true;
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer= new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());

    while(logowanie==true)
      {
            wybor = uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
         switch (wybor)
            {
            case '1':
                 dodajAdresata();
                break;
            case '2':
                adresatMenedzer->wyszukajAdresatowPoImieniu();
                break;
            case '3':
              adresatMenedzer->wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                 adresatMenedzer->wyswietlWszystkichAdresatow();
                break;
            case '5':
                  adresatMenedzer->usunAdresata();
                break;
            case '6':
                adresatMenedzer->edytujAdresata();
                break;
            case '7':
                uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogowanieUzytkownika();
                logowanie=false;
                break;
            }
      }
    }
}
void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer= NULL;
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

void KsiazkaAdresowa::wyborOpcjiMenuPoczatkowym()
{
    char wybor;
    bool menu=true;

     while(menu)
     {
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
                menu=false;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
     }
}
