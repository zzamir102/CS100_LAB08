#include "gtest/gtest.h"
#include "rand.hpp"
#include "add.hpp"
#include "op.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "visitor.hpp"
#include "VisitorLatex.hpp"

//----------------------------------
//Optests
//----------------------------------

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
    delete test;
}

TEST(OpTest, OpStringifyNum) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8");
    delete test;
}

TEST(OpTest, OpgetChildInvalid) {
    Op* test = new Op(12);
    EXPECT_EQ(test->get_child(0), nullptr);
    delete test;
}

TEST(OpTest, Opnumber_of_children) {
    Op* test = new Op(15);
    EXPECT_EQ(test->number_of_children(), 0);
    delete test;
}

//-----------------------------------
//add_tests
//-----------------------------------

TEST(AddTest, AddEvaluateNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 18.5);
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, AddEvaluateNonDouble) {
	Op* left = new Op(9);
	Op* right = new Op(16);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 25.0);
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, AddEvaluateNegativeInputs) {
	Op* left = new Op(-9.0);
	Op* right = new Op(16.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 7.000000);
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, AddEvaluateAddZero) {
	Op* left = new Op(0.0);
	Op* right = new Op(10.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 10.0);
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, AddStringifyNonZero) {
	Op* left = new Op(9);
	Op* right = new Op(16);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(),"(9 + 16)");	
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, AddgetChildOne) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->get_child(0),left);
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, AddgetChildTwo) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->get_child(1),right);
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, AddgetChildInvalid) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->get_child(3),nullptr);
	delete left;
	delete right;
	delete test;
}

TEST(AddTest, Addgetnumber_of_children) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
	delete left;
	delete right;
	delete test;
}

//-----------------------------------
//SubTest
//-----------------------------------

TEST(SubTest, SubEvaluateNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -1.5);
	delete left;
	delete right;
	delete test;
}

TEST(SubTest, SubEvaluateNegative) {
	Op* left = new Op(-18.5);
	Op* right = new Op(-10.2341);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -8.2659);
	delete left;
	delete right;
	delete test;
}


TEST(SubTest, SubEvaluateZero) {
	Op* left = new Op(0);
	Op* right = new Op(12.44287);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -12.44287);
	delete left;
	delete right;
	delete test;
}



TEST(SubTest, SubStringifyNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->stringify(),"(8.5 - 10)");
	delete left;
	delete right;
	delete test;
}

TEST(SubTest, SubgetChildOne) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->get_child(0), left);
	delete left;
	delete right;
	delete test;
}

TEST(SubTest, SubgetChildTwo) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->get_child(1), right);
	delete left;
	delete right;
	delete test;
}

TEST(SubTest, SubgetChildInvalid) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->get_child(2), nullptr);
	delete left;
	delete right;
	delete test;
}

TEST(SubTest, Subnumber_of_children) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
	delete left;
	delete right;
	delete test;
}


//----------------------------------------
//MultTest
//----------------------------------------

TEST(MultTest, MultEvaluateNonzero) { 
	Op* right = new Op(6.0);
	Op* left = new Op(8.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), 48);
	delete left;
	delete right;
	delete test;
}

TEST(MultTest, MultEvaluateNegative) {
	Op* right = new Op(5.0);
	Op* left = new Op(-10.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), -50.0);
	delete left;
	delete right;
	delete test;
}

TEST(MultTest, MultStringifyNonzero) { 
	Op* right = new Op(20.0);
	Op* left = new Op(25.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "(25 * 20)");
	delete left;
	delete right;
	delete test;
}

TEST(MultTest, MultStringifyNegative) {
	Op* right = new Op(-54.0);
	Op* left = new Op(26.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "(26 * -54)"); 
	delete left;
	delete right;
	delete test;
}

TEST(MultTest, MultgetChildOne) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->get_child(0), left);
	delete left;
	delete right;
	delete test;
}

