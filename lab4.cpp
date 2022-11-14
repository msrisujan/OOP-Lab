#include<iostream>
using namespace std;
class node
{
    private :
        int data;
        node *next;
        node *prev;
    public :
        node(int data=0,node*next=NULL,node*prev=NULL)
        {
            this->data=data;
            this->next=next;
            this->prev=prev;
        }
        inline int getdata()
        {
            return(this->data);
        }
        friend class dllist;
};
class dllist
{
    private :
        node*head;
        node*tail;
    public :
        dllist(node*head=NULL,node*tail=NULL)
        {
            this->head=head;
            this->tail=tail;
        }
        void sort_insert(node* p)
        {
            if (head == NULL)
            {
                head = p;
                tail = p;
                return;
            }
            node *temp = this->head;
            while (temp->data <= p->data && temp->next != NULL)
            {
                temp = temp->next;
            }
            if (temp->next == NULL && p->data >= temp->data)
            {
                temp->next = p;
                p->prev = temp;
                this->tail = p;
            }
            else if (temp == this->head)
            {
                this->head->prev = p;
                p->next = this->head;
                this->head = p;
            }
            else
            {
                p->prev = temp->prev;
                p->next = temp;
                p->prev->next = p;
                temp->prev = p;
            }
            return;
        }
        void deletenode(int pos)
        {
            node *temp = this->head;
        int i;
        for (i = 1; i < pos && temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        if (pos > i || pos < 1)
        {
            cout << "Position " << pos << " does not exist" << endl;
            return;
        }
        if (this->tail == this->head)
        {
            delete this->head;
            this->tail = this->head = NULL;
            return;
        }
        if (temp->next == NULL)
        {
            tail = tail->prev;
            delete (tail->next);
            tail->next = NULL;
        }
        else if (temp == this->head)
        {
            head = head->next;
            delete (head->prev);
            head->prev = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete (temp);
        }
        }
        void display()
        {
            node*temp=head;
            if(temp==NULL)
            {
                cout<<"empty"<<endl;
            }
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
            return;
        }
        void clearlist()
        {
            node *temp=head;
            while(temp!=NULL)
            {
                head=head->next;
                delete(temp);
                temp=head;
            }
            head=tail=NULL;
        }
        dllist merge(dllist list)
        {
            dllist list3;
            node*temp1=head,*temp2=list.head;
            while(temp1!=NULL && temp2!=NULL)
            {
                if(temp1->data < temp2->data)
                {
                    list3.sort_insert(new node(temp1->data));
                    temp1=temp1->next;
                }
                else
                {
                    list3.sort_insert(new node(temp2->data));
                    temp2=temp2->next;
                }
            }
                while(temp2!=NULL)
                {
                    list3.sort_insert(new node(temp2->data));
                    temp2=temp2->next;
                }
                while(temp1!=NULL)
                {
                    list3.sort_insert(new node(temp1->data));
                    temp1=temp1->next;
                }
            return list3;
        }
};
int main()
{
    int ch;
    dllist list,list2;
    while(ch!=5)
    {
        cout<<"enter your choice\n 1)Insert\n 2)Delete\n 3)Display\n 4)Merge\n 5)exit\n";
        cin>>ch;
        if(ch==1)
        {
            int data;
            cout<<"Enter number to insert"<<endl;
            cin>>data;
            list.sort_insert(new node(data));
        }
        else if(ch==2)
        {
            int num;
            cout<<"enter the place to delete"<<endl;
            cin>>num;
            list.deletenode(num);
        }
        else if(ch==3)
        {
            cout<<"the list is : ";
            list.display();
        }
        else if(ch==4)
        {
            dllist list3;
            list2.clearlist();
            list3.clearlist();
            int m,i=0;
            int num;
            cout<<"enter number of elements in list2"<<endl;
            cin>>m;
            cout<<"enter the elements in list2"<<endl;
            while(i<m)
            {
                cin>>num;
                list2.sort_insert(new node(num));
                i++;
            }
            cout<<"the list1 is : ";
            list.display();
            cout<<"the list2 is : ";
            list2.display();
            list3=list2.merge(list);
            cout<<"the merged list is : ";
            list3.display();
        }
        else if(ch==5)
        {
            break;
        }
    }
    return 0;
}