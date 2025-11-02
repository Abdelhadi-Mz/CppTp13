#include <iostream>
#include "Matrice.h"

int main() {
    std::cout << "   Matrices d'entiers   \n";
    Matrice<int, 2, 2> A{{ {1, 2}, {3, 4} }};
    Matrice<int, 2, 2> B{{ {5, 6}, {7, 8} }};
    std::cout << "A =\n" << A;
    std::cout << "B =\n" << B;

    auto C = A + B;
    std::cout << "A + B =\n" << C;

    auto D = A * B;
    std::cout << "A * B =\n" << D;

    std::cout << "\n    Matrices de reels    \n";
    Matrice<double, 2, 3> M1{{ {1.5, 2.2, 3.1}, {4.0, 5.5, 6.3} }};
    Matrice<double, 3, 2> M2{{ {1.0, 0.5}, {2.0, 1.5}, {3.0, 2.5} }};

    std::cout << "M1 =\n" << M1;
    std::cout << "M2 =\n" << M2;

    auto M3 = M1 * M2;
    std::cout << "M1 * M2 =\n" << M3;

    return 0;
}
