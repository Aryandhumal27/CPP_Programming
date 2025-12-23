#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    public:
        PNODE first;
        PNODE last;
        PNODE temp;
        int iCount;
        int i;

    DoublyLL()
    {
        first = NULL;
        last = NULL;
        temp = NULL;
        iCount = 0;
        i = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        
        iCount++;
    }

    void InsertLast(int no)
    {

        PNODE newn = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            newn->prev = last;
            last = newn;
        }
        
        iCount++;
    }

    void DeleteFirst()
    {
        if(first == NULL && last == NULL)
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete first->prev;
            first->prev = NULL;
        }

        iCount--;
    }

    void DeleteLast()
    {
        if(first == NULL && last == NULL)
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            last = last->prev;
            delete last->next;
            last->next = NULL;
        }

        iCount--;
    }

    void Display()
    {
        temp = first;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" | <=> ";
            temp = temp->next;
        }

        cout<<"NULL\n";
    }

    int Count()
    {
        return iCount;
    }

    void InsertAtPos(int no, int pos)
    {
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == (iCount+1))
        {
            InsertLast(no);
        }
        else
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            temp = first;

            for(i = 1; i < (pos - 1); i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            newn->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
        }

        iCount++;
    }

    void DeleteAtPos(int pos)
    {
        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;

            for(i = 1; i < (pos - 1); i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
        }

        iCount--;
    }
};

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(11, 3);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}