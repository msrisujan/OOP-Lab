#include<iostream>
using namespace std;
class A
{
    int a;
    float b;
    public :
        A& setdata(int a,float b) // return an object
        {
            this->a=a; // first use case of this pointer
            this->b=b;
            return *this; // second use case of this pointer => return an object
            // you can make use of this by combining a,b,c as single object
        }
        void getdata()
        {
            cout<<"the value of a is "<<a<<endl;
            cout<<"the value of b is "<<b<<endl;
        }
};
int main()
{
    A a,a1;
    a1=a.setdata(4,5.677); // cascading of function calls ; setdata() followed by getdata() 
    a1.getdata();
    a.setdata(4,5.5).getdata();
    return 0;
}