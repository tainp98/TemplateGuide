#ifndef VARIADICPRINT_H
#define VARIADICPRINT_H
#include <iostream>

template <typename T>
void print(T arg){
    std::cout << arg << "\n";
}
template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
//    std::cout << firstArg << "\n";
    std::cout << sizeof... (Types) << "\n";
    std::cout << sizeof... (args) << "\n";
    print(firstArg);
    print(args...);
}
#endif // VARIADICPRINT_H
