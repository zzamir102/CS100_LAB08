#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "add.hpp"
#include "visitor.hpp"
#include "VisitorLatex.hpp"

using namespace std;

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);

    Base* expression = new Add(mult, add);

    VisitorLaTeX sample1;

    cout << sample1.PrintLaTeX(expression) << endl;

    delete three;
    delete seven;
    delete four;
    delete mult;
    delete add;
    delete expression;

    return 0;
}
