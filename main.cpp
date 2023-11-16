#include <iostream>
#include <locale.h>
#include <limits>
#include <vector>
#include <fstream>

#define endl '\n';

using std::cout;
using std::cin;
using std::cerr;
using std::string;



template<typename T>
void wprowadz(T* txt);
void wyswietl_menu();
bool start()
{
    wyswietl_menu();
    return false;
}

void mechanizm();
void posortuj(std::vector<int> &tab, int rozmiar);

int main()
{
    setlocale(LC_CTYPE, "Polish");

    try
    {
        while (!start());
        return 0;
    }
    catch (string blod)
    {
        cerr << blod;
    }
    return 0;
}



void wyswietl_menu()
{
    string opcje[] = { "Parzyste liczby","Która liczba większa","Sortowanie", "kalkulator", "koniec programu" };
    cout << "------MENU----------" << endl;
    for (int i = 0; i < (sizeof(opcje) / sizeof(opcje[0])); i++) cout << (i + 1) << ". " << opcje[i] << endl;
    cout << "--------------------" << endl;
    mechanizm();
}


void mechanizm()
{
    std::fstream zapis;
    zapis.open("zapisanie.txt", std::ios::app);

    int wybor{ 0 };
    cout << "Wprowadż numer opcji: ";
    wprowadz(&wybor);
    system("cls"); //działa tylko na win api
    switch (wybor)
    {
    case 1:
    {
        int ile_liczb{ 0 };
        cout << "Do jakiej liczby wyświetlić parzyste?: ";
        wprowadz(&ile_liczb);
        cout << " kolejne liczby parzyste do " << ile_liczb << " : " << endl;
        zapis << " kolejne liczby parzyste do " << ile_liczb << " : " << endl;
        for (int i = 2; i <= ile_liczb; i += 2) {
            cout << i << endl;
            zapis << i << endl;
        }
    }
    break;
    case 2:
    {
        long long a{ 0 }, b{ 0 };
        cout << "Wprowadż 1 liczbe: ";
        wprowadz(&a);
        cout << "Wprowadż 2 liczbe: ";
        wprowadz(&b);

        system("cls"); //działa tylko na win api

        if (a > b) {
            cout << a << " jest większe  od " << b;
            zapis << a << " jest większe  od " << b;
        }
        else if (a < b) {
            cout << b << " jest większe od " << a;
            zapis << b << " jest większe od " << a;
        }
        else {
            cout << "Liczba 1 i 2: " << a << " jest równa! ";
            zapis << b << " jest większe od " << a;
        }

    }
    break;
    case 3:
    {
        //int liczby[] = { 4,2,3,8,5,1 }
        int ile_liczb{ 0 };
        cout << "Ile liczb chcesz posortować?: ";
        wprowadz(&ile_liczb);
        system("cls"); //działa tylko na win api
        std::vector<int> liczby(ile_liczb);
        int ktora{ 1 };
        for (auto& i : liczby) {
            cout << "Wprowadż liczbe numer " << ktora << " : ";
            cin >> i;
            ktora++;
        }
        posortuj(liczby, liczby.size());
        system("cls"); //działa tylko na win api
        cout << "Posortowane liczby: ";
        zapis << "Posortowane liczby: ";
        for (auto i : liczby) {
            cout << i << " ";
            zapis << i << " ";
        }
        cout << endl;
        zapis << endl;
    }
    
    break;
    case 4:
    {
        double a{ 0 }, b{ 0 };
        cout << "Podaj 1 liczbe: ";
        wprowadz(&a);
        cout << "Podaj 2 liczbe: ";
        wprowadz(&b);
        system("cls"); //działa tylko na win api
        cout << "Suma  liczb: " << a << " + " << b << " = " << a + b << endl;
        zapis << "Suma  liczb :" << a << " + " << b << " = " << a + b << endl;
        cout << "Różnica liczb " << a << " - " << b << " = " << a - b << endl;
        zapis << "Różnica liczb " << a << " - " << b << " = " << a - b << endl;
        cout << "Iloczyn liczb " << a << " * " << b << " = " << a * b << endl;
        zapis << "Iloczyn liczb " << a << " * " << b << " = " << a * b << endl;
        if (b != 0) {
            cout << "Iloraz liczb " << a << " / " << b << " = " << a / b << endl;
            zapis << "Iloraz liczb " << a << " / " << b << " = " << a / b << endl;
            cout << "Reszta z dzielenia liczb " << a << " % " << b << " = " << (int)a % (int)b << endl;
            zapis << "Reszta z dzielenia liczb " << a << " % " << b << " = " << (int) a % (int) b << endl;
        } 
        else {
            cerr << "Nie można dzielić przez 0!";
        }
    }
    break;
    case 5:
    {
        system("cls"); //działa tylko na win api
        cout << "Wyłączanie programu ";
        exit(0);
        return;
    }
    break;
    default:
        system("cls"); //działa tylko na win api
        cout << "Opcja poza zakresu!!!";
    }
    zapis << "\n ---------------- \n ";
    zapis.close();
}



void posortuj(std::vector<int> &tab, int rozmiar)
{
    if (rozmiar <= 1) return;
    for (int i = 0; i < rozmiar - 1; i++)
    {
        for (int j = 0; j < rozmiar - 1 - i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                std::swap(tab[j], tab[j + 1]);
            }
        }
    }
}

template<typename T>
void wprowadz(T* txt)
{
    while (!(cin >> *txt))
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Błędne dane wejściowe. Wprowadż jeszcze raz: ";
        }
    }
}
