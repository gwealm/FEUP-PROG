#include <iostream>

/**
 * @brief Calculates the greatest common divisor of 2 integers
 * 
 * @param n1 int 
 * @param n2 int
 * @return int 
 */
int getGcd(int n1, int n2) {

    if (n1 == n2)     { return n1; }
    else if (n1 == 0) { return n2; }
    else if (n2 == 0) { return n1; }

    while (n1 != n2) {
        if (n1 > n2)
            n1 -= n2;
        else 
            n2 -= n1;
    }
    return n1;
}


/**
 * @brief Reads a fraction and returns its validity
 * 
 * @param numerator  int
 * @param denominator int
 * @return true if valid, otherwise false
 */
bool readFraction(int &numerator, int &denominator) {
    bool valid = false;                             // Tracks if the fraction is valid
    char sep;                                       // Stub for the fraction separator
    std::cin >> numerator >> sep >> denominator;

    // Checks if the input was in the right fraction format
    if (std::cin.good() && sep == '/' && !std::cin.eof() && denominator != 0) { // Valid fraction
        valid = true; 
    } else {                                                                    // Invalid fraction
        numerator = 0;
        denominator = 0;
    }

    // Claring the buffer
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    return valid;
}



/**
 * @brief Reduces the fraction as much as possible
 * 
 * @param numerator int
 * @param denominator int
 */
void reduceFraction(int &numerator, int &denominator) {
    if (!(numerator == 0 && denominator == 0)) {
        int gcd = getGcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
}


/**
 * @brief Adds 2 fractions
 * 
 * @param num1 fraction 1 num
 * @param den1 fraction 1 den
 * @param num2 fraction 2 num
 * @param den2 fraction 2 den
 * @param resNum result numerator
 * @param resDen result denominator
 */
void addFrac(const int num1, const int den1, const int num2, const int den2, int &resNum, int &resDen) {
    if (num1 == 0 && den1 == 0) { resNum = num2; resDen = den2; }
    if (num2 == 0 && den2 == 0) { resNum = num1; resDen = den1; }
    if (den1 == den2) {
        resNum = num1 + num2;
        resDen = den1;
    } else {
        resNum = (num1 * den2) + (num2 * den1);
        resDen = den1 * den2;
    }
    return reduceFraction(resNum, resDen);
}


/**
 * @brief Subtracts 2 fractions
 * 
 * @param num1 fraction 1 num
 * @param den1 fraction 1 den
 * @param num2 fraction 2 num
 * @param den2 fraction 2 den
 * @param resNum result numerator
 * @param resDen result denominator
 */
void subFrac(const int num1, const int den1, const int num2, const int den2, int &resNum, int &resDen) {
    if (num1 == 0 && den1 == 0) { resNum = -num2; resDen = den2; }
    if (num2 == 0 && den2 == 0) { resNum = -num1; resDen = den1; }
    if (den1 == den2) {
        resNum = num1 - num2;
        resDen = den1;
    } else {
        resNum = (num1 * den2) - (num2 * den1);
        resDen = den1 * den2;
    }
    return reduceFraction(resNum, resDen);
}


/**
 * @brief Multiplies 2 fractions
 * 
 * @param num1 fraction 1 num
 * @param den1 fraction 1 den
 * @param num2 fraction 2 num
 * @param den2 fraction 2 den
 * @param resNum result numerator
 * @param resDen result denominator
 */
void multFrac(const int num1, const int den1, const int num2, const int den2, int &resNum, int &resDen) {
    resNum = num1 * num2;
    resDen = den1 * den2;
    return reduceFraction(resNum, resDen);
}


/**
 * @brief Divides 2 fractions
 * 
 * @param num1 fraction 1 num 
 * @param den1 fraction 1 den
 * @param num2 fraction 2 num
 * @param den2 fraction 2 den
 * @param resNum result numerator
 * @param resDen result denominator
 * 
 * @note Res = fraction_1 / fraction2
 */
void divFrac(const int num1, const int den1, const int num2, const int den2, int &resNum, int &resDen) {
    resNum = num1 * den2;
    resDen = den1 * num2;
    return reduceFraction(resNum, resDen);
}


void displayFrac(int num, int den) {
    std::cout << num << "/" << den;
}


int main() {
	int num1, den1, num2, den2, resNum, resDen;
	char sep = '/', operation;

    std::cout << "Enter a fraction: " << std::endl;
    readFraction(num1, den1);

    std::cout << "Enter a fraction: " << std::endl;
    readFraction(num2, den2);

	std::cout << "Enter an operation ['+', '-', '*', '/']: " << std::endl;
    std::cin >> operation;

    if (!std::cin.good() || std::cin.eof()) { 
        std::cerr << "Invalid operation!\n"; 
        return -1;
    }

	
	if (operation == '+') {                                             // Addition
		addFrac(num1, den1, num2, den2, resNum, resDen);
        std::cout << num1 << "/" << den1 
                  << operation << num2 << "/" << den2 << " = " 
                  << resNum << "/" << resDen << std::endl;
	} else if (operation == '-') {                                      // Subtraction
		subFrac(num1, den1, num2, den2, resNum, resDen);
        std::cout << num1 << "/" << den1 
                  << operation << num2 << "/" << den2 << " = " 
                  << resNum << "/" << resDen << std::endl;
	} else if (operation == '*') {                                      // Multiplication
		multFrac(num1, den1, num2, den2, resNum, resDen);
        std::cout << num1 << "/" << den1 
                  << operation << num2 << "/" << den2 << " = " 
                  << resNum << "/" << resDen << std::endl;
	} else if (operation == '/') {                                      // Division 
		divFrac(num1, den1, num2, den2, resNum, resDen);
        std::cout << num1 << "/" << den1                
                  << operation << num2 << "/" << den2 << " = " 
                  << resNum << "/" << resDen << std::endl;
	} else {                                                            // Invalid operation
		std::cerr << "Invalid operation!\n";
        return -1;
	}
    return 0;
}