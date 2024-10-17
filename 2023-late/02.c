//assume that you have a double linked list finst node of the list is pointed by pointer q write a c function to insturt a node after the kth node of the list

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

void insert_after_k(struct node *q, int k, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (q == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    for (int i = 0; i < k; i++)
    {
        q = q->next;
        if (q == NULL)
        {
            printf("k is greater than the length of the list\n");
            return;
        }
    }
    new_node->next = q->next;
    q->next = new_node;
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
    print(head);
    struct node *q = head;
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    insert_after_k(q, k, data);
    print(head);
    return 0;
}
