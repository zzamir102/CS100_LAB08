#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Sub : public Base {
   public:
	Sub(Base* leftChild, Base* rightChild) : Base () {
		leftVal = leftChild;
		rightVal = rightChild;
	}
	virtual ~Sub() {
			delete leftVal;
			delete rightVal;
		}
	virtual double evaluate() {
		return (leftVal->evaluate() - rightVal->evaluate());
	}
	virtual string stringify() {
		string str;
		string left = leftVal->stringify();
		string right = rightVal->stringify();
		str = "(" + left + " - " + right + ")";
		return str;
	}

   private:
	Base* leftVal;	
	Base* rightVal;

};

#endif

