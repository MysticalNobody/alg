#include <iostream>
#include "List.h"

int main() {
	List list;
	list.add(12);
	list.add(13);
	list.add(27);
	list.add(15);
	list.add(10);

	list.print();

	list.remove(15);

	list.print();

	system("pause");

	return 0;
}