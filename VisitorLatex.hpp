#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include <iostream>
#include "visitor.hpp"
#include <string>
#include "iterator.cpp"

using namespace std;

class VisitorLaTeX : public Visitor {
  private:
	string output;
  public:
	VisitorLaTeX(): Visitor() {
		output = "$";
	}

	string PrintLaTeX(Base* root) {
		Iterator* it = new Iterator(root);
		for (it; !it->is_done(); it->next()) {
			it->current_node()->accept(this,it->current_index());
		}
		delete it;
		output += "$";
		return output;
	}


	virtual void visit_op(Op* node) {
		output += "{";
		output += node->stringify();
		output += "}";
	}

	virtual void visit_rand(Rand* node) {
		output += "(";
		output += ")";
	}

	virtual void visit_add_begin(Add* node) {
		output += "{(";
	}

	virtual void visit_add_middle(Add* node) {
		output += "+";
	}

	virtual void visit_add_end(Add* node) {
		output += ")}";
	}

	virtual void visit_sub_begin(Sub* node) {
		output += "{(";
	}

	virtual void visit_sub_middle(Sub* node) {
		output += "-";
	}

	virtual void visit_sub_end(Sub* node) {
		output += ")}";
	}

	virtual void visit_mult_begin(Mult* node) {
		output += "{(";
	}

	virtual void visit_mult_middle(Mult* node) {
		output += "\\cdot";
	}

	virtual void visit_mult_end(Mult* node) {
		output += ")}";
	}
	
	virtual void visit_div_begin(Div* node) {
		output += "{\\frac";
	}

	virtual void visit_div_middle(Div* node) {

	}

	virtual void visit_div_end(Div* node) {
		output += "}";
	}

	virtual void visit_pow_begin(Pow* node) {
		output += "{(";
	}

        virtual void visit_pow_middle(Pow* node) {
		output += "^";
	}

        virtual void visit_pow_end(Pow* node) {
		output += ")}";
	}


};




#endif