TEST(MultTest, MultgetChildTwo) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->get_child(1), right);
	delete left;
	delete right;
	delete test;
}

TEST(MultTest, MultgetChildInvalid) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->get_child(5), nullptr);
	delete left;
	delete right;
	delete test;
}

TEST(MultTest, Multnumber_of_children) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
	delete left;
	delete right;
	delete test;
}


//----------------------------------------
//DivTests
//----------------------------------------

TEST(DivTest, DivEvaluateNonzero) {
	Op* right = new Op(4.0);
	Op* left = new Op(8.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 2.0);
	delete left;
	delete right;
	delete test;
}

TEST(DivTest, DivEvaluateNegative) {
	Op* right = new Op(10.0);
	Op* left = new Op(-19.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), -1.9);
	delete left;
	delete right;
	delete test;
}


TEST(DivTest, DivEvaluateTwoNegative) { 
	Op* right = new Op(-25.0);
	Op* left = new Op(-50.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 2.0); 
	delete left;
	delete right;
	delete test;
}

TEST(DivTest, DivStringifyNonZero) { 
	Op* right = new Op(56.0);
	Op* left = new Op(5.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->stringify(), "(5 / 56)"); 
	delete left;
	delete right;
	delete test;
} 

TEST(DivTest, DivgetChildOne) {
	Op* right = new Op(24);
	Op* left = new Op(3.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->get_child(0), left);
	delete left;
	delete right;
	delete test;
}

TEST(DivTest, DivgetChildTwo) {
	Op* right = new Op(24);
	Op* left = new Op(3.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->get_child(1), right);
	delete left;
	delete right;
	delete test;
}

TEST(DivTest, Divnumber_of_children) {
	Op* right = new Op(24);
	Op* left = new Op(3.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
	delete left;
	delete right;
	delete test;
}

//---------------------------------------------
//PowTests
//---------------------------------------------

TEST(PowTest, PowEvaluateNonZero) {
	Op* left = new Op(3.0);
	Op* right = new Op(6.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(),729.000000);
	delete left;
	delete right;
	delete test;
} 

TEST(PowTest, PowEvaluateZero) {
	Op* left = new Op(10.0);
	Op* right = new Op(0.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 1.0);
	delete left;
	delete right;
	delete test;
}

TEST(PowTest, PowEvaluateNegative) {
	Op* left = new Op(2.0);
	Op* right = new Op(-2.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 0.25);
	delete left;
	delete right;
	delete test;
}

TEST(PowTest, PowStringifyNonZero) {
	Op* left = new Op(3.0);
	Op* right = new Op(6.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->stringify(), "(3 ** 6)");
	delete left;
	delete right;
	delete test;
}

TEST(PowTest, PowgetChildOne) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->get_child(0), left);
	delete left;
	delete right;
	delete test;
}

TEST(PowTest, PowgetChildTwo) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->get_child(1), right);
	delete left;
	delete right;
	delete test;
}


TEST(PowTest, PowgetChildInvalid) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->get_child(9), nullptr);
	delete left;
	delete right;
	delete test;
}


TEST(PowTest, Pownumber_of_children) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
	delete left;
	delete right;
	delete test;
}

//-------------Multiple Tests----------------------

TEST(DoubleOps, MultAddEvaluate) {
	Op* left = new Op(5.0);
	Op* right = new Op(2.0);
	Mult* leftChildren = new Mult(left, right);
	Op* rightChild = new Op(2.0);
	Add* test = new Add(leftChildren, rightChild);
	EXPECT_EQ(test->evaluate(), 12.0);
	delete left;
	delete right;
	delete leftChildren;
	delete rightChild;
	delete test;
}

