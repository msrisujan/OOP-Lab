#include<iostream>
#include<cmath>
using namespace std;
class coordinate
{
    private:
        double xnum;
        double ynum;
    public:
        coordinate()
        {
            xnum=0;
            ynum=0;
        }
        coordinate operator -(coordinate p)
        {
            coordinate temp;
            temp.xnum=xnum-p.xnum;
            temp.ynum=ynum-p.ynum;
            return temp;
        }
        void operator ~()
        {
            if(xnum<0)
                xnum=-xnum;
            if(ynum<0)
                ynum=-ynum;
        }
        void operator ^(int x)
        {
            this->xnum=pow(xnum,x);
            this->ynum=pow(ynum,x);
        }
        double sum()
        {
            double a=xnum+ynum;
            return a;
        }
       friend ostream & operator <<(ostream &out,coordinate &c);
       friend istream & operator >>(istream &in,coordinate &c);

};
ostream & operator <<(ostream &out,coordinate &c)
{
    out<<"("<<c.xnum<<","<<c.ynum<<")"<<endl;
    return out;
}
istream & operator >>(istream &in,coordinate &c)
{
    in>>c.xnum;
    in>>c.ynum;
    return in;
}
int main()
{
    int ch;
    coordinate c1,c2,c3,d1,d2,d3;
    cout<<" 1)Set point\n 2)Display point\n 3)Display length\n 4)check right traingle\n 5)exit"<<endl;
    while(ch!=5)
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==1)
        {
            int a,b;
            cout<<"enter the coordinates of point 1 : ";
            cin>>c1;
            ~c1;
            cout<<"enter the coordinates of point 2 : ";
            cin>>c2;
            ~c2;
            cout<<"enter the coordinates of point 3 : ";
            cin>>c3;
            ~c3;
        }
        else if(ch==2)
        {
            int a;
            cout<<"enter the point number to display : ";
            cin>>a;
            if(a==1)
                cout<<c1;
            if(a==2)
                cout<<c2;
            if(a==3)
                cout<<c3;
        }
        else if(ch==3)
        {
            int a,b;
            cout<<"enter the two point numbers for distance : ";
            cin>>a;
            cin>>b;
            if(a==b)
            {
                cout<<"distance between points is 0"<<endl;
            }
            else if(a==1 && b==2 || a==2 && b==1)
            {
                d1=c2-c1;
                d1^2;
                double e=d1.sum();
                double distance1 = sqrt(e);
                cout<<"distance between points : "<<distance1<<endl;
            }
            else if(a==1 && b==3 || a==3 && b==1)
            {
                d2=c3-c1;
                d2^2;
                double e=d2.sum();
                double distance1 = sqrt(e);
                cout<<"distance between points : "<<distance1<<endl;
            }
            else if(a==2 && b==3 || a==3 && b==2)
            {
                d3=c3-c2;
                d3^2;
                double e=d3.sum();
                double distance1 = sqrt(e);
                cout<<"distance between points : "<<distance1<<endl;
            }
            else 
            {
                cout<<"enter the numbers correctly"<<endl;
            }
        }
        else if(ch==4)
        {
            d1=c2-c1;
            d1^2;
            double a=d1.sum();
            d2=c3-c1;
            d2^2;
            double b=d2.sum();
            d3=c3-c2;
            d3^2;
            double c=d3.sum();
            if(a+b==c || b+c==a || a+c==b)
            {
                cout<<"The coordinates form right triangle"<<endl;
            }
            else
            {
                cout<<"The coordinates not form right triangle"<<endl;
            }
        }
        else if(ch==5)
        {
            break;
        }
        else
        {
            cout<<"enter your choice correctly"<<endl;
        }
    }
    return 0;
}