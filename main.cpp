#include <iostream>
#include "Linked_lists.h"

using namespace std;

Linked_lists *array_obj[10];
int i = 0;

void menu(Linked_lists *obj)
{
start:
	cout << "\n==============================================================================";
	cout << "\n1.Add node at head  2.Add node at tail  3.Add after a data  4.Add before a data";
	cout << "\n5.Del node at head  6.Del node at tail  7.Del after a data  8.Del before a data";
	cout << "\n9.Del node at data  10.Del numbered node  11.Total nodes  12.Total nodes with data";
	cout << "\n13.Display linked list  14.Reverse  15:Selection Sort  16.Insertion Sort  17.Exit";
	cout << "\n18.move to front  19.pointed by p  20.return data pointer  21.insert in middle";
	cout << "\n22.insert at fraction";
	cout << "\n==============================================================================";
	cout << "\n\nEnter choice : ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		cout << "\nEnter the data : ";
		int data;
		cin >> data;
		obj->add_node_head(data);
		obj->display_linked_list();
		break;
	}

	case 2:
	{
		cout << "\nEnter the data : ";
		int data;
		cin >> data;
		obj->add_node_tail(data);
		obj->display_linked_list();
		break;
	}

	case 3:
	{
		cout << "\nEnter the data to be added : ";
		int data;
		cin >> data;

		int data_temp;

		cout << "\nEnter the data after we have to add: ";
		cin >> data_temp;

		obj->add_after_node(data, data_temp);
		obj->display_linked_list();
		break;
	}

	case 4:
	{
		cout << "\nEnter the data to be added : ";
		int data;
		cin >> data;

		int data_temp;

		cout << "\nEnter the data before we have to add: ";
		cin >> data_temp;

		obj->add_before_node(data, data_temp);
		obj->display_linked_list();
		break;
	}

	case 5:
	{
		obj->remove_node_head();
		obj->display_linked_list();
		break;
	}

	case 6:
	{
		obj->remove_node_tail();
		obj->display_linked_list();
		break;
	}

	case 7:
	{
		int data_temp;
		cout << "\nEnter the data after we have to delete node: ";
		cin >> data_temp;

		obj->remove_after_node(data_temp);
		obj->display_linked_list();
		break;
	}

	case 8:
	{
		int data_temp;
		cout << "\nEnter the data before we have to delete node: ";
		cin >> data_temp;

		obj->remove_before_node(data_temp);
		obj->display_linked_list();
		break;
	}

	case 9:
	{
		int data_temp;
		cout << "\nEnter the data of the node to delete : ";
		cin >> data_temp;

		obj->remove_node_data(data_temp);
		obj->display_linked_list();
		break;
	}

	case 10:
	{
		int node_no;
		cout << "\nEnter the node no to be deleted : ";
		cin >> node_no;

		obj->remove_numbered_node(node_no);
		obj->display_linked_list();
		break;
	}

	case 11:
	{
		cout << "\nTotal nodes are : " << obj->total_nodes();
		break;
	}

	case 12:
	{
		int data_temp;
		cout << "\nEnter the data of the node to count : ";
		cin >> data_temp;

		cout << "\ntotal nodes with given data : " << obj->total_nodes_given_data(data_temp);
		break;
	}

	case 13:
	{
		obj->display_linked_list();
		break;
	}

	case 14:
	{
		obj->reverse_linked_list();
		obj->display_linked_list();
		break;
	}

	case 15:
	{
		obj->selection_sort();
		obj->display_linked_list();
		break;
	}

	case 16:
	{
		obj->insertion_sort();
		obj->display_linked_list();
	}
	break;

	case 17:
	{
	}
	break;

	case 18:
	{
		int data;
		cout << "\nEnter the data to find: ";
		cin >> data;

		if (obj->move_to_front(data))
			cout << "\n found\n";
		else
			cout << "\nnot found\n";
		obj->display_linked_list();
	}
	break;

	case 19:
	{
		int data;
		cout << "\nenter data to pointed : ";
		cin >> data;

		Node *ptr = obj->data_pointer(data);

		cout << "\nenter new node data : ";
		cin >> data;
		obj->insertBeforePtr(obj->head, ptr, data);
		obj->display_linked_list();
	}
	break;

	case 21:
	{
		int data;
		cout << "\nenter data to insert : ";
		cin >> data;

		obj->insertInMiddle(data);
		obj->display_linked_list();
	}
	break;

	case 22:
	{
		int data;
		cout << "\nenter data to insert : ";
		cin >> data;

		int f;
		cout << "\nenter fraction of place : ";
		cin >> f;

		obj->insertAtFraction(data, f);
		obj->display_linked_list();
	}
	break;

	default:
		cout << "\nInvalid option...";
	}

	cout << "\n\nwant to try again(y/n): ";
	char chChoice;
	cin >> chChoice;

	if (chChoice == 'y' || chChoice == 'Y')
		goto start;

	return;
}

int main()
{
	int data;
	cout << "\nEnter the data : ";
	cin >> data;

	Linked_lists obj_one(data);
	menu(&obj_one);

	cout << "\nwant to create another linked list (y/n) : ";
	char chChoice;
	cin >> chChoice;

	if (chChoice != 'y' && chChoice != 'Y')
		return 0;

	cout << "\nEnter the data : ";
	cin >> data;

	Linked_lists obj_two(data);
	menu(&obj_two);

	cout << "\n\nwant to join linked lists (y/n) : ";
	cin >> chChoice;

	if (chChoice != 'y' && chChoice != 'Y')
		return 0;

	obj_one + obj_two;

	cout << "\nlinked list 1 : ";
	obj_one.display_linked_list();

	cout << "\nlinked list 2 : ";
	obj_two.display_linked_list();

	cout << "\n\n";
	system("pause");
	return 0;
}

// void store_linked_lists(Doubly_Linked_Lists *obj)
// {
// 	array_obj[i] = obj;
// 	i++;

// 	return;
// }

// int main()
// {
// 	int data;

// start:
// 	cout << "\nEnter the data : ";
// 	cin >> data;

// 	Doubly_Linked_Lists obj_one(data);
// 	store_linked_lists(&obj_one);
// 	menu(&obj_one);

// 	cout << "\nwant to create another linked list (y/n) : ";
// 	char chChoice;
// 	cin >> chChoice;

// 	if (chChoice == 'y' || chChoice == 'Y')
// 	{
// 		cout << "\nEnter the data : ";
// 		cin >> data;

// 		Doubly_Linked_Lists obj_two(data);
// 		store_linked_lists(&obj_two);
// 		menu(&obj_two);
// 	}
// 	cout << "\n\nwant to join linked lists (y/n) : ";
// 	cin >> chChoice;

// 	if (chChoice == 'y' || chChoice == 'Y')
// 	{
// 		array_obj[0]->join_linked_lists(array_obj[1]);
// 		cout << "\njoined linked list : ";
// 		array_obj[0]->display_linked_list();
// 	}

// 	cout << "\n\n";
// 	system("pause");
// 	return 0;
// }