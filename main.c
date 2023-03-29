#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

void viewLinkedList(struct Node* head);
void viewNodeAtPosition(struct Node* head, int pos);
void addNodeAtPosition(struct Node** head, int pos, int val);
void addNodeAtEnd(struct Node** head, int data);
void removeNodeAtPosition(struct Node** head, int pos);
void removeNodeByValue(struct Node** head, int val);
int lengthOfList(struct Node* head);

int main() {
  struct Node* head = NULL;
  bool running = true;

  printf("Linked list stores (int) types!!!\n");
  printf("All position commands are 0 indexed!!!\n");

  while(running) {
    printf("Please type number of one of the following commands:\n");
    printf("1) View entire linked list\n");
    printf("2) View value of node at specified location\n");
    printf("3) Add a node to the end of the list\n");
    printf("4) Add a node to the specified location\n");
    printf("5) Remove a node at a specified location\n");
    printf("6) Remove a node by value\n");
    printf("7) Exit\n");
    printf("\n");
    printf("Option number: ");
    fflush(stdout);
    
    int userInput = 0;
    scanf("%d", &userInput);

    int input = 0;
    int input1 = 0;

    switch(userInput) {
      case 1:
        viewLinkedList(head);
        break;
      case 2:
        printf("Enter position of the node you would like to see: ");
        scanf("%d", &input);
        viewNodeAtPosition(head, input);
        break;
      case 3:
        printf("Enter value of new Node (int): ");
        scanf("%d", &input);
        addNodeAtEnd(&head, input);
        break;
      case 4:
        printf("Enter position you would like to insert node: ");
        scanf("%d", &input);
        printf("Enter a value of new Node (int): ");
        scanf("%d", &input1);
        addNodeAtPosition(&head, input, input1);
        break;
      case 5:
        printf("Enter a position of the node you would like to remove: ");
        scanf("%d", &input);
        removeNodeAtPosition(&head, input);
        break;
      case 6:
        printf("Enter the value of the node you would like to remove: ");
        scanf("%d", &input);
        removeNodeByValue(&head, input);
        break;
      case 7:
        running = false;
        break;
      default:
        fprintf(stderr, "Invalid user input\n");
        break;
    }

    fflush(stdout);
  }

  // NOTE: clearing linked list
  printf("Freeing linked list\n");
  while(lengthOfList(head) > 0) {
    printf("Removing node with value: %d", head->data);
    removeNodeAtPosition(&head, 0);
  }

  return 0;
}


void addNodeAtPosition(struct Node** head, int pos, int val) {
	if(pos < 0 || pos  > lengthOfList(*head)) {
	    fprintf(stderr, "Invalid position: %d\n\n", pos);
	    return;
	}

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = val;

	struct Node* prev = NULL;
 	struct Node* temp = *head;

	while(pos > 0) {
	  prev = temp;
		temp = temp->next;
		pos--;
	}	

	if(prev != NULL) {
		prev->next = newNode;
	} else {
    (*head) = newNode; 
  }

  newNode->next = temp;
  printf("\n");
}

void removeNodeAtPosition(struct Node** head, int pos) {
	if(pos < 0 || pos  >= lengthOfList(*head)) {
	    fprintf(stderr, "Invalid position: %d\n\n", pos);
	    return;
	}
	
	struct Node* prev = NULL;
 	struct Node* temp = *head;

	while(pos > 0) {
	  prev = temp;
		temp = temp->next;
		pos--;
	}	

	if(prev != NULL) {
		prev->next = temp->next;
	} else {
    (*head) = (*head)->next; 
  }

  free(temp);
  printf("\n");
}

void removeNodeByValue(struct Node** head, int val) {
	struct Node* prev = NULL;
 	struct Node* temp = *head;

	while(temp != NULL && temp->data != val) {
	  prev = temp;
		temp = temp->next;
	}	

  if(temp == NULL) {
    fprintf(stderr, "No node with value found: %d\n\n", val);
    return;
  }

	if(prev != NULL) {
		prev->next = temp->next;
	} else {
    (*head) = (*head)->next; 
  }

  free(temp);
  printf("\n");
}

void addNodeAtEnd(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  
  if((*head) == NULL) {
    (*head) = newNode;
    printf("\n");
    return;
  }

  struct Node* tail = (*head);

  while(tail->next != NULL) {
    tail = tail->next;
  }

  tail->next = newNode;
  printf("\n");
}

void viewLinkedList(struct Node* head) {
  printf("Linked List: ");

  if(head == NULL) {
    printf("Empty Linked List");
  }

  struct Node* temp = head;

  while(temp != NULL) {
    if(temp->next != NULL) {
      printf("[%d]->", temp->data);
    } else {
      printf("[%d]", temp->data);
    } 
    temp = temp->next;
  }
  printf("\n\n");
}

void viewNodeAtPosition(struct Node* head, int pos) {
  if(pos < 0 || pos > lengthOfList(head) - 1) {
    fprintf(stderr, "Invalid position: %d\n\n", pos);
    return;
  }
 
  struct Node* temp = head;
  int tempPos = pos;
  
  while(tempPos > 0) {
    temp = temp->next;
    tempPos--;
  }

  printf("Node at position: %d, value: %d\n\n", pos, temp->data);
}

int lengthOfList(struct Node* head) {
  int length = 0;

  while(head != NULL) {
    length++; 
    head = head->next;
  }

  return length;
}
