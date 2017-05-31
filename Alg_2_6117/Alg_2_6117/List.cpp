#include "List.h"
#include <iostream>

List::List() {
	size_ = 0;
	head_ = nullptr;
	end_ = nullptr;
}

List::~List() {
	size_ = 0;
	head_ = nullptr;
	end_ = nullptr;
}

void List::add(int data) {
	if (size_ == 0) {
		this->size_++;
		ListObject *lb = new ListObject();
		lb->data_ = data;
		lb->next_ = nullptr;
		lb->pervious_ = nullptr;
		this->head_ = lb;
		this->end_ = lb;
	}
	else {
		ListObject *lb = this->head_;
		while (true) {
			if ((lb->data_>data)) {
				ListObject *newLb = new ListObject();
				newLb->next_ = lb;
				newLb->pervious_ = lb->pervious_;
				newLb->data_ = data;
				if (lb->pervious_ == nullptr) {
					lb->pervious_ = newLb;
					this->head_ = newLb;
				}
				else {
					lb->pervious_->next_ = newLb;
					lb->pervious_ = newLb;
				}

				size_++;
				break;
			}
			if (lb->next_ == nullptr) {
				ListObject *newLb = new ListObject();
				newLb->next_ = lb->next_;
				newLb->pervious_ = lb;
				newLb->data_ = data;
				lb->next_ = newLb;
				size_++;
				break;
			}
			lb = lb->next_;
		}

	}


}

void List::remove(int data) {
	ListObject *lb = new ListObject;
	lb = this->head_;
	while (lb != nullptr) {
		if (lb->data_ == data) {
			if (lb->pervious_ == nullptr) {
				this->head_ = lb->next_;
				lb->next_->pervious_ = nullptr;
				delete lb;
				size_--;
				break;
			}
			if (lb->next_ == nullptr) {
				this->end_ = lb->pervious_;
				lb->pervious_->next_ = nullptr;
				delete lb;
				size_--;
				break;
			}
			lb->pervious_->next_ = lb->next_;
			lb->next_->pervious_ = lb->pervious_;
			delete lb;
			size_--;
			break;
		}
		lb = lb->next_;
	}
}

int List::getSize() {
	return this->size_;
}

void List::print() {
	ListObject *lb = this->head_;
	std::cout << "Head: " << lb->data_ << std::endl;
	while (lb->next_->next_ != nullptr) {
		lb = lb->next_;
		std::cout << "data: " << lb->data_ << std::endl;
	}
	lb = lb->next_;
	std::cout << "End:  " << lb->data_ << std::endl;
	std::cout << "size:  " << this->size_ << std::endl;

}