#include<iostream>
using namespace std;
class B;
class A
{
    int num1;
    public :
        A() : num1(5) {}
    friend int add(A,B);
};
class B
{
    int num2;
    public :
        B() : num2(4) {}
    friend int add(A,B);
};
int add(A obja,B objb)
{
    return(obja.num1 + objb.num2);
}
int main()
{
    A obja;
    B objb;
    cout<<"Sum : "<<add(obja,objb);
    return 0;
}