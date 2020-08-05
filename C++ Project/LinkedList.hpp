/*
 * LinkedList.hpp
 *
 *  Created on: Feb 5, 2018
 *      Author: Naweeda
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

class LinkedList {
private:
	struct ListNode
	{
		int data;
		struct ListNode * next;
	};

	ListNode * head;
public:
	LinkedList();
	~LinkedList();
	void push_back(int);
	void push_front(int);
	int size();
	void delete_list(void);
	void print_list();
	void pop_front();
	void pop_back();
	int first();
	int last();
	int getAt(int);
	int operator[](int);
	void insertAt(int, int);
	void deleteAt(int);
	void insertSorted(int);

};

#endif /* LINKEDLIST_HPP_ */
