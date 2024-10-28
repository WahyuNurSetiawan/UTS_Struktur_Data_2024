#include <iostream>
#include <stack>
#include <string>
#include <cmath>

class Stack {
public:
    void push(float value) {
        st.push(value);
    }

    float pop() {
        if (st.empty()) {
            std::cerr << "Error: Stack kosong!\n";
            return 0;
        }
        float value = st.top();
        st.pop();
        return value;
    }

    bool isEmpty() const {
        return st.empty();
    }

private:
    std::stack<float> st;
};

// Fungsi untuk mengevaluasi ekspresi postfix
float evaluatePostfix(const std::string &expression) {
    Stack stack;

    for (size_t i = 0; i < expression.size(); i++) {
        char token = expression[i];

        // Lewati spasi
        if (token == ' ') {
            continue;
        }

        // Jika token adalah angka, lakukan push ke stack
        if (isdigit(token)) {
            float number = token - '0';
            stack.push(number);
            std::cout << "Push: " << number << '\n';
        }
        // Jika token adalah operator, pop dua elemen untuk operasi
        else {
            float operand2 = stack.pop();
            float operand1 = stack.pop();
            float result;

            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = std::pow(operand1, operand2);
                    break;
                default:
                    std::cerr << "Operator tidak valid: " << token << '\n';
                    return 0;
            }

            stack.push(result);
            std::cout << "Operasi: " << operand1 << " " << token << " " << operand2 << " = " << result << '\n';
        }
    }

    // Hasil akhir ada di puncak stack
    return stack.pop();
}

int main() {
    std::string expression;
    std::cout << "Masukkan ekspresi postfix (misal: 5 3 + 8 2 - *): ";
    std::getline(std::cin, expression);

    float result = evaluatePostfix(expression);
    std::cout << "Hasil akhir: " << result << '\n';

    return 0;
}
