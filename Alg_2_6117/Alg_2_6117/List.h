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
