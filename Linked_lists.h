#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
#include "Node.h"

class Linked_lists
{
	int data;
	Node *tail;

  public:
	Node *head;
	Linked_lists();
	Linked_lists(int data);
	void showHeadTail();
	void add_node_head(int);
	void add_node_tail(int);
	void add_after_node(int, int);
	void add_before_node(int, int);
	void remove_node_head();
	void remove_node_tail();
	void remove_after_node(int);
	void remove_before_node(int);
	void remove_node_data(int);
	void remove_numbered_node(int);
	int total_nodes();
	int total_nodes_given_data(int);
	void display_linked_list();
	void reverse_linked_list();
	void selection_sort();
	void insertion_sort();
	bool move_to_front(int);
	void insertInMiddle(int);
	void insertAtFraction(int, int);
	Node *data_pointer(int);
	void insertBeforePtr(Node *, Node *, int);
	// void join_linked_lists(Linked_lists *);
	void operator+(Linked_lists &);
	~Linked_lists();
};

#endif
