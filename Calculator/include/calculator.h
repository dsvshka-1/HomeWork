#ifndef CALCULATOR_H
#define CALCULATOR_H

class calculator
{
    typedef char symbol;

    static constexpr symbol space = static_cast<symbol>(' ');
    static constexpr symbol min_digit = static_cast<symbol>('0');
    static constexpr symbol max_digit = static_cast<symbol>('9');
    static constexpr symbol plus = static_cast<symbol>('+');
    static constexpr symbol minus = static_cast<symbol>('-');
    static constexpr symbol multiply = static_cast<symbol>('*');
    static constexpr symbol divide = static_cast<symbol>('/');
    static constexpr symbol left_bracket = static_cast<symbol>('(');
    static constexpr symbol right_bracket = static_cast<symbol>(')');

    enum class operators{null, plus, multiply, divide};
    enum class brackets{null, left, right};

    operators cur_operator;
    brackets cur_bracket;

    const symbol* expression;
    const symbol* cursor;

    int sign;
    unsigned int n_left_brackets;
    bool isError, isEOF;

    calculator(const symbol* expr);
    void get_operator();
    double get_number();
    void evaluate(double& left_number);

public:

    static double calculate(const symbol* expr);

};

#endif // CALCULATOR_H
