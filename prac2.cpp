#include<iostream>
using namespace std;
class Demo
{
    private :
        int num;
        char ch;
    public :
        void setvalue(int num,char ch)
        {
            this->num = num;
            (*this).ch = ch;
        }
        void putvalue()
        {
            cout<<num<<endl;
            cout<<ch<<endl;
        }
};
int main()
{
    Demo obj;
    obj.setvalue(100,'A');
    obj.putvalue();
    return 0;
}