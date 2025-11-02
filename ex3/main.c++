#include <iostream>
#include <vector>
#include "Stack.h"

int main() {
    try {
        std::cout << "    Test 1 : Pile d'entiers    \n";
        Stack<int> pileInt(5);
        pileInt.push(10);
        pileInt.push(20);
        pileInt.push(30);
        std::cout << "Contenu de la pile : " << pileInt << "\n";
        std::cout << "Sommet : " << pileInt.peek() << "\n";
        pileInt.pop();
        std::cout << "Après pop : " << pileInt << "\n";

        std::cout << "\n    Test 2 : Pile de chaînes (std::string)    \n";
        Stack<std::string> pileStr(3);
        pileStr.push("Bonjour");
        pileStr.push("C++");
        pileStr.push("Templates");
        std::cout << pileStr << "\n";

        std::cout << "\n   Test 3 : Construction via iterateurs     \n";
        std::vector<int> vec = {1, 2, 3, 4, 5};
        Stack<int> pileVec(vec.begin(), vec.end());
        std::cout << pileVec << "\n";

        std::cout << "\n   Test 4 : Depassement volontaire  \n";
        Stack<int> pilePetite(2);
        pilePetite.push(1);
        pilePetite.push(2);
        pilePetite.push(3);
    } 
    catch (const StackOverflow& e) {
        std::cerr << e.what() << "\n";
    } 
    catch (const StackUnderflow& e) {
        std::cerr << e.what() << "\n";
    } 
    catch (const std::exception& e) {
        std::cerr << "Autre exception : " << e.what() << "\n";
    }

    return 0;
}
