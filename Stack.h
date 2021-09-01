#ifndef STACK_H
#define STACK_H
#include <array>
#include <deque>

#include <cassert>
template<typename T, auto Maxsize>
class Stack {
public:
    using size_type = decltype(Maxsize);
private:
    std::array<T,Maxsize> elems; // elements

    size_type numElems; // current number of elements
public:
    Stack(); // constructor
    void push(T const& elem); // push element
    void pop(); // pop element
    T const& top() const; // return top element
    bool empty() const { //return whether the stack is empty
        return numElems == 0;
    }
    size_type size() const { //return current number of elements
        return numElems;
    }
};
// constructor
template<typename T, auto Maxsize>
Stack<T,Maxsize>::Stack ()
: numElems(0) //start with no elements
{
// nothing else to do
}
template<typename T, auto Maxsize>
void Stack<T,Maxsize>::push (T const& elem)
{
    assert(numElems < Maxsize);
    elems[numElems] = elem; // append element
    ++numElems; // increment number of elements
}
template<typename T, auto Maxsize>
void Stack<T,Maxsize>::pop ()
{
    assert(!elems.empty());
    --numElems; // decrement number of elements
}
template<typename T, auto Maxsize>
T const& Stack<T,Maxsize>::top () const
{
    assert(!elems.empty());
    return elems[numElems-1]; // return last element
}

template <typename T>
class Stack2{
  private:
    std::deque<T> elems;
    T x{};
public:
    void push(T const& elem);
    void pop();
    T const& top();
    bool empty()
    {
        return elems.empty();
    }

    template<typename T2>
    Stack2& operator = (Stack2<T2> const& op2);
    template<typename> friend class Stack2;
};

template <typename T>
template <typename T2>
Stack2<T>& Stack2<T>::operator=(Stack2<T2> const& op2)
{
    elems.clear();
    elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
    return *this;
}

template <typename T, template <typename Elem, typename = std::allocator<Elem>> class Cont = std::deque>
class Stack3{
private:
    Cont<T> elems;
public:
    void push(T const& elem);
    void pop();
    T const& top();
    bool empty() const
    {
        return elems.empty();
    }
    template <typename T2, template <typename Elem2, typename = std::allocator<Elem2>> class Cont2>
    Stack3<T, Cont>& operator = (Stack3<T2, Cont2> const& op2);
    template <typename, template <typename, typename>class> friend class Stack3;
};

template <typename T, template <typename, typename> class Cont>
void Stack3<T, Cont>::push(T const& elem)
{
    elems.push_back(elem);
}

template <typename T, template <typename, typename> class Cont>
void Stack3<T, Cont>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T, template <typename, typename> class Cont>
T const& Stack3<T, Cont>::top()
{
    assert(!elems.empty());
    return elems.back();
}

template <typename T, template <typename, typename> class Cont>
template <typename T2, template <typename, typename> class Cont2>
Stack3<T, Cont>& Stack3<T, Cont>::operator=(Stack3<T2, Cont2> const& op2)
{
    elems.clear();
    elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
    return *this;
}

#endif // STACK_H
