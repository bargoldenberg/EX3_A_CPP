#include <iostream>
#include <vector>
#include "Matrix.hpp"
using namespace zich;
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

void const Matrix::print(){
    uint n = (size_t)this->n;
    uint m = (size_t)this->m;
    for(uint i=0;i<n;i++){
        for(uint j=0;j<m;j++){
            cout<<this->matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

Matrix zich::operator+(const Matrix& a,const Matrix& b) {
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
Matrix zich::operator-(const Matrix& a,const Matrix& b) {
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
            res[k++]=firstarg-secarg;
        }
    }
    return Matrix(res,(int)n,(int)m);
}

Matrix zich::Matrix::operator+(){
    vector<double> res;
    res.resize(this->n*this->m);
    size_t k=0;
    for(size_t i =0;i<this->n;i++){
        for(size_t j = 0;j<this->m;j++){
            res[k++]=this->matrix[i][j];
        }
    }
    return Matrix(res,(int)this->n,(int)this->m);
}

void zich::Matrix::operator+=(const Matrix &a){
     if(a.m!=this->m||a.n!=this->n){
        throw invalid_argument("dimensions are different");
    }
    uint m=(uint)a.m;
    uint n=(uint)a.n;
    vector<double> res;
    uint k=0;
    res.resize(m*n);
    for(uint i=0;i<n;i++){
        for(uint j=0;j<m;j++){
            this->matrix[i][j]+=a.matrix[i][j];
        }
    }
}

Matrix zich::Matrix::operator-(){
    vector<double> res;
    res.resize(this->n*this->m);
    size_t k=0;
    for(size_t i =0;i<this->n;i++){
        for(size_t j = 0;j<this->m;j++){
            res[k++]=this->matrix[i][j]*-1;
        }
    }
    return Matrix(res,(int)this->n,(int)this->m);
}

void Matrix::operator-=(const Matrix &a){
     if(a.m!=this->m||a.n!=this->n){
        throw invalid_argument("dimensions are different");
    }
    uint m=(uint)a.m;
    uint n=(uint)a.n;
    vector<double> res;
    uint k=0;
    res.resize(m*n);
    for(uint i=0;i<n;i++){
        for(uint j=0;j<m;j++){
            this->matrix[i][j]-=a.matrix[i][j];
        }
    }
}

bool zich::operator<(const Matrix& a, const Matrix& b){
    return !(a>=b);
}

bool zich::operator==(const Matrix& a, const Matrix& b){
    double localsum = 0;
    double argsum=0;
    if(a.m!=b.m||a.n!=b.n){
        throw invalid_argument("dimensions are different");
    }
    for(size_t i=0;i<b.n;i++){
        for(size_t j=0;j<b.m;j++){
            if(a.matrix[i][j]!=b.matrix[i][j]){
                return false;
            }
        }
    }
  \
    return true;
}

bool zich::operator>=(const Matrix& a, const Matrix& b){
    double bsum = 0;
    double asum=0;
    for(size_t i=0;i<b.n;i++){
        for(size_t j=0;j<b.m;j++){
            bsum+=b.matrix[i][j];
        }
    }
    for(size_t i=0;i<a.n;i++){
        for(size_t j=0;j<a.m;j++){
            asum += a.matrix[i][j];
        }
    }
    return asum>=bsum;
}


bool zich::operator>(const Matrix& a, const Matrix& b){
    return !(a<=b);
}

bool zich::operator<=(const Matrix& a,const Matrix& b){
    double bsum = 0;
    double asum=0;
    for(size_t i=0;i<b.n;i++){
        for(size_t j=0;j<b.m;j++){
            bsum+=b.matrix[i][j];
        }
    }
    for(size_t i=0;i<a.n;i++){
        for(size_t j=0;j<a.m;j++){
            asum += a.matrix[i][j];
        }
    }
    return asum<=bsum;
}

