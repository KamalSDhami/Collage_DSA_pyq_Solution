//inauer at the end of circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void delete(struct node **head, int data)
{
    struct node *temp = *head, *prev;
    if (temp != NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Number not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_end(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head;
    new_node->data = data;
    new_node->next = *head;
    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }
    else
    {
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

int main()
{
    struct node *head = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(&head, data);
    }
    printf("The list is: ");
    print(head);
    printf("Enter the element to be inserted at the end: ");
    scanf("%d", &data);
    insert_at_end(&head, data);
    printf("The list after insertion is: ");
    print(head);
    return 0;
}
