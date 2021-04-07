// Huffman_CAQUELIN_Brieux.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>

/* QUESTION DU PATRON
1) Selon la table ASCII, un caractère peut théoriquement être codé sur combien de
    bit ? et en pratique, sur combien de bit ?

    En théorie un character est codé sur 7 bit parce que Ascii utilise une table binaire mais en pratique cela reviens sur 2 bit parce que c'est de l'hexa en cpp

2) Le message “Coucou” prendrait combien d’espace en mémoire ?
3) Le codage de Huffman va permettre de créer un arbre en fonction du nombre
d’occurrence des caractères. Plus il est présent, plus court sera son code. Pour cela,
    Huffman utilise un arbre binaire. De quoi s’agit-il ?
4) La construction de l’arbre se fait de la façon suivante :
    - Nous calculons le nombre d’occurrence de chaque caractère du texte et les
        mettons par ordre croissant dans une structure de données. Pour chaque
        caractère, nous avons donc leur nombre d’occurrence associé.
    - Nous prenons les deux caractères ayant le moins d’occurrence, nous les
        assemblons ensemble avec un nœud parent qui a pour valeur la somme des
        occurrences de ces deux caractères, nous les enlevons de la structure de
        données et mettons le nœud parent à la place. Ce nœud n’a pas de
        caractère mais servira à l’assemblage de l’arbre.
    - Nous répétons l’étape précédente jusqu'à arriver au dernier caractère, ce
        qui donnera la racine de notre arbre.
    - Cet arbre va nous permettre d’encoder nos caractères. En faisant un
        parcours de la racine vers chaque feuille, nous pouvons savoir l’encodage
        d’un caractère. Si nous prenons le nœud fils gauche, nous ajoutons un 0,
        sinon nous ajoutons un 1. Une fois arrivé à la feuille, nous retournons cette
        suite. Nous pouvons donc créer une table qui associera à chaque caractère
        une suite de 0 et de 1

1) Ajoutez le fichier texte donné en exemple dans votre programme (Mettez le dans
    le même dossier que votre source.cpp et ajoutez le dans le dossier “Fichiers de
    ressources” du projet Visual). Utilisez une bibliothèque qui permet de lire un
    fichier.
2) Mettez l’ensemble du texte présent dans ce fichier dans une variable de votre
    choix. Affichez cette variable dans un cout.
3) Calculez le nombre d’occurrence de chaque caractère de ce fichier et ajoutez les
    dans la structure de donnée de votre choix. N’oubliez pas que vous devez associer
    chaque caractère à son nombre d’occurrence.
4) Afin de faciliter la création de l’arbre de Huffman, mettez en place une classe
    Node qui aura comme attribut une valeur, une fréquence, et des références sur des
    nœuds enfants (gauche et droit). Vous ferez les getter/setter, ainsi que les
    constructeurs en fonction de vos besoins.
5) Créez une structure qui pourra contenir des références sur des nœuds. N’oubliez
    pas que cette structure doit être facilement modifiable et qu’elle doit rester triée
    en permanence. Ajoutez un nœud pour chaque caractère et sa fréquence dans
    cette structure.
6) Tant qu’il reste au moins deux nœuds dans cette structure, on prend les deux
    nœuds ayant le moins d’occurrence, on les enlève de la structure, on crée un
    nœud ayant une référence sur ces deux nœuds en fils gauche d’abord puis fils
    droit. Ce nœud aura sa fréquence égale à la somme de celles de ses deux fils. On
    ajoute enfin ce nœud dans la structure.
7) Créez une structure pouvant associer à chaque caractère une suite de 0 et de 1.
8) Parcourez depuis la racine de l’arbre toutes les branches possibles pour atteindre
    les feuilles. Si on prend une branche vers un fils gauche, on ajoute un 0, si on
    prend une branche vers un fils droit, on ajoute un 1, si on arrive à une feuille, on
    associe la valeur de cette feuille au chemin que nous avons parcouru. Une
    référence vers la structure de données et de la récursivité est vivement
    recommandée.
9) Pour chaque caractère du texte, on remplace le caractère par son code équivalent.
    (N’écrivez pas directement dans le fichier texte, enregistrez la suite de 0 et de 1
    dans une variable). Afficher le codage de Huffman du texte.
10) Faites une méthode pour décoder votre message en utilisant l’arbre déjà créé.
*/
using namespace std;

int main()
{
    fstream file;
    file.open("texteDeChanson.txt");
    char c;
    while (file.get(c)) {
        cout << c;
    }
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
