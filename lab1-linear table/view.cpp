#include <iostream>
#include "seq-list.h"
#include "view.h"


SeqList<int>* list;

void print()
{
		int total = list->getLens();
		std::cout << "Current data:" << std::endl;
		for (int a = 0; a < total; a++)
			std::cout << list->get(a) << " ";
		std::cout << std::endl;
}

void create() {
	try {
		std::cout << "---CREATE---" << std::endl;
		int n, t;
		std::cout << "Plz input the total number of the data:";
		std::cin >> n;
		std::cout << "Now input the data:" << std::endl;
		list = new SeqList<int>();
		for (int a = 0; a < n; a++) {
			std::cin >> t;
			list->add(t);
		}	
		print();
	}
	catch (char* e) {
		std::cout << "AN EXCEPTION CAUGHT:" << e << std::endl;
		std::cout << "---TRY AGAIN---" << e << std::endl;
		create();
	}
}

void insert()
{
	try {
		std::cout << "---INSERT---" << std::endl;
		int n, d;
		std::cout << "Plz input the index you insert:";
		std::cin >> n; 
		std::cout << "Plz input the data you insert:";
		std::cin >> d;
		list->add(n, d);
		print();
	}
	catch (char* e) {
		std::cout << " AN EXCEPTION CAUGHT:" << e << std::endl;
		std::cout << "---TRY AGAIN---" << e << std::endl;
		insert();
	}
}

void remove()
{
	try {
		std::cout << "---REMOVE---" << std::endl;
		int n;
		std::cout << "Plz input the index you remove:";
		std::cin >> n;
		list->removeAt(n);
		print();
	}
	catch (char* e) {
		std::cout << "AN EXCEPTION CAUGHT:" << e << std::endl;
		std::cout << "---TRY AGAIN---" << e << std::endl;
		remove();
	}
}

void searchAt()
{
	try {
		std::cout << "---GET---" << std::endl;
		int n;
		std::cout << "Plz input the index you get:";
		std::cin >> n;
		std::cout << "It is " << list->get(n) << std::endl;
	}
	catch (char* e) {
		std::cout << "AN EXCEPTION CAUGHT:" << e << std::endl;
		std::cout << "---TRY AGAIN---" << e << std::endl;
		searchAt();
	}
}

void search()
{
	try {
		std::cout << "---SEARCH---" << std::endl;
		int n;
		std::cout << "Plz input the data you rearch:";
		std::cin >> n;
		std::cout << "It is at " << list->findIndex(n) << std::endl;
	}
	catch (char* e) {
		std::cout << "AN EXCEPTION CAUGHT:" << e << std::endl;
		std::cout << "---TRY AGAIN---" << e << std::endl;
		search();
	}
}
