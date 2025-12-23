// Tabla adunarii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char raspuns;
    int x, y, suma;
    cout << "Sa invatam tabla adunarii! Esti pregatit? (D/N) ";
    raspuns = getchar();
    if (raspuns == 'N' || raspuns == 'n')
        cout << "Mai gandeste-te! Eu zic sa incercam!\n";
    srand(100); // Initializez generatorul de numere aleatorii
    do
    {
        x = rand() % 100; y = rand() % 100; // Generez aleator numerele
        cout << x << " + " << y << " = "; raspuns = 'D';
        do
        {
            cin >> suma; // Citeste raspunsul elevului
            if (suma == x + y) cout << "Excelent raspuns!!!\n";
            else
            {
                cout << "Nu! Mai incerci inca o data? (D/N) ";
                raspuns = getchar();
            }
        } while (suma != x + y && (raspuns == 'D' || raspuns == 'd'));
        if (raspuns == 'N' || raspuns == 'n')
            cout << "Raspunsul corect era " << x + y << '\n';
        cout << "Continuam? (D/N) "; raspuns = getchar();
    } while (raspuns == 'D' || raspuns == 'd');
    cout << "La revedere!!!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