TEST(DoubleOps, MultAddStringify) {
	Op* left = new Op(5.0);
	Op* right = new Op(2.0);
	Mult* leftChildren = new Mult(left, right);
	Op* rightChild = new Op(2.0);
	Add* test = new Add(leftChildren, rightChild);
	EXPECT_EQ(test->stringify(), "((5 * 2) + 2)");
	delete left;
	delete right;
	delete leftChildren;
	delete rightChild;
	delete test;
}

TEST(DoubleOps, MultAddGetChild) {
	Op* left = new Op(5.0);
	Op* right = new Op(2.0);
	Mult* leftChildren = new Mult(left, right);
	Op* rightChild = new Op(2.0);
	Add* test = new Add(leftChildren, rightChild);
	EXPECT_EQ(test->get_child(0), leftChildren);
	delete left;
	delete right;
	delete leftChildren;
	delete rightChild;
	delete test;
}

TEST(DoubleOps, MultAddNumberofChildren) {
	Op* left = new Op(5.0);
	Op* right = new Op(2.0);
	Mult* leftChildren = new Mult(left, right);
	Op* rightChild = new Op(2.0);
	Add* test = new Add(leftChildren, rightChild);
	EXPECT_EQ(test->number_of_children(), 2);
	delete left;
	delete right;
	delete leftChildren;
	delete rightChild;
	delete test;
}

//----------------PrintLatex Tests-----------------

TEST(PrintLatex, Add) {
	Base* three = new Op(3);
	Base* four = new Op(4);
	Base* add = new Add(three, four);
	VisitorLaTeX test;
	EXPECT_EQ(test.PrintLaTeX(add), "${({3}+{4})}$");
	delete three;
	delete four;
	delete add;
}

TEST(PrintLatex, Sub) {
	Base* three = new Op(3);
	Base* four = new Op(4);
	Base* sub = new Sub(three, four);
	VisitorLaTeX test;
	EXPECT_EQ(test.PrintLaTeX(sub), "${({3}-{4})}$");
	delete three;
	delete four;
	delete sub;
}

TEST(PrintLatex, Mult) {
	Base* three = new Op(3);
	Base* four = new Op(4);
	Base* mult = new Mult(three, four);
	VisitorLaTeX test;
	EXPECT_EQ(test.PrintLaTeX(mult), "${({3}\\cdot{4})}$");
	delete three;
	delete four;
	delete mult;
}

TEST(PrintLatex, Div) {
	Base* eight = new Op(8);
	Base* four = new Op(4);
	Base* div = new Div(eight, four);
	VisitorLaTeX test;
	EXPECT_EQ(test.PrintLaTeX(div), "${\\frac{8}{4}}$");
	delete eight;
	delete four;
	delete div;
}

TEST(PrintLatex, Pow) {
	Base* three = new Op(3);
	Base* four = new Op(4);
	Base* pow = new Pow(three, four);
	VisitorLaTeX test;
	EXPECT_EQ(test.PrintLaTeX(pow), "${({3}^{4})}$");
	delete three;
	delete four;
	delete pow;
}

TEST(PrintLatex, Mult_Add) {
	Base* three = new Op(3);
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* mult = new Mult(seven, four);
	Base* add = new Add(three, mult);
	Base* expression = new Add(mult, add);
	VisitorLaTeX test;
	EXPECT_EQ(test.PrintLaTeX(expression),"${({({7}\\cdot{4})}+{({3}+{({7}\\cdot{4})})})}$");
	delete three;
	delete seven;
	delete four;
	delete mult;
	delete add;
	delete expression;
}

TEST(PrintLatex, Sub_Add) {
	Base* three = new Op(3);
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* sub = new Sub(seven, four);
	Base* add = new Add(three, sub);
	Base* expression = new Mult(sub, add);
	VisitorLaTeX test;
	EXPECT_EQ(test.PrintLaTeX(expression),"${({({7}-{4})}\\cdot{({3}+{({7}-{4})})})}$");
	delete three;
	delete seven;
	delete four;
	delete sub;
	delete add;
	delete expression;
}

//-------------------------------------------------

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

