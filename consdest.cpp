#include<iostream>
using namespace std;
class cars
{
    private :
        string company_Name; //member variable
        string model_Name;
        string fule_Type;
        float mileage;
        double price;
    public :
        cars()  //special member functon and it is called constructor
        {
            cout<<"default constructor\n";
            company_Name="maruti";
            model_Name="baleno";
            fule_Type="petrol";
            mileage=45.6;
            price=800000;    //it is used to initialize the object variable
        }
        cars(string cname,string mname,string ftype,float m,double p)  //parameterized constructor
        {
            cout<<"parameterized constructor\n";
            company_Name=cname;
            model_Name=mname;
            fule_Type=ftype;
            mileage=m;
            price=p;
        }
        void display() //member function
        {
            cout<<"company name : "<< company_Name <<endl;
            cout<<"model name : "<< model_Name <<endl;
            cout<<"fuel type : "<< fule_Type <<endl;
            cout<<"mileage : "<< mileage <<endl;
            cout<<"price : "<< price <<endl;
        }
        cars(cars &c) //object as a parameter
        {
            cout<<"copy constructor\n";
            company_Name=c.company_Name;
            model_Name=c.model_Name;
            fule_Type=c.fule_Type;
            mileage=c.mileage;
            price=c.price;
        }
        void print()
        {
            cout<<"this is OOP class\n";
        }
        ~cars() //destructor
        {
            cout<<"destructor called at the end"<<endl;
        }
};

int main()
{
    cars c1; //object creation, implicit call to default constructor
    c1.display(); //explicit call to the member function

    cars c2("hyundai","i10","petrol",89.7,700000); //calls parametrized constructor
    c2.display();

    cars c3=c2;  //it calls implicitly copy constructor
    c3.display();

    cars c4(c1);  //it calls implicitly copy constructor, this is another way
    c4.display();

    cars *ptr;  // pointer variable to store the address of an object
    ptr = &c2;  // ptr points to address of c2
    cout<<"address of c2 "<<ptr<<endl;
    ptr = &c3;  // ptr points to address of c3
    cout<<"address of c3 "<<ptr<<endl;

    cars c5;
    c5.print();
}