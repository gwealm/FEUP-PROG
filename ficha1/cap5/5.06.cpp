#include <iostream>
#include <cmath>


// Struct definition

struct Fraction {
    int numerator;
    int denominator;
};


int getGcd(int n1, int n2);
bool readFraction(Fraction &fraction);
void reduceFraction(Fraction &fract);
void addFrac(const Fraction &frac1, const Fraction &frac2, Fraction &resFrac);
void subFrac(const Fraction &frac1, const Fraction &frac2, Fraction &resFrac);
void multFrac(const Fraction &frac1, const Fraction &frac2, Fraction &resFrac);
void divFrac(const Fraction &numFrac, const Fraction &denFrac, Fraction &resFrac);
void displayFrac(const Fraction &frac);


int main() {
	Fraction frac1, frac2, resFrac;
	char sep = '/', operation;

    std::cout << "Enter a fraction: " << std::endl;
    readFraction(frac1);

    std::cout << "Enter a fraction: " << std::endl;
    readFraction(frac2);

	std::cout << "Enter an operation ['+', '-', '*', '/']: " << std::endl;
    std::cin >> operation;

    if (!std::cin.good() || std::cin.eof()) { 
        std::cerr << "Invalid operation!\n"; 
        return -1;
    }

	
	if (operation == '+') {                                             // Addition
		addFrac(frac1, frac2, resFrac);
        std::cout << frac1.numerator << "/" << frac1.denominator 
                  << operation << frac2.numerator << "/" << frac2.denominator << " = " 
                  << resFrac.numerator << "/" << resFrac.denominator << std::endl;
	} else if (operation == '-') {                                      // Subtraction
		subFrac(frac1, frac2, resFrac);
        std::cout << frac1.numerator << "/" << frac1.denominator 
                  << operation << frac2.numerator << "/" << frac2.denominator << " = " 
                  << resFrac.numerator << "/" << resFrac.denominator << std::endl;
	} else if (operation == '*') {                                      // Multiplication
		multFrac(frac1, frac2, resFrac);
        std::cout << frac1.numerator << "/" << frac1.denominator 
                  << operation << frac2.numerator << "/" << frac2.denominator << " = " 
                  << resFrac.numerator << "/" << resFrac.denominator << std::endl;

	} else if (operation == '/') {                                      // Division 
		divFrac(frac1, frac2, resFrac);
        std::cout << frac1.numerator << "/" << frac1.denominator 
                  << operation << frac2.numerator << "/" << frac2.denominator << " = " 
                  << resFrac.numerator << "/" << resFrac.denominator << std::endl;
	} else {                                                            // Invalid operation
		std::cerr << "Invalid operation!\n";
        return -1;
	}
    return 0;
}

/**
 * @brief Calculates the greatest common divisor of 2 integers
 * 
 * @param n1 int 
 * @param n2 int
 * @return int 
 */
int getGcd(int n1, int n2) {
    if( n1 == 0) { return n2; }
    if (n2 == 0) { return n1; }

    n1 = abs(n1);
    n2 = abs(n2);
    if(n1 > n2) { return getGcd(n2, n1); }
    return getGcd(n2 % n1, n1);
}


/**
 * @brief Reads a fraction and returns its validity
 * 
 * @param fract fraction 
 * @return true 
 * @return false 
 */
bool readFraction(Fraction &fract) {
    bool valid = false;                             // Tracks if the fraction is valid
    char sep;                                       // Stub for the fraction separator
    std::cin >> fract.numerator >> sep >> fract.denominator;
    // Checks if the input was in the right fraction format
    if (std::cin.good() && sep == '/' && !std::cin.eof() && fract.denominator != 0) { // Valid fraction
        valid = true; 
    } else {                                                                    // Invalid fraction
        fract.numerator = 0;
        fract.denominator = 0;
    }

    // Claring the buffer
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    return valid;
}



/**
 * @brief Reduces the fraction as much as possible
 * 
 * @param fract fraction 
 */
void reduceFraction(Fraction &fract) {

    if (!(fract.numerator == 0 && fract.denominator == 0)) {
        int gcd = getGcd(fract.numerator, fract.denominator);
        fract.numerator /= gcd;
        fract.denominator /= gcd;
    } else if (fract.numerator == 0) {
        fract.numerator = 0;
        fract.denominator = 0;
    }
}


/**
 * @brief Adds 2 fractions
 * 
 * @param frac1 result denominator
 * @param frac2 result denominator
 * @param resFrac result denominator
 */
void addFrac( const Fraction &frac1, const Fraction &frac2, Fraction &resFrac) {
    if (frac1.numerator == 0 && frac1.denominator == 0) { 
        resFrac.numerator = frac2.numerator; resFrac.denominator = frac2.denominator; 
    } else if (frac2.numerator == 0 && frac2.denominator == 0) { 
        resFrac.numerator = frac1.numerator; resFrac.denominator = frac1.denominator; 
    } else if (frac1.denominator == frac2.denominator) {
        resFrac.numerator = frac1.numerator + frac2.numerator;
        resFrac.denominator = frac1.denominator;
    } else {
        resFrac.numerator = (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
        resFrac.denominator = frac1.denominator * frac2.denominator;
    }
    return reduceFraction(resFrac);
}


/**
 * @brief Subtracts 2 fractions
 * 
 * @param frac1 result denominator
 * @param frac2 result denominator
 * @param resFrac result denominator
 */
void subFrac(const Fraction &frac1, const Fraction &frac2, Fraction &resFrac) {
    if (frac1.numerator == 0 && frac1.denominator == 0) { 
        resFrac.numerator = -frac2.numerator; 
        resFrac.denominator = frac2.denominator; 
    } else if (frac2.numerator == 0 && frac2.denominator == 0) { 
        resFrac.numerator = frac1.numerator; 
        resFrac.denominator = frac1.denominator; 
    } else if (frac1.denominator == frac2.denominator) {
        resFrac.numerator = frac1.numerator - frac2.numerator;
        resFrac.denominator = frac1.denominator;
    } else {
        resFrac.numerator = (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
        resFrac.denominator = frac1.denominator * frac2.denominator;
    }

    std::cout << resFrac.numerator << " / " << resFrac.denominator << std::endl;
    return reduceFraction(resFrac);
}


/**
 * @brief Multiplies 2 fractions
 * 
 * @param frac1 fraction 1
 * @param frac2 fraction 2
 * @param resFrac result fraction
 */
void multFrac(const Fraction &frac1, const Fraction &frac2, Fraction &resFrac) {
    resFrac.numerator = frac1.numerator * frac2.numerator;
    resFrac.denominator = frac1.denominator * frac2.denominator;
    return reduceFraction(resFrac);
}


/**
 * @brief Divides 2 fractions
 * 
 * @param numFrac result denominator
 * @param denFrac denominator
 * @param resFrac result denominator
 * 
 * @note Res = fraction_1 / fraction2
 */
void divFrac(const Fraction &numFrac, const Fraction &denFrac, Fraction &resFrac) {
    resFrac.numerator = numFrac.numerator * denFrac.denominator;
    resFrac.denominator = numFrac.denominator * denFrac.numerator;
    return reduceFraction(resFrac);
}


void displayFrac(const Fraction &frac) {
    std::cout << frac.numerator << "/" << frac.denominator;
}