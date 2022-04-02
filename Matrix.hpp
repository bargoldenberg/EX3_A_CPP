#include <iostream>
#include <vector>
using namespace std;
namespace bar{
    class Matrix
    {
    private:
        
    public:
        double** matrix;
        size_t n;
        size_t m;
        Matrix(vector<double> data,int n,int m);
        ~Matrix();
        void print();
    };
    Matrix operator+(const Matrix& a,const Matrix& b);
}


