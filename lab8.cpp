#include<iostream>
#include<vector>
using namespace std;
class Student
{
    protected:
        string name;
        int roll;
    public:
        Student(){}
        Student(string name,int roll)
        {
            this->name=name;
            this->roll=roll;
        }
        void virtual display()=0;
};
class PG_student : public virtual Student
{
    protected:
        string course1;
        string course2;
        string course3;
    public:
        PG_student(){}
        PG_student(string course1,string course2,string course3,string name,int roll):Student(name,roll)
        {
            this->course1=course1;
            this->course2=course2;
            this->course3=course3;
        }
        void virtual display()
        {
            cout<<"course1 :"<<course1<<endl;
            cout<<"course2 :"<<course2<<endl;
            cout<<"course3 :"<<course3<<endl;
        }
};
class Research_student : public virtual Student
{
    protected:
        string rcourse1;
        string area;
    public:
        Research_student(){}
        Research_student(string rcourse1,string area,string name,int roll):Student(name,roll)
        {
            this->rcourse1=rcourse1;
            this->area=area;
        }
        void display()
        {
            cout<<"course1 :"<<rcourse1<<endl;
            cout<<"research area :"<<area<<endl;
        }
};
class TA : public PG_student,public Research_student
{
    private:
        string course_a;
        string role;
    public:
        TA(string course_a,string role,string rcourse1,string area,string name,int roll) : Research_student(rcourse1,area,name,roll),Student(name,roll)
        {
            this->course_a=course_a;
            this->role=role;
        }
        TA(string course_a,string role,string course1,string course2,string course3,string name,int roll) : PG_student(course1,course2,course3,name,roll),Student(name,roll)
        {
            this->course_a=course_a;
            this->role=role;
        }
        void display()
        {
           cout<<"Name :"<<name<<endl;
           cout<<"Roll no :"<<roll<<endl;
           cout<<"course assigned :"<<course_a<<endl;
           cout<<"role :"<<role<<endl;
           if(role=="pg_student")
           {
                PG_student::display();
           }
           else if(role=="research_student")
           {
                Research_student::display();
           }
        }
        friend int search(vector<TA>arr,int roll);
};
int search(vector<TA>a,int roll)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i].roll==roll)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<TA>arr;
    cout<<"1. Set Details"<<endl;
    cout<<"2.Display"<<endl;
    cout<<"3.Exit"<<endl;
    int ch;
    while(ch!=3)
    {
        cout<<"Enter your choice :";
        cin>>ch;
        if(ch==1)
        {
            string name,course1,course2,course3,rcourse1,course_a,area;
            int roll,role;
            cout<<"Enter name:";
            cin>>name;
            cout<<"Enter roll number:";
            cin>>roll;
            int q=search(arr,roll);
            if(q!=-1)
            {
                cout<<"Entered roll number already exists"<<endl;
            }
            else{
            cout<<"Enter role 1)pg student 2)research student :";
            cin>>role;
            cout<<"Enter course research area :";
            cin>>course_a;
            if(role==1)
            {
                cout<<"Enter course1 :";
                cin>>course1;
                cout<<"Enter course2 :";
                cin>>course2;
                cout<<"Enter course3 :";
                cin>>course3;
                if(course1==course_a || course2==course_a || course3==course_a)
                {
                    cout<<"There is already a course same as assigned course"<<endl;
                }
                else
                {
                    TA a(course_a,"pg_student",course1,course2,course3,name,roll);
                    arr.push_back(a);
                }
            }
            else if(role==2)
            {
                cout<<"Enter course1 :";
                cin>>rcourse1;
                cout<<"Enter Course assigned :";
                cin>>area;
                if(rcourse1==course_a)
                {
                    cout<<"There is already a course same as assigned course"<<endl;
                }
                else
                {
                    TA a(course_a,"research_student",rcourse1,area,name,roll);
                    arr.push_back(a);
                }
            }
            else
            {
                cout<<"Incorrect input"<<endl;
            }
            }

        }
        else if(ch==2)
        {
            int roll;
            cout<<"Enter roll number :";
            cin>>roll;
            int i=search(arr,roll);
            if(i==-1)
            {
                cout<<"Entered roll number not exist"<<endl;
            }
            else
                arr[i].display();
        }
        else if(ch==3)
        {
            break;
        }
        else
        {
            cout<<"Enter the correct option"<<endl;
        }
    }
    return 0;
}