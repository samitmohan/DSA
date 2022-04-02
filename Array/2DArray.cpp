#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
// Multidimensional Arrays -> vec<vec<int>> row

// 4 row, 3 columns
// int row = 4, column = 3; can store arr[row][column]
// int arr[4][3] =  {{1,2,3}, {4,5,6}, {8,9,10}, {11,12,13}};
// Rows
// for(int i=0;i<4;i++){
// Columns
// for(int j=0;j<3;j++){
// cout << arr[i][j] << " "; // matrix like structure.

// vector inside a vector for multidimensional.

// Another way to define it
// vector<vector<int> vec2 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

// Reading and Printing 2D Array

void readA(int a[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
}

void printA(int a[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Read a list of strings and store them in a 2D array

void string_2d()
{
    char arr[100][1000];
    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        cin.getline(arr[i], 1000);
    }

    // Print out all the strings
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

// Printing using vectors.

void print2D(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            cout << vec[i][j] << endl;
        }
    }
}

// Transpose of 2D Arrays -> Reversing the vector (Swapping values)

void transpose(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            swap(vec[i][j], vec[j][i]);
        }
    }
}

// Rotate by 90 degrees -> Step 1 : Transpose. Step 2 -> Reverse.

void rotate(vector<vector<int>> &vec)
{
    transpose(vec);
    // Reverse every row
    for (int i = 0; i < vec.size(); i++)
    {
        // reverse every row -> just like reversing an array (Two pointer approach)
        int low = 0, high = vec[i].size() - 1; // first row = i.
        while (low < high)
        {
            swap(vec[i][low], vec[i][high]);
            low++;
            high--;
        }
    }
}

int main()
{
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    return 0;
}
