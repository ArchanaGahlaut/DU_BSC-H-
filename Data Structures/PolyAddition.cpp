#include <iostream>
using namespace std;
class Node
{
public:
    int coeff;
    int power;
    Node *next;
    Node()
    {
        next=NULL;
    }
};
class LinkedList
{
    
public:
    Node *head;
    
    Node* CreatePoly(Node *head)
    {
        int num,coeff,power;
        cout<<"Please enter the power from highest to lowest"<<endl;
        char ch='y';
        while(ch=='y')
        {
        Node * newnode = new Node();
        cout<<"Enter the coefficient"<<endl;
        cin>>newnode->coeff;
        cout<<"Enter the power"<<endl;
        cin>>newnode->power;

        if(head==NULL)
            head=newnode;
        else
        {
            Node *ptr=head;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
         }
         cout<<"Do you wish to add more terms(y/n)...  "<<endl;
         cin>>ch;
        }
        return (head);
    }
    Node * AddPoly(Node *ptr1,Node *ptr2)
    {
        Node *newnode , *ptr3 , *head3=NULL;
        while (ptr1!=NULL && ptr2!=NULL)
        {
            newnode =new Node();
            if (ptr1->power==ptr2->power)
            {
                newnode->power=ptr1->power;
                newnode->coeff=(ptr1->coeff)+(ptr2->coeff);
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else if (ptr1->power>ptr2->power)
            {
                newnode->power=ptr1->power;
                newnode->coeff=ptr1->coeff;
                ptr1=ptr1->next;
            }
            else if (ptr1->power<ptr2->power)
            {
                newnode->power=ptr2->power;
                newnode->coeff=ptr2->coeff;
                ptr2=ptr2->next;
            }
            
            if(head3==NULL)
            {
                head3=newnode;
                newnode->next=NULL;
            }
            else
            {
                ptr3=head3;
                while(ptr3->next!=NULL)
                   ptr3=ptr3->next;
                ptr3->next=newnode;
            }
        }
        while(ptr1==NULL && ptr2!=NULL)
        {
            newnode=new Node();
            newnode->coeff=ptr2->coeff;
            newnode->power=ptr2->power;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
            ptr3->next=newnode;
        }
        while(ptr2==NULL && ptr1!=NULL)
        {
            newnode=new Node();
            newnode->coeff=ptr1->coeff;
            newnode->power=ptr1->power;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
            ptr3->next=newnode;
        }
        return(head3);
    }
    void DisplayPoly(Node *head)
    {
        cout<<"The Polynomial is "<<endl;
        Node * ptr=head;
        while (ptr->next!=NULL)
        {
            cout<<ptr->coeff<<"x^"<<ptr->power<<"+";
            ptr=ptr->next;
        }
        if (ptr->power==0)
            cout<<ptr->coeff<<endl;
        else
            cout<<ptr->coeff<<"x^"<<ptr->power<<endl;
        
    }
};
int main()
{   
    LinkedList l1,l2,l3;
    l1.head=NULL;
    l2.head=NULL;
    l3.head=NULL;
    int choice=1;
    while( choice != 5)
    {
    cout<<"~~~~~~~~~~~~~~~Polynomial Addition~~~~~~~~~~~~~~~"<<endl;
    cout<<"1. Enter polynomial 1"<<endl;
    cout<<"2. Enter polynomial 2"<<endl;
    cout<<"3. Add polynomials"<<endl;
    cout<<"4. display"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    if (choice==1)
         l1.head=l1.CreatePoly(l1.head);
    if (choice==2)
         l2.head=l2.CreatePoly(l2.head);
    if (choice==3)
         l3.head=l3.AddPoly(l1.head,l2.head);
         
    if (choice==4)
    {
        if (l1.head!=NULL)
             l1.DisplayPoly(l1.head);
        if (l2.head!=NULL)
             l2.DisplayPoly(l2.head);
        if (l3.head!=NULL)
             l3.DisplayPoly(l3.head);
        }
    if (choice ==5)
         break;
    }         
    return 0;
}