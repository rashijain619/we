#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex() : real(0.0), imaginary(0.0) {}

    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    friend std::ostream& operator<<(std::ostream& os, const Complex& complexNumber) {
        os << complexNumber.real << " + " << complexNumber.imaginary << "i";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& complexNumber) {
        std::cout << "Enter real part: ";
        is >> complexNumber.real;

        std::cout << "Enter imaginary part: ";
        is >> complexNumber.imaginary;

        return is;
    }
};

int main() {
    Complex complex1, complex2;

    // Input for complex1
    std::cout << "Enter values for Complex Number 1:\n";
    std::cin >> complex1;

    // Input for complex2
    std::cout << "\nEnter values for Complex Number 2:\n";
    std::cin >> complex2;

    // Output complex numbers
    std::cout << "\nComplex Number 1: " << complex1 << std::endl;
    std::cout << "Complex Number 2: " << complex2 << std::endl;

    return 0;
}
