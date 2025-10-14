#include <iostream>
using namespace std;

// compile: g++-15 Car.cpp
// Run:  ./a.out
class Car {
public:
    // data members
    string brand;
    int year;

    // member function
    void start() {
        cout << brand << " started!" << endl;
    }
};

int main() {
    // create objects
    Car c1, c2;

    // assign values
    c1.brand = "Tesla";
    c1.year = 2024;

    c2.brand = "BMW";
    c2.year = 2022;

    // call methods
    c1.start();
    c2.start();

    return 0;
}

/**
class Car {
public:
    string brand;
    int year;

    // constructor
    Car(string b, int y) {
        brand = b;
        year = y;
    }

    void show() {
        cout << brand << " - " << year << endl;
    }
};

int main() {
    Car c1("Tesla", 2024);
    Car c2("BMW", 2022);

    c1.show();
    c2.show();
}

*/

/*
 // Default constructor and “this” pointer
class Car {
    string brand;
    int year;

public:
    // default constructor
    Car() {
        brand = "Unknown";
        year = 0;
    }

    // parameterized constructor
    Car(string brand, int year) {
        this->brand = brand; // “this” refers to the current object
        // this.brand = brand; // ❌ Error: 'this' is a pointer, use '->' instead
        this->year = year;
    }

    void display() {
        cout << brand << " (" << year << ")" << endl;
    }
};

int main() {
    Car c1;               // default constructor
    Car c2("Toyota", 2023); // parameterized

    c1.display();
    c2.display();
}

*/

/*
Destructor: A destructor cleans up when an object goes out of scope (e.g., frees memory).
class Car {
public:
    Car() { cout << "Car created\n"; }
    ~Car() { cout << "Car destroyed\n"; }
};

int main() {
    Car c1; // constructor runs
} // destructor runs here

*/

/*
// Access modifiers
public:	Accessible from anywhere
private:	Accessible only inside the class
protected:	Like private, but accessible to derived classes

class Account {
private:
    int balance;

public:
    Account(int amount) { balance = amount; }

    void deposit(int amt) { balance += amt; }

    int getBalance() { return balance; }
};

int main() {
    Account a(100);
    a.deposit(50);
    cout << "Balance: " << a.getBalance() << endl;
}

*/

/*
class Example {
    int x;           // private by default

public:
    void setX(int val) { x = val; }
    int getX() { return x; }
};

int main() {
    Example e;
    // e.x = 5; ❌ Error: x is private
    e.setX(5);        // ✅ OK
    cout << e.getX(); // ✅ OK
}
*/

/*
Example 2: Struct
struct Example {
    int x;            // public by default
};

int main() {
    Example e;
    e.x = 10;         // ✅ OK — public by default
    cout << e.x;
}
*/