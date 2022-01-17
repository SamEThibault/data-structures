// Samuel Emard-Thibault - 01/05/2022
// Basic singly linked list structure for general use with stack/queue/dequeue functionalities

#include <stdio.h>
#include <stdlib.h>
#define NUM 10 // value to test populating the list

// singly linked node structure
typedef struct node
{
    struct node *next;
    int val;
} node, *pnode;

// linked list with head and tail node ptrs
typedef struct list
{
    pnode head;
    pnode tail;
} list, *plist;

// initializes and returns new list if memory is allocated succesfully
plist newList()
{
    plist temp = (plist)malloc(sizeof(list));

    if (temp != NULL)
    {
        temp->head = NULL;
        temp->tail = NULL;
    }
    else
    {
        printf("ERROR: Unable to initialize list\n");
    }

    return temp;
}

// initializes and returns node with value a
pnode newNode(int a)
{
    pnode temp = (pnode)malloc(sizeof(node));

    if (temp != NULL)
    {
        temp->val = a;
        temp->next = NULL;
    }
    else
    {
        printf("ERROR: Unable to initialize node\n");
    }
    return temp;
}

// adds argument node to front of argument list (dequeue)
void addFront(pnode node, plist list)
{
    // if list empty, both head and tail point to node
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    // if not, let new node point to existing head and update head to point to new node
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

// adds argument node to the tail of argument list (stack/queue)
void addBack(pnode node, plist list)
{
    // same logic as previous function
    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    // if not, use convenient tail ptr: point tail node to new one, update tail ptr
    {
        list->tail->next = node;
        list->tail = node;
    }
}

// delete head node from list (queue)
void delHead(plist list)
{
    // allocate memory for temp ptr
    pnode ptr = (pnode)malloc(sizeof(pnode));

    // if we got the memory: assign temp to the head of the list,
    // update head to the next node, and free memory of previous head
    if (ptr != NULL)
    {
        ptr = list->head;
        int val = ptr->val; // store old head value to print
        list->head = list->head->next;
        free(ptr);

        printf("Succesfully deleted head node containing value %d\n", val);
    }
    else
    {
        printf("ERROR: Unable to delete node.");
    }
}

// delete tail node from list (stack)
void delTail(plist list)
{
    // allocate memory for temp ptr
    pnode ptr = (pnode)malloc(sizeof(pnode));

    // if we got memory: assign temp to the head of the list
    if (ptr != NULL)
    {
        ptr = list->head;

        // increment ptr from head until it's pointing to the node BEFORE the tail node
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }

        // store the value of the tail node before deleting, then free
        int val = ptr->next->val;
        free(ptr->next);
        list->tail = ptr; // update list tail ptr
        ptr->next = NULL; // set new tail ptr to point to NULL

        printf("Succesfully deleted tail node containing value %d\n", val);
    }
    else
    {
        printf("ERROR: Unable to delete node.");
    }
}

// routine to print list for testing
void printList(plist list)
{
    pnode temp = (pnode)malloc(sizeof(node));
    temp = list->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    // initialize list pointer
    plist list1 = newList();

    // add elements to the tail of the specified list from 0 to the defined NUM
    for (int i = 0; i < NUM; i++)
    {
        addBack(newNode(i), list1);
    }

    printList(list1);

    // TESTING:

    // test: add node to front and re-print list
    addFront(newNode(6), list1);
    printList(list1);

    // test front delete function then re-print list
    delHead(list1);
    printList(list1);

    // test rear delete function then re-print list
    delTail(list1);
    printList(list1);
}