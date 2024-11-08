#include "apc.h"
extern int neg_flag;
int readAndValidation(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,int argc, char *argv[]){
	// chceking argument count is 4 or not
    if(argc!=4){
        printf("INFO: Error: invalid number of arguments\n");
        return FAILURE;
    }
    /*Validation for the operator*/
	if((strcmp(argv[2],"+") !=0) && (strcmp(argv[2],"-") !=0) && (strcmp(argv[2],"x") !=0) && (strcmp(argv[2], "/") !=0))
	{
		printf("INFO: Error: invalid number of arguments\n");
        return FAILURE;
	}
    char *str1=argv[1], *str2=argv[3];
	int i=0,j=0;
	// chceking for '+' or '-' is present in operand's
	if(str1[0] == '+'  || str1[0] == '-')
		i=1;
	if(str2[0] == '+'  || str2[0] == '-')
		j=1;
	// running a loop
    while(str1[i] != '\0' || str2[j] !='\0'){
        // checking operand's having numeric number or not
        if(str1[i] >= '0' &&  str1[i] <= '9' || str2[j] >= '0' &&  str2[j] <= '9'){
            if(str1[i] != '\0'){
				// inserting the data to list
                dl_insert_last(head1,tail1,(str1[i] - 48));
                i++;
            }
			else if(argv[2][0] != 'x')
			// inserting the data to list
				dl_insert_first(head1,tail1,0);
            if(str2[j] != '\0'){
                // inserting the data to list
                dl_insert_last(head2,tail2,(str2[j] - 48));
                j++;
            }
			else if(argv[2][0] != 'x')  
				// inserting the data to list
				dl_insert_first(head2,tail2,0);

        }
        else{
            printf("INFO: Error: invalid argument  must be a number or a sign\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}
/*Function to find bigger based on lists*/
int find_bigger(Dlist** head1,Dlist** head2)
{
	//take temporary variables to pint last nodes of list
	Dlist* temp1 = *head1;
	Dlist* temp2 = *head2;
	// running a loop
	while(temp1 && temp2)
	{
		// checking if temp1 node is greater than temp2 node
		if(temp1->data > temp2->data)
			return 1;
		// checking if temp2 node is greater than temp1 node
		else if(temp2->data > temp1->data)
			return 3;
		// traversing forword
		temp1 = temp1->next;
		temp2 = temp2->next;

	}
	return 0;
}
char checkOperation(char *argv[], int big_num){
    char ch = argv[2][0];
	//if operator is +
    if( ch == '+')											
	{
		//if both signs are negative add sign bit
		if( argv[1][0] == '-' && argv[3][0] == '-')			
		{
			neg_flag = 1;
		}
		//if big num has - add negative sign
		else if(argv[big_num][0] == '-')				
		{
			neg_flag = 1;
		}
	}
	//if ch is -
	else if( ch == '-')					
	{
		//if both arguments are - enable negative flag 
		if(big_num == 1 && argv[1][0] == '-') 		
		{
			neg_flag = 1;
		}
		//if second argument has - and big number is not 1 enable negative flag
		else if(argv[3][0] != '-' && big_num != 1)		
		{
			neg_flag = 1;
		}
	}
	else if( ch == '/' || ch == 'x')
	{
		if( argv[1][0] == '-' && argv[3][0] != '-')
			neg_flag = 1;
		else if( argv[1][0] != '-' && argv[3][0] == '-')
			neg_flag = 1;
	}
	/*Choose correct operator based on signs given for arguments*/
	if( argv[2][0] == '+')
	{
		if ( (argv[1][0] != '-' && argv[3][0] == '-') || (argv[1][0] == '-' && argv[3][0] != '-'))
		{
			ch = '-';
		}
		else
		{
			ch = '+';
		}
	}
	else if( argv[2][0] == '-')
	{
		if( (argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-'))
		{
			ch = '+';
		}
		else
		{
			ch = '-';
		}
	}
    return ch;
} 
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
     // creating a new node
    Dlist *new=malloc(sizeof(Dlist));
    // checking if node is created or not
    if(new==NULL)
        return FAILURE;
    // updata the data, prev and next
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    // checking if list is empty or not
    if(*head==NULL && *tail==NULL){
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    // creating link
    new->prev=*tail;
    (new->prev)->next=new;
    *tail=new;
    return SUCCESS;
}
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    // creating a new node
    Dlist *new=malloc(sizeof(Dlist));
    // checking if node is created or not
    if(new==NULL)
        return FAILURE;
    // updata the data, prev and next
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    // checking if list is empty or not
    if(*head==NULL && *tail==NULL){
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    // creating link
    new->next=*head;
    (new->next)->prev=new;
    *head=new;
    return SUCCESS;
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
   //checking for list is empty or not
	if(*head==NULL)
	    return FAILURE;
	//declaring a temp pointer
	Dlist *temp=*head;
	//traverse trough the list
	while(temp != NULL){
	   *head = temp->next;
	   free(temp);
	   temp=*head;
	}
	*tail=NULL;
	return SUCCESS;
}


void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
        printf("Result: ");
        if(neg_flag == 1)
            printf("-");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
        printf("\n");
    }
}