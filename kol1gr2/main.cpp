#include "litera.h"
#include "operatory.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
// kod testowy - NIE ZMIENIAC - powinien dzialac na koncu
// mozna na chwile zakomentowac w trakcie pisania

    Litera p1{'A'};
    Litera p2 = 'B';
    bool isBigger = p1 > p2;
    bool isSmaller = p1 < p2;
    cout << "isBigger: " << isBigger << " isSmaller: " << isSmaller << endl;
    vector<Litera> vec { 'C', 'D', 'E', 'F', 'G', 'H'  };
    std::sort(vec.begin(), vec.end(), greater<Litera>());
    for (auto c : vec) cout << c << endl;

    cout << "Podaj litere: ";
    cin >> p1;
    unsigned kod = p1.Litera_to_ascii();

    cout << "p1 i p2: " << p1 << "," << p2 << endl;
    cout << "p1 jako kod ascii: " << kod << endl;
}
