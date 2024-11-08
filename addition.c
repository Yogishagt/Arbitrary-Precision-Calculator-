/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	// /* Definition goes here */
	int num1,num2,carry=0,i=0,j=0,result;
	//take temporary variables to pint last nodes of list
	Dlist  *temp1=*tail1,*temp2=*tail2;
	//run loop till NULL
	while(temp1 != NULL || temp2 != NULL ){
		if(temp1 != NULL){
			// storing list data to num1
			num1=temp1->data;
			//traverse backwards
			temp1=temp1->prev;
		}
		else
			num1=0;
		if(temp2 != NULL){
			// storing list data to num2
			num2=temp2->data;
			//traverse backwards
			temp2=temp2->prev;
		}
		else
			num2=0;
		// adding two number
		result=num1+num2+carry;
		// finding the carry
		carry=result/10;
		// taking the last digit
		result %=10; 
		// printf("%d + %d + %d= %d\n",num1, num2,carry, result);
		//add the result in resultatnt list
		dl_insert_first(headR,tailR,result);
    }
	// checking if carry is there or not
	if(carry != 0)
	//add the result in resultatnt list
		dl_insert_first(headR,tailR,carry);
	return SUCCESS;
}
