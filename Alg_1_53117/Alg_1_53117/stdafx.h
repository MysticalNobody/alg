// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
class ListObject {
public:
	int data_;
	ListObject *pervious_;
	ListObject *next_;
};


class List {
public:
	List();

	~List();

	void add(int data);

	void remove(int data);

	int getSize();

	void print();

	ListObject *getHead();

	ListObject *getEnd();
private:
	ListObject *head_;
	ListObject *end_;
	int size_;
};

// TODO: reference additional headers your program requires here
