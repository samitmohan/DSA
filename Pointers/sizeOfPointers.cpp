#include <iostream>
using namespace std;

void print(int arr[])
{
  cout << arr << endl;
  cout << "sizeof print " << sizeof(arr) << endl; // size of pointer because address is passed
}

void print2(int *arr)
{
  cout << arr << endl;
  cout << "sizeof print2 : " << sizeof(arr) << endl; // size of pointer
}

void print3(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    // cout << arr[i] << " ";
    // same as
    cout << *(arr + i) << " ";
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4};

  cout << arr << endl;
  cout << &arr << endl;
  print(arr);
  print2(arr);
  // print2(&arr[0]);

  cout << "sizeof in main : " << sizeof(arr) << endl; // gives size of entire array
  cout << "sizeof in main : " << sizeof(&arr) << endl;

  print3(arr, 4);

  int c[] = {6, 7, 8, 9};
  int *b = c;
  cout << b[3];
  // same as
  cout << *(b + 3);

  return 0;
}
