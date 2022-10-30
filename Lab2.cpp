#include <iostream>
using namespace std;

class gtime
{
    int hour;
    int min;
    int sec;

public:
    gtime()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }

    void set_time(int h, int m, int s)
    {
        if (h < 24 && m < 60 && s < 60 && h >= 0 && m >= 0 && s >= 0)
        {
            hour = h;
            min = m;
            sec = s;
        }
        else
        {
            cout << "Wrong Input,invalid time" << endl;
        }
    }

    int ghour()
    {
        return hour;
    }

    int gmin()
    {
        return min;
    }

    int gsec()
    {
        return sec;
    }

    ~gtime() {}
};

void standard(gtime t)
{
    int hrs=t.ghour();
    string ampm;
    if (hrs < 12)
        ampm = "AM";
    else if (hrs > 12)
    {
        ampm = "PM";
        hrs -= 12;
    }
    else
        ampm = "PM";
    cout<<"Standard Time(AM or PM) : "<<hrs<<":"<<t.gmin()<<":"<<t.gsec()<<" "<<ampm<<endl;
}
void universal(gtime t)
{
    cout<<"Universal Time(24 hrs) : "<<t.ghour()<<":"<<t.gmin()<<":"<<t.gsec()<<endl;
}
void indian(gtime t)
{
    int hrs = t.ghour();
    int mins = t.gmin();

    mins += 30;
    if (mins >= 60)
    {
        mins -= 60;
        hrs = (hrs + 1) % 24;
    }
    hrs = (hrs + 5) % 24;
    cout<<"India Standard Time(24 hrs) : "<<hrs<<":"<<mins<<":"<<t.gsec()<<endl;
}
void pacific(gtime t)
{
    int hrs = t.ghour();
    hrs = (hrs - 8) % 24;
    if(hrs<0)
    {
        hrs +=24;
    }
    string ampm;
    if (hrs < 12)
        ampm = "AM";
    else if (hrs > 12)
    {
        ampm = "PM";
        hrs -= 12;
    }
    else
        ampm = "PM";
    cout<<"Pacific Standard Time(AM or PM) : "<<hrs<<":"<<t.gmin()<<":"<<t.gsec()<<" "<<ampm<<endl;
}

int main()
{
    gtime t;
    int choice = 0;

    cout << "1) Set Time" << endl;
    cout << "2) Print Standard Time (AM or PM)" << endl;
    cout << "3) Print UNiversal Time(24 hours)" << endl;
    cout << "4) Print Indian Standard Time(24 hours)" << endl;
    cout << "5) Print Pacific Standard Time(AM or PM)" << endl;
    cout << "6) Exit" << endl;

    while (choice != 6)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int hr, min, sec;
            cout << "Enter Time in 24hr-format (hr min sec): ";
            cin >> hr >> min >> sec;
            t.set_time(hr, min, sec);
            break;

        case 2:
            standard(t);
            break;

        case 3:
            universal(t);
            break;

        case 4:
            indian(t);
            break;

        case 5:
            pacific(t);
            break;

        case 6:
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }

    return 0;
}