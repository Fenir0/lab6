#include "matr.h"
#include <iomanip>
#include <cstdlib>
int matrix::id_count = 0;

matrix::matrix(){
        id = id_count;
        id_count++;
        mt = new int*[2];
        n = 2, m = 2;
        for(int i = 0; i < m; i++){
            mt[i] = new int[2];
            for(int j = 0; j < n; j++){
                mt[i][j] = 0;
            }
        }
    }
matrix::matrix(int c_m, int c_n){
    srand(matrix::id_count);
    id = id_count;
    id_count++;
    mt = new int*[c_m];
    n = c_n, m = c_m;
    for(int i = 0; i < c_m; i++){
        mt[i] = new int[c_n];
        for(int j = 0; j < c_n; j++){
            mt[i][j] = std::rand()%20;
        }
    }    
   // std::cout << mt << ' ' << id << " CREATED" << '\n';
}

matrix::matrix(const matrix& res){
    m = res.m;
    n = res.n;
    id = res.id;
    mt = new int*[res.m];
    for(int i = 0; i < res.m; i++){
        mt[i]= new int[res.n];
        for(int j = 0; j < res.n; j++){
            mt[i][j] = res.mt[i][j];
        }
    }
}

matrix::~matrix(){
    for(int i = 0; i < m; i++){
        delete[] mt[i];
    }
    delete[] mt;
}

matrix matrix::operator+(matrix& res){
    matrix dummy (m, n);
    try{
        operate('+', &dummy, &res);
        return dummy;
    }
    catch (std::exception err) {
        std::cout << err.what();
    }
    return *this;
}
matrix matrix::operator-(matrix& res){
    matrix dummy (m, n);
    try{
        operate('-', &dummy, &res);
        return dummy;
    }
    catch (std::exception err) {
        std::cout << err.what();
    }
    return *this;
}
matrix matrix::operator*(int num){
    matrix dummy (m, n);
    operate('*', &dummy, nullptr, num);
    return dummy;
}
matrix matrix::operator*(matrix& res){ 
    if(res.m != n){
        throw std::runtime_error("Wrong dimensions");
    }
    matrix tmp(m, res.n);
    int s;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < res.n; j++){
            s = 0;
            for(int k = 0; k < n; k++){
                s += mt[i][k]*res.mt[k][j];
            }
            tmp.mt[i][j] = s;
        }
    }
    return tmp;  
}

matrix matrix::operator=(const matrix& res){
    m = res.m;
    n = res.n;
    for(int i = 0; i < m; i++){
        delete[] mt[i];
    }
    delete[] mt;
    mt = new int*[res.m];
    for(int i = 0; i < res.m; i++){
        mt[i] = new int[n];
        for(int j = 0; j < res.n; j++){
            mt[i][j] = res.mt[i][j];
        }
    }
    return *this;
}
bool matrix::operator==(matrix& res){
    try{
        return operate('=', nullptr, &res);
    }
    catch (std::exception err) {
        std::cout << err.what();
    }
    return false;
}

bool matrix::operate(char operation, matrix* dummy, matrix* res, int temp){
    if(res && (res->m != m || res->n != n)){
        throw std::runtime_error("\nError: different dimensions\n");
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            switch (operation){
                case '-':
                    dummy->mt[i][j] = mt[i][j] - res->mt[i][j];
                    break;
                case '+':
                    dummy->mt[i][j] = mt[i][j] + res->mt[i][j];
                    break;
                case '*':
                    dummy->mt[i][j] = mt[i][j] * temp;
                    break;
                case '=':
                    if(res->mt[i][j] != mt[i][j]){
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
    }
//    std::cout << *dummy;
    return true;
}
 
int matrix::max(){
    int s;
    for(int i = 0; i < m; i++){
        if(i == 0) s = mt[i][0];
        for(int j = 0; j < n; j++){
            s = std::max(s, mt[i][j]);
        }
    }
    return s;
}

std::ostream& operator<<(std::ostream& s, const matrix& res){
   // std::cout << res.mt << ' ' << res.id << '\n';
    for(int i = 0; i < res.m; i++){
        for(int j = 0; j < res.n; j++){
            s << std::setw(4) << (res.mt[i][j]) << " ";
        }
        s << "\n";
    }
    return s;
}
std::istream& operator>>(std::istream& s, matrix& res){
    for(int i = 0; i < res.m; i++){
        for(int j = 0; j < res.n; j++){
            s >> (res.mt[i][j]);
        }
    }
    return s;
}
