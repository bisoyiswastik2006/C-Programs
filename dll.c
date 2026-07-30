#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert()
{
    struct Node *newnode, *temp;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

void display()
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void search()
{
    int key, pos = 1;
    struct Node *temp = head;

    printf("Enter value: ");
    scanf("%d", &key);

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Found at position %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }

    printf("Not Found\n");
}

void deleteNode()
{
    int key;
    struct Node *temp = head;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Element Not Found\n");
        return;
    }

    if(temp == head)
    {
        head = temp->next;
        if(head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Deleted Successfully\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: search(); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
}