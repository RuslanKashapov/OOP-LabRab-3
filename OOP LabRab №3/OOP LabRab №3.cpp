#include <iostream>
using namespace std;

//класс, объекты которого мы будем помещать в хранилище
class Object
{
public:
    Object()
    {

    };
    virtual ~Object()
    {
        cout << "~Object" << endl;
    }
public:
    void show()
    {

    }
};


class Car :public Object
{
protected:
    int num_of_doors;
    string model;
public:
    Car()
    {
     cout << "Car()" << endl;
     num_of_doors = 0;
     model = "";
    }
    Car(int num_of_doors, string model)
    {
        cout << "Car(int num_of_doors, string model)" << endl;
        this->num_of_doors = num_of_doors;
        this->model = model;
    }
    Car(const Car &c)
    {
        cout << "Car(const Car &c)" << endl;
        num_of_doors = c.num_of_doors;
        model = c.model;
    }
    ~Car()
    {
        cout << num_of_doors << " " << model << " ";
        cout << "~Car()" << endl;
    }
};
class Truck : public Object
{
protected:
    int num_of_doors;
    int weight;
    string model;
public:
    Truck()
    {
        num_of_doors = 0;
        weight = 0;
        model = "";
        cout << "Truck()" << endl;
    }
    Truck(int num_of_doors, int weight, string model)
    {
        cout << "Truck(int num_of_doors, int weight, string model)" << endl;
        this->num_of_doors = num_of_doors;
        this->weight = weight;
        this->model = model;
    }
    Truck(Truck& t)
    {
        cout << "Truck(Truck& t)" << endl;
        num_of_doors = t.num_of_doors;
        weight = t.weight;
        model = t.model;
    }
    ~Truck()
    {
        cout << " ~Truck()" << endl;
    }
    void show()
    {
        cout << "Truck" << endl;
        cout << "Характеристики грузовика: " << num_of_doors << weight << model << endl;
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
            cout << "Oшибка void AddObject(Object* s, int i)" << endl;
        }
    }
    Object* getObject(int i)
    {
        if (object[i] != NULL)
        {
            cout << "Object* getObject(int i)" << endl;
            return object[i];
        }
        else
        {
            cout << "Ошибка Object* getObject(int i)" << endl;
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
    Storage storage(100);
    Object* t = new Car(5, "Mazda");
    storage.AddObject(t, 5);
    delete t;

}

