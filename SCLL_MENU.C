// Singly Circulat  Linked list using c with dynamic appproch and using switch case

#include <stdio.h>
#include <stdlib.h>

// creation of structure
struct node
{
    int data;
    struct node *next;
};

// typedef for structre use
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

// function to insert the value at start
void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*first == NULL && (*last) == NULL)
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
    }
    else
    {
        newn->next = *first;
        *first = newn;
        (*last)->next = *first;
    }
}

// function to insert the value at last of linked list i.e. from the tail
void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*first == NULL && (*last) == NULL)
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
        (*last)->next = *first;
    }
}

// function to delete the node from start
void Deletefirst(PPNODE first, PPNODE last)
{
    if (*first == NULL && *last == NULL)
    {
        return;
    }
    else if (*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*last)->next);
        (*last)->next = *first;
    }
}

// function to delete node from tail or last
void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;
    if (*first == NULL && *last == NULL)
    {
        return;
    }
    else if (*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        while (temp->next != *last)
        {
            temp = temp->next;
        }
        free(*last);
        *last = temp;
        (*last)->next = *first;
    }
}

// function to display the linked list
void Display(PNODE first, PNODE last)
{
    if (first == NULL && (last) == NULL)
    {
        return;
    }
    do
    {
        printf("%d -> ", first->data);
        first = first->next;
    } while (first != last->next);
    printf("\n");
}

// function to count the number of nodes in liked list
int Count(PNODE first, PNODE last)
{
    int iCount = 0;
    if (first == NULL && (last) == NULL)
    {
        return 0;
    }
    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);

    return iCount;
}

// function to delete a node from linked list at desired position
void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int icount = 0, iCnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    // caluculate the no of nodes in Linked list
    icount = Count(*first, *last);

    // filter the given position is valid or invalid
    if (pos < 0 || pos > icount)
    {
        printf("Invalid POsition.\n");
        return;
    }

    // check if position is 1 then call the Deletefirst funtion
    if (pos == 1)
    {
        Deletefirst(first, last);
    }
    // check if position is last then call the DeleteLast funtion
    else if (pos == icount)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

// function to insert a node from linked list at desired position
void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int iCount = 0;

    // calculate the no of nodes
    iCount = Count(*first, *last);

    // validate the position
    if (pos < 0 || pos > (iCount + 1))
    {
        printf("Invalid Position");
        return;
    }
    // check if position is 1 then call the insertFirst funtion
    if (pos == 1)
    {
        InsertFirst(first, last, no);
    }
    // check if position is last then call the insertLast funtion
    else if (pos == iCount)
    {
        InsertLast(first, last, no);
    }
    else
    {
        int iCnt = 0;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}
int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0, choice = 0, iValue = 0, iPos = 0;

    printf("\n----------------------------------------------------------");
    printf("\n//////////////// Singly Circular linked List /////////////");
    printf("\n----------------------------------------------------------");

    while (1)
    {
        printf("\n1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete the node from first position\n");
        printf("5 : Delete the node from last position\n");
        printf("6 : Delete the node from given position\n");
        printf("7 : Display all elements of LinkedList\n");
        printf("8 : Count number of nodes of LinkedList\n");
        printf("0 : Terminate the application\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting the program\nThank you for you time to check this code works or not..");
            exit(1);
            break;
        case 1:
            printf("Enter the value that you want to insert into likned list: \n");
            scanf("%d", &iValue);
            InsertFirst(&head, &tail, iValue);
            break;
        case 2:
            printf("Enter the value that you want to insert into likned list: \n");
            scanf("%d", &iValue);
            InsertLast(&head, &tail, iValue);
            break;
        case 3:
            printf("Enter the value that you want to insert into likned list: \n");
            scanf("%d", &iValue);
            printf("Enter the position at which you insert Element: \n");
            scanf("%d", &iPos);
            InsertAtPos(&head, &tail, iValue, iPos);
            break;
        case 4:
            Deletefirst(&head, &tail);
            printf("First node in the Linked list is deleted\n ");
            break;
        case 5:
            DeleteLast(&head, &tail);
            printf("Last node in the Linked list is deleted\n ");
            break;
        case 6:
            printf("Enter the position from you want to delete the node:\n");
            scanf("%d", &iPos);
            DeleteAtPos(&head, &tail, iPos);
            printf("%d node in the Linked list is deleted\n ", iPos);
            break;
        case 7:
            printf("The Elements of the linked list are as below : \n");
            Display(head, tail);
            break;
        case 8:
            printf("There are %d nodes in the linked list.\n", Count(head, tail));
            break;
        default:
            printf("Invalid choice please Enter the correct choice\n");
            break;
        }
    }
    return 0;
}
