#include <fstream>
#include <map>
#include <vector>
#include <algorithm> 
#include "Node.h"

using namespace std;

void tableEncode(Node* tree, string binary, map<char, string>& dict) {
    if (tree->getValue() != '|') {
        dict[tree->getValue()] = binary;
        return;
    }
    tableEncode(tree->getChild('l'), binary + "0", dict);
    tableEncode(tree->getChild('r'), binary + "1", dict);
}

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
    cout <<endl<< "TRI" << endl;
    sortWithFrequency(leaf);
    for (int i = 0; i <leaf.size(); i++) {
        cout << leaf[i]->getValue() << " & " << leaf[i]->getFrequency() << endl;
    }
    cout << endl << "Arbre" << endl;
    //for (int j = 0; j < leaf.size(); j++) {
    while (leaf.size() > 1) {
        Node* l1 = leaf[leaf.size()-1];
        leaf.pop_back();
        Node* l2 = leaf[leaf.size()-1];
        leaf.pop_back();

        leaf.push_back(
            new Node(
            l1->getFrequency() + l2->getFrequency(),
            l2,
            l1
            )
        );
        sortWithFrequency(leaf);
    }

        for (int i = 0; i < leaf.size(); i++) {
            cout << leaf[i]->getValue() << " & " << leaf[i]->getFrequency() << endl;
        }
        map<char, string> dico;
        tableEncode(leaf[0], "", dico);

        
        for (const auto& y : dico) {
            cout << "salut je suis dans la boucle" << endl;
            cout << y.first << " " << y.second << endl;
        }
        //cout << endl << endl;
    //}
    return 0;
}
