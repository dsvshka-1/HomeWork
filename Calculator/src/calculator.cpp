#include "calculator.h"
#include <iostream>

calculator::calculator(const symbol* expr):
    cur_operator(operators::null), cur_bracket(brackets::null),
    expression(expr), cursor(expression),
    sign(1), n_left_brackets(0),
    isError(false), isEOF(false) { }

void calculator::get_operator(){
    if( isError || isEOF ) return;
    cur_operator = operators::null;
    cur_bracket = brackets::null;
    sign = 1;
    while(1){
        while(*cursor == space) ++cursor;
        switch(*cursor){
            case plus:
                if( cur_operator == operators::null ) cur_operator = operators::plus;
                break;

            case minus:
                if( cur_operator == operators::null ) cur_operator = operators::plus;
                sign*= -1;
                break;

            case multiply:
                if( cur_operator == operators::null ) cur_operator = operators::multiply;
                else{ isError = true; return; }
                break;

            case divide:
                if( cur_operator == operators::null) cur_operator = operators::divide;
                else{ isError = true; return; }
                break;

            case left_bracket:
                cur_bracket = brackets::left;
                ++n_left_brackets;
                ++cursor;
                return;

            case right_bracket:
                if( cur_operator != operators::null ){ isError = true; return; }
                if( n_left_brackets == 0){ isError = true; return; }
                else --n_left_brackets;
                cur_bracket = brackets::right;
                ++cursor;
                return;

            case 0:
                if( cur_operator != operators::null ){ isError = true; }
                if( n_left_brackets > 0){ isError = true; }
                isEOF = true;
                return;

            default:
                if( !(min_digit <= *cursor && *cursor <= max_digit) ){isError = true;}
                return;
        }
        ++cursor;
    }
}

double calculator::get_number(){
    double res = 0;
    while (min_digit <= *cursor && *cursor <= max_digit){
        res*= 10;
        res+= *cursor - min_digit;
        ++cursor;
    }
    return res;
}

void calculator::evaluate(double& left_number){
    get_operator();
    if( isError || isEOF ) return;

    double right_number = get_number();

    auto sgn = sign;
    auto op = cur_operator;

    switch(cur_bracket){
        case brackets::left: evaluate(right_number); break;
        case brackets::right: return;
        case brackets::null: break;
    }

    right_number*= sgn;
    switch(op){
        case operators::plus:
            //std::cout << "number: " << left_number << std::endl;
            //std::cout << "number: " << right_number << std::endl;
            evaluate(right_number);
            left_number+= right_number;
            break;
        case operators::multiply:
            left_number*= right_number;
            evaluate(left_number);
            break;
        case operators::divide:
            left_number/= right_number;
            evaluate(left_number);
            break;
        default:
            left_number = right_number;
            evaluate(left_number);
            break;
    }
}

double calculator::calculate(const symbol* expr)
{
    double res = 0;
    calculator calc(expr);
    calc.evaluate(res);
    return res;
}
