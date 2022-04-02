#include <iostream>
#include <vector>
#include "Matrix.hpp"
using namespace bar;
using namespace std;
Matrix::Matrix(vector<double> data,int n, int m){
    this->n=(size_t)n;
    this->m=(size_t)m;
    if(data.size()!=n*m){
        throw std::runtime_error("data does not fit given size");
    }
    if(n<=0||m<=0){
        throw runtime_error("n and m must be positive!");
    }
    this->matrix = new double*[this->n];
    for(uint i=0;i<n;i++){
        this->matrix[i] = new double[this->m];
    }
    uint k=0;
    for(uint i=0;i<n;i++){
        for(uint j=0;j<m;j++){
            this->matrix[i][j]=data[k++];
        }
    }
}
Matrix::~Matrix(){
    for(size_t i = 0;i<this->n;i++){
        delete [] this->matrix[i];
    }
    delete [] this->matrix;
}
void Matrix::print(){
    uint n = (size_t)this->n;
    uint m = (size_t)this->m;
    for(uint i=0;i<n;i++){
        for(uint j=0;j<m;j++){
            cout<<this->matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

Matrix bar::operator+(const Matrix& a,const Matrix& b) {
    if(a.m!=b.m||a.n!=b.n){
        throw invalid_argument("dimensions are different");
    }
    uint m=(uint)a.m;
    uint n=(uint)a.n;
    vector<double> res;
    uint k=0;
    res.resize(m*n);
    for(uint i=0;i<n;i++){
        for(uint j=0;j<m;j++){
            double firstarg = a.matrix[i][j];
            double secarg = b.matrix[i][j];
            res[k++]=firstarg+secarg;
        }
    }
    return Matrix(res,(int)n,(int)m);
}

