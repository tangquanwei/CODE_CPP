#include <iostream>
using namespace std;

class Matrix
{
private:
    int n;           //* 阶数
    double **matrix; //* 矩阵

public:
    Matrix(int n = 3, int input = 0) : n(n)
    {
        matrix = new double *[n];
        for (int i = 0; i < n; ++i)
            matrix[i] = new double[n];
        if (input)
        {
            cout << "Input " << endl;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    cin >> matrix[i][j];
        }
        else
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = (j == i ? 1 : 0);
        }
    }
    Matrix(const Matrix &m)
    {
        n = m.n;
        matrix = new double *[n];
        for (int i = 0; i < n; ++i)
            matrix[i] = new double[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] = m.matrix[i][j]; //! Sagmentation Fault
    }
    ~Matrix()
    {
        for (int i = 0; i < n; ++i)
            delete[] matrix[i];
        delete[] matrix;
        matrix = nullptr;
    }
    void printMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << this->matrix[i][j] << "  ";
            cout << endl;
        }
    }

    Matrix &operator=(const Matrix &m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] = m.matrix[i][j];
        return *this;
    }
    Matrix &operator+=(const Matrix &m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                this->matrix[i][j] += m.matrix[i][j];
        return *this;
    }
    Matrix &operator-=(const Matrix &m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                this->matrix[i][j] -= m.matrix[i][j];
        return *this;
    }
    Matrix &operator*=(const double k)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                this->matrix[i][j] *= k;
        return *this;
    }
    double calRowCol(const Matrix &m1, const Matrix &m2, int row, int col)
    {
        double result = 0;
        for (int j = 0; j < m1.n; ++j)
            result += m1.matrix[row][j] * m2.matrix[j][col];
        return result;
    }
    // Matrix &operator*=(const Matrix &m)
    // {
    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < n; j++)
    //             matrix[i][j] = calRowCol(*this, m, i, j);
    //     return *this;
    // }
    int *MatrixMul(int *a, int *b, int *c, int n)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                *(c + i * n + j) = 0;
                for (int k = 0; k < 3; k++)
                {
                    *(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
                }
            }
        return c;
    }
    Matrix &operator*=(const Matrix &m)
    {
        Matrix temp(n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                temp.matrix[i][j] = 0;
                for (int k = 0; k < n; ++k)
                    temp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        *this = temp;
        return *this;
    }
    Matrix operator*(const double k)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] *= k;
        return *this;
    }
    Matrix operator*(const Matrix &m)
    {
        Matrix temp = m;
        temp *= *this;
        return temp;
    }
    Matrix operator+(const Matrix &m)
    {
        Matrix temp = m;
        temp += *this;
        return temp;
    }
    Matrix operator-(const Matrix &m)
    {
        Matrix temp = *this;
        temp -= m;
        return temp;
    }
    Matrix &operator++()
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < this->n; ++j)
                matrix[i][j] += 1;
        return *this;
    }
    Matrix &operator--()
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < this->n; ++j)
                matrix[i][j] -= 1;
        return *this;
    }
    Matrix operator++(int)
    {
        Matrix *m = this;
        return ++(*m);
    }
    Matrix operator--(int)
    {
        Matrix *m = this;
        return --(*m);
    }
    Matrix &transpose()
    {
        double k;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
            {
                k = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = k;
            }
        return *this;
    }
    friend istream &operator>>(istream &is, const Matrix &m)
    {
        cout<<"请输入矩阵"<<m.n<<" x "<<m.n<<endl;
        for (int i{0}; i < m.n; ++i)
            for (int j{0}; j < m.n; ++j)
                is >> m.matrix[i][j];
        return is;
    }
    friend ostream &operator<<(ostream &os, const Matrix &m)
    {
        for (int i{0}; i < m.n; ++i)
        {
            cout.setf(ios::left);
            for (int j{0}; j < m.n; ++j)
            {
                cout.width(5);
                cout << m.matrix[i][j];
            }
            cout << endl;
        }
        return os;
    }
};
int main()
{
    Matrix m1(3, 0), m2(3, 0);
    cout << m1;
    // (m1 * m2).printMatrix();
    // cout<<m2;

    return 0;
}
