#include <stack>
#include <string>
#include <unordered_map>


int calculate(const std::string& s) {
    typedef enum {
        END,
        VALUE,
        OPERATOR
    } TokenType;

    typedef union {
        int value;
        char oper;
    } Token;

    // We set ')' and '(' to have lowest priority. If '(' has the lowest
    // priority, new operators will be appended, and only ')' can consume it.
    const std::unordered_map<char, int> PRIORITIES {
        // unary +/-
        {'p', 5},
        {'m', 5},
        {'*', 10},
        {'/', 10},
        {'-', 30},
        {'+', 30},
        {')', 999},
        {'(', 999}
    };

    const int LEN = s.length();
    int stringIter = 0;
    auto fetchToken = [&s, &LEN, &stringIter](const std::pair<Token, TokenType>& lastToken) -> std::pair<Token, TokenType> {
        while(stringIter < LEN && s[stringIter] == ' ') ++stringIter;
        if (stringIter == LEN) return std::make_pair(Token{0}, END);

        char v = s[stringIter];
        if ('0' <= v && v <= '9') {
            long value = 0;
            do {
                value = value * 10 - '0' + v;
                v = s[++stringIter];
            } while(stringIter < LEN && '0' <= v && v <= '9');
            return std::make_pair(Token{static_cast<int>(value)}, VALUE);
        }

        ++stringIter;

        if (v == '+' && lastToken.second != VALUE && lastToken.first.oper != ')') {
            return std::make_pair(Token{'p'}, OPERATOR);
        }
        if (v == '-' && lastToken.second != VALUE && lastToken.first.oper != ')') {
            return std::make_pair(Token{'m'}, OPERATOR);
        }
        return std::make_pair(Token{v}, OPERATOR);
    };

    std::stack<int> operands;
    std::stack<char> operators;
    auto evaluateUntil = [&PRIORITIES, &operands, &operators](char op) {
        if (op == '(') {
            operators.push(op);
            return;
        }
        auto priority = PRIORITIES.at(op);
        while(PRIORITIES.at(operators.top()) <= priority) {
            if (operators.top() == '(' && op == ')') {
                operators.pop();
                return;
            } else {
                if (operators.top() == 'p' || operators.top() == 'm') {
                    if (operators.top() == 'm') {
                        operands.top() *= -1;
                    }
                } else {
                    long op2 = operands.top();
                    operands.pop();
                    long op1 = operands.top();
                    operands.pop();

                    long result;

                    switch(operators.top()) {
                        case '+':
                            result = op1 + op2;
                            break;
                        case '-':
                            result = op1 - op2;
                            break;
                        case '*':
                            result = op1 * op2;
                            break;
                        case '/':
                            result = op1 / op2;
                            break;
                    }

                    operands.push(result);
                }
                operators.pop();
            }
        }
        operators.push(op);
    };

    operators.push('(');
    auto token = fetchToken(std::make_pair(Token{'\0'}, END));
    while (token.second != END) {
        if (token.second == VALUE) {
            operands.push(token.first.value);
        } else {
            evaluateUntil(token.first.oper);
        }
        token = fetchToken(token);
    }
    evaluateUntil(')');

    return operands.top();
}

#include <stdio.h>
int main() {
    //printf("%d\n", calculate("1 + 1"));
    //printf("%d\n", calculate("6 - 4 / 2"));
    //printf("%d\n", calculate("2*(5+5*2)/3+(6/2+8)"));
    //printf("%d\n", calculate("(2+6* 3+5- (3*14/7+2)*5)+3"));
    //printf("%d\n", calculate("-1+4*3/3/3"));
    printf("%d\n", calculate("2147483647"));
}
