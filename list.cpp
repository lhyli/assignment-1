
#include"list.h"
#include <cassert>
#include <iostream>
using namespace std;

//Node Constructor
Node::Node(string s) {
	data = s;
	previous = nullptr;
	next = nullptr;
}

//Iterator Constructor
Iterator::Iterator() {
	position = nullptr;
	container = nullptr;
}


string Iterator::get() const {
	assert(position != nullptr); //ensures that there's a value being pointed
	return position->data;
}

void Iterator::next() {
	assert(position != nullptr); // ensures that there's a pointer in the next position
	position = position->next;

}

void Iterator::previous() {
	assert(position != container->first); //ensures that the iterator cannot go before the first element of the list
	if (position == nullptr) {
		position = container->last;  // if the iterator point past the last node of the list, the previous() should get the last element of the list
	}
	else {
		position = position->previous;
	}
}


bool Iterator::equals(Iterator b) const {

	return position == b.position;  // check if two pointers point to the same position

}

// List Constructor
List::List() {
	first = nullptr;
	last = nullptr;
}

void List::push_front(string data) {
	Node* new_node = new Node(data);
	if (first == nullptr) {   // when the list is empty, insert the node into the list.  This node is both the first and the last node.
		first = new_node;
		last = new_node;
	}
	else {   // manipulate the links between this newly inserted node with the first node
		new_node->next = first;
		first->previous = new_node;
		first = new_node;
	}
}

void List::push_back(string data) {
	Node* new_node = new Node(data);
	if (last == nullptr) {  // when the list is empty, insert the node into the list
		first = new_node;
		last = new_node;
	}
	else { // manipulate the links between this newly inserted node with the last node
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
}


void List::swap(Iterator iter1, Iterator iter2) { // use pointer to manipulate the data pointed by two iterators
	
	// Case 1  two iterators point to the same position  
	// Simply do nothing.
	if (iter1.equals(iter2)) {
		return;
	} 

	// Case 2 iter1 is adjacent to iter2  OR  iter1 is adjacent to iter2
	// We just need to solve 1 case and use symmetricity to solve the other one. 
	// 
	// if iter2 is in front of iter1, we use the code below
	if (iter2.position->next == iter1.position) {
		swap(iter2, iter1); // repeat using the swap function, the only change is that iter2 is in front of iter1
		return;
	}

	//identify the node pointer by two iterators
	Node* n1 = iter1.position;
	Node* n2 = iter2.position;

	// if iter1 is in front of iter2
	if (n1->next == n2) {
		// modify first and last pointers
		if (n1 == iter1.container->first) { // when node pointed by n1 is the first node in the list
			iter1.container->first = n2;    // then node pointed by n2 become the first the node in the list
		}
		if (n2 == iter2.container->last) { // when node pointed by n2 is the first node in the list
			iter1.container->last = n1;  // then node pointed by n1 become the first the node in the list
		}
		//identify pointers to the surrounding nodes inpmacted by the swap
		Node* prev = n1->previous;
		Node* next = n2->next;

		// manipulate the links between the given nodes and the surrounding nodes
		n2->previous = prev;	
		n2->next = n1;
		n1->next = next;
		n1->previous = n2;
		
		//when the node "prev" is not a null pointer, link "prev" to node pointed by n2
		if (n2->previous != nullptr) {
			prev->next = n2;
		}
		// when the node "next" is not a null pointer, link "next" to node pointed by n1
		if (n1->next != nullptr) {
			next->previous = n1;
		}
	}


	// Case 3  The nodes are not adjacent.
	else {
		//Swap Two Non Adjacent Nodes(iter1, iter2);
		//identify the node pointer by two iterators
		Node* n1 = iter1.position;
		Node* n2 = iter2.position;

		//modify first and last pointers when nodes pointed by the given pointers are in the "extreme" positions of the list
		if (n1 == iter1.container->first) {  //when node pointed by n1 is the first node
			iter1.container->first = n2;   //node pointed by n2 become the first node
		}
		if (n1 == iter1.container->last) {  //when node pointed by n1 is the last node
			iter1.container->last = n2;  //node pointed by n2 become the last node
		}
	}


	if (n2 == iter2.container->first) { //when node pointed by n2 is the first node
		iter1.container->first = n1;  //node pointed by n1 become the first node
	}
	if (n2 == iter2.container->last) {  //when node pointed by n2 is the last node
		iter1.container->last = n1;  //node pointed by n1 become the last node
	}

	//identify the pointers to the surrounding nodes pointed by the given two iterators
	Node* n1_next = n1->next;
	Node* n2_next = n2->next;
	Node* n1_prev = n1->previous;
	Node* n2_prev = n2->previous;

	// modify prev and next nodes' connection
	// manipulate the links between the surrounding nodes with the nodes pointed by the given iterators
	if (n1_prev != nullptr) {
		n1_prev->next = n2;
	}
	if (n1_next != nullptr) {
		n1_next->previous = n2;
	}

	if (n2_prev != nullptr) {
		n2_prev->next = n1;
	}
	if (n2_next != nullptr) {
		n2_next->previous = n1;
	}
	//manipulate the links between the nodes pointed by the iterators with the surrounding nodes
	n1->next = n2_next;
	n1->previous = n2_prev;
	n2->next = n1_next;
	n2->previous = n1_prev;
	
}

void List::reverse() {
	// set up two iterators to track the list
	Iterator iter1 = begin();
	Iterator iter2 = end();

	//set the initial current node to be the last node of the list
	Node* current_node = this->last;
	// when the initial current node is a null pointer, do nothing
	if (current_node == nullptr) {
		return;
	}
	// set up a "dummy" node pointer to go through nodes in the list
	Node* dummy = new Node("dummy");
	Node* ptr = dummy;

    //go through each node in the list, and manipulate the links with surrounding nodes
	while (current_node != nullptr) {
		ptr->next = current_node;
		Node* prev = current_node->previous;
		current_node->previous = ptr;
		current_node->next = prev;
		//go through the next node
		ptr = current_node;
		current_node = current_node->next;

	}
	// modify first 
	// modify last
	this->first = dummy->next;
	this->first->previous = nullptr;
	this->last = iter1.position;
	this->last->next = nullptr;
}


Iterator List::erase(Iterator iter) {
	assert(iter.position != nullptr); // avoid the case when the iterator point to nothing	
	// Find the position of the node to be removed
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	// move to the next position 
	iter.next();
	
	// Case 1 To be removed node is the first and last node (only 1 node in the list)
	if (remove == first && remove == last) {
		remove->previous = remove->next = nullptr;
		first = last = nullptr;
	}
	// Case 2 To be removed node is the first but not the last node
	else if (remove == first) {
		remove->next = nullptr;
		after->previous = nullptr;
		first = after;
	}
	// Case 3 To be removed node is the last but no the first node
	else if (remove == last) {
		remove->previous = nullptr;
		before->next = nullptr;
		last = before;
	}
	// Case 4 To be removed node is an iterior node. (Neither the first nor the last)
	else {
		remove->previous = remove->next = nullptr;
		before->next = after;
		after->previous = before;
	}
	delete remove;
	return iter;
}

Iterator List::begin() {
	Iterator iter;
	iter.position = first; //point to the first node
	iter.container = this;
	return iter;
}

Iterator List::end() {
	Iterator iter;
	iter.position = nullptr;  //point to the position one after the final node
	iter.container = this;
	return iter;
}