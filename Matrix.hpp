#include <iostream>
#include <vector>
using namespace std;
namespace zich{
    class Matrix
    {
        public:
            double** matrix;
            size_t n;
            size_t m;
            Matrix(vector<double> data,int n,int m);
            ~Matrix();
            void const print();
            void operator+=(const Matrix& a);
            void operator-=(const Matrix& a);
            Matrix operator-();
            Matrix operator+();
            void operator*=(const double scalar);
            void operator*=(const Matrix& a);
            Matrix& operator++();
            Matrix operator++(int);
            Matrix& operator--();
            Matrix operator--(int);
    };
    Matrix operator+(const Matrix& a,const Matrix& b);
    Matrix operator-(const Matrix& a,const Matrix& b);
    Matrix operator*(const double scalar,const Matrix& a);
    Matrix operator*(const Matrix& a,const double scalar);
    Matrix operator*(const Matrix& a,const Matrix& b);
    bool operator<(const Matrix& a, const Matrix& b);
    bool operator==(const Matrix& a, const Matrix& b);
    bool operator<=(const Matrix& a, const Matrix& b);
    bool operator>(const Matrix& a, const Matrix& b);
    bool operator>=(const Matrix& a, const Matrix& b);
    ostream& operator<< (ostream& output, const Matrix& a);
    ostream& operator>> (ostream& intput, const Matrix& a);
}


