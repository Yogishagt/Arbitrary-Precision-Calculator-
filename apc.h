#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

int readAndValidation(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,int argc, char *argv[]);
int dl_delete_list(Dlist **head, Dlist **tail);
int find_bigger(Dlist** head1,Dlist** head2);
char checkOperation(char *agvv[], int big_num);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);


int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int check_node(Dlist** head1,Dlist** head2);

#endif
