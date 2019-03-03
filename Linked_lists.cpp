#include "Linked_lists.h"
#include <iostream>

Linked_lists::Linked_lists() {}

Linked_lists::Linked_lists(int data) : data(data)
{
    Node *new_node = new Node(data);
    head = tail = new_node;
}

void Linked_lists::showHeadTail()
{
    std::cout << "\nhead : " << head << "\ntail : " << tail;
    return;
}

void Linked_lists::add_node_head(int data)
{
    Node *new_node = new Node(data, head);
    // new_node->next_node = head;
    head = new_node;

    return;
}

Node *Linked_lists::data_pointer(int data_ptr)
{
    if (head)
    {
        Node *curr = head;

        while (curr->data != data_ptr)
        {
            curr = curr->next_node;
        }

        return curr;
    }

    return 0;
}

void Linked_lists::insertBeforePtr(Node *temp, Node *p, int data)
{
    if (head != p)
    {
        if (temp->next_node == p)
        {
            Node *new_node = new Node(data, p);
            temp->next_node = new_node;
        }
        else
            insertBeforePtr(temp->next_node, p, data);
    }
    else
        Node *new_node = new Node(data, p);

    return;
}

bool Linked_lists::move_to_front(int dataFind)
{
    if (head)
    {
        Node *curr = head;

        if (head != tail)
        {
            if (curr->data == dataFind)
                return true;

            while (curr->next_node->data != dataFind)
            {
                curr = curr->next_node;
                if (curr->next_node == 0)
                    return false;
            }

            Node *temp = curr->next_node;
            curr->next_node = temp->next_node;
            temp->next_node = head;

            return true;
        }

        else
            return curr->data == dataFind;
    }

    return false;
}

void Linked_lists::insertInMiddle(int data)
{
    if (head)
    {
        Node *p = head;
        Node *s = head;
        bool flag = false;

        while (p->next_node != 0)
        {
            p = p->next_node;
            if (flag)
                s = s->next_node;
            flag = (!flag);
        }

        Node *new_node = new Node(data, s->next_node);
        s->next_node = new_node;

        if (tail == head)
            tail = new_node;
    }
    else
    {
        Node *new_node = new Node(data, 0);
        head = tail = new_node;
    }

    return;
}

void Linked_lists::insertAtFraction(int data, int fraction)
{
    if (head)
    {
        Node *p = head;
        Node *s = head;
        int flag = fraction - 1;

        while (p->next_node != 0)
        {
            p = p->next_node;
            if (flag == 0)
            {
                s = s->next_node;
                flag = fraction - 1;
            }
            else
                --flag;
        }

        Node *new_node = new Node(data, s->next_node);
        s->next_node = new_node;

        if (tail == head)
            tail = new_node;
    }
    else
    {
        Node *new_node = new Node(data, 0);
        head = tail = new_node;
    }

    return;
}

void Linked_lists::add_node_tail(int data)
{
    static Node *curr_node = head;
    if (curr_node->next_node != 0)
    {
        curr_node = curr_node->next_node;
        add_node_tail(data);
    }
    else
    {
        Node *new_node = new Node(data, 0);
        tail->next_node = new_node;
        tail = new_node;
    }
    return;
}

void Linked_lists::add_after_node(int data, int data_after)
{
    // Node *curr_node = head;
    // while (curr_node->data != data_after)
    // {
    //     curr_node = curr_node->next_node;
    // }

    // Node *new_node = new Node(data, curr_node->next_node);
    // curr_node->next_node = new_node;
    // if (curr_node == tail)
    //     tail = new_node;

    // return;
    static Node *curr_node = head;
    if (curr_node->data != data_after)
    {
        curr_node = curr_node->next_node;
        add_after_node(data, data_after);
    }
    else
    {
        Node *new_node = new Node(data, curr_node->next_node);
        curr_node->next_node = new_node;
        if (curr_node == tail)
            tail = new_node;
    }

    return;
}

void Linked_lists::add_before_node(int data, int data_before)
{
    /*
ITERATIVE METHOD
*/
    // Node *curr_node = head;
    // if (head->data != data_before)
    // {
    //     while ((curr_node->next_node)->data != data_before)
    //     {
    //         curr_node = curr_node->next_node;
    //     }

    //     Node *new_node = new Node(data, curr_node->next_node);
    //     curr_node->next_node = new_node;
    // }
    // else
    // {
    //     Node *new_node = new Node(data, head);
    //     head = new_node;
    // }

    // return;

    /*
RECURSIVE METHOD
*/
    static Node *curr_node = head;
    if (head->data != data_before)
        if (curr_node->next_node->data != data_before)
        {
            curr_node = curr_node->next_node;
            add_before_node(data, data_before);
        }
        else
        {
            Node *new_node = new Node(data, curr_node->next_node);
            curr_node->next_node = new_node;
        }
    else
    {
        Node *new_node = new Node(data, head);
        head = new_node;
    }

    return;
}

