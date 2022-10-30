#include<iostream>
using namespace std;
class node
{
    private:
        int data;
        node *next;
    public:
        node(int data=0,node*next=NULL)
        {
            this->data=data;
            this->next=next;
        }
        inline int getdata()
        {
            return(this->data);
        }
        friend class cllist;
};
class cllist
{
    private:
        node *head;
        int size;
    public:
        cllist(node*head=NULL,int size=0)
        {
            this->head=head;
            this->size=size;
        }
        void insertnode(node *newnode)
        {
            node*temp=head;
            if(head==NULL)
            {
                head=newnode;
                head->next=head;
            }
            else
            {
                while(temp->next!=head && temp->next!=NULL)
                {
                    temp=temp->next;
                }
                newnode->next=head;
                temp->next=newnode;
            }
            size++;
        }
        void insertnode(node*newnode,int pos)
        {
            node*temp=head;
            int i=1;
            size++;
            if(head==NULL && pos==1)
            {
                head=newnode;
                head->next=head;
            }
            else if(pos==1)
            {
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->next=head;
                head=newnode;
            }
            else
            {
                if(pos>size || pos<1)
                {
                    cout<<"Invalid Position"<<endl;
                    size--;
                }
                else
                {
                    while(i<pos-1)
                    {
                        temp=temp->next;
                        i++;
                    }
                    newnode->next=temp->next;
                    temp->next=newnode;
                }
            }
        }
        void deletenode()
        {
            node*prev=NULL;
            node*temp=head;
            if(head==NULL)
            {
                cout<<"list is empty"<<endl;
            }
            else
            {
                if(temp->next==head)
                {
                    delete(temp);
                    head=NULL;
                }
                else
                {
                    while(temp->next!=head)
                    {
                        prev=temp;
                        temp=temp->next;
                    }
                    prev->next=head;
                }
                size--;
            }
        }
        void deletenode(int pos)
        {
            node*temp=head;
            node*prev=NULL;
            int i=0;
            if(pos>size || pos<1)
            {
                cout<<"Invalid Position"<<endl;
            }
            else if(pos==1 && temp->next!=head)
            {
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=head->next;
                head=head->next;
            }
            else
            {
                if(temp->next==head)
                {
                    delete(temp);
                    head=NULL;
                }
                else
                {
                    while(i<pos-1)
                    {
                        prev=temp;
                        temp=temp->next;
                        i++;
                    }
                    prev->next=temp->next;
                    delete(temp);
                }
                size--;
            }
        }
        void search(int data)
        {
            node *temp=head;
            int i;
            cout<<"The position is ";
            int j=0;
            for(i=0;i<size;i++)
            {
                if(temp->data==data)
                {
                    cout<<i+1<<";";
                    j++;
                }
                temp=temp->next;
            }
            if(j==0)
            {
                cout<<"not found";
            }
            cout<<endl;
        }
        int getsize()
        {
            return this->size;
        }
        void display()
        {
            node*temp=head;
            if(temp==NULL)
            {
                cout<<"empty"<<endl;
            }
            else
            {
                while(temp->next!=head)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<temp->data;
            }
            cout<<endl;
        }
        
};
int main()
{
    int ch;
    cllist list;
    cout<<" 1)Insert\n 2)Delete\n 3)Search\n 4)Display\n 5)exit"<<endl;
    while(ch!=5)
    {
        cout<<"Enter your choice :";
        cin>>ch;
        if(ch==1)
        {
            int a,b,c;
            cout<<"Enter 1)insert any position 2)insert at end :";
            cin>>a;
            if(a==1)
            {
                cout<<"Enter the data to insert :";
                cin>>b;
                cout<<"Enter the position :";
                cin>>c;
                list.insertnode(new node(b),c);
            }
            else if(a==2)
            {
                cout<<"Enter the data to insert at end :";
                cin>>b;
                list.insertnode(new node(b));
            }
            else
            {
                cout<<"Invalid choice"<<endl;
            }
        }
        else if(ch==2)
        {
            int a,b,c;
            cout<<"Enter 1)delete any position 2)delete at end :";
            cin>>a;
            if(a==1)
            {
                cout<<"Enter the position :";
                cin>>c;
                list.deletenode(c);
            }
            else if(a==2)
            {
                list.deletenode();
            }
            else
            {
                cout<<"Invalid choice"<<endl;
            }
        }
        else if(ch==3)
        {
            if(list.getsize()==0)
            {
                cout<<"list is empty"<<endl;
            }
            else
            {
                int a;
                cout<<"enter the data to search in list :";
                cin>>a;
                list.search(a);
            }
        }
        else if(ch==4)
        {
            cout<<"The list is :";
            list.display();
        }
        else if(ch==5)
        {
            break;
        }
        else
        {
            cout<<"Enter the valid option"<<endl;
        }
    }
    return 0;
}