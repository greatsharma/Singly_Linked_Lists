#ifndef NODE_H
#define NODE_H

class Node
{
	int data;
	Node *next_node;
	friend class Linked_lists;

  public:
	Node(int data, Node *next_node = nullptr);
	~Node();
};

#endif
