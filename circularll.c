#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert()
{
    struct Node *newnode, *temp;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("(Head)\n");
}

void search()
{
    int key, pos = 1;
    struct Node *temp = head;

    printf("Enter value: ");
    scanf("%d", &key);

    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    do
    {
        if(temp->data == key)
        {
            printf("Found at position %d\n", pos);
            return;
        }

        pos++;
        temp = temp->next;

    } while(temp != head);

    printf("Not Found\n");
}

void deleteNode()
{
    int key;
    struct Node *temp = head, *prev = NULL;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    if(head == NULL)
        return;

    while(temp->data != key)
    {
        prev = temp;
        temp = temp->next;

        if(temp == head)
        {
            printf("Not Found\n");
            return;
        }
    }

    if(temp == head)
    {
        if(head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct Node *last = head;

            while(last->next != head)
                last = last->next;

            last->next = head->next;
            head = head->next;
            free(temp);
        }
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }

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