// This pointer : will hold the address of calling object
// This pointer hold the address of current object
// It points to the object for which the member function is called

// This pointer is a constant pointer

// More about this pointer 

// This pointer is a constant pointer
// static member function dont have a this pointer
// friend fuction does not have this pointer because it is not a member function

#include<iostream>
using namespace std;

class Test
{
    private :
        int x;
    public :
        Test(int x) // parameterized constructor
        {
            //x=x; not valid
            this->x=x;
        }
        void print()
        {
            cout<<"x="<<x<<endl;
            cout<<"address of this "<<this<<endl;;
        }
};
int main()
{
    Test t(12),t1(10);
    cout<<endl;
    t.print();
    cout<<"address of t= "<<&t<<endl; // to check this pointer to address of t
    t1.print();
    cout<<"address of t= "<<&t1<<endl; // to check this pointer to address of t1
    return 0;
}