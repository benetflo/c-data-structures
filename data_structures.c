#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/*
	VECTOR IMPLEMENTATION

	FUNCTIONS:

	create_vector
	resize_vector
	add_back
*/

typedef struct{
	uint32_t capacity;
	uint32_t elements;
	int* array;
}Vector;

Vector create_vector(uint32_t capacity){
	Vector vector;
	vector.capacity = capacity;
	vector.elements = 0;
	vector.array = malloc((sizeof(int)) * capacity);
	if(vector.array == NULL){ //CHECK IN MAIN?
		Vector c;
		printf("Failed allocating memory\n");
		return c;
	}
	return vector;
}

void resize_vector(Vector *vec){
	Vector new_vec;
	new_vec.capacity = (vec->capacity) * 2;
	vec->capacity = new_vec.capacity;
	new_vec.array = malloc((sizeof(int)) * new_vec.capacity);

	for(int i = 0; i < (vec->elements); i++){
		new_vec.array[i] = vec->array[i];
	}

	int* old_array = vec->array;
	vec->array = new_vec.array;
	free(old_array);
}

void add_back(Vector *vec, int element){
	if(vec->elements == vec->capacity){
		resize_vector(vec);
	}
	vec->array[vec->elements] = element;
	vec->elements++;
}

void pop_back(Vector *vec){
	if(vec->elements == 0){
		printf("Vector is empty!\n");
		return;
	}
	vec->array[vec->elements] = 0;
	vec->elements--;
}

/*
	SINGLE LINKED LIST IMPLEMENTATION

*/

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* create_slinked_list(){

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

	if(*head == NULL) return;

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

int main(){

	Node* list = create_slinked_list();
	add_back(&list, 10);
}
