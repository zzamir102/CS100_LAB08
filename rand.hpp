#ifndef __RAND_HPP__
#define __RAND_HPP__
#include "base.hpp"
#include <cstdlib> 
#include <string>
using namespace std;

class Rand : public Base {
	public:
		Rand() : Base() {
			val = rand() % 100; 
		}
		virtual double evaluate() { return val; }
       		virtual string stringify() {
			ostringstream ss;
			ss << setprecision(8) << noshowpoint << val;
			return ss.str();
		}
		
		virtual int number_of_children() {
			return 0;
		}

		virtual Base* get_child(int i) {
			return nullptr;
		}
   	 private:
		double val;
};

#endif //__RAND_HPP__


