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

/*Functions' Prototypes*/
Node_t *DeleteNode(Node_t *Start, int Node);
Node_t *AddNode(Node_t *Start, int Node, int Position);

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
	int DeletedNode;
	int AddPosition;
	
	/*Super Loop*/
	while(1)
	{
		/*Print choices to the user then scan his choice*/
		printf("\nChoose from the following: \n");
		printf("0 -> Add a node.\n");
		printf("1 -> Print the linked list.\n");
		printf("2 -> Delete a node.\n");
		printf("3 -> Add a node at certain position.\n");
		printf("4 -> Exit.\n");
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
			/*Scan the node data from the user*/
			printf("Please, Enter the node value: ");
			scanf("%d", &DeletedNode);
			
			/*Call a function to delete the node*/
			Start = DeleteNode(Start, DeletedNode);

		}
		else if(Choice == 3)
		{
			/*Scan the node data from the user*/
			printf("Please, Enter the node value: ");
			scanf("%d", &NodeData);

			printf("Please, Enter the position: ");
			scanf("%d", &AddPosition);

			/*Call a function to delete the node*/
			Start = AddNode(Start, NodeData, AddPosition);
		}
		else if(Choice == 4)
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

/*Functions' Implementation*/
Node_t *DeleteNode(Node_t *Start, int Node)
{
	/*Define variables*/
	Node_t *TempPtr = Start;
	Node_t *TempDelete = NULL;
	
	/*Validate the pointer to start*/
	if(Start != NULL)
	{
		/*Pass over all elements of the list*/
		while(TempPtr -> Link != NULL)
		{
			/*If we find the node, delete it*/
			if(TempPtr -> Link -> Data == Node)
			{
				TempDelete = TempPtr -> Link;
				TempPtr -> Link = TempDelete -> Link;
				free(TempDelete);
			}
			/*Else move to the next node*/
			else
			{				
				TempPtr = TempPtr -> Link;				
			}
		}
		
		/*If the node is the first node, delete it and update the start address*/
		if(Start -> Data == Node)
		{
			TempDelete = Start;
			Start = TempDelete -> Link;
			free(TempDelete);
		}
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Return the new address of the start*/
	return Start;
}


Node_t *AddNode(Node_t *Start, int Node, int Position)
{
	/*Define variables*/
	Node_t *Temp = Start;
	int ListSize = 0;
	int i = 0;
	
	/*Get the linked list size*/
	while(Temp != NULL)
	{
		Temp = Temp -> Link;
		ListSize++;
	}	
	
	/*If it was needed to be the first position or the only node in the linked list*/
	if(Position == 0)
	{
		/*Reserve a new node*/
		Node_t *NewNode = (Node_t *) malloc(sizeof(Node_t));
		NewNode -> Data = Node;
		
		/*Insert the node into the list*/
		Temp = Start;
		Start = NewNode;
		NewNode -> Link = Temp;
	}
	else
	{
		if((Position <= ListSize) && (Position > 0))
		{
			/*Reserve a new node*/
			Node_t *NewNode = (Node_t *) malloc(sizeof(Node_t));
			NewNode -> Data = Node;
			
			/*Traverse till the node before the node we will add*/
			Temp = Start;
			while(i < (Position - 1))
			{
				Temp = Temp -> Link;
				i++;
			}
			
			/*Insert the node into the list*/
			NewNode -> Link = Temp -> Link;
			Temp -> Link = NewNode;
		}
	}

	/*Return the new address of the start*/
	return Start;
}