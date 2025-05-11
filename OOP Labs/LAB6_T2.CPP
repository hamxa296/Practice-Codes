#include <iostream>
using namespace std;
class Matrix_Analyzer
{
protected:
    int matrix[2][2];
    int size;

public:
    Matrix_Analyzer()
    {
        size = 2;

        cout << "Enter the matrix elements: "
             << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: " << endl;
                cin >> matrix[i][j];
            }
        }
    }
};
class Identity_Matrix_Checker : public Matrix_Analyzer
{
public:
    void Display()
    {
        cout << "Matrix elements: " << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void Identity_Check()
    {
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j && matrix[i][j] != 1)
                {
                    flag = 1;
                    break;
                }
                else if (i != j && matrix[i][j] != 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            cout << "Matrix is an identity matrix!" << endl;
        }
        else
        {
            cout << "Matrix is not an identity matrix!" << endl;
        }
    }
};
int main()
{
    Identity_Matrix_Checker m1;

    m1.Display();

    m1.Identity_Check();

    return 0;
}