#include"Functions.hpp"



int main() {
    std::string infix;
    std::cout << "Enter Infix: ";
    std::cin >> infix;

    if (!balancedParen(infix)) {
        std::cout << "There is something wrong with the inputted Parentheses\n";
    }
    else {
        std::cout << "Postfix: " << postfix(infix) << std::endl;
    }
    return 0;
}
