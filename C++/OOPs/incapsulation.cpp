#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/* Incapsulation. -> Provides security.

You can't access class members directly.

# Access Modifiers.

# Private -> Can not access outside class.
# Public ->  Can access everywhere (like struct (no security))
# Protected -> Used to inherit

As we've seen in basic concept -> if attributes are public -> they can be accessed from everywhere
                               -> if attributes are private -> they can only be accessed in the class.

How to access private attributes in the main function / some other function? Incapsulation.
*/

class student
{
private:
    string name;
    int roll_number;
    int marks;

public:
    void set_Name(string myName)
    {
        name = myName;
    }

    void set_RollNumber(int myRollNumber)
    {
        roll_number = myRollNumber;
    }

    void set_Marks(int myMarks)
    {
        marks = myMarks;
    }

    string getName()
    {
        return name;
    }

    int getRoll_number()
    {
        return roll_number;
    }

    int getMarks()
    {
        return marks;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // In public, you can change class members according to you from the outisde.
    student s1;
    // s1.name = "Samit";
    // s1.roll_number = 12;
    // s1.marks = 80;
    // cout << s1.name << " " << s1.marks << " " << s1.roll_number << endl;

    // Incapsulation does not allow this, you can still change the class members but you have to follow some rules.

    // If it's private and you still want to access it -> write some function (set, get) -> call it in main function.
    s1.set_Name("Samit");
    s1.set_Marks(100);
    s1.set_RollNumber(147);

    cout << s1.getName() << "\n";
    cout << s1.getRoll_number() << "\n";
    cout << s1.getMarks() << "\n";

    // Why do we do this? to get more control of our program. According to us, abstraction is taking place.
    // eg -> We only need to show marks of students who have failed (< 40%) -> we can do (if(marks < 40) return ;) in set_Marks
    // Only marks < 40 will be displayed then. We have more control of the program when we do incapsulation (provide security)
    // You can't change my things directly, it's restricted. All rules are set by the user.

    return 0;
}
