#include <fstream>
#include <map>
#include <vector>
#include <algorithm> 
#include "Node.h"

using namespace std;

struct tree {
    vector<Node> leaf;
} tree;

void sortWithFrequency(vector<Node> &v) {
    for (int j = 0; j < v.size() - 1; j++) {
        for (int i = 0; i < v.size() - j - 1; i++) {


            if (v[i].getFrequency() < v[i + 1].getFrequency()) {
                Node tampon(v[i].getValue(), v[i].getFrequency());
                v[i].setValue(v[i + 1].getValue());
                v[i].setFrenquency(v[i + 1].getFrequency());
                v[i + 1].setValue(tampon.getValue());
                v[i + 1].setFrenquency(tampon.getFrequency());

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
        Node l(p.first, p.second);
        tree.leaf.push_back(l); //ajout de la feuille dans l'arbres    
    }
    /*
    for (int i = 0; i < tree.leaf.size(); i++) {
        cout << tree.leaf[i].getValue() << " & " << tree.leaf[i].getFrequency() << endl ;
    }
    cout << endl << endl;*/
    sortWithFrequency(tree.leaf);

    /*for (int i = 0; i < tree.leaf.size(); i++) {
        cout << tree.leaf[i].getValue() << " & " << tree.leaf[i].getFrequency() << endl;
    }*/
    for (int j = 0; j < tree.leaf.size() - 1; j++) {
        for (int i = tree.leaf.size() - 1; i > 1; i = i - 2) {
            Node l1(tree.leaf[i].getValue(), tree.leaf[i].getFrequency());
            tree.leaf.pop_back();
            Node l2(tree.leaf[i - 1].getValue(), tree.leaf[i - 1].getFrequency());
            tree.leaf.pop_back();
            Node branch('|', l1.getFrequency() + l2.getFrequency());
            branch.setChild('l', l2);
            branch.setChild('r', l1);
            tree.leaf.push_back(branch);
            sortWithFrequency(tree.leaf);
        }

        for (int i = 0; i < tree.leaf.size(); i++) {
            cout << tree.leaf[i].getValue() << " & " << tree.leaf[i].getFrequency() << endl;
        }
    }
    /*
    cout << tree.leaf[1].getChild('r')->getValue() << endl;*/
    return 0;
}
