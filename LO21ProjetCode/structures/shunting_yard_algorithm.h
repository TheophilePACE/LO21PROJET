#ifndef SHUNTING_YARD_ALGORITHM_H
#define SHUNTING_YARD_ALGORITHM_H

#include <iostream>
#include <sstream>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <utility>
#include <stdlib.h>
//#include "parser.h"

/*! \name      Les algorithmes suivants viennent du site Technical recipes, publié par Andy :
 *http://www.technical-recipes.com/2011/a-mathematical-expression-parser-in-java-and-cpp/
* Ils permettent d'interpréter des chaine en Reverse Polish Notation.
*/
bool isParenthesis(const std::string& token);
bool isOperator( const std::string& token);
bool isAssociative( const std::string& token, const int& type);
int cmpPrecedence( const std::string& token1, const std::string& token2 );
bool infixToRPN( const std::vector<std::string>& inputTokens,
                 const int& size,
                 std::vector<std::string>& strArray );

#endif // SHUNTING_YARD_ALGORITHM_H
