#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
class DoubblyCLL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    DoubblyCLL()
    {
        // cout << "INside constructer\n";
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if ((first == NULL) && (last == NULL)) // if(iCount == 0)
        {
            first = newn;
            last = newn;
            last->next = first;
            last->prev = first;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
            first->prev = last;
            last->next = first;
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

        if ((first == NULL) && (last == NULL)) // if(iCount == 0)
        {
            first = newn;
            last = newn;
            last->next = first;
            last->prev = first;
        }
        else
        {
            last->next = newn;
            newn->prev = last;
            last = newn;
            last->next = first;
            first->prev = last;
        }
        iCount++;
    }

    void DeleteFirst()
    {

        if ((first == NULL) && (last == NULL)) // if(iCount == 0)
        {
            return;
        }
        else if (first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
            first->prev = last;
        }
        iCount--;
    }

    void DeleteLast()
    {
        PNODE temp = NULL;
        if ((first == NULL) && (last == NULL)) // if(iCount == 0)
        {
            return;
        }
        else
        {

            temp = first;
            while (temp->next != last)
            {
                temp = temp->next;
            }

            delete last;
            last = temp;
            last->next = first;
            first->prev = last;
        }
        iCount--;
    }

    void Display()
    {
        cout << "\n";
        PNODE temp = NULL;
        if ((first == NULL) && (last == NULL)) // if(iCount == 0)
        {
            cout << "Linked list is empty\n";
            return;
        }
        temp = first;
        do
        {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        } while (temp != first); // while(temp!=last->next)
        cout << "\n";
    }

    void DisplayRev()
    {
        cout << "\n";
        PNODE temp = NULL;
        if ((first == NULL) && (last == NULL)) // if(iCount == 0)
        {
            cout << "Linked list is empty\n";
            return;
        }
        temp = last;
        do
        {
            cout << "[" << temp->data << "] -> ";
            temp = temp->prev;
        } while (temp != last); // while(temp!=last->next)
        cout << "\n";
    }

    int Count()
    {
        return iCount;
    }

    void DeleteAtPos(int pos)
    {
        PNODE temp = NULL;
        PNODE target = NULL;
        if (pos < 0 || pos > iCount)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = target->next;
            target->next->prev = temp;
            delete target;
            iCount--;
        }
    }

    void InsertAtPos(int no, int pos)
    {
        PNODE temp = NULL;
        PNODE newn = NULL;
        if (pos < 0 || pos > (iCount + 1))
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount)
        {
            InsertLast(no);
        }
        else
        {
            newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            temp = first;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            newn->prev = temp;
            temp->next = newn;
            newn->next->prev = newn;

            iCount++;
        }
    }
};

int main()
{
    DoubblyCLL sobj;
    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    sobj.DisplayRev();
    cout << "Number of Elements is " << sobj.Count();
    sobj.InsertAtPos(191, 5);

    sobj.Display();
    cout << "Number of Elements is " << sobj.Count();

    sobj.DeleteAtPos(5);
    sobj.Display();
    cout << "Number of Elements is " << sobj.Count();
    sobj.DeleteFirst();
    sobj.Display();
    cout << "Number of Elements is " << sobj.Count();

    sobj.DeleteLast();
    sobj.Display();
    cout << "Number of Elements is " << sobj.Count();
    sobj.DisplayRev();

    return 0;
}