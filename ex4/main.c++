#include <iostream>
#include <vector>
#include <string>
#include "Sorter.h"

struct Etudiant {
    std::string nom;
    int age;

    bool operator<(const Etudiant& other) const {
        return age < other.age;
    }

    bool operator>(const Etudiant& other) const {
        return age > other.age;
    }

    friend std::ostream& operator<<(std::ostream& os, const Etudiant& e) {
        os << e.nom << " (" << e.age << ")";
        return os;
    }
};

int main() {
    std::vector<int> nums = {5, 3, 8, 1, 9};
    std::vector<std::string> mots = {"pomme", "banane", "orange"};
    std::vector<Etudiant> etudiants = {{"Alice", 20}, {"Bob", 22}, {"Charlie", 19}};

    quickSort(nums, Asc<int>{});
    quickSort(mots, Desc<std::string>{});
    quickSort(etudiants, Asc<Etudiant>{});

    std::cout << "Entiers tries: ";
    for (auto n : nums) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "Mots tries (desc): ";
    for (auto& m : mots) std::cout << m << " ";
    std::cout << "\n";

    std::cout << "Etudiants tries par age: ";
    for (auto& e : etudiants) std::cout << e << " | ";
    std::cout << "\n";

    return 0;
}

