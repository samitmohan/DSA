#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// all things we deal is are objects (boss, mom, father) -> code should be similar to real life.
// Every object has a property (attributes)
// Every student will have a name, age etc properties.
// Every teacher will have a name, qualifiaction etc properties.

// By default -> everything in class is private, you can access them inside the class but not somewhere else (main function)
// For that -> make it public so it can be used everywhere.
// Difference between C and C++. (struct)

/*
# Template Student (Blueprint)
    -> Age
    -> Roll Number
    -> Name

Create student 1 -> the above template will be automatically enabled.

This blueprint/template is called a "Class"
Each of these individual instance is called an "Object" (students)

Class -> Blueprint. 
*/


class student
{
public:
    // attributes
    string name;
    int roll_number;
    int marks;

    // constructor

    student(string myName, int myRoll_Number, int myMarks)
    {
        name = myName;
        roll_number = myRoll_Number;
        marks = myMarks;
    }

    // Overloading the default constructor because there is a constructor (which we made) above this, so C++ doens't make the default constructor and hence it'll show error, to overload it, we create our new constructor.

    // C++ has a default constructor (no parameters) -> Overload it.
    student()
    {
    }
};

bool comparison(student &a, student &b)
{
    return a.roll_number > b.roll_number; // Decreasing
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // will throw error now (not accessible) unless we use public.
    student s1;
    s1.name = "Samit";
    s1.roll_number = 147;
    s1.marks = 100;
    cout << s1.name << " " << s1.roll_number << " " << s1.marks << "\n";

    // We have to write s1.name, s1.roll_number, s1.marks everytime,
    // better way to do this -> Constructors.
    // What if instead of just name, roll_number, marks (3), there are 100 items. How will you print all of it? In one line? CONSTRUCTORS.

    // Constructor name should be the same as class name + No return type.
    //student s2 = {"Samit", 147, 100};
    //cout << s2.name << " " << s2.roll_number << " " << s2.marks << "\n";

    // Another method.
    // What is s2? instance / object of a class.

    student s2("Samit", 20, 100);
    cout << s2.name << " " << s2.roll_number << " " << s2.marks << "\n";

    // Vectors + Classes

    vector<student> arr = {{"Samit", 20, 100}, {"Mohan", 10, 112}};
    //for(student x : arr)
    //{
    //cout << x.name << " " << x.marks << " " << x.roll_number << "\n";
    //}

    // Sort on the basis of marks.
    sort(arr.begin(), arr.end(), [](student &a, student &b)
         {
             // desc order (return true / false)
             return a.marks > b.marks;
         });

    // Print (Mohan, Samit) {basis of marks (112 > 100)}
    for (student x : arr)
    {
        cout << x.name << " " << x.marks << " " << x.roll_number << "\n";
    }

    // Same goes for asc order or on the basis of any attribute.

    // Another method.
    sort(arr.begin(), arr.end(), comparison); // comparison function seperately written.

    // this keyword.
    // If we have something like this, wont the program get confused on what variable to use?

    // student(string name, int roll, int marks)
    // {
    //  name = name;
    //  roll = roll;
    //  marks = marks;
    // }

    // To solve this, we use "this" keyword
    // student(string name, int roll, int marks)
    // {
    //  this -> name=name;
    //  this -> roll = roll;
    //  this -> marks = marks;
    // }

    return 0;
}
