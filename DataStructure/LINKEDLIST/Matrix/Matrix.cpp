#include<iostream>
#include<algorithm>
using namespace std;
class SparseMatrix;
class MatrixTerm
{
    friend class SparseMatrix;
private:
    int row, col, value;
};
class SparseMatrix
{
private:
    int rows, cols, terms, capacity;
    MatrixTerm* smArray;
public:
    SparseMatrix(int r, int c, int t) {
        rows = r;
        cols = c;
        terms = t;
        capacity = t + 1;
        smArray = new MatrixTerm[capacity];
    };
    SparseMatrix Transpose();
    void Input() {
        int nPos = 0;
        while (nPos < terms)
        {
            cin >> this->smArray[nPos].row;
            cin >> this->smArray[nPos].col;
            cin >> this->smArray[nPos].value;
            nPos++;
        }
    }
    void Output() {
        int nPos = 0;
        while (nPos < terms)
        {
            cout << this->smArray[nPos].row << this->smArray[nPos].col << this->smArray[nPos].value << endl;
            nPos++;
        }
    }
};
SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix b(cols, rows, terms);
    if (terms > 0)
    {
        int currentB = 0;
        for (int c = 0; c < cols; c++)
            for (int i = 0; i < terms; i++)
                if (smArray[i].col == c)
                {
                    b.smArray[currentB].row = c;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB++].value = smArray[i].value;
                }
    }
    return b;
}
int main()
{
    int r, c, t, v;
    cin >> r >> c >> t;
    SparseMatrix a(r, c, t), b(r, c, t);
    a.Input();
    b = a.Transpose();
    b.Output();
    return 0;
}