void Linked_lists::remove_node_head()
{
    if (tail == head)
    {
        tail = head = 0;
    }
    else
    {
        Node *curr_node = head;
        head = curr_node->next_node;
        delete curr_node;
    }
    return;
}

void Linked_lists::remove_node_tail()
{
    /*
    ITERATIVE METHOD
     */
    // Node *curr_node = head;
    // while (curr_node->next_node != tail)
    // {
    //     curr_node = curr_node->next_node;
    // }

    // delete tail;
    // tail = curr_node;
    // curr_node->next_node = nullptr;

    // return;

    /*
    RECURSIVE METHOD
    */

    static Node *curr_node = head;
    if (curr_node->next_node->next_node != 0)
    {
        curr_node = curr_node->next_node;
        remove_node_tail();
    }
    else
    {
        delete curr_node->next_node;
        curr_node->next_node = 0;
        tail = curr_node;
    }

    return;
}

void Linked_lists::remove_after_node(int data_after)
{
    /*
    ITERATIVE METHOD
     */

    // Node *curr_node = head;
    // while (curr_node->data != data_after)
    // {
    //     curr_node = curr_node->next_node;
    // }
    // Node *node_remove = curr_node->next_node;
    // curr_node->next_node = (node_remove)->next_node;
    // if (node_remove == tail)
    // tail = curr_node;
    // delete node_remove;

    // return;

    /*
    RECURSIVE METHOD
    */

    static Node *curr_node = head;

    if (curr_node->data != data_after)
    {
        curr_node = curr_node->next_node;
        remove_after_node(data_after);
    }
    else
    {
        Node *remove_node = curr_node->next_node;
        curr_node->next_node = remove_node->next_node;
        if (remove_node == tail)
            tail = curr_node;
        delete remove_node;
    }

    return;
}

void Linked_lists::remove_before_node(int data_before)
{
    /*
    ITERATIVE METHOD
     */
    // if (head->next_node->data != data_before)
    // {
    //     Node *curr_node = head;
    //     while (((curr_node->next_node)->next_node)->data != data_before)
    //     {
    //         curr_node = curr_node->next_node;
    //     }

    //     Node *node_remove = curr_node->next_node;
    //     curr_node->next_node = node_remove->next_node;
    //     delete node_remove;
    // }
    // else
    // {
    //     Node *new_head = head->next_node;
    //     delete head;
    //     head = new_head;
    // }

    // return;

    /*
    RECURSIVE METHOD
    */

    static Node *curr_node = head;
    if (head->next_node->data != data_before)
        if (curr_node->next_node->next_node->data != data_before)
        {
            curr_node = curr_node->next_node;
            remove_before_node(data_before);
        }
        else
        {
            Node *node_remove = curr_node->next_node;
            curr_node->next_node = node_remove->next_node;
            delete node_remove;
        }
    else
    {
        Node *new_head = head->next_node;
        delete head;
        head = new_head;
    }

    return;
}

void Linked_lists::remove_node_data(int data_remove)
{
    /*
ITERATIVE METHOD
*/

    // Node *curr_node = head;
    // if (curr_node->data != data_remove)
    // {
    //     while ((curr_node->next_node)->data != data_remove)
    //     {
    //         curr_node = curr_node->next_node;
    //     }

    //     Node *node_remove = curr_node->next_node;
    //     curr_node->next_node = node_remove->next_node;
    //     if (node_remove == tail)
    //         tail = curr_node;
    //     delete node_remove;
    // }
    // else
    // {
    //     Node *new_head = curr_node->next_node;
    //     delete head;
    //     head = new_head;
    // }
    // return;

    /*RECURSIVE METHOD*/

    static Node *curr_node = head;
    if (head->data != data_remove)
        if (curr_node->next_node->data != data_remove)
        {
            curr_node = curr_node->next_node;
            remove_node_data(data_remove);
        }
        else
        {
            Node *node_remove = curr_node->next_node;
            curr_node->next_node = node_remove->next_node;
            if (node_remove == tail)
                tail = curr_node;
            delete node_remove;
        }
    else
    {
        Node *new_head = head->next_node;
        delete head;
        head = new_head;
    }

    return;
}

void Linked_lists::remove_numbered_node(int node_no)
{
    Node *curr_node = head;
    int node = 1;
    while (node != (node_no - 1))
    {
        curr_node = curr_node->next_node;
        ++node;
    }

    Node *node_remove = curr_node->next_node;
    curr_node->next_node = node_remove->next_node;
    delete node_remove;

    return;
}

