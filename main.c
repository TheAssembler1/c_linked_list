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
void removeNodeAtPosition(struct Node** head);
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
    printf("Number: ");
    fflush(stdout);
    
    int userInput = 0;
    scanf("%d", &userInput);

    switch(userInput) {
      case 1:
        viewLinkedList(head);
        break;
      case 2:
        printf("Enter position of node you would like to see: ");
        int userInputPos= 0;
        scanf("%d", &userInputPos);
        printf("\n");
        viewNodeAtPosition(head, userInputPos);
        break;
      case 3:
        printf("Enter value of new Node (int): ");
        int userInputData = 0;
        scanf("%d", &userInputData);
        addNodeAtEnd(&head, userInputData);
        break;
      case 4:
        fprintf(stderr, "Invalid user input\n");
        break;
      case 5:
        fprintf(stderr, "Invalid user input\n");
        break;
      case 6:
        fprintf(stderr, "Invalid user input\n");
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

  // FIXME: clear linked list

  return 0;
}

void addNodeAtEnd(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  
  if((*head) == NULL) {
    (*head) = newNode;
    return;
  }

  struct Node* tail = (*head);

  while(tail->next != NULL) {
    tail = tail->next;
  }

  tail->next = newNode;
}

void addNodeAtPosition(struct Node**, int pos, int data) {
  if(pos < 0 || pos > lengthOfList(head) - 1) {
    fprintf(stderr, "Invalid position: %d\n\n", pos);
    return;
  }
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
