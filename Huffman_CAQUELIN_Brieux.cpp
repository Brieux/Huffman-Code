#include <fstream>
#include <map>
#include <vector>
#include <algorithm> 
#include <windows.h>
#include "Node.h"

using namespace std;

string encodeText(map<char, string> dict, string textToConvert) {
    string result;
    for (int i = 0; i < textToConvert.size(); i++) {
        Sleep(3);
        cout << dict[textToConvert[i]];
        result += dict[textToConvert[i]];
    }
    return result;
}

void decodeText(Node* tree, map<string, char>dict, int& index, string text) {
    if (tree == nullptr){
        return;
    }

    if (!tree->getChild('l') && !tree->getChild('r')) {
        
        cout << tree->getValue();
        return;
    }
    index = index + 1;
    if (text[index] == '0') {
        decodeText(tree->getChild('l'), dict, index, text);
    }
    else {
        decodeText(tree->getChild('r'), dict, index, text);
    }
}

void tableEncode(Node* tree, string binary, map<char, string>& dict, int i) {

    if ((tree == nullptr)){
        return;
    }

    if (!tree->getChild('l') && !tree->getChild('r')) {
        dict[tree->getValue()] = binary;
        return;
    }
    tableEncode(tree->getChild('r'), binary + "1", dict, i++);
    tableEncode(tree->getChild('l'), binary + "0", dict,i++);
}

void sortWithFrequency(vector<Node *> v) {
    for (int j = 0; j < v.size() - 1; j++) {
        for (int i = 0; i < v.size() - j - 1; i++) {


            if (v[i]->getFrequency() < v[i + 1]->getFrequency()) {
                Node tampon(v[i]->getValue(), v[i]->getFrequency(), v[i]->getChild('l'), v[i]->getChild('r'));

                v[i]->setValue(v[i + 1]->getValue());
                v[i]->setFrenquency(v[i + 1]->getFrequency());
                v[i]->setChild('l', v[i + 1]->getChild('l'));
                v[i]->setChild('r', v[i + 1]->getChild('r'));

                v[i + 1]->setValue(tampon.getValue());
                v[i + 1]->setFrenquency(tampon.getFrequency());
                v[i + 1]->setChild('l', tampon.getChild('l'));
                v[i + 1]->setChild('r', tampon.getChild('r'));

            }
        }
    }
}

int main()
{
    fstream file;
    file.open("texteDeChanson.txt");
    string text;
    map<char, int> cTab;
    char c;
    vector<Node *> leaf;
    /*------------------------------------------------------------------------------------------------------------*/
    while (file.get(c)) {
        map<char, int>::iterator it = cTab.find(c);
        text += c;
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
    /*------------------------------------------------------------------------------------------------------------*/
    cout <<endl<< "TRI" << endl;
    sortWithFrequency(leaf);
    for (int i = 0; i <leaf.size(); i++) {
        cout << leaf[i]->getValue() << " & " << leaf[i]->getFrequency() << endl;
    }
    /*------------------------------------------------------------------------------------------------------------*/
    cout << endl << "Arbre" << endl;
    while (leaf.size() > 1) {
        Node* l1 = leaf[leaf.size()-1];
        leaf.pop_back();
        Node* l2 = leaf[leaf.size()-1];
        leaf.pop_back();
        leaf.push_back(
            new Node(
                l1->getFrequency() + l2->getFrequency(),
                l1,
                l2
            )
        );
        sortWithFrequency(leaf);
    }

    for (int i = 0; i < leaf.size(); i++) {
        cout << leaf[i]->getValue() << " & " << leaf[i]->getFrequency() << endl<< endl;
    }
    /*------------------------------------------------------------------------------------------------------------*/
    map<char, string> dicoE;
    map<string, char> dicoD;

    tableEncode(leaf[0], "", dicoE,0);
    for (pair<char, string> p : dicoE) {
        dicoD[p.second] = p.first;
    }
    /*------------------------------------------------------------------------------------------------------------*/
    string convert;
    convert = encodeText(dicoE, text);
    cout << convert << endl<< endl;

    int index =-1;
    while (index < int(convert.size() - 1)) {
        decodeText(leaf[0], dicoD, index, convert);
    }
    return 0;
}
