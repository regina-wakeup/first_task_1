#include <iostream>
#include "ip_sort.h"

void ip_sort(){
    #ifdef NDEBUG
    std::cout << "ip_sort/0.1: Hello World Release!" <<std::endl;
    #else
    std::cout << "ip_sort/0.1: Hello World Debug!" <<std::endl;
    #endif
}
