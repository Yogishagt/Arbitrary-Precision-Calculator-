/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int sub=0;
	//take temporary variables to pint last nodes of list
	Dlist* temp1 = *tail1;
	Dlist* temp2 = *tail2;									
	Dlist* temp3 = temp1;
	//run loop till NULL
	while( temp1 != NULL || temp2 != NULL)						
	{
		//if first data is greater than second data directly 
		if( temp1->data >= temp2->data)								
		{
			//do subtraction
			sub = (temp1->data) - (temp2->data);						
		}
		else
		{
			//if not take one temp for traversal
			temp3 = temp1->prev;									
			//run loop till NULL
			while( temp3 != NULL)										
			{
				//if any data found which is greater tha 0
				if( temp3->data > 0 )									
				{
					//decrement by one and stop process
					(temp3->data)--;									
					break;
				}
				//if zero came
				else if ( temp3->data == 0 && temp3->prev != NULL)		
				{
					//update it with 9
					temp3->data = 9;									
				}
				//traverse backwards
				temp3 = temp3->prev;									
			}
			//add borrow and do subtraction
			sub = ( (temp1->data) +10) - (temp2->data);					
		}
		//add the result in resultatnt list
		dl_insert_first(headR,tailR,sub);									
		temp1 = temp1->prev;	
		//traverse backwards for previous data											
		temp2 = temp2->prev;
	}
}
