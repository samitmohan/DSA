#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/*
# Inheritance -> Inheriting Data from main class (template)

class car{

}

class bus{

}

class truck{

}


Some things are common between those classes. Why to use those things again?

Make a parent class.
class vehicle{
    # common items (tyre, color, mileage etc)

}

Now if we have to make a new class of vehicle type, just inherit.
Make a child class (which inherits from the parent class)

class car : public vehicle {
    // template made, all items inherited from vehicle.

    properties of car (unique ppt of just that car) can also be there.

}
*/

/*
# Polymorphism = 2 Types (Compile time & Run time)
Compile Time = 2 tyre functions but are different, first one (parent class) attributes will be used even if it points to child class.
void tyre(int a, int b)
{

}

void tyre(int a)
{

}


Runtime  = 2 tyre functions but only one is used (attribute of the class it's currently pointing to)
$type1
void tyre(int a, int b)
{

}

I want to use this tyre function and not the above one, how? by adding 'virtual' in front of it.
$type2
virtual void tyre(int a, int b) 
{

}

Now the program knows if it's pointing to a class which has type2 property, it should use that instead of using type1 default property.
*/

class vehicle
{
public:
    int mileage;
    int door;
    // default constructor
    vehicle()
    {
    }

    // methods
    void tyre(int a, int b)
    {
        cout << "Vehicle has " << a << " black tyre " << b << " white tyre "
             << "\n";
    }

    // using virtual here = runtime polymorphism (makes sure if vehicle is pointing to another class -> it uses property of that class and not this.)
    virtual void move()
    {
        cout << "Vehicle can move anywhere "
             << "\n";
    }
};

// Inheritance = Inherit from vehicle (class child : address modifier parent)
class car : public vehicle
{
public:
    int seat;
    // Unique property of car.
    void move()
    {
        cout << "Car can move anywhere"
             << "\n";
    }

    void tyre(int a, int b)
    {
        cout << "Car has " << a << " yellow tyres"
             << " and " << b << " blue tyres "
             << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // vehicle vc;
    // vehicle * vc_ptr = &vc;
    // can do this also (using heap memory)
    vehicle *vc_ptr = new vehicle;
    // (*vc_ptr).door = 4;
    // or
    vc_ptr->door = 4;
    // (*vc_ptr).mileage = 40
    // or
    vc_ptr->mileage = 60;

    cout << vc_ptr->door << "\n";
    vc_ptr->tyre(3, 2);

    // Car (using heaps (new car() and c -> ))

    car *c1 = new car();
    // Inherits all properties (move, tyre, door, mileage etc)
    c1->move();
    // prints vehicle can move anywhere
    // we can override this by void move() in car (unique property)
    // now it prints car can move anywhere

    // Parent class vehicle (v1) pointing to child class car
    vehicle *v1 = new car();
    /* 
    what should this print? Car can move anywhere? (This should be the answer but it is not -> Hence we use polymorphism)
    (when it did new car(); it doesnt overrides it's move property to the one that class car has)
    prints Vehicle can move anywhere and not Car can move anywhere

    The above prints by rules of vehicle class and not car class. What to do if I want to make sure it runs by car Class and over rides vehicle class

    Hence we use the keyword 'virtual' in the main vehicle class (Runtime Polymorphism) so it lets it know that whenever you're pointing to a different class
    (in this case car instead of vehicle) use the properties of car and not vehicle.
    */

    // Now this should print car can move anywhere instead of vehicle can move anywhere
    v1->move();

    return 0;
}
