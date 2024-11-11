/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
int neg_flag=0;	
int main(int argc, char *argv[])
{
	
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL, *tailR=NULL;
	char option, operator;
	
	/* Code for reading the inputs */
	if(readAndValidation(&head1, &tail1,&head2, &tail2, argc, argv)== FAILURE)
		return FAILURE;
	printf("INFO: readAndValidation is Done!\n");
	char *str=argv[3];

	// checking argument 2 is zero in division operation
	if((strlen(str) == 1) && argv[2][0]== '/'){
		if(argv[3][0] == '0'){
			printf("INFO: Division can not be done for this arguments!\n");
			return 0;
		}
	}
	/*Find big number among two lists*/
	int big_num = find_bigger(&head1,&head2);
	/* Function for extracting the operator */
	operator = checkOperation(argv,big_num);
	// operator=*argv[2];
	printf("operator:%c\n",operator);
	switch (operator)
	{
		case '+':
			/* call the function to perform the addition operation */
			if(addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS){
				printf("INFO: Addition successfully done\n");
				print_list(headR);
			}
			else
				printf("INFO: Addition failed\n");
			break;
		case '-':
			/*Call Subtraction Function*/
			if(big_num == 1)
			{
				printf("hello\n");
				/*Call Subtraction Function*/
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				printf("INFO: Subtraction of two numbers Done!\n");
				print_list(headR);
				
			}
			else if( big_num == 3)
			{
				printf("hi\n");
				/*Call Subtraction Function, waping head1 and head2*/
				subtraction(&head2, &tail2, &head1, &tail1,  &headR, &tailR);
				printf("INFO: Subtraction of two numbers Done!\n");
				print_list(headR);
			}
			else
			{
				printf("Result is 0\n");
				return 0;
			}
			break;
		case 'x':	
			/* call the function to perform the multiplication operation */
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("INFO: Multiplication of two numbers Done!\n");
			print_list(headR);
			break;
		case '/':	
			
			if(big_num == 3)
			{
				printf("Result is 0\n");		//if denominator is big number than numerator the result is 0
				return 0;
			}
			else{
				/*Call division Function*/
				
				// else{
					division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					printf("INFO: Division of two numbers Done!\n");
				// }
			}
			break;
		default:
			printf("Invalid Input:-( Try again...\n");
	}

	return FAILURE;
}
