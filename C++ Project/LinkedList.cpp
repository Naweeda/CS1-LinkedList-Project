/*
 * LinkedList.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: Naweeda
 */

#include <iostream>
using namespace std;

#include "LinkedList.hpp"

LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub
	this->head = nullptr;

}

LinkedList::~LinkedList() {
	ListNode *aNode;
	ListNode *nextNode;

	aNode = head;

	while (aNode != nullptr)
	{
		nextNode = aNode->next;
		delete aNode;

		aNode = nextNode;
	}
}
void LinkedList::push_back(int x)
{

	if(head==nullptr)
	{
		head = new ListNode;
		head->data = x;
		head->next = nullptr;
	}
	else
	{
	    ListNode *nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = new ListNode;

		nodePtr->next->data = x;
		nodePtr->next->next = nullptr;

	}
}
void LinkedList::push_front(int x)
{
	if(head==nullptr)
	{
		head = new ListNode;
		head->data = x;
		head->next = nullptr;
	}
	else
	{
		ListNode *nodePtr = new ListNode;
		nodePtr->data = x;
		nodePtr->next = head;

		head = nodePtr;
	}
}
int LinkedList::size()
{
	int counter = 0;

	ListNode * current = head;
	while(current!=nullptr)
	{
		current = current->next;
		counter++;
	}

	return counter;

}
void LinkedList::delete_list(void)
{
	ListNode * aNode;

	while (aNode != nullptr)
	{
		aNode = aNode->next;
		delete head;
		head = aNode;
	}
}
void LinkedList::print_list()
{
	if(head != nullptr)
	{
		ListNode *value = head;
		while (value != nullptr)
		{
			cout << value->data << endl;
			value = value->next;
		}
	}
		else
		{
			cout << "No Linked List " << endl;
		}
}

void LinkedList::pop_front()
{
	if(head == nullptr)
	{
		cout << "No list" << endl;
	}
	else
	{
		ListNode* aNode = head->next;
		delete head;
		head = aNode;
		aNode = nullptr;
	}
}
void LinkedList::pop_back()
{
	if(head->next == nullptr)
	{
		delete head;
	}
	else if(head != nullptr)
	{
		ListNode *tempNode = head;
		ListNode *tempHead;
		while (tempNode->next != nullptr)
		{
			tempHead = tempNode;
			tempNode = tempNode->next;
		}
		delete tempNode;
		tempHead->next = nullptr;
	}
	else
	{
		cout << "No list" << endl;
	}
}
int LinkedList::first()
{
	if(head == nullptr)
	{
		throw "There is no data in the list ";
		return 0;
	}
	else
	{
		return head->data;///Throw a c string
	}
}
int LinkedList::last()
{
	if(head == nullptr)
	{
		throw "There is no data in the list";
		return 0;
	}
	else
	{
		ListNode *headPtr = head;
		while(headPtr->next != nullptr)
		{
			headPtr = headPtr->next;
		}
		return headPtr->data;
	}
}
int LinkedList::getAt(int num)
{
	int a = 0;
	ListNode * aHead = head;
	if(head == nullptr)
	{
		cout << "No List" << endl;
	}
	else if(num > size())
	{
		throw "Error: Doesn't exist in the Linked List.";
	}
	else
	{
	while (a < size() && a < num)
	{
		aHead = aHead->next;
		a++;
	}
}
	return aHead->data;

}
int LinkedList::operator[](int num)
{
	if(num > size())
	{
		throw "Too high";
	}
	else
	{
		return getAt(num);
	}
}
void LinkedList::insertAt(int node, int x)
{
	if(head == nullptr)
	{
		throw "Error, cannot insert.";
	}
	else if(node >= this->size())
	{
		throw "Error, the number is outside the list.";
	}
	else if(node < 0)
	{
		throw "Error, lower than zero, cannot insert.";
	}
	else if (node== 0)
	{
		this->push_front(x);
	}
	else if(node == this->size() -1)
	{
		this->push_back(x);
	}
	else
	{

		ListNode* temp = nullptr;
		ListNode *current = head;
		int counter = 1;

		while(current != nullptr && counter < x)
		{
			temp = current;
			current = current->next;
			counter++;
		}
		if(current != nullptr)
		{
			ListNode* tempNode = new ListNode();
			tempNode->data = node;

			if (temp != nullptr)
			{
				temp->next = current;

			}
		else
		{
			temp = temp->next;
			temp->next = current;

		}
			temp->next = tempNode;
			tempNode->next = current;
		}
	}
}

void LinkedList::deleteAt(int num)
{
	if(head == nullptr)
	{
		throw "Error: there is nothing in the list, can't delete.";
		return;
	}
	else if(num < 0)
	{
		throw "Error: The num is less than zero.";
	}
	else if (num == 0)
	{
		pop_front();
	}
	else if (num == size()-1)
	{
		pop_back();
	}
	else if (num >= size())
	{
		throw "Error, doesn't exist.";
	}
	else
	{
		ListNode* temp = nullptr;
		ListNode* current = head;
		int x = 0;
		while(x < num && current != nullptr)
		{
			temp = current;
			current = current->next;
			x++;
		}
		if(current != nullptr)
		{
			temp->next = current->next;
			delete current;
			current = nullptr;
		}
		else
		{
			pop_back();
		}
	}
}
void LinkedList::insertSorted(int a)
{
	if(head == nullptr)
	{
		throw "There are no nodes to sort, try to add some node first.";
	}
	else
	{
		this->push_back(a);
		ListNode *prev = head;
		ListNode *curr = head;

		for(curr = head; curr != nullptr; curr = curr->next)
		{

			for(prev = head; prev != nullptr; prev = prev->next)
			{
			if(prev->data > curr->data)
			{
				int tempData = 0;

				tempData = prev->data;
				prev->data = curr->data;
				curr->data = tempData;
			}
			}
		}
	}
}
