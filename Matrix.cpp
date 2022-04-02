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
            if(this->matrix[i][j]==0){
                res[k++]=0;
                continue;
            }
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

Matrix zich::operator*(const double scalar, const Matrix& a){
    vector<double> res;
    res.resize(a.n*a.m);
    size_t k=0;
    for(size_t i = 0; i<a.m; i++){
        for(size_t j=0; j<a.m; j++){
            res[k++]=a.matrix[i][j]*scalar;
        }
    }
    return Matrix(res,a.n,a.m);
}

Matrix zich::operator*(const Matrix& a,const double scalar){
    return scalar*a;
}

void zich::Matrix::operator*=(const double scalar){
    for(size_t i =0 ;i<this->n;i++){
        for(size_t j=0;j<this->m;j++){
            this->matrix[i][j]*=scalar;
        }
    }
}

void zich::Matrix::operator*=(const Matrix& a){
    if(this->m!=a.n){
        throw invalid_argument("cannot multiply these matrices");
    }
    vector<double> res;
    res.resize(this->n*a.m);
    size_t count=0;
    for(size_t i=0;i<this->n;i++){
        for(size_t j=0;j<a.m;j++){
            for(size_t k=0;k<this->m;k++){
                this->matrix[i][j]=this->matrix[i][k]*a.matrix[k][j];
            };
        }
    }
}

Matrix zich::operator*(const Matrix& a,const Matrix& b){
    if(a.m!=b.n){
        throw invalid_argument("cannot multiply these matrices");
    }
    vector<double> res;
    res.resize(a.n*b.m);
    size_t count=0;
    for(size_t i=0;i<a.n;i++){
        for(size_t j=0;j<b.m;j++){
            double coord=0;
            for(size_t k=0;k<a.m;k++){
                coord+=a.matrix[i][k]*b.matrix[k][j];
            }
            res[count++]=coord;
        }
    }
    return Matrix(res,a.n,b.m);
}

Matrix& zich::Matrix::operator++(){
    for(size_t i=0;i<this->n;i++){
        for(size_t j=0;j<this->m;j++){
            this->matrix[i][j]++;
        }
    }
    return *this;
}

Matrix zich::Matrix::operator++(int){
    Matrix temp = +(*this);
    ++*this;
    return temp;
}

Matrix& zich::Matrix::operator--(){
    for(size_t i=0;i<this->n;i++){
        for(size_t j=0;j<this->m;j++){
            this->matrix[i][j]--;
        }
    }
    return *this;
}

Matrix zich::Matrix::operator--(int){
    Matrix temp = +(*this);
    --*this;
    return temp;
}

ostream& zich::operator<< (ostream& output, const Matrix& a) {
    uint n = (size_t)a.n;
    uint m = (size_t)a.m;
    for(uint i=0;i<n;i++){
        output<<"[";
        for(uint j=0;j<m;j++){
            output<<a.matrix[i][j];
            if(j<m-1){
                output<<" ";
            }
        }
        output<<"]"<<endl;
    }
    return output;   
}