# Abstraction -> Hide data that is unneccessary

How does car work how does engine work lock key? No need to know.
I just need to know that if I insert key, car will start.

<!-- The user doesn't need to know the insides of the process, it should just work. -->

class vehicle
{
    void f1()
    {

    }

    virual void f2() = 0; // do-nothing function (Can't call it) or pure virtual function
    {
        dangerous code
    }
}


You can't invoke this. You can't use f2. You can't create an object of f2 function.
Then what's the use? It's the same as knowing how inside of a car works and just driving the car.

What's the use?

Example -> First car made. Working of the Engine and lock key system,
I don't want any user of the car to know how the car is actually working,
it's not useful for them, I just want them to drive.

# But other car makers (Mercedes, Audi etc) should know how a car is made so they can call the f2 function and use it whenever they want.

class new_car : public vehicle
{
    # when another company is making a car, they can use f2 (after defining it)
    you have to define f2().
    c1.f2() now you can use this here.
}

