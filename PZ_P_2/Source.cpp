#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;


void menu() {
    cout << "1. Dodaj element" << endl;
    cout << "2. Usuń element" << endl;
    cout << "3. Usuń całe drzewo" << endl;
    cout << "4. Szukaj ścieżki do elementu" << endl;
    cout << "5. Wyświetl drzewo (1-Preorder, 2-Inorder, 3-Postorder)" << endl;
    cout << "6. Zapisz drzewo do pliku" << endl;
    cout << "0. Wyjdź" << endl;
}


int main()
{
	 BST A;
    int option, value;

    do {
        menu();
        cout << "Wybierz opcję: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Podaj wartość do dodania: ";
                cin >> value;
                A.Dodanie(value);
                break;
            case 2:
                cout << "Podaj wartość do usunięcia: ";
                cin >> value;
                A.Usun(value);
                break;
            case 3:
                A.wyczysc();
                cout << "Drzewo zostało usunięte." << endl;
                break;
            case 4:
                cout << "Podaj wartość do znalezienia: ";
                cin >> value;
                vector<int> path;
                if (A.znajdzSciezke(value, path)) {
                    cout << "Ścieżka do " << value << ": ";
                    for (int n : path) cout << n << " ";
                    cout << endl;
                } else {
                    cout << "Element nie znaleziony." << endl;
                }
                break;
            case 5:
                cout << "Podaj metodę wyświetlania (1-Preorder, 2-Inorder, 3-Postorder): ";
                cin >> value;
                A.wyp_all(value);
                break;
            case 6:
                A.zapiszDoPliku("drzewo.txt");
                cout << "Drzewo zapisane do pliku 'drzewo.txt'." << endl;
                break;
            case 0:
                cout << "Zamykanie programu." << endl;
                break;
            default:
                cout << "Nieprawidłowa opcja. Spróbuj ponownie." << endl;
        }
    } while (option != 0);

    return 0;
}






/* 
na razie tyle rzeczy doda�em, tutaj zapisuje reszte plan�w i cel�w w zadaniu i to jak je oceniam pod wzgl�dem trudno�ci, 
tego trzeciego nie wiem czy trzeba  i nie wiem jak to zrobi� je�eli tak, 
je�eli chcesz to mo�esz to lub inne zrobi� a je�eli nie to ja sprubuje rano

Do dodania :  
 - mo�liwo�� zapisania w binarnym, (�atwa-�rednie)
 - doda� menu wyoru sposobu odczytu i zapisu pliku (�atwe)
 - je�eli to jak to obecnie nie liczy sie jako "graficzne wy�wietlenie" (tak jak to nazwa� w zadaniu) to doda� graficzne wy�wietlanie
 (obecnie nie wiem jak mo�na by by�o dod�c graficzne wy�wietlanie, zak�adam �e jest to trudne ale nie mam poj�cia)
  
*/