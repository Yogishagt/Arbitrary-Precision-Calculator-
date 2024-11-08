/*******************************************************************************************************************************************************************
*Title			: Division
*Description	: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
extern int neg_flag;
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int stop_flag=0;
	//declare the all variables
	int count = 0,flag,result = 0; 			
	Dlist* temp;
	while(stop_flag != 1)
	{				
		//if result value is even			 
		if(result % 2 == 0)							
		{
			count++;
			//perform subtraction operation
			subtraction(head1,tail1,head2,tail2,headR,tailR); 
			temp = *headR;
		}
		else
		{
			count++;
			//perform sutraction and swap the lists
			subtraction(headR,tailR,head2,tail2,head1,tail1);				
			temp = *head1;
		}
		//if result is greater than denominator
		stop_flag = check_node(&temp,head2);			
		if(stop_flag == 1)
		{
			//stop process
			break;											
		}
		else
		{
			if(result % 2 == 0)
			//based on result value free the nodes
				dl_delete_list(head1,tail1);			
			else
				dl_delete_list(headR,tailR);
			result++;
		}
	}
	printf("Result is : ");
	if(neg_flag)
	//directly add count in list and print result
		printf("-");	
	printf("%d\n",count);
}

/*Function to check the bigger node*/
int check_node(Dlist** head1,Dlist** head2){
	Dlist* temp1 = *head1;
	Dlist* temp2 = *head2;
	while(temp1)
	{
		//if first list data is greater than second list data return 0
		if(temp1->data > temp2->data)			
			return 0;
		//if it is vice versa result 1
		else if(temp1->data < temp2->data)		
			return 1;
		temp1 = temp1->next;
		//traverse till end of list
		temp2 = temp2->next;						
	}
	//if equal return 0
	return 0;										
}  
