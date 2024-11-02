#include "BST.h"

using namespace std;
void menu() {
    BST A;

    cout << endl << endl << "1. Dodaj element" << endl;
    cout << "2. Usuñ element" << endl;
    cout << "3. Usuñ ca³e drzewo" << endl;
    cout << "4. Szukaj œcie¿ki do elementu" << endl;
    cout << "5. Wyœwietl drzewo (1-Preorder, 2-Inorder, 3-Postorder)" << endl;
    cout << "6. Zapisz drzewo do pliku" << endl;
    cout << "7. Wczytaj dane z pliku" << endl;
    cout << "0. WyjdŸ" << endl;
}


int main()
{
    BST A;

    int option, value;

    do {
        menu();
        cout << "Wybierz opcjê: ";
        cin >> option;

        switch (option) {
        case 1:
        {
            cout << "Podaj wartoœæ do dodania: ";
            cin >> value;
            A.Dodanie(value);
            break;
        }
        case 2:
        {
            cout << "Podaj wartoœæ do usuniêcia: ";
            cin >> value;
            A.Usun(value);
            break;
        }
        case 3:
        {
            A.wyczysc();
            cout << "Drzewo zosta³o usuniête." << endl;
            break;
        }
        case 4:
        {
            cout << "Podaj wartoœæ do znalezienia: ";
            cin >> value;
            vector<int> path;
            if (A.znajdzSciezke(value, path)) {
                cout << "Œcie¿ka do " << value << ": ";
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
            A.c_order();
            break;

        }
        case 6:
        {
            A.f_order();
            break;
        }
        case 7:
        {
            int x = 2;
            string file;
            cout << "\nPodaj nazwe pliku (podaj sama nazwe z formatem):\n";
            cin >> file;
            cout << "\nplik zapisany w jêzyku binarnym, nacisnij 0\nnplik zapisany w jêzyku dziesietnym, nacisnij 1 : \n";
            cin >> x;
            A.f_read(file, x);
        }
        case 0:
        {
            cout << "\nZamykanie programu." << endl;
            break;
        }
        default:
        {
            cout << "\nNieprawid³owa opcja. Spróbuj ponownie." << endl;
        }
        }
    } while (option != 0);

    return 0;
}





/* 
na razie tyle rzeczy doda³em, tutaj zapisuje reszte planów i celów w zadaniu i to jak je oceniam pod wzglêdem trudnoœci, 
tego trzeciego nie wiem czy trzeba  i nie wiem jak to zrobiæ je¿eli tak, 
je¿eli chcesz to mo¿esz to lub inne zrobiæ a je¿eli nie to ja sprubuje rano

Do dodania :  
 - mo¿liwoœæ zapisania w binarnym, (³atwa-œrednie)
 - je¿eli to jak to obecnie nie liczy sie jako "graficzne wyœwietlenie" (tak jak to nazwa³ w zadaniu) to dodaæ graficzne wyœwietlanie
 (obecnie nie wiem jak mo¿na by by³o dod¹c graficzne wyœwietlanie, zak³adam ¿e jest to trudne ale nie mam pojêcia)
  
*/