#include <iostream>
#include "max.h"
//#include "VariadicPrint.h"
#include "FoldExpression.h"
#include "Tricky.h"
#include "Stack.h"
#include <vector>
using namespace std;


int main()
{
    double f1 = 3.4 ; double f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1, 2) << "\n";
    auto t = ::max(f1,2);
    int i = 2;
    std::cout << typeid (t).name() << "\n";
    std::string s("world");
//    print(7.5, "hello", s);
    std::cout << "FoldSum = " << foldSum(1,2,3,4,5,6,7,8,9) << "\n";
    ::print(1,2,3,4,5);
    std::vector<int> vec{1,2,3,4,5,6,7,8,9};
    ::printcoll(vec);
    int x[] = {1,2,3};
    int y[] = {1,2,3,4,5};
    std::cout << ::less(y,x) << "\n";
    std::cout << ::less("ab", "abc") << "\n";

    // <----------------------> test stack3
    Stack3<int> iStack; // stack of ints
    Stack3<float> fStack; // stack of floats
    // manipulate int stack
    iStack.push(1);
    iStack.push(2);
    std::cout << "iStack.top(): " << iStack.top() << "\n";
    // manipulate float stack:
    fStack.push(3.3);
    std::cout << "fStack.top(): " << fStack.top() << "\n";
    // assign stack of different type and manipulate again
    fStack = iStack;
    fStack.push(4.4);
    std::cout << "fStack.top(): " << fStack.top() << "\n";

    // stack for doubless using a vector as an internal container
    Stack3<double, std::vector> vStack;
    vStack.push(5.5);
    vStack.push(6.6);
    std::cout << "vStack.top(): " << vStack.top() << "\n";
    Stack3<int, std::deque> dStack;
    dStack.push(12);
    dStack.push(22);
//    vStack = dStack;
    vStack = fStack;
    std::cout << "vStack: ";
    while (! vStack.empty()) {
    std::cout << vStack.top() << " ";
    vStack.pop();
    std::vector<Stack3<int>> vecStack3;
    vecStack3.push_back(iStack);
    vecStack3[0] = fStack;
    }
    std::cout << "\ns";

    return 0;
}
