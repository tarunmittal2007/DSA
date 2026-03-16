/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create(struct node *head, int c, int e)
{
    struct node *temp, *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &e);
        head = create(head, c, e);
    }

    printf("Polynomial: ");
    display(head);

    return 0;
}
