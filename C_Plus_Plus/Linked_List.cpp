#include <iostream>

using namespace std;

struct persons
{
    int age;
    char name1[20], name2[20];
    persons *next = NULL;
};

persons *first = NULL;

void view()
{
    persons *dummy;
    dummy = first;
    int i=1;
    while(dummy != NULL)
    {
        cout<<"\n("<<i<<") "<<dummy->name1<<" "<<dummy->name2<<" -> "<<dummy->age<<"\n";
        dummy = dummy->next;
        i++;
    }
    cout<<"\n";
}

void add()
{
    persons *start = new persons;
    if(first == NULL)
    {
        first = start;
        start->next = NULL;
    }
    else
    {
        start->next = first;
        first = start;
    }
    cout<<"Enter First Name of the person you want to add (without any space) : ";
    cin>>start->name1;
    cout<<"Enter Last Name of "<<start->name1<<" (without any space) : ";
    cin>>start->name2;
    cout<<"Enter Mr. "<<start->name2<<"\'s age : ";
    cin>>start->age;
    cout<<"\n";
}

void del_person()
{
    int n;
    view();
    cout<<"Enter the serial number of the person you want to delete: ";
    cin>>n;
    persons *dummy = first;
    if(n==1)
    {
        first = first->next;
    }
    else
    {
        for(n; n>2; n--)
        {
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;
    }
}

void name_edit()
{
    int n;
    persons *dummy = first;
    view();
    cout<<"Enter the serial number of the person whose name you want to edit: ";
    cin>>n;
    for(n; n>1; n--)
    {
        dummy = dummy->next;
    }
    cout<<"\nEnter 1 if you want to edit first name and 2 for last name: ";
    cin>>n;
    if(n==1)
    {
        cout<<"\nEnter new first name: ";
        cin>>dummy->name1;
    }
    else
    {
        cout<<"\nEnter new last name: ";
        cin>>dummy->name2;
    }
}

void age_edit()
{
    int n;
    persons *dummy = first;
    view();
    cout<<"Enter the serial number of the person whose age you want to edit: ";
    cin>>n;
    for(n; n>1; n--)
    {
        dummy = dummy->next;
    }
    cout<<"\nEnter new age: ";
    cin>>dummy->age;
}

int main()
{
    int choice;
    while(true)
    {
        cout<<"Choose one of the following options?";
        cout<<"\n1: Add a person \t 2: Delete a person \t 3: View the list";
        cout<<"\n4: Change name \t\t 5: Change age \t\t 6: exit";
        cout<<"\nYour choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            del_person();
            break;
        case 3:
            if(first == NULL)
            {
                cout<<"\nThe list is empty!!! \nYou should first add a person.\n\n";
            }
            else
            {
                view();
            }
            break;
        case 4:
            name_edit();
            break;
        case 5:
            age_edit();
            break;
        case 6:
            return 0;
            break;
        default:
            cout<<"Try Again\n";
            break;
        }
    }
    return 0;
}
