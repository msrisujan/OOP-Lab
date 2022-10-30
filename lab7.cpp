#include<bits/stdc++.h>
using namespace std;
class Account
{
    protected:
        int id;
        double balance;
        int acc_num;
    public:
        Account(int id,int acc_num)
        {
            this->id=id;
            this->balance=0.0;
            this->acc_num=acc_num;
        }
        friend class Bank;
};
class Bank 
{
    protected:
        vector<Account>acc;
    public:
        Bank(){}
        int search_id(int id)
        {
            int i=0;
            for(i=0;i<acc.size();i++)
            {
                if(acc[i].id==id)
                {
                    return i;
                }
            }
            return -1;
        }
        int search_acc(int num)
        {
            int i=0;
            for(i=0;i<acc.size();i++)
            {
                if(acc[i].acc_num==num)
                {
                    return i;
                }
            }
            return -1;
        }
        void credit(double num,int id,int fees=0)
        {
            int i=search_acc(id);
            if(i==-1)
            {
                cout<<"Account number not found"<<endl;
            }
            else
            {
                if(num<fees)
                {
                    cout<<"minimum credit fees not reached"<<endl;
                }
                else
                {
                    acc[i].balance=acc[i].balance+num-fees;
                    cout<<"balance after credited :"<<acc[i].balance<<endl;
                }
            }
            
        }
        void debit(double num,int id,int fees=0)
        {
            int i=search_acc(id);
            if(i==-1)
            {
                cout<<"Account number not found"<<endl;
            }
            else if((acc[i].balance-num-fees)<0)
            {
                cout<<"Account balance not sufficient"<<endl;
            }
            else
            {
                acc[i].balance=acc[i].balance-num-fees;
                cout<<"balance after debited :"<<acc[i].balance<<endl;
            }
        }
        double calculate_interest(int num,double t,double r)
        {
            int i=search_acc(num);
            double p=acc[i].balance;
            double inter=(p*t*r)/100;
            return inter;
        }
        void print_id(int i)
        {
            Account accs=acc[i];
            cout<<"Account number :"<<accs.acc_num<<endl;
            cout<<"Balance :"<<accs.balance<<endl;
        }
        void add_acc(int id,int num)
        {
            acc.push_back(Account(id,num));
        }
};
class Savings : public Bank
{
    private:
        double interest;
    public:
        Savings()
        {
            this->interest=2.5;
        }
        void set_interest(double num)
        {
            this->interest=num;
        }
        double calculate_interest(int num,double t)
        {
           return Bank :: calculate_interest(num,t,interest);
        }
        void print_id(int i)
        {
            Bank :: print_id(i);
            cout<<"Interest rate :"<<interest<<endl;
        }
};
class Checking : public Bank
{
    private:
        double fees;
    public:
        Checking()
        {
            this->fees=30;
        }
        void set_fees(double num)
        {
            this->fees=num;
        }
        void credit(double num,int id)
        {
            Bank :: credit(num,id,fees);
        }
        void debit(double num,int id)
        {
            Bank :: debit(num,id,fees);
        }
        double get_fees()
        {
            return fees;
        }
        void print_id(int i)
        {
            Bank :: print_id(i);
            cout<<"Fees amount :"<<fees<<endl;
        }
};
int main()
{
    cout<<"\t1. Open Account (Savings or Checking Account)"<<endl;
    cout<<"\t2. Credit (Savings or Checking Account)"<<endl;
    cout<<"\t3. Debit (Savings or Checking Account)"<<endl;
    cout<<"\t4. Change/Update Interest rate (Savings Account)"<<endl;
    cout<<"\t5. Calculate Interest (Savings Account - Print)"<<endl;
    cout<<"\t6. Calculate and Update Principle amount with interest (Savings Account - Credit)"<<endl;
    cout<<"\t7. Change/Update Fee Amount (Checking Account)"<<endl;
    cout<<"\t8. Print Checking Fee (Checking Account)"<<endl;
    cout<<"\t9. Search Customer Details"<<endl;
    cout<<"\t10. Exit"<<endl;
    int ch;
    int id=2500,save_acc=100,check_acc=200;
    Savings save;
    Checking check;
    while(ch!=10)
    {
        cout<<"Enter your choice:";
        cin>>ch;
        if(ch==1)
        {
            int ch1;
            cout<<"Enter 1)savings account 2)checking account"<<endl;
            cin>>ch1;
            if(ch1==1)
            {
                int a;
                cout<<"Enter 1)if have id 2)no id"<<endl;
                cin>>a;
                if(a==1)
                {
                    int x;
                    cout<<"Enter your id :";
                    cin>>x;
                    int i=check.search_id(x);
                    int j=save.search_id(x);
                    if(j!=-1)
                    {
                        cout<<"Entered ID already has savings account"<<endl;
                    }
                    else if(i==-1)
                    {
                        cout<<"Entered id not exist"<<endl;
                    }
                    else
                    {
                        save.add_acc(x,save_acc);
                        save_acc++;
                        int i=save.search_id(x);
                        cout<<"Your Savings account has been created"<<endl;
                        cout<<"ID :"<<x<<endl;
                        save.print_id(i);
                    }
                }
                else if(a==2)
                {
                    save.add_acc(id,save_acc);
                    int i=save.search_id(id);
                    id++;
                    save_acc++;
                    cout<<"Your Savings account has been created"<<endl;
                    cout<<"ID :"<<id-1<<endl;
                    save.print_id(i);
                }
                else
                {
                    cout<<"invalid input"<<endl;
                }
            }
            else if(ch1==2)
            {
                int a;
                cout<<"Enter 1)if have id 2)no id"<<endl;
                cin>>a;
                if(a==1)
                {
                    int x;
                    cout<<"Enter your id :";
                    cin>>x;
                    int i=save.search_id(x);
                    int j=check.search_id(x);
                    if(j!=-1)
                    {
                        cout<<"Entered ID already has checking account"<<endl;
                    }
                    else if(i==-1)
                    {
                        cout<<"Entered id not exist"<<endl;
                    }
                    else if(j!=-1)
                    {
                        cout<<"Entered ID already has checking account"<<endl;
                    }
                    else
                    {
                        check.add_acc(x,check_acc);
                        check_acc++;
                        int i=check.search_id(x);
                        cout<<"Your Checking account has been created"<<endl;
                        cout<<"ID :"<<x<<endl;
                        check.print_id(i);
                    }
                }
                else if(a==2)
                {
                    check.add_acc(id,check_acc);
                    int i=check.search_id(id);
                    id++;
                    check_acc++;
                    cout<<"Your Checking account has been created"<<endl;
                    cout<<"ID :"<<id-1<<endl;
                    check.print_id(i);
                }
                else
                {
                    cout<<"invalid input"<<endl;
                }
            }
            else
            {
                cout<<"invalid input"<<endl;
            }
        }
        else if(ch==2)
        {
            int ch1,x;
            double y;
            cout<<"Enter 1)savings account 2)checking account"<<endl;
            cin>>ch1;
            cout<<"enter account number :";
            cin>>x;
            cout<<"Enter amount to be credited :";
            cin>>y;
            if(ch1==1)
            {
                save.credit(y,x);
            }
            else if(ch1==2)
            {
                check.credit(y,x);
            }
            else
            {
                cout<<"invalid input"<<endl;
            }
        }
        else if(ch==3)
        {
            int ch1,x;
            double y;
            cout<<"Enter 1)savings account 2)checking account"<<endl;
            cin>>ch1;
            cout<<"enter account number :";
            cin>>x;
            cout<<"Enter amount to be debited :";
            cin>>y;
            if(ch1==1)
            {
                save.debit(y,x);
            }
            else if(ch1==2)
            {
                check.debit(y,x);
            }
            else 
            {
                cout<<"invalid input"<<endl;
            }
        }
        else if(ch==4)
        {
            double x;
            cout<<"Enter the interest rate to update :";
            cin>>x;
            if(x<0)
                cout<<"Give correct input"<<endl;
            else
            {
                save.set_interest(x);
                cout<<"new interest rate :"<<x<<endl;
            }
        }
        else if(ch==5)
        {
            int x;
            cout<<"Enter your account number :";
            cin>>x;
            int i=save.search_acc(x);
            if(i==-1)
            {
                cout<<"Account number not found"<<endl;
            }
            else
            {
                int t;
                cout<<"Enter time period :";
                cin>>t;
                int z=save.calculate_interest(x,t);
                cout<<"Interest is :"<<z<<endl;
            }
        }
        else if(ch==6)
        {
            int x;
            cout<<"Enter your account number :";
            cin>>x;
            int i=save.search_acc(x);
            if(i==-1)
            {
                cout<<"Account number not found"<<endl;
            }
            else
            {
                int t;
                cout<<"Enter time period :";
                cin>>t;
                if(t<=0)
                    cout<<"give correct input"<<endl;
                else
                {
                    double z=save.calculate_interest(x,t);
                    save.credit(z,x);
                    cout<<"rs:"<<z<<" of interest has been credited to your account"<<endl;
                }
            }
        }
        else if(ch==7)
        {
            double x;
            cout<<"Enter values of fees amount to change :";
            cin>>x;
            if(x<0)
                cout<<"Give correct input"<<endl;
            else
            {
                check.set_fees(x);
                cout<<"new fees amount :"<<x<<endl;
            }
        }
        else if(ch==8)
        {
            double x=check.get_fees();
            cout<<"Fees amount :"<<x<<endl; 
        }
        else if(ch==9)
        {
            int x;
            cout<<"Enter your ID :";
            cin>>x;
            int i=save.search_id(x);
            int j=check.search_id(x);
            if(i!=-1)
            {
                cout<<"Savings account :"<<endl;
                save.print_id(i);
            }
            if(j!=-1)
            {
                cout<<"Checking account :"<<endl;
                check.print_id(j);
            }
            else if(i==-1 || j==-1)
            {
                cout<<"No account with given ID"<<endl;
            }
        }
        else if(ch==10)
        {
            break;
        }
        else if(ch>10)
        {
            cout<<"Enter your choice correctly"<<endl;
        }
    }
    return 0;
}