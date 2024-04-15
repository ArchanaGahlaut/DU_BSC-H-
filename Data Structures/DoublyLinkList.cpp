#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        next=NULL;
        prev=NULL;
    }
};
class LinkedList
{
    Node *head;
public:
    LinkedList()
    {
        head=NULL;
    }
    void Insert_at_Begin(int data)
    {
        Node *newNode= new Node();
        newNode->data= data;
        if (head==NULL)
            head=newNode;
        else
        {
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
    }
    void Insert_at_End(int data)
    {
        Node *newNode= new Node();
        newNode->data=data;
        if (head==NULL)
             head=newNode;
        else
        {
            Node *ptr=head;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            newNode->prev=ptr;
            ptr->next=newNode;
        }
    }
    void Insert_at_Location(int data,int loc)
    {
        Node *newNode= new Node();
        newNode->data=data;
        Node *ptr=head;
        Node *ptr1=head;
        for (int i=1;i<loc-1;i++)
        {
             ptr=ptr->next;
             ptr1=ptr1->next;
        }
        ptr1=ptr1->next;
        newNode->next=ptr1;
        ptr1->prev=newNode;
        ptr->next=newNode;
        newNode->prev=ptr;
    }
    void Delete_from_Begin()
    {
        if(head==NULL)
        cout<<"Linked List is empty!"<<endl;
        else
        {
            Node *ptr=head;
            cout<<"Deleted node is "<<ptr->data<<endl;
            head=head->next;
            head->prev=NULL;
            delete(ptr);
        }
    }
    void Delete_from_End()
    {
        if (head==NULL)
           cout<<"Linked List is empty"<<endl;
        else
        {
            if (head->next==NULL)
            {
                cout<<"Delete node is "<<head->data<<endl;
                delete(head);
                head=NULL;
            }
            else
            {
                Node *ptr=head;
                Node *ptr1=head->next;
                while (ptr1->next!=NULL)
                {
                     ptr=ptr->next;
                     ptr1=ptr1->next;
                }    
                cout<<"Deleted node is "<<ptr1->data<<endl;
                delete(ptr1);
                ptr->next=NULL;
            }
        }
    }
    void Delete_from_Location(int loc)
    {
        if (head==NULL)
        cout<<"Linked List is empty"<<endl;
        else
        {
            Node *ptr=head;
            Node *ptr1=head->next;
            Node *ptr2=head->next->next;
            for (int i=1;i<loc-1;i++)
            {
                ptr=ptr->next;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            cout<<"Deleted node is "<<ptr1->data<<endl;
            ptr->next=ptr2;
            ptr2->prev=ptr;
            delete(ptr1);
        }
    }
     void Display()
    {
        if (head==NULL)
        cout<<"List is empty "<<endl;
        else
        {
            Node *ptr=head;
            cout<<"List elements are "<<endl;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<"->";
                ptr=ptr->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};
int main()
{
    LinkedList LL;
    int ch,num,loc;
    cout<<"~~~~~~~~~~~~~~~Linked List~~~~~~~~~~~~~~~"<<endl;
    do
    {
        cout<<"1. Insert an element at the beginning"<<endl;
        cout<<"2. Insert an element at the end"<<endl;
        cout<<"3. Insert an element at a location"<<endl;
        
        cout<<"4. delete an element at the beginning"<<endl;
        cout<<"5. delete an element at the end"<<endl;
        cout<<"6. delete an element at a location"<<endl;
        
        cout<<"7. Display all the elements"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        if (ch==1)
        {
            cout<<"Enter the element"<<endl;
            cin>>num;
            LL.Insert_at_Begin(num);
        }
        if (ch==2)
        {
            cout<<"Enter the element"<<endl;
            cin>>num;
            LL.Insert_at_End(num);
        }
        if (ch==3)
        {
            cout<<"Enter the element"<<endl;
            cin>>num;
            cout<<"Enter the location at which element is inserted"<<endl;
            cin>>loc;
            LL.Insert_at_Location(num,loc);
        }
        if (ch==4)
        {
            LL.Delete_from_Begin();
        }
        if (ch==5)
        {
            LL.Delete_from_End();
        }
        if (ch==6)
        {
            cout<<"Enter the location from where element is deleted"<<endl;
            cin>>loc;
            LL.Delete_from_Location(loc);
        }
        if (ch==7)
        {
            LL.Display();
        }
        if (ch==8)
        {
            cout<<"Exiting the program"<<endl;
        }
        if (ch>8)
        {
            cout<<"Invalid choice"<<endl;
        }
    }while (ch!=8);   
}