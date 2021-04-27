#include <fstream>
#include <map>
#include <vector>
#include <algorithm> 
#include "Node.h"

using namespace std;

struct translate {
    char character;
    int binary;
};

void sortWithFrequency(vector<Node *> v) {
    for (int j = 0; j < v.size() - 1; j++) {
        for (int i = 0; i < v.size() - j - 1; i++) {


            if (v[i]->getFrequency() < v[i + 1]->getFrequency()) {
                Node tampon(v[i]->getValue(), v[i]->getFrequency());
                v[i]->setValue(v[i + 1]->getValue());
                v[i]->setFrenquency(v[i + 1]->getFrequency());
                v[i + 1]->setValue(tampon.getValue());
                v[i + 1]->setFrenquency(tampon.getFrequency());

            }
        }
    }
}

int main()
{
    fstream file;
    file.open("texteDeChanson.txt");
    map<char, int> cTab;
    char c;
    vector<Node *> leaf;

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
        cout << p.first << " " << p.second << endl;
        leaf.push_back(new Node(p.first, p.second)); //ajout de la feuille dans l'arbres

    }
    cout <<endl<< "TRI" << endl<< endl;
    sortWithFrequency(leaf);
    for (int i = 0; i <leaf.size(); i++) {
        cout << leaf[i]->getValue() << " & " << leaf[i]->getFrequency() << endl;
    }
    cout <<endl<< "Arbre" << endl << endl;
    
    for (int i = leaf.size() - 2; i > 1; i = i - 2) {
            Node l1(leaf[i]->getValue(), leaf[i]->getFrequency());
            leaf.pop_back();
            Node l2(leaf[i - 1]->getValue(), leaf[i - 1]->getFrequency());
            leaf.pop_back();
            Node branch('|', l1.getFrequency() + l2.getFrequency());
            branch.setChild('l', l2);
            branch.setChild('r', l1);
            leaf.push_back(&branch);
            sortWithFrequency(leaf);
    }
    for (int i = 0; i < leaf.size(); i++) {
        cout << leaf[i]->getValue() << " & " << leaf[i]->getFrequency() << endl;
    }
    return 0;
}
