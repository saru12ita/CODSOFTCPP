#include <stdio.h>

template <class T>
class Calculator {
private:
    T num1, num2;

public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void displayResult() {
        printf("Numbers are: %lf and %lf.\n", num1, num2);
        printf("Addition is: %lf\n", add());
        printf("Subtraction is: %lf\n", subtract());
        printf("Product is: %lf\n", multiply());
        printf("Division is: %lf\n", divide());
    }

    T add() { return num1 + num2; }

    T subtract() { return num1 - num2; }

    T multiply() { return num1 * num2; }

    T divide() { return num1 / num2; }
};

int main() {
    double n1, n2;

    printf("Enter two numbers for integer calculation: ");
    scanf("%lf %lf", &n1, &n2);
    Calculator<double> intCalc(n1, n2);

    printf("\nInt results:\n");
    intCalc.displayResult();

    printf("\n");

    printf("Enter two numbers for floating-point calculation: ");
    scanf("%lf %lf", &n1, &n2);
    Calculator<double> floatCalc(n1, n2);

    printf("\nFloat results:\n");
    floatCalc.displayResult();

    return 0;
}
