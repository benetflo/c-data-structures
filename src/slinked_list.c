#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
	SINGLE LINKED LIST IMPLEMENTATION

*/

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* create_slinklist(){

	Node* head = NULL;
	return head;
}

void add_back(Node** head, int data){

	Node* n = malloc(sizeof(Node));
	n->data = data;

	// if list is empty
	if(*head == NULL){
		*head = n;
	}else{
		Node* current = *head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = n;
	}
	n->next = NULL;
}

void add_front(Node** head, int data){

	Node* n = malloc(sizeof(Node));
	n->data = data;

	n->next = *head;
	*head = n;
}

void remove_node_byindex(Node** head, uint8_t index){

	if(*head == NULL){
		return;
	}
	if(index == 0){
		Node* temp = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}

	Node* current = *head;

	for(int i = 0; i < index - 1; i++){
		current = current->next;
	}

	Node* temp = current->next;

	if (temp == NULL){
		 return;
	}

	current->next = temp->next;
	free(temp);
}

void remove_node_byvalue(Node** head, int data){

	if(*head == NULL){
		return;
	}

	if((*head)->data == data){
		Node* temp = *head;
		*head = (*head)->next;
		free(temp);
	}else{
		Node* current = *head;

		while(current->next != NULL && (current->next)->data != data){
			current = current->next;
		}
		if(current->next != NULL){

			Node* temp = current->next;
			current->next = temp->next;
			free(temp);
		}
	}
}

void insert_at_index(Node** head, uint8_t index, int data){

	Node* n = malloc(sizeof(Node));
	n->data = data;

	if(index == 0){
		add_front(head, data);
		return;
	}

	Node* current = *head;

	for(int i = 0; i < index - 1; i++){

		if(current == NULL){
			return;
		}
		current = current->next;
	}

	if(current == NULL){ // if list is too short
		return;
	}

	Node* temp = current->next; // the actual index;
	current->next = n;
	n->next = temp;
}

void print_slinklist(Node** head){

	if((*head) == NULL){
		printf("List is empty\n");
		return;
	}
	Node* current = *head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

uint16_t count_nodes(Node** head){

	Node* current = *head;
	uint16_t count = 0;

	while(current != NULL){
		current = current->next;
		count++;
	}
	return count;
}

void free_slinklist(Node** head){

	Node* current = *head;
	Node* temp;

	while(current != NULL){
		temp = current;
		current = current->next;
		free(temp);
	}

	*head = NULL;
}

int main(){

	Node* list = create_slinklist();
	add_back(&list, 10);
	add_back(&list, 15);
	print_slinklist(&list);
	return 0;
}
