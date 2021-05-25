#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <string>
#include <math.h>

using namespace std;

class Pow : public Base {
   public:
	Pow(Base* leftChild, Base* rightChild) : Base() {
		leftVal = leftChild;
		rightVal = rightChild;
	}		
	virtual ~Pow() {
		delete leftVal;
		delete rightVal;
	}
	virtual double evaluate() {
		return(pow(leftVal->evaluate(), rightVal->evaluate()));
	}

	virtual string stringify() {
		string str;
		string left = leftVal->stringify();
		string right = rightVal->stringify();
		str = "(" + left + " ** " + right + ")";
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

	virtual void accept(Visitor* visitor, int index) {
		if (index == 0) {
			visitor->visit_pow_begin(this);
		}
		else if(index == 1) {
			visitor->visit_pow_middle(this);
		}
		else {
			visitor->visit_pow_end(this);
		}
	}

   private:
	Base* leftVal;
	Base* rightVal;

};

#endif
