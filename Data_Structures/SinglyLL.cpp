#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLL
{
    public:
        PNODE first;
        PNODE temp;
        PNODE target;
        int iCount;
        int i;

        SinglyLL()
        {
            cout<<"Object of SinglyLL get created.\n";
            first = NULL;
            temp = NULL;
            target = NULL;
            iCount = 0;
            i = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
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

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
            }

            iCount++;
        }

        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                first = first->next;
                delete temp;
            }

            iCount--;
        }

        void DeleteLast()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = NULL;
            }

            iCount--;
        }

        void Display()
        {
            temp = first;

            while(temp != NULL)
            {
                cout<<" | "<<temp->data<<" | -> ";
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
            if(pos < 1 || pos > (iCount + 1))
            {
                return;
            }
            
            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == (iCount + 1))
            {
                InsertLast(no);
            }
            else
            {
                PNODE newn = NULL;

                newn = new NODE;

                newn->data = no;
                newn->next = NULL;

                temp = first;

                for(i = 1; i < (pos - 1); i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > (iCount))
            {
                return;
            }    
            
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

                target = temp->next;

                temp->next = temp->next->next;
                delete target;

                iCount--;
            }
        }       
};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

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

