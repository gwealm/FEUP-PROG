#include <iostream>

int main() {
    
    /*
    int x = 1, y = 2;
    int &ref_x = x, &ref_y = y;
    ref_x = ref_y;
    std::cout << "x = " << x << "; y = " << y << std::endl;
    */

    /*
    x = 2; y = 2
    */

    ///////////////////////////////

    /*
    int x = 1, y = 2;
    int *ptr_x = &x, *ptr_y = &y;
    ptr_x = ptr_y;
    std::cout << "x = " << x << "; y = " << y << std::endl;
    std::cout << "ptr_x = " << ptr_x << "; ptr_y = " << ptr_y << std::endl;
    std::cout << "*ptr_x = " << *ptr_x << "; *ptr_y = " << *ptr_y << std::endl;
    */

    /*
    x = 1; y = 2
    ptr_x = <address_of_y>; ptr_y = <address_of_y>
    *ptr_x = 2; *ptr_y = 2
    */
   
   return 0;
}