﻿#include <iostream>
#include <ctime>
using namespace std;

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
    virtual void show()
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
    void show()
    {
        cout << "Автомобиль" << endl;
        cout << "Характеристики автомобиля: " << num_of_doors << model << endl;
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
        cout << "Грузовик" << endl;
        cout << "Характеристики грузовика: " << num_of_doors << weight << model << endl;
    }
};

class Storage
{
protected:
    int j;
    int size;
    Object **object;
public:
    Storage(int size)
    {
        cout << "Storage(int size)" << endl;
        this->size = size;
        int j = 0;
        object = new Object *[size];
        for (int i = 0; i < size; i++)
        {
            object[i] = NULL;
        }
    }
    void AddObject(Object* s, int i)
    {
        if ((i < size))
        {
            object[i] = s;
            j++;
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
    void delObject(int i)
    {
        if (object[i] != NULL)
        {
            object[i] = NULL;
            j--;
            cout << "void delObject(int i)" << endl;
        }
        else
        {
            cout << "Oшибка  void delObject(int i)" << endl;
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
    unsigned int start_time = clock();
    Storage storage(10000);
    for (int i = 0; i < 10000; i++)
    {
        if (rand() % 2 == 0)
        {
            Object *с = new Car;
            if (rand() % 3 == 0)
            {
                storage.AddObject(с, i);
            }
            else if (rand() % 4 == 1)
            {
                storage.delObject(i);
            }
            else
            {
                storage.getObject(i);
            }
        }
        else
        {
            Object *t  = new Truck;
            if (rand() % 3 == 0)
            {
                storage.AddObject(t, i);
            }
            else if (rand() % 4 == 1)
            {
                storage.delObject(i);
            }
            else
            {
                storage.getObject(i);
            }
        }
    }
    unsigned int end_time = clock();
    unsigned int result_time = end_time - start_time;
    cout << "Время работы: " << result_time << endl;

}

