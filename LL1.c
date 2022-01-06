// Samuel Emard-Thibault - 01/05/2022
// Basic singly linked list structure for general use with stack and queue functionalities

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

// adds argument node to front of argument list
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

// adds argument nodee to the tail of argument list
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

// routine to print list for testing
void printList(plist list)
{
    pnode temp = (pnode)malloc(sizeof(node));
    temp = list->head;

    while (temp != NULL)
    {
        printf("%d", temp->val);
        temp = temp->next;
    }
}

int main()
{
    plist list1 = newList();

    for (int i = 0; i < NUM; i++)
    {
        addBack(newNode(i), list1);
    }

    addFront(newNode(6), list1);
    printList(list1);
}