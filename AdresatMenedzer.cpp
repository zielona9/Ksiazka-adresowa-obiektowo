#include "AdresatMenedzer.h"


Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    MetodyPomocnicze metodaPomocnicza;
    Adresat adresat;
    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata(adresaci)+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(metodaPomocnicza.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodaPomocnicza.wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metodaPomocnicza.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodaPomocnicza.wczytajLinie()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodaPomocnicza.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodaPomocnicza.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodaPomocnicza.wczytajLinie());

    return adresat;
}

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout<<"Nowy adresat zostal dodany"<<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego adresata do pliku." <<endl;
    system ("pause");


}
void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout <<"Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzadres() << endl;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
void AdresatMenedzer::wczytajAdresatowZPliku()
{

    adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    idOstatniegoAdresata=plikZAdresatami.pobierzIdOstatniegoAdresata(adresaci);
}
