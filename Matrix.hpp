#include <iostream>
#include <vector>
using namespace std;
namespace zich{
    class Matrix
    {
        private:
            
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
    };
    Matrix operator+(const Matrix& a,const Matrix& b);
    Matrix operator-(const Matrix& a,const Matrix& b);
    bool operator<(const Matrix& a, const Matrix& b);
    bool operator==(const Matrix& a, const Matrix& b);
    bool operator<=(const Matrix& a, const Matrix& b);
    bool operator>(const Matrix& a, const Matrix& b);
    bool operator>=(const Matrix& a, const Matrix& b);

}


