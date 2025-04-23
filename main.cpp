#include "src/matr.h"
#include "src/sq_matr.h"
#include<iostream>
using std::cout;
using std::cin;

int main(){
    matrix x1(5, 5);
    matrix x2(3, 3);
    cout << x1;
    cout << "_\n";
    x1 = x1 * x2;
    cout << x1;
}
