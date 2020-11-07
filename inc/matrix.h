#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    vector<vector<double>> mat;
    size_t n;
    vector<int> index;

    Matrix subMatrix(int k, int m);

    int findMajor(int k);

public:

    Matrix() {}

    Matrix(vector<vector<double>> vec, size_t size) : mat(vec), n(size) {}

    Matrix(size_t n);

    Matrix(const Matrix &another);

    ~Matrix();

    static Matrix getFromFunc(double (*f)(int,int),size_t size);

    Matrix operator=(const Matrix &another);

    Matrix operator*(const Matrix &another) const;

    vector<double> operator*(const vector<double> &vec) const;

    void calcLU();

    Matrix getL() const;

    Matrix getU() const;

    void print(ostream &stream = cout) const;

    int getSumCol(int k);

    size_t getSize() {return n;}

    vector<double> solveL(vector<double> b);

    vector<double> solveU(vector<double> y);

    double determinant();

    vector<double> solve(vector<double> b) {return solveU(solveL(b));}
};