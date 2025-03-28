#include <iostream>
using namespace std;

class Polynomial {
private:
    int *coeffs;
    int degree;

public:
    Polynomial(int deg) {
        degree = deg;
        coeffs = new int[degree + 1](); // Initialize to 0
    }

    ~Polynomial() {
        delete[] coeffs;
    }

    void setCoefficient(int power, int coefficient) {
        if (power <= degree) {
            coeffs[power] = coefficient;
        }
    }

    void display() {
        bool first = true;
        for (int i = degree; i >= 0; i--) {
            if (coeffs[i] != 0) {
                if (!first) cout << " + ";
                cout << coeffs[i] << "x^" << i;
                first = false;
            }
        }
        if (first) cout << "0"; // In case all coefficients are 0
        cout << endl;
    }

    Polynomial multiply(const Polynomial &other) {
        Polynomial result(degree + other.degree);
        
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                result.coeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return result;
    }
};

int main() {
    Polynomial p1(2), p2(2);
    
    p1.setCoefficient(0, 1);
    p1.setCoefficient(1, 2);
    p1.setCoefficient(2, 3);
    
    p2.setCoefficient(0, 4);
    p2.setCoefficient(1, 5);
    p2.setCoefficient(2, 6);
    
    cout << "Polynomial 1: ";
    p1.display();
    cout << "Polynomial 2: ";
    p2.display();
    
    Polynomial result = p1.multiply(p2);
    cout << "Result of Multiplication: ";
    result.display();
    
    return 0;
}
