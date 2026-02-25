#include <iostream>

/**
 * Performs basic arithmetic operations.
 * Declared as constexpr to allow compile-time evaluation if arguments are constant.
 * Note: Cannot contain std::cout because I/O is not allowed in constexpr functions.
 */
constexpr int calculate(int num1, int num2, char symbol)
{
    switch (symbol)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        // Basic protection against division by zero
        return (num2 != 0) ? num1 / num2 : 0;
    case '%':
        return num1 % num2;
    default:
        // Returns 0 for invalid symbols (error handling)
        return 0;
    }
}

int main()
{
    // Initialize variables with uniform initialization
    int num1{};
    int num2{};
    char aritmeticSymbol{};

    // Prompt user for input data
    std::cout << "Enter your first integer: ";
    std::cin >> num1;
    std::cout << "Enter your second integer: ";
    std::cin >> num2;
    std::cout << "Enter the operation (+, -, *, /, %): ";
    std::cin >> aritmeticSymbol;

    // Call the calculation function
    // Since input comes from std::cin, this executes at runtime
    int result{calculate(num1, num2, aritmeticSymbol)};

    // Output the formatted result to the console
    std::cout << "The operation of " << num1 << ' ' << aritmeticSymbol << ' ' << num2 << " = " << result << '\n';

    return 0;
}
