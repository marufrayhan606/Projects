/*
            ====================================================
            ||         Created By: Md. Maruf Rayhan           ||
            ||            ID: 0242320005341623                ||
            ||               Happy Coding :D                  ||
            ====================================================
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "***************************************************************" << endl;
    cout << "**                                                           **" << endl;
    cout << "*** Minor && Cofactor Calculator for (1 to 4) Square Matrix ***" << endl;
    cout << "**                                                           **" << endl;
    cout << "***************************************************************" << endl;

    int size, sl;

    cout << "Select the size of the matrix: " << endl;
    cout << "1. 1X1 Matrix" << endl;
    cout << "2. 2X2 Matrix" << endl;
    cout << "3. 3X3 Matrix" << endl;
    cout << "4. 4X4 Matrix" << endl;
    cout << "Select: ";
    cin >> sl;
    while (sl < 1 || sl > 4)
    {
        cout << "Invalid Selection !!! Try again" << endl;
        cout << "Select: ";
        cin >> sl;
    }
    switch (sl)
    {
    case 1:
        size = 1;
        break;
    case 2:
        size = 2;
        break;
    case 3:
        size = 3;
        break;
    case 4:
        size = 4;
        break;
    }

    int matrix[size][size];

    cout << "Enter the elements of the matrix: " << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    if (size == 1)
    {
        cout << "No Minor & Co-factor for 1X1 Matrix" << endl;
        return 0;
    }

    cout << "Enter the position to find the Minor & Co-factor : ";
    int row, column;
    cin >> row >> column;

    int minor[size - 1][size - 1];
    int x = 0, y = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == row - 1)
        {
            continue;
        }
        y = 0;
        for (int j = 0; j < size; j++)
        {
            if (j == column - 1)
            {
                continue;
            }

            minor[x][y] = matrix[i][j];
            y++;
        }
        x++;
    }

    int determinant;
    if (size == 2)
    {
        determinant = minor[0][0];
    }
    else if (size == 3)
    {
        determinant = (minor[0][0] * minor[1][1]) - (minor[0][1] * minor[1][0]);
    }
    else if (size == 4)
    {
        determinant = (minor[0][0] * ((minor[1][1] * minor[2][2]) - (minor[1][2] * minor[2][1]))) - (minor[0][1] * ((minor[1][0] * minor[2][2]) - (minor[1][2] * minor[2][0]))) + (minor[0][2] * ((minor[1][0] * minor[2][1]) - (minor[1][1] * minor[2][0])));
    }

    int sign = (row + column) % 2 == 0 ? 1 : -1;
    cout << "Minor: " << determinant << endl;
    cout << "Co-factor: " << sign * determinant << endl;
}