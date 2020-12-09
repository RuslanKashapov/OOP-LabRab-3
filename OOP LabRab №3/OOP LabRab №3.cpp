#include <iostream>
using namespace std;

class Object
{
public:
    Object()
    {

    };
    ~Object()
    {
        cout << "~Object" << endl;
    }
public:
    void show()
    {

    }
};

class Storage
{
protected:
    int size;
    Object **object;
public:
    Storage(int size)//создаём динамический массив в конструкторе 
    {
        cout << "Storage(int size)" << endl;
        this->size = size;
        object = new Object *[size];
    }
    ~Storage()
    {
        cout << "~Storage()" << endl;
        delete[] object;
    }
};

int main()
{
    Storage mas(10);

    
}

