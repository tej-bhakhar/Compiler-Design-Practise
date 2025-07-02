#include <iostream>
#include <string>
#include <stack>

using namespace std;

string generateTempVar() {
    static int tempCount = 0;
    return "t" + to_string(tempCount++);
}

string generateLabel() {
    static int labelCount = 0;
    return "L" + to_string(labelCount++);
}

string generateThreeAddressCode(const string& op, const string& arg1, const string& arg2, const string& result) {
    return result + " = " + arg1 + " " + op + " " + arg2;
}

string generateBooleanExpression(const string& expression) {
    stack<string> operands;
    stack<char> operators;

    for (char ch : expression) {
        if (ch == '(') {
            operators.push(ch);
        } else if (ch == '0' || ch == '1') {
            operands.push(string(1, ch));
        } else if (ch == '&' || ch == '|') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                string tempVar = generateTempVar();
                string code = generateThreeAddressCode(string(1, op), operand1, operand2, tempVar);
                cout << code << endl;

                operands.push(tempVar);
            }
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                string tempVar = generateTempVar();
                string code = generateThreeAddressCode(string(1, op), operand1, operand2, tempVar);
                cout << code << endl;

                operands.push(tempVar);
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();

        string tempVar = generateTempVar();
        string code = generateThreeAddressCode(string(1, op), operand1, operand2, tempVar);
        cout << code << endl;

        operands.push(tempVar);
    }

    return operands.top();
}

string generateArithmeticExpression(const string& expression) {
    stack<string> operands;
    stack<char> operators;

    for (char ch : expression) {
        if (ch == '(') {
            operators.push(ch);
        } else if (isdigit(ch)) {
            operands.push(string(1, ch));
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                string tempVar = generateTempVar();
                string code = generateThreeAddressCode(string(1, op), operand1, operand2, tempVar);
                cout << code << endl;

                operands.push(tempVar);
            }
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                string tempVar = generateTempVar();
                string code = generateThreeAddressCode(string(1, op), operand1, operand2, tempVar);
                cout << code << endl;

                operands.push(tempVar);
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();

        string tempVar = generateTempVar();
        string code = generateThreeAddressCode(string(1, op), operand1, operand2, tempVar);
        cout << code << endl;

        operands.push(tempVar);
    }

    return operands.top();
}

int main() {
    string booleanExpression;
    cout<<"Enter the boolean expression: "<<endl;
    cin>>booleanExpression;
    string booleanResult = generateBooleanExpression(booleanExpression);
    cout << "Boolean Result: " << booleanResult << endl;

    string arithmeticExpression;
    cout<<"Enter the Arithmetic Expresion: "<<endl;
    cin>>arithmeticExpression;
    string arithmeticResult = generateArithmeticExpression(arithmeticExpression);
    cout << "Arithmetic Result: " << arithmeticResult << endl;
}