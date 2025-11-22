/* Singly Linked List */
/*
    A linked list is a linear data structure that consists of a sequence of nodes.
    Each node contains a data element and a reference (or link) to the next node in the sequence.
    The last node in the list points to NULL, indicating the end of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_at_beginning(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_after_given_node(struct node **head, int data, int data2)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *temp = *head;
        while (temp != NULL)
        {
            if (temp->data == data2)
            {
                new_node->next = temp->next;
                temp->next = new_node;
                break;
            }
            temp = temp->next;
        }
    }
}

void delete_first_node(struct node **head)
{
    struct node *temp = *head;
    if (temp != NULL)
    {
        printf("Deleting element: %d\n", temp->data);
        *head = temp->next;
        free(temp);
    }
}

void delete_last_node(struct node **head)
{
    struct node *temp = *head;
    if (temp == NULL)
    {
        return;
    }
    if (temp->next == NULL)
    {
        printf("Deleting element: %d\n", temp->data);
        free(temp);
        *head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("Deleting element: %d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_given_node(struct node **head, int data)
{
    struct node *temp = *head;

    // Check if list is empty
    if (temp == NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }

    // If first node matches, delete it
    if (temp->data == data)
    {
        delete_first_node(head);
        return;
    }

    // Traverse the list to find the node to delete
    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            // Found the node to delete
            struct node *node_to_delete = temp->next;
            printf("Deleting element: %d\n", node_to_delete->data);
            temp->next = node_to_delete->next;
            free(node_to_delete);
            return;
        }
        temp = temp->next;  // Move to next node
    }

    // Node not found
    printf("Data %d not found in the list\n", data);
}

void display_list(struct node *head)
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void search_for_given_node(struct node *head, int data)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found\n");
}

void sort_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->data > temp2->data)
            {
                int temp_data = temp->data;
                temp->data = temp2->data;
                temp2->data = temp_data;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void reverse_list(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    int choice, data, data2;
    struct node *head = NULL;
    while (1)
    {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a given node\n");
        printf("4. Delete the first node\n");
        printf("5. Delete the last node\n");
        printf("6. Delete a given node\n");
        printf("7. Display the list\n");
        printf("8. Search for a given node\n");
        printf("9. Sort the list\n");
        printf("10. Reverse the list\n");
        printf("11. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the data after which to insert: ");
                scanf("%d", &data2);
                insert_after_given_node(&head, data, data2);
                break;
            case 4:
                delete_first_node(&head);
                break;
            case 5:
                delete_last_node(&head);
                break;
            case 6:
                printf("Enter the data: ");
                scanf("%d", &data);
                delete_given_node(&head, data);
                break;
            case 7:
                display_list(head);
                break;
            case 8:
                printf("Enter the data: ");
                scanf("%d", &data);
                search_for_given_node(head, data);
                break;
            case 9:
                sort_list(head);
                break;
            case 10:
                reverse_list(&head);
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
