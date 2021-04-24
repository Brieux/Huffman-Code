#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm> 

using namespace std;



int main()
{
    fstream file;
    file.open("texteDeChanson.txt");
    map<char, int> cTab;
    char c;
    vector<int> nbrIte;

    while (file.get(c)) {
        map<char, int>::iterator it = cTab.find(c);
        if (it == cTab.end()) {
            cTab.insert({c,1});
        }
        else {
            it->second += 1;
        }       
    }
    
    cout << "Non tri" << endl;

    for (const auto& p : cTab) {
        cout << "Char [" << p.first << "] = " << p.second << " iterations." << endl;
        nbrIte.push_back(p.second);
    }

    sort(nbrIte.begin(), nbrIte.end(), greater<int>());
    
    cout << "tri" << endl;

    for (auto x : nbrIte)
        cout << x << " ";



    return 0;
}
