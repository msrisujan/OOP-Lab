#include<iostream>
#include<cmath>
using namespace std;
class Volume;
class Area
{
    
    double side,length,breadth,radius;
    public :
        Area()
        {
            side=1.0;
            length=1.0;
            breadth=1.0;
            radius=1.0;
        }
        void set_side(double side=1.0)
        {
            this->side=side;
        }
        void set_length(double length=1.0)
        {
            this->length=length;
        }
        void set_breadth(double breadth=1.0)
        {
            this->breadth=breadth;
        }
        void set_radius(double radius=1.0)
        {
            this->radius=radius;
        }
        inline double square()
        {
            return (side*side);
        }
        inline double rectangle()
        {
            return (length*breadth);
        }
        inline double circle()
        {
            return (M_PI*radius*radius);
        }
            friend double cube(Area,Volume);
            friend double cuboid(Area,Volume);
            friend double sphere(Area,Volume);
};
class Volume
{
    double height;
    public :
        Volume()
        {
            height=1.0;
        }
        void set_height(double height=1.0)
        {
            this->height=height;
        }
        friend double cube(Area,Volume);
        friend double cuboid(Area,Volume);
        friend double sphere(Area,Volume);
};
inline double cube(Area A,Volume V)
{
    return(A.side*A.side*A.side);
}
inline double cuboid(Area A,Volume V)
{
    return (A.breadth*A.length*V.height);
}
inline double sphere(Area A,Volume V)
{
    return (4*M_PI*A.radius*A.radius*A.radius/3);
}
inline void compare(double x,double y)
{
    if(x>y)
    {
        cout<<"Maximum Volume is "<<x<<endl;
    }
    else
    {
        cout<<"Maximum Volume is "<<y<<endl;
    }
}
double vsphere()
{
    int ch;
    double radius;
    Area A1;
    Volume V1;
    cout<<"1)default radius or 2)Parameterized radius"<<endl;
    cin>>ch;
    if(ch==1)
    {
        A1.set_radius();
    }
    else if(ch==2)
    {
        cout<<"Enter the value of radius"<<endl;
        cin>>radius;
        A1.set_side(radius);
    }
    return (sphere(A1,V1));   
}
double vcube()
{
    int ch;
    double side;
    Area A1;
    Volume V1;
    cout<<"1)default or 2)Parameterize"<<endl;
    cin>>ch;
    if(ch==1)
    {
        A1.set_side();
    }
    else if(ch==2)
    {
        cout<<"Enter the value of side"<<endl;
        cin>>side;
        A1.set_side(side);
    }
    return (cube(A1,V1));
}
double vcuboid()
{
    int ch1,ch2,ch3;
    double length,breadth,height;
    Area A1;
    Volume V1;
    cout<<"1)default length or 2)Parameterized length"<<endl;
    cin>>ch1;
    if(ch1==1)
    {
        A1.set_length();
    }
    if(ch1==2)
    {
        cout<<"Enter the value of length"<<endl;
        cin>>length;
        A1.set_length(length);
    }
    cout<<"1)default breadth or 2)Parameterized breadth"<<endl;
    cin>>ch2;
    if(ch2==1)
    {
        A1.set_breadth();
    }
    if(ch2==2)
    {
        cout<<"Enter the value of breadth"<<endl;
        cin>>breadth;
        A1.set_breadth(breadth);
    }
    cout<<"1)default height or 2)Parameterized height"<<endl;
    cin>>ch3;
    if(ch3==1)
    {
        V1.set_height();
    }
    if(ch3==2)
    {
        cout<<"Enter the value of height"<<endl;
        cin>>height;
        V1.set_height(height);
    }
    return (cuboid(A1,V1));
}
int main()
{
    int choice;
    while(choice!=10)
    {
        cout<<"Enter your choice \n1)Area of square \n2)Area of rectangle \n3)Area of circle \n4)Volume of cube \n5)Volume of cuboid \n6)Volume of sphere \n7)Compare Cube \n8)Compare cuboid \n9)Compare sphere \n10)exit"<<endl;
        cin>>choice;
        if(choice==1)
        {
            int ch;
            double side;
            cout<<"1)default side or 2)Parameterized side"<<endl;
            cin>>ch;
            if(ch==1)
            {
                Area A1;
                cout<<"The area of square is "<<A1.square()<<endl;
            }
            else if(ch==2)
            {
                cout<<"Enter the value of side"<<endl;
                cin>>side;
                Area A1;
                A1.set_side(side);
                cout<<"The area of square is "<<A1.square()<<endl;
            }   
        }
        else if(choice==2)
        {
            int ch1,ch2;
            double length,breadth;
            Area A1;
            cout<<"1)default length or 2)Parameterized length"<<endl;
            cin>>ch1;
            if(ch1==1)
            {
                A1.set_length();
            }
            if(ch1==2)
            {
                cout<<"Enter the value of length"<<endl;
                cin>>length;
                A1.set_length(length);
            }
            cout<<"1)default breadth or 2)Parameterized breadth"<<endl;
            cin>>ch2;
            if(ch2==1)
            {
                A1.set_breadth();
            }
            if(ch2==2)
            {
                cout<<"Enter the value of breadth"<<endl;
                cin>>breadth;
                A1.set_breadth(breadth);
            }
            cout<<"Area of rectangle is "<<A1.rectangle()<<endl;
        }
        else if(choice==3)
        {
            int ch;
            double radius;
            cout<<"1)default radius or 2)Parameterized radius"<<endl;
            cin>>ch;
            if(ch==1)
            {
                Area A1;
                cout<<"The area of circle is "<<A1.circle()<<endl;
            }
            else if(ch==2)
            {
                cout<<"Enter the value of radius"<<endl;
                cin>>radius;
                Area A1;
                A1.set_side(radius);
                cout<<"The area of circle is "<<A1.circle()<<endl;
            }      
        }
        else if(choice==4)
        {
            double x;
            x=vcube();
            cout<<"The volume of cube is "<<x<<endl;
        }
        else if(choice==5)
        {
            double x;
            x=vcuboid();
            cout<<"The volume of cuboid is "<<x<<endl;
        }
        else if(choice==6)
        {
            double x;
            x=vsphere();
            cout<<"The volume of sphere is "<<x<<endl;      
        }
        else if(choice==7)
        {
            double x,y;
            x=vcube();
            y=vcube();
            compare(x,y);
        }
        else if(choice==8)
        {
            double x,y;
            x=vcuboid();
            y=vcuboid();
            compare(x,y);
        }
        else if(choice==9)
        {
            double x,y;
            x=vsphere();
            y=vsphere();
            compare(x,y);
        }
    }
    return 0;
}