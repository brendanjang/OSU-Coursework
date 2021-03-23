/*****************************************************************************
** Program Name:	Lab 6 - Node.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Node class. Has following member variables:
					next - a pointer to the next Node object, prev - a pointer
					to the previous Node object, val - integer value the 
					specific Node contains.
*****************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    // Constructor
    Node();
    // Copy constructor
    Node(const Node& orig);
    // Destructor
    virtual ~Node();
    // Setter
    void setNext(Node * next);
    void setPrev(Node * prev);
    void setVal(int val);
    
    // Getter
    Node * getNext();
    Node * getPrev();
    int getVal();
        
private:
    Node * next;
    Node * prev;
    int val;
};

#endif /* NODE_HPP */
