//write a c code to input a number and search in the linked list if number is fund ,update the linked list by deleting that node otherwise print number not found
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
    printf("Enter the number to be searched: ");
    scanf("%d", &data);
    delete(&head, data);
    print(head);
    return 0;
}
