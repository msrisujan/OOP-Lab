#include<bits/stdc++.h>
using namespace std;
class node
{
    public :
        char data;
        node *next;
        node(char data)
        {
            this->data=data;
            next=NULL;
        }
};
class Queue
{
    private :
        node *front,*rear;
    public :
        Queue()
        {
            front=rear=NULL;
        }
        void enqueue(char x)
        {
            node *temp=new node(x);
            if(rear==NULL)
            {
                front=rear=temp;
                return ;
            }
            rear->next=temp;
            rear=temp;
        }
        void dequeue()
        {
            try
            {
                if(front==NULL)
                    throw 1;
            }
            catch(int a)
            {
                cout<<"Queue is Underflow"<<endl;
                return;
            }
            node *temp=front;
            if(front->next==NULL)
            {
                front=rear=NULL;
            }
            else
            {
                front =front->next;
                if(front==NULL)
                    rear=NULL;
                delete(temp);
            }
        }
        friend void inftopost(string inf);
        friend Queue pop_queue(Queue q1);
};
int precedence(char a)
{
    if(a=='/' || a=='*')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return -1;
}
Queue pop_queue(Queue q1)
{
    Queue q2;
    while(q1.front !=q1.rear)
    {
        q2.enqueue(q1.front->data);
        q1.dequeue();
    }
    return q2;
}
void inftopost(string inf)
{
    Queue q;
    string pos="";
    for(int i=0;i<inf.length();i++)
    {
        char c=inf[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        {
            pos+=c;
        }
        else
        {
            while(q.front!=NULL && precedence(inf[i])<=precedence(q.rear->data))
            {
                pos+=q.rear->data;
                q=pop_queue(q);
            }
            q.enqueue(c);
        }
    }
    while(q.front!=NULL)
    {
        pos+=q.rear->data;
        q=pop_queue(q);
    }
    cout<<"Postfix expression :"<<pos<<endl;
}
int check_char(char a)
{
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || a=='+' || a=='-' || a=='/' || a=='*')
        return 1;
    else 
        return -1;
}
void check_exp(string s)
{
    if(s[0]=='+' || s[0]=='-' || s[0]=='/' || s[0]=='*')
        throw 0;
    for(int i=0;i<s.length()-1;i++)
    {
        if(check_char(s[i])!=1)
            throw i;
        else if(((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && ((s[i+1]>='a' && s[i+1]<='z') || (s[i+1]>='A' && s[i+1]<='Z')))
            throw i;
        else if(precedence(s[i])!=-1 && precedence(s[i+1])!=-1)
            throw i;
    }
    if(check_char(s[s.length()-1])!=1)
        throw (int)s.length()-1;
    else if(precedence(s[s.length()-1])!=-1)
        throw (int)s.length()-1;
}
int main()
{
    cout<<"1.Get Infix Expression"<<endl;
    cout<<"2.Print Infix Expression"<<endl;
    cout<<"3.Print Postfix Expression"<<endl;
    cout<<"4.Exit"<<endl;
    int ch;
    string exp="";
    while(ch!=4)
    {
        cout<<"Enter your choice :";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter the infix expression :";
            cin>>exp;
            try
            {
                check_exp(exp);
            }
            catch(int x )
            {
                cout<<"Invalid expression :"<<exp<<endl;
                cout<<"                    ";
                for(int i=0;i<x;i++)
                    cout<<" ";
                cout<<"^^"<<endl;
                exp="";
            }
        }
        else if(ch==2)
        {
            if(exp=="")
                cout<<"please enter infix expression first"<<endl;
            else
                cout<<"Infix expression :"<<exp<<endl;
        }
        else if(ch==3)
        {
            if(exp=="")
                cout<<"please enter infix expression first"<<endl;
            else
                inftopost(exp);
        }
        else if(ch==4)
        {
            break;
        }
        else
            cout<<"Enter correct choice"<<endl;
    }
    return 0;
}