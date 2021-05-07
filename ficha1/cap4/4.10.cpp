#include <iostream>

int main() {
    
    int values[] = {2, 3, 5, 7, 11, 13};
    int *p = values + 1;
    std::cout << values[1] << std::endl;                  // 3
    std::cout << values + 1 << std::endl;                 // address of the 2nd element
    std::cout << *p << std::endl;                         // 3
    std::cout << *(values + 3) << std::endl;              // 7 
    std::cout << p + 1 << std::endl;                      // address of the 3rd element
    std::cout << p[1] << std::endl;                       // 5 (the same as *(p + 1) <-> values + 2) 
    std::cout << p - values << std::endl;                 // The offset between the first and the second addresses (1)

   return 0;
}