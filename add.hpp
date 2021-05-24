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
	
     private:
	Base* leftVal;
	Base* rightVal;
};

#endif
