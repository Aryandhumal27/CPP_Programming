/////////////////////////////////////////////////////////////////////////////////////////////////
//                              Generalized Data Structure Library
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------------------------------
Type                            Name of class for node                          Name of class for functionality
-------------------------------------------------------------------------------------------------------------------------
Singly Linear                   SinglyLLLnode                                   SinglyLLL               
Singly Circular                 SinglyCLLnode                                   SinglyCLL
Doubly Linear                   DoublyLLLnode                                   DoublyLLL
Doubly Circular                 DOublyCLLnode                                   DoublyCLL
--------------------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                      Singly Linear Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:                
        SinglyLLLnode<T> *first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);            
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyLLL
//  Input :             None
//  Output :            Initializes object
//  Description :       Constructor used to initialize SinglyLL object
//                      by setting first pointer to NULL.
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL get created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position in SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)  
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;            

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position in SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)           
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to Delete node at first position in SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to Delete node at last position in SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL) 
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to Display elements from SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   
    {
        cout<<" | "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to Display Count of elements from SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of the node, It's Position
//  Output :            Nothing
//  Description :       Used to insert node at given position in SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;
    int i = 0;

    if(pos < 1 || pos > (this->iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for(i = 1; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }   
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position of the node
//  Output :            Nothing
//  Description :       Used to Delete node from given position in SinglyLLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int i = 0;

    if(pos < 1 || pos > (this->iCount))
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == (this->iCount))
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = temp->next->next;
        delete target;
        
        this->iCount--;
    }   
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                      Singly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyCLL
//  Input :             None
//  Output :            Initializes linked list
//  Description :       Constructor used to initialize Singly Circular Linked List
//                      by setting first and last pointers to NULL and
//                      initializing node count to zero.
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert a new node at the beginning of SinglyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->last->next = this->first;
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert a new node at the end of SinglyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert a new node at given position in SinglyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> *newn = NULL;
    SinglyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > (iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete the first node of SinglyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first; 
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete the last node of SinglyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete temp->next;
        this->last = temp;

        this->last->next = this->first;   
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to remove a node from given position
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > (iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == (iCount))
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = temp->next->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display elements of SinglyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> *temp = NULL;

    temp = this->first;

    cout<<"-> ";

    do
    {
        cout<<" | "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             None
//  Output :            Returns number of nodes
//  Description :       Used to return total number of nodes present in SInglyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                      Doubly Linear Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    public:
        DoublyLLLnode<T> *first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyLLL
//  Input :             None
//  Output :            Initializes linked list
//  Description :       Constructor used to initialize Doubly Linear Linked List
//                      by setting first pointer to NULL and initializing
//                      node count to zero.
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List get created\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert a new node at the beginning of DOublyLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert a new node at the end of DoublyLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert a new node at the given position in DoublyLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > (this->iCount + 1)))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete the first node of DoublyLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL Contain 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL Contain more than 1 node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete the last node of DoublyLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL Contain 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL Contain more than 1 node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete a node from the given position
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > (this->iCount)))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == (this->iCount))
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             None
//  Output :            Displays all nodes
//  Description :       Used to display all elements of DoublyLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout<<"\nNULL <=>";
    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to return the total number of nodes from DoublyLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                      Doubly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T>* next;
        DoublyCLLnode<T>* prev;

        DoublyCLLnode<T>(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyCLL
//  Input :             None
//  Output :            Initializes linked list
//  Description :       Constructor used to initialize Doubly Circular Linked List
//                      by setting first and last pointers to NULL and
//                      initializing node count to zero.
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Object of DoublyCLL get created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert a new node at the beginning of DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert a new node at the end of DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;

}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert a new node at the given position in DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> * newn = NULL;
    DoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 && pos > (this->iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == (this->iCount + 1))
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = this->first;

        for(iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete the first node of DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete the last node of DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete a node from the given position in DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 && pos > (this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == (this->iCount))
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display all elements of DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<" <=> ";
    do
    {
        cout<<" | "<<temp->data<<" | <=> ";
        temp = temp->next;
    } while (temp != this->last->next);

    cout<<"\n";
    
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Returns number of nodes
//  Description :       Used to return the total number of nodes present in DoublyCLL
//  Author :            Aryan Pandharinath Dhumal
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////End of Library/////////////////////////////////////////

int main()
{

    return 0;
}