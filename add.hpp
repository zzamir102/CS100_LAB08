#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"
#include <string>

using namespace std;

class Add : public Base {
     public:
	Add (Base* leftChild, Base* rightChild) : Base () {
		leftVal = leftChild;
		rightVal = rightChild;
	}
	
	virtual ~Add () {
		delete leftVal;
		delete rightVal;
	}

	virtual double evaluate() {
		return (leftVal->evaluate() + rightVal->evaluate());
	}

	virtual string stringify() {
		string str;
		string left = leftVal->stringify();
		string right = rightVal->stringify();
		str = "(" + left + " + " + right + ")";
		return str;
	}

	virtual int number_of_children() {
		return 2;
	}
	
	virtual Base* get_child(int i) {
		if (i == 0) {
			return leftVal;
		}
		else if(i == 1) {
			return rightVal;
		}
		else {
			return nullptr;
		}
	}
	
     private:
	Base* leftVal;
	Base* rightVal;
};

#endif
