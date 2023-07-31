/*Needed libraries*/
#include <stdio.h>
#include <stdlib.h>

/*Create Linked List Node Type*/
typedef struct Node
{
	int Data;
	struct Node *Link;
}
Node_t;

/*It is the main*/
int main()
{
	/*Define variables*/
	int Choice;
	Node_t *Start = NULL;
	Node_t *TempPtr = NULL;
	int NodeData;
	Node_t *TempTraverse = NULL;
	int TempCounter;
	Node_t *TempFree = NULL;
	
	/*Super Loop*/
	while(1)
	{
		/*Print choices to the user then scan his choice*/
		printf("\nChoose from the following: \n");
		printf("0 -> Add a node.\n");
		printf("1 -> Print the linked list.\n");
		printf("2 -> Exit.\n");
		printf("\nYour Choice: ");
		scanf("%d", &Choice);
		printf("\n");
		printf("-----------------\n");
		
		/*Excute the code according to the user choice*/
		if(Choice == 0)
		{
			/*Scan the node data from the user*/
			printf("Please, Enter the node value: ");
			scanf("%d", &NodeData);
			
			/*Reserve a memory location for the new node*/
			TempPtr = (Node_t *) malloc(sizeof(Node_t));
			
			/*Validate the Pointer to node*/
			if(TempPtr != NULL)
			{
				/*Assign the node value to the new node*/
				TempPtr -> Data = NodeData;
				
				/*Make the new node point to NULL*/
				TempPtr -> Link = NULL;
				
				/*If the list is empty*/
				if(Start == NULL)
				{
					Start = TempPtr;
				}
				/*If there are any nodes inside the list*/
				else
				{
					/*Traverse until you find the last node*/
					TempTraverse = Start;
					while(TempTraverse -> Link != NULL)
					{
						TempTraverse = TempTraverse -> Link;
					}
					
					/*Add the new node to the list*/
					TempTraverse -> Link = TempPtr;				
				}
				
				/*Print a message to the user*/
				printf("Node has been added successfully.\n");
			}
			else
			{
				/*Print a message to the user*/
				printf("Unsuccessful Add.\n");
			}
		}
		else if(Choice == 1)
		{
			/*If the list is empty*/
			if(Start == NULL)
			{
				printf("List is empty!\n");
			}
			/*If there are any nodes inside the list*/
			else
			{
				/*Traverse over all nodes in linked list*/
				TempCounter = 0;
				TempTraverse = Start;
				while(TempTraverse != NULL)
				{
					/*Print the current node*/
					printf("Node Number %d: %d\n", TempCounter, TempTraverse -> Data);
					
					/*Move to the next node*/
					TempTraverse = TempTraverse -> Link;
					
					/*Update the counter*/
					TempCounter++;
				}		
			}
			
		}
		else if(Choice == 2)
		{
			/*Free all memory we reserved through the program*/
			/*Traverse over all nodes in linked list*/
			TempTraverse = Start;
			while(TempTraverse != NULL)
			{	
				/*Make a temporary pointer point to the need that needed to free*/
				TempFree = TempTraverse;
				
				/*Move to the next node*/
				TempTraverse = TempTraverse -> Link;
				
				/*Free the node*/
				free(TempFree);
			}		

			/*Print a message to the user*/
			printf("Thank You.\n");
			printf("Good Bye!\n");
			printf("-----------------\n");
			
			/*Break the loop*/
			break;
		}
		else
		{
			/*Print a message to the user*/
			printf("Invalid Choice! Please, Try again.\n");
		}
		
		printf("-----------------\n");
	}
	
	/*Return to the linked list*/
	return 0;
}