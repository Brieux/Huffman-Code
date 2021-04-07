#include <iostream>
#include <fstream>
#include <map>

using namespace std;
<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes

int main()
{
    fstream file;
    file.open("texteDeChanson.txt");
    map<char, int> cTab;
    char c;
    while (file.get(c)) {
        map<char, int>::iterator it = cTab.find(c);
        if (it == cTab.end()) {
            cTab.insert({c,1});
        }
        else {
            it->second += 1;
        }       
    }

    for (const auto& p : cTab) {
        std::cout << "Char [" << p.first << "] = " << p.second << " iterations." << endl;
    }

    return 0;
}
