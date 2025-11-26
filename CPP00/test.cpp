#include <iostream>

using namespace std;



// class Car {
//     public:
//         Car(std::string brand);
//         Car(std::string pbrand , std::string pmodel , int pyear);
//         std::string _brand;
//         std::string _model;
//         int year;
// };

class Vehicle {
    private:
    std::string brand ;
    public:
    Vehicle()
    {
        brand = "Df Veh";
    }
    Vehicle(string b)
    {
        brand = b;
    }
    void honk() {
        std::cout << "Tuut, tuut!" << std::endl;
    }
    void getBarnd()
    {
        cout << brand << endl;
    }
};

class Car : public Vehicle {
public:
    std::string model = "Mustang";
    Car() : Vehicle("Hello")
    {
        getBarnd();
    }
};


// Car::Car(std::string brand) : _brand(brand) , _model("test") , year(222)  
// {
//     std::cout << "hey " << endl;
//     return ;
// }
// Car::Car(std::string brand , std::string pmodel , int pyear)
// {
//     _brand = brand;
//     _model = pmodel;
//     year = pyear;
// }


class MyClass {
    public :
        MyClass() {
            std::cout << "hello world ana khedam " << endl;
        }
};

int main() {
    // std::cout << "hello world" << endl;
    // Car car1;
    Car  m;

    std::cout << "hey" << endl;


    char buf[26];
    std::cout << "enter a num" << endl;

    std::cin >> buf; 


    std::cout << "you enter this : " << buf << endl;
    // cout << m.brand << endl ;
    // Car car2("ford","Mustang", 888);
    // Car car3("ford","Mustang", );
    // MyClass obj;
    // std::cout << car1.brand << " " << car1.model << " " << car1.year  << endl;
    // std::cout << car2.brand << " " << car2.model << " " << car2.year  << endl;
    return 0;
}
