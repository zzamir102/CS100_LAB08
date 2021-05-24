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
		
	private:
		Base* leftVal;
		Base* rightVal; 
}; 

#endif

