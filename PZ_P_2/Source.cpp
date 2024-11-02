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

int main(){
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
		}
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
     return 0;
}
}