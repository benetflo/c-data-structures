#ifndef SLINKED_LIST_H
#define SLINKED_LIST_H

#include "data_structures.h"

Node* create_slinked_list();
void add_back(Node** head, int data);
void add_front(Node** head, int data);
void remove_node_byindex(Node** head, uint8_t index);
void remove_node_byvalue(Node** head, int data);
void insert_at_index(Node** head, uint8_t index, int data);

#endif
