#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
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
        if(head==NULL)
        {
            newNode->next=newNode;
            head=newNode;
        }
        else
        {
            Node *ptr=head;
            while (ptr->next!=head)
                ptr=ptr->next;
            newNode->next=head;
            ptr->next=newNode;
            head=newNode;
        }
    }
    void Insert_at_End(int data)
    {
        Node *newNode= new Node();
        newNode->data=data;
        if (head==NULL)
        {
            newNode->next=newNode;
            head=newNode;
        }
        else
        {
            Node *ptr=head;
            while(ptr->next!=head)
                ptr=ptr->next;
            ptr->next=newNode;
            newNode->next=head;
        }
    }
    void Insert_at_Location(int data,int loc)
    {
        Node *newNode= new Node();
        newNode->data=data;
        Node *ptr=head;
        for (int i=1;i<loc-1;i++)
        ptr=ptr->next;
        newNode->next=ptr->next;
        ptr->next=newNode;
    }
    void Delete_from_Begin()
    {
        if(head==NULL)
        cout<<"List is empty!"<<endl;
        else
        {
            Node *ptr=head;
            while (ptr->next!=head)
                ptr=ptr->next;
            Node *temp=head;
            ptr->next=head->next;
            head=head->next;
            cout<<"Deleted node is "<<temp->data<<endl;
            delete(temp);
        }
    }
    void Delete_from_End()
    {
        if (head==NULL)
           cout<<"List is empty"<<endl;
        else
        {
            Node *ptr=head;
            Node *ptr1=head->next;
            while (ptr1->next!=head)
            {
                ptr=ptr->next;
                ptr1=ptr1->next;
            }
            ptr->next=head;
            cout<<"Deleted node is "<<ptr1->data<<endl;
            delete(ptr1); 
        }
    }
    void Delete_from_Location(int loc)
    {
        if (head==NULL)
        cout<<"List is empty"<<endl;
        else
        {
            Node *ptr=head;
            Node *ptr1;
            for (int i=1;i<loc;i++)
            {
                ptr1=ptr;
                ptr=ptr->next;
            }
            cout<<"Deleted node is "<<ptr->data<<endl;
            ptr1->next=ptr->next;
            delete(ptr);
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
            while(ptr->next!=head)
            {
                cout<<ptr->data<<"->";
                ptr=ptr->next;
            }
            cout<<(ptr->data)<<endl;
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