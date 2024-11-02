/** @file Source.cpp
 *  @brief Główny plik programu zawierający funkcję `main` oraz menu interakcji użytkownika z drzewem BST.
 */
#include "BST.h"


/**
 * @brief Wyświetla menu opcji dla użytkownika.
 * 
 * Funkcja `menu` prezentuje dostępne operacje na drzewie BST, takie jak dodawanie, usuwanie, wyświetlanie,
 * zapisywanie i odczyt z pliku.
 */
void menu() {
    BST A;

    cout << endl << endl << "1. Dodaj element" << endl;
    cout << "2. Usu� element" << endl;
    cout << "3. Usu� ca�e drzewo" << endl;
    cout << "4. Szukaj �cie�ki do elementu" << endl;
    cout << "5. Wy�wietl drzewo (1-Preorder, 2-Inorder, 3-Postorder)" << endl;
    cout << "6. Zapisz drzewo do pliku" << endl;
    cout << "7. Wczytaj dane z pliku" << endl;
    cout << "0. Wyjd�" << endl;
}
/**
 * @brief Główna funkcja programu.
 * 
 * Funkcja `main` obsługuje logikę interakcji użytkownika z drzewem BST poprzez menu.
 * Umożliwia wykonywanie operacji na drzewie, takich jak dodawanie, usuwanie, przeglądanie,
 * zapisywanie do pliku i odczyt z pliku.
 * 
 * @return Zwraca 0 po zamknięciu programu.
 */

int main()
{
    BST A;///< Obiekt klasy BST reprezentujący drzewo binarne.

    int option, value;

    do {
        menu();///< Wywołanie funkcji wyświetlającej menu.
        cout << "Wybierz opcj�: ";
        cin >> option;

        switch (option) {
        case 1:
        {
            cout << "Podaj warto�� do dodania: ";
            cin >> value;
            A.Dodanie(value);///< Dodaje wartość do drzewa.
            break;
        }
        case 2:
        {
            cout << "Podaj warto�� do usuni�cia: ";
            cin >> value;
            A.Usun(value);///< Usuwa wskazaną wartość z drzewa.
            break;
        }
        case 3:
        {
            A.wyczysc();///< Usuwa wszystkie węzły drzewa.
            cout << "Drzewo zosta�o usuni�te." << endl;
            break;
        }
        case 4:
        {
            cout << "Podaj warto�� do znalezienia: ";
            cin >> value;
            vector<int> path;///< Wektor przechowujący ścieżkę do znalezionego elementu
            if (A.znajdzSciezke(value, path)) {///< Wyświetla ścieżkę do elementu.
                cout << "�cie�ka do " << value << ": ";
                for (int n : path) cout << n << " ";
                cout << endl;
            }
            else {
                cout << "\nElement nie znaleziony." << endl;
            }
            break;
        }
        case 5:
        {
            A.c_order();///< Wyświetla drzewo w wybranym porządku.
            break;

        }
        case 6:
        {
            A.f_order();///< Zapisuje drzewo do pliku w wybranym porządku
            break;
        }
        case 7:
        {
            int x = 2;
            string file;
            cout << "\nPodaj nazwe pliku (podaj sama nazwe z formatem):\n";
            cin >> file;
            cout << "\nplik zapisany w j�zyku binarnym, nacisnij 0\nnplik zapisany w j�zyku dziesietnym, nacisnij 1 : \n";
            cin >> x;
            A.f_read(file, x);///< Wczytuje dane z pliku do drzewa.
        }
        case 0:
        {
            cout << "\nZamykanie programu." << endl;
            break;
        }
        default:
        {
            cout << "\nNieprawid�owa opcja. Spr�buj ponownie." << endl;
        }
        }
    } while (option != 0);///< Kontynuuje działanie programu, dopóki użytkownik nie wybierze opcji 0.

    return 0;
}





/* 
na razie tyle rzeczy doda�em, tutaj zapisuje reszte plan�w i cel�w w zadaniu i to jak je oceniam pod wzgl�dem trudno�ci, 
tego trzeciego nie wiem czy trzeba  i nie wiem jak to zrobi� je�eli tak, 
je�eli chcesz to mo�esz to lub inne zrobi� a je�eli nie to ja sprubuje rano

Do dodania :  
 - mo�liwo�� zapisania w binarnym, (�atwa-�rednie)
 - je�eli to jak to obecnie nie liczy sie jako "graficzne wy�wietlenie" (tak jak to nazwa� w zadaniu) to doda� graficzne wy�wietlanie
 (obecnie nie wiem jak mo�na by by�o dod�c graficzne wy�wietlanie, zak�adam �e jest to trudne ale nie mam poj�cia)
  
*/