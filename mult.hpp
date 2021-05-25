#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"
#include <string>

using namespace std;

class Mult : public Base {
	public:
		Mult(Base* leftNum, Base* rightNum) : Base() {
			leftVal = leftNum;
			rightVal = rightNum;
		}
		virtual ~Mult() {
			delete leftVal;
			delete rightVal;
		}
		virtual double evaluate() { 
			return (leftVal->evaluate() * rightVal->evaluate());
		}
		
		virtual string stringify() {
			string s;
			string left = leftVal->stringify();
			string right = rightVal->stringify();
			s = "(" + left + " * " + right + ")";
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
				visitor->visit_mult_begin(this);
			}	
			else if(index == 1) {
				visitor->visit_mult_middle(this);
			}
			else {
				visitor->visit_mult_end(this);
			}
		}		


	private:
		Base* leftVal;
		Base* rightVal; 
}; 

#endif

