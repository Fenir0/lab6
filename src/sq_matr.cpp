#ifndef SQ_MATRIX
#define SQ_MATRIX

#include "sq_matr.h"
#include<cmath>

square_matrix::square_matrix(): matrix() {}
square_matrix::square_matrix(int n):matrix(n,n){
}



square_matrix& square_matrix::operator*(square_matrix& res){ 
    if(res.m != n){
        throw "\nError: different dimensions\n";
    }
    square_matrix tmp(m);
    int s;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            s = 0;
            for(int k = 0; k < m; k++){
                s += mt[i][k]*res.mt[k][j];
            }
            tmp.mt[i][j] = s;
        }
    }
    *this = tmp;
    return *this;  
}

int square_matrix::determinant(){
    if(n>2){
        int d = 0;
        for(int pos = 0; pos < m; pos++){
            square_matrix tmp(m-1);
            int it = 0, jt = 0;
            for(int i = 0; i < m; i++){
                if(i == pos) continue;
                for(int j = 1; j < n; j++){
                    tmp.mt[it][jt++] = mt[i][j];
                }
                it++;
                jt = 0;
            }
            d += mt[pos][0] * tmp.determinant() * std::pow(-1,pos);
        }
        return d;
    }
    else{
        return mt[0][0]*mt[1][1]-mt[0][1]*mt[1][0];
    }
}
bool square_matrix::is_symmetrical(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mt[i][j] != mt[j][i]) 
                return false;
        }
    }
    return true;
}
square_matrix square_matrix::power(int n){
    if(n < 1) throw std::runtime_error("Wrong power\n");
    square_matrix res = *this;
    if(n == 1){
        for(int i = 0; i < res.m; i++){
            for(int j = 0; j < res.n; j++){
                res.mt[i][j] = (i==j?1:0);
            }
        }
        return res;
    }
    for(int i = 1; i < n; i++){
        res = (*this) * res;
    }
    return res;
}


#endif