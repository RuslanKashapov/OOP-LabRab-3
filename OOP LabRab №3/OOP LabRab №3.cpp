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
public:
    int size;
    Object **object;
public:
    Storage(int size)//создаём динамический массив в конструкторе 
    {
        cout << "Storage(int size)" << endl;
        this->size = size;
        object = new Object *[size];
        for (int i = 0; i < size; i++)
        {
            object[i] = NULL;
            cout << object[i] << endl;
        }
    }

    void AddObject(Object* s, int i)
    {
        if ((i < size) && object[i] == NULL)
        {
            object[i] = s;
            size += 1;
            cout << "void AddObject(Object* s, int i)" << endl;
        }
        else
        {
            cout << "Oшибка" << endl;
        }
    }

    ~Storage()
    {
        cout << "~Storage()" << endl;
        delete[] object;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Object* t = new Object;
    Storage mas(10);
    mas.AddObject(t, 5);

}

