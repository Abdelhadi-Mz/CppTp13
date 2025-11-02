#include <iostream>
#include "arraydyn.h"

class Produit {
private:
    std::string nom;
    double prix;
public:
    Produit(std::string n = "", double p = 0.0) : nom(n), prix(p) {}
    friend std::ostream& operator<<(std::ostream& os, const Produit& p) {
        os << p.nom << " (" << p.prix << " DH)";
        return os;
    }
};

int main() {
    ArrayDyn<int> tabInt;
    tabInt.push_back(10);
    tabInt.push_back(20);
    tabInt.push_back(30);

    std::cout << "Contenu du tableau d'entiers : ";
    for (auto &e : tabInt)
        std::cout << e << " ";
    std::cout << "\n";

    ArrayDyn<std::string> tabStr;
    tabStr.push_back("Bonjour");
    tabStr.push_back("C++");
    tabStr.push_back("Templates");

    std::cout << "Contenu du tableau de chaînes : ";
    for (auto &s : tabStr)
        std::cout << s << " ";
    std::cout << "\n";

    ArrayDyn<Produit> tabProd;
    tabProd.push_back(Produit("Stylo", 5.5));
    tabProd.push_back(Produit("Cahier", 12.0));

    std::cout << "Contenu du tableau de produits : ";
    for (auto &p : tabProd)
        std::cout << p << " ";
    std::cout << "\n";

    return 0;
}
