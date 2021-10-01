//Sample cpp program to understand Class,Constructor, Destructor, Inheritance, Polymorphism in cpp 

#include <bits/stdc++.h>
using namespace std;
class vehicle
{
private:
    int price;
    char* manufacturer;

public:
    vehicle()
    {
        price = 0;
        manufacturer=new char[15];
        manufacturer[0] = '\0';
        cout<<"Constructor called for base class"<<endl;
    }
    vehicle(int i, char *x)
    {
        price = i;
        manufacturer = new char[strlen(x) + 1];
        strcpy(manufacturer, x);
        cout<<"Constructor called for base class"<<endl;
    }
    vehicle(const vehicle &obj)
    {
        this->price = obj.price;
        this->manufacturer = new char[strlen(obj.manufacturer) + 1];
        strcpy(manufacturer, obj.manufacturer);
    }
    vehicle &operator=(const vehicle &rhs)
    {
        manufacturer = new char[strlen(rhs.manufacturer) + 1];
        strcpy(manufacturer, rhs.manufacturer);
        return *this;
    }
    virtual void Read()
    {
        cout << "Enter the Price of the Vehicle : " << endl;
        cin >> price;
        getchar();
        cout << "Enter the Name of Manufacturer of the Vehicle : " << endl;
        scanf("%[^\n]s", manufacturer);
        getchar();
    }
    virtual void display()
    {
        cout << "Price of the Vehicle is : " << price << endl;
        cout << "Name of the Manufacturer is : " << manufacturer << endl;
    }
    ~vehicle()
    {
         cout<<"Destructor called for base class"<<endl;
    }
};
class car : public vehicle
{
private:
    char *color;
    int seats;
    char *model;

public:
    car()
    {
        color=new char[15];
        color[0] = '\0';
        seats = 0;
        model=new char[15];
        model[0] = '\0';
        cout<<"Constructor called for derived class"<<endl;
    }
    car(char *y, int i, char *x)
    {
        color = new char[strlen(y) + 1];
        strcpy(color, y);
        seats = i;
        model = new char[strlen(x) + 1];
        strcpy(model, x);
        cout<<"Constructor called for derived class"<<endl;
    }
    car(const car &obj)
    {
        this->color = new char[strlen(obj.color) + 1];
        strcpy(color, obj.color);
        this->seats = obj.seats;
        this->model = new char[strlen(obj.model) + 1];
        strcpy(model, obj.model);
    }
    car &operator=(const car &rhs)
    {
        color = new char[strlen(rhs.color) + 1];
        strcpy(color, rhs.color);
        this->seats = rhs.seats;
        model = new char[strlen(rhs.model) + 1];
        strcpy(color, rhs.model);
        return *this;
    }
    void Read()
    {
        cout << "Tell the Color of the Car : " << endl;
        scanf("%[^\n]s", color);
        getchar();
        cout << "Tell the Number of Seats of the Car : " << endl;
        cin >> seats;
        getchar();
        cout << "Enter the Name of Model of the Car : " << endl;
        scanf("%[^\n]s", model);
        getchar();
    }
    void display()
    {
        cout << "Color of the Car is : " << color << endl;
        cout << "Number of Seats of the Car is : " << seats << endl;
        cout << "Name of Model of the Car is : " << model << endl;
    }
    ~car()
    {
        cout<<"Destructor called for derived class"<<endl;
    }
};
int main()
{
    car *obj2;
    vehicle *obj1;
    obj2=new car;
    obj1=new vehicle;
    obj1->Read();
    obj2->Read();
    obj1->display();
    obj2->display();
    delete obj2;
    obj2=NULL;
    delete obj1;
    obj1=NULL;
    return 0;
}