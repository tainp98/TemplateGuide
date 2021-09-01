#ifndef MAX_H
#define MAX_H
#include <type_traits>
#include <cstring>
template <typename RT = double, typename T1, typename T2>
auto max(T1 a, T2 b)
{
    return b < a ? a : b;
}
#endif // MAX_H
