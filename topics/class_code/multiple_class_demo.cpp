#include <bits/stdc++.h>
using namespace std;
class One{
public:
    int a;
    void display();
    void print()
    {
        std::cout << "print from class one" << std::endl;
    }
};

void One::display(){
    std::cout<<"outside display method class one"<<endl;
}

class Two{
    public:
       void print() {
            std::cout<<"print from calss two"<<std::endl;
        }
        void display();
        void access();

};

void Two::display(){
    cout<<"outside class display method from clas two"<<endl;
}

struct First{
    void print(){
        cout<<"print function from first structure"<<endl;
    }
};

void Two::access(){
    One one;
    cout<<"class two access function"<<endl;
    one.print();
}
int main()
{
    One one;
    Two two;
    First first;
    std::cout << one.a << std::endl;
    one.print();
    one.display();
    two.print();
    first.print();
    two.access();
    return 0;
}
