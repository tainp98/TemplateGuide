#ifndef TRICKY_H
#define TRICKY_H
#include <iostream>
template<typename T>
void printcoll (T const& coll)
{
    typename T::const_iterator pos; // iterator to iterate over coll
    typename T::const_iterator end(coll.end()); // end position
    for (pos=coll.begin(); pos!=end; ++pos) {
        std::cout << *pos << " ";
    }
    std::cout << "\n";
}

template <typename T, int N, int M>
bool less(T(&a)[N], T(&b)[M])
{
    for(int i = 0; i < N && i < M; ++i)
    {
        if(a[i] < b[i])
            return  true;
        if(b[i] < a[i])
            return false;

    }
    return N < M;
}
#endif // TRICKY_H
