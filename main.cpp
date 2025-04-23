#include "src/matr.h"
#include "src/sq_matr.h"
#include<iostream>
using std::cout;
using std::cin;

int main(){
    matrix x1(3, 5);
    cout << "Randomly created matrix:\n" << x1 << "\n_ _ _ _ _ _ _\n";
    matrix x2(3, 5);
    cout << "Inputing a matrix:\n";
    cin >> x2;
    cout << "X1 is equal to X2? " << (x1 == x2?"YES":"NO") << '\n';
    cout << "\nAddition\n";
    cout << x1 + x2 << '\n';
    cout << "\nSubstraction\n";
    cout << x1 - x2 << '\n';
    cout << "\nMultiplication by a number [5]\n";
    cout << x1 * 5 << '\n';
    cout << "\n_ _ _ _ _ _ _\n";
    matrix x3(5, 3);
    cout << x1 << "\n_\n" << x3;
    cout << "\nMultiplication by a matrix\n";
    cout << x1*x3;
    square_matrix m1 (4);
    cout << m1 << '\n';
    cout << "\nDeterminant:\n" << m1.determinant() << '\n';
    cout << "\nSymmetrical:\n" << (m1.is_symmetrical()?"YES":"NO") << '\n';
    cout << "\n in power of 2:\n" << m1.power(2);

}
