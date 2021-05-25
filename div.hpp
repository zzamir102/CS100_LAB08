#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"
#include <string>

using namespace std;

class Div : public Base {
	public:
		Div(Base* leftNum, Base* rightNum) : Base() { 
			rightVal = rightNum;
			leftVal = leftNum;
		}
		
		//virtual ~Div() {
		//	delete leftVal;
		//	delete rightVal;
		//}
		virtual double evaluate() { 
			return (leftVal->evaluate() / rightVal->evaluate());
		}
		
		virtual string stringify() { 
			string s;
			string left = leftVal->stringify();
			string right = rightVal->stringify(); 
			s = "(" + left + " / " + right + ")"; 
			return s;
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
				visitor->visit_div_begin(this);
			}	
			else if(index == 1) {
				visitor->visit_div_middle(this);
			}
			else {
				visitor->visit_div_end(this);
			}
		}

	private:
		Base* leftVal;
		Base* rightVal;
};

#endif