int Linked_lists::total_nodes()
{
    // Node *curr_node = head;
    // int counter = 0;

    // while (curr_node != nullptr)
    // {
    //     ++counter;
    //     curr_node = curr_node->next_node;
    // }
    // delete curr_node;
    // return counter;

    static int counter = 0;
    static Node *curr_node = head;
    if (curr_node != 0)
    {
        ++counter;
        curr_node = curr_node->next_node;
        total_nodes();
    }

    return counter;
}

int Linked_lists::total_nodes_given_data(int given_data)
{
    // Node *curr_node = head;
    // int counter = 0;

    // while (curr_node != nullptr)
    // {
    //     if (curr_node->data == given_data)
    //         ++counter;
    //     curr_node = curr_node->next_node;
    // }

    // delete curr_node;
    // return counter;

    static int counter = 0;
    static Node *curr_node = head;
    if (curr_node != 0)
    {
        if (curr_node->data == given_data)
            ++counter;
        curr_node = curr_node->next_node;
        total_nodes_given_data(given_data);
    }

    return counter;
}

void Linked_lists::display_linked_list()
{
    std::cout << "\nLinked list : ";
    Node *curr_node = head;

    while (curr_node != nullptr)
    {
        std::cout << "\n"
                  << curr_node << "   " << curr_node->data << "   " << curr_node->next_node;
        curr_node = curr_node->next_node;
    }

    delete curr_node;
    return;

    // static Node *curr_node = head;
    // if (curr_node != 0)
    // {
    //     std::cout << "\n"
    //               << curr_node << "   " << curr_node->data << "   " << curr_node->next_node;
    //     curr_node = curr_node->next_node;
    //     display_linked_list();
    // }
    // else
    //     curr_node = head;

    // return;
}

// void Linked_lists::reverse_linked_list(Node *temp_node = head, Node *curr_node = head->next)
// {
//     static new_tail = head;
//     if (temp_node != 0)
//     {
//         temp_node = curr_node->next_node;
//         curr_node->next_node = head;
//         head = curr_node;
//         curr_node = temp_node;
//         reverse_linked_list(temp_node, curr_node);
//     }
//     else
//     {
//         tail = new_tail;
//         tail->next_node = 0;
//     }

//     return;
// }

void Linked_lists::reverse_linked_list()
{
    if (head)
    {
        if (head != tail)
        {
            Node *curr_node;
            Node *temp_node = head;
            tail = head;
            curr_node = temp_node->next_node;
            head->next_node = nullptr;
            while (temp_node != 0)
            {
                temp_node = curr_node->next_node;
                curr_node->next_node = head;
                head = curr_node;
                curr_node = temp_node;
            }
        }
    }

    return;

    /*
RECURSIVE METHOD
*/

    // if (head)
    //     if (head != tail)
    //     {
    //         static Node *temp_node = head;
    //         static Node *curr_node = temp_node->next_node;
    //         static Node *new_tail = head;
    //         if (temp_node != 0)
    //         {
    //             temp_node = curr_node->next_node;
    //             curr_node->next_node = head;
    //             head = curr_node;
    //             curr_node = temp_node;
    //             reverse_linked_list();
    //         }
    //         else
    //         {
    //             tail = new_tail;
    //             tail->next_node = 0;
    //         }
    //     }

    // return;
}

void Linked_lists::selection_sort()
{
    if (head != nullptr)
    {
        if (head != tail)
        {
            for (Node *i = head; i != 0; i = i->next_node)
            {
                for (Node *j = i->next_node; j != 0; j = j->next_node)
                {
                    if (j->data < i->data)
                    {
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }
    }

    return;
}

void Linked_lists::insertion_sort()
{
    if (head != nullptr)
    {
        if (head != tail)
        {
            for (Node *i = head->next_node; i != 0; i = i->next_node)
            {
                for (Node *j = head; j != i; j = j->next_node)
                {
                    if (j->next_node->data > i->data)
                    {
                        int var = i->data;
                        remove_node_data(i->data);
                        display_linked_list();

                        if (j != head)
                            add_before_node(var, j->next_node->data);
                        else
                            add_before_node(var, j->data);

                        display_linked_list();
                        break;
                    }
                }
                std::cout << "\n\n===========";
            }
        }
    }

    return;
}

// Linked_lists Linked_lists::join_linked_lists(Linked_lists *obj)
// {
//     Node *temp = tail;
//     tail->next_node = obj->head;
//     tail = obj->tail;

//     Linked_lists newList;
//     newList.head = this->head;
//     newList.tail = this->tail;

//     return newList;
// }

void Linked_lists::operator+(Linked_lists &obj)
{
    if (tail)
    {
        tail->next_node = obj.head;
        tail = obj.tail;
    }
    else
    {
        head = obj.head;
        tail = obj.tail;
    }
}

Linked_lists::~Linked_lists() {}