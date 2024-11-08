/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int result, i, carry = 0, count = 0;
	//take temporary variables to pint last nodes of list
	Dlist *temp1=*tail1, *temp2=*tail2, *r1=NULL,*r2=NULL,*r3=NULL,*t1=NULL,*t2=NULL,*t3=NULL;
	//run loop till NULL
	while(temp1){
		//do multiplication
		result=(temp1->data * temp2->data) + carry;
		carry = result/10;
		result %=10 ;
		dl_insert_first(&r1,&t1,result);
		//traverse backwards
		temp1=temp1->prev;
	}
	// incrementing the count
	count++;
	if(carry != 0){
		dl_insert_first(&r1,&t1,carry);
	}
	//traverse backwards
	temp2=temp2->prev;
	//run loop till NULL
	while(temp2){
		for(i=0;i<count;i++){
			dl_insert_first(&r2,&t2,0);
		}
		temp1=*tail1;
		carry=0;
		//run loop till NULL
		while(temp1){
			//do multiplication
			result=(temp1->data * temp2->data) + carry;
			carry = result/10;
			result %=10 ;
			//add the result in resultatnt list
			dl_insert_first(&r2,&t2,result);
			//traverse backwards
			temp1=temp1->prev;
		} 
		
		if(carry != 0){
			//add the result in resultatnt list
			dl_insert_first(&r2,&t2,carry);
		}
		// do addtition
		addition(&r1, &t1,  &r2, &t2, &r3, &t3);
		// deleting the list
		dl_delete_list(&r1,&t1);
		dl_delete_list(&r2,&t2);
		temp1=t3;
		//run loop till NULL
		while(temp1){
			//add the result in resultatnt list
			dl_insert_first(&r1,&t1,temp1->data);
			temp1=temp1->prev;
		}
		// deleting the list
		dl_delete_list(&r3,&t3);
		// incrementing the count
		count++;
		//traverse backwards
		temp2=temp2->prev;
	}
	temp1=t1;
	//run loop till NULL
	while(temp1){
		//add the result in resultatnt list
		dl_insert_first(headR,tailR,temp1->data);
		temp1=temp1->prev;
	}
	// deleting the list
	dl_delete_list(&r1,&t1);
	return SUCCESS;
}
