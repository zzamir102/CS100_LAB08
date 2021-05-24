#include "gtest/gtest.h"
#include "rand.hpp"
#include "add.hpp"
#include "op.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"

//----------------------------------
//Optests
//----------------------------------

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpStringifyNum) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8");
}

TEST(OpTest, OpgetChildInvalid) {
    Op* test = new Op(12);
    EXPECT_EQ(test->get_child(0), nullptr);
}

TEST(OpTest, Opnumber_of_children) {
    Op* test = new Op(15);
    EXPECT_EQ(test->number_of_children(), 0);
}

//-----------------------------------
//add_tests
//-----------------------------------

TEST(AddTest, AddEvaluateNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 18.5);
}

TEST(AddTest, AddEvaluateNonDouble) {
	Op* left = new Op(9);
	Op* right = new Op(16);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 25.0);
}

TEST(AddTest, AddEvaluateNegativeInputs) {
	Op* left = new Op(-9.0);
	Op* right = new Op(16.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 7.000000);
}

TEST(AddTest, AddEvaluateAddZero) {
	Op* left = new Op(0.0);
	Op* right = new Op(10.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 10.0);
}

TEST(AddTest, AddStringifyNonZero) {
	Op* left = new Op(9);
	Op* right = new Op(16);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(),"(9 + 16)");	
}

TEST(AddTest, AddgetChildOne) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->get_child(0),left);
}

TEST(AddTest, AddgetChildTwo) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->get_child(1),right);
}

TEST(AddTest, AddgetChildInvalid) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->get_child(3),nullptr);
}

TEST(AddTest, Addgetnumber_of_children) {
	Op* left = new Op(-9);
	Op* right = new Op(20);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
}

//-----------------------------------
//SubTest
//-----------------------------------

TEST(SubTest, SubEvaluateNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -1.5);
}

TEST(SubTest, SubEvaluateNegative) {
	Op* left = new Op(-18.5);
	Op* right = new Op(-10.2341);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -8.2659);
}

TEST(SubTest, SubEvaluateZero) {
	Op* left = new Op(0);
	Op* right = new Op(12.44287);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -12.44287);
}

TEST(SubTest, SubStringifyNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->stringify(),"(8.5 - 10)");
}

TEST(SubTest, SubgetChildOne) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->get_child(0), left);
}

TEST(SubTest, SubgetChildTwo) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->get_child(1), right);
}

TEST(SubTest, SubgetChildInvalid) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(SubTest, Subnumber_of_children) {
	Op* left = new Op(30);
	Op* right = new Op(14);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
}


//----------------------------------------
//MultTest
//----------------------------------------

TEST(MultTest, MultEvaluateNonzero) { 
	Op* right = new Op(6.0);
	Op* left = new Op(8.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), 48);
}

TEST(MultTest, MultEvaluateNegative) {
	Op* right = new Op(5.0);
	Op* left = new Op(-10.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), -50.0);
}

TEST(MultTest, MultStringifyNonzero) { 
	Op* right = new Op(20.0);
	Op* left = new Op(25.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "(25 * 20)");
}

TEST(MultTest, MultStringifyNegative) {
	Op* right = new Op(-54.0);
	Op* left = new Op(26.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "(26 * -54)"); 
}

TEST(MultTest, MultgetChildOne) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->get_child(0), left);
}

TEST(MultTest, MultgetChildTwo) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->get_child(1), right);
}

TEST(MultTest, MultgetChildInvalid) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->get_child(5), nullptr);
}

TEST(MultTest, Multnumber_of_children) {
	Op* right = new Op(-20);
	Op* left = new Op(34);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
}


//----------------------------------------
//DivTests
//----------------------------------------

TEST(DivTest, DivEvaluateNonzero) {
	Op* right = new Op(4.0);
	Op* left = new Op(8.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 2.0);
}

TEST(DivTest, DivEvaluateNegative) {
	Op* right = new Op(10.0);
	Op* left = new Op(-19.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), -1.9);
}

TEST(DivTest, DivEvaluateTwoNegative) { 
	Op* right = new Op(-25.0);
	Op* left = new Op(-50.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 2.0); 
}

TEST(DivTest, DivStringifyNonZero) { 
	Op* right = new Op(56.0);
	Op* left = new Op(5.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->stringify(), "(5 / 56)"); 
} 

TEST(DivTest, DivgetChildOne) {
	Op* right = new Op(24);
	Op* left = new Op(3.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->get_child(0), left);
}

TEST(DivTest, DivgetChildTwo) {
	Op* right = new Op(24);
	Op* left = new Op(3.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->get_child(1), right);
}

TEST(DivTest, Divnumber_of_children) {
	Op* right = new Op(24);
	Op* left = new Op(3.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
}

//---------------------------------------------
//PowTests
//---------------------------------------------

TEST(PowTest, PowEvaluateNonZero) {
	Op* left = new Op(3.0);
	Op* right = new Op(6.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(),729.000000);
} 

TEST(PowTest, PowEvaluateZero) {
	Op* left = new Op(10.0);
	Op* right = new Op(0.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 1.0);
}

TEST(PowTest, PowEvaluateNegative) {
	Op* left = new Op(2.0);
	Op* right = new Op(-2.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 0.25);
}

TEST(PowTest, PowStringifyNonZero) {
	Op* left = new Op(3.0);
	Op* right = new Op(6.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->stringify(), "(3 ** 6)");
}

TEST(PowTest, PowgetChildOne) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->get_child(0), left);
}

TEST(PowTest, PowgetChildTwo) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->get_child(1), right);
}

TEST(PowTest, PowgetChildInvalid) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->get_child(9), nullptr);
}

TEST(PowTest, Pownumber_of_children) {
	Op* left = new Op(12.0);
	Op* right = new Op(-4.5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->number_of_children(), 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

