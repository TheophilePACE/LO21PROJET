#include "shunting_yard_algorithm.h"
/*
const int LEFT_ASSOC  = 0;
const int RIGHT_ASSOC = 1;

// Map the different operators: +, -, *, / etc
typedef std::map< std::string, std::pair< int,int > > OpMap;
typedef std::vector<std::string>::const_iterator cv_iter;
typedef std::string::iterator s_iter;

const OpMap::value_type assocs[] =
    {  OpMap::value_type( "+", std::make_pair<int,int>( 0, LEFT_ASSOC ) ),
       OpMap::value_type( "-", std::make_pair<int,int>( 0, LEFT_ASSOC ) ),
       OpMap::value_type( "*", std::make_pair<int,int>( 5, LEFT_ASSOC ) ),
       OpMap::value_type( "/", std::make_pair<int,int>( 5, LEFT_ASSOC ) ) };

const OpMap opmap( assocs, assocs + sizeof( assocs ) / sizeof( assocs[ 0 ] ) );

// Test if token is an pathensesis
bool isParenthesis( const std::string& token)
{
    return token == "(" || token == ")";
}

// Test if token is an operator
bool isOperator( const std::string& token)
{
    return token == "+" || token == "-" ||
           token == "*" || token == "/";
}

// Test associativity of operator token
bool isAssociative( const std::string& token, const int& type)
{
    const std::pair<int,int> p = opmap.find( token )->second;
    return p.second == type;
}

// Compare precedence of operators.
int cmpPrecedence( const std::string& token1, const std::string& token2 )
{
    const std::pair<int,int> p1 = opmap.find( token1 )->second;
    const std::pair<int,int> p2 = opmap.find( token2 )->second;

    return p1.first - p2.first;
}

// Convert infix expression format into reverse Polish notation
bool infixToRPN( const std::vector<std::string>& inputTokens,
                 const int& size,
                 std::vector<std::string>& strArray )
{
    bool success = true;

    std::list<std::string> out;
    std::stack<std::string> stack;

    // While there are tokens to be read
    for ( int i = 0; i < size; i++ )
    {
        // Read the token
        const std::string token = inputTokens[ i ];

        // If token is an operator
        if ( isOperator( token ) )
        {
            // While there is an operator token, o2, at the top of the stack AND
            // either o1 is left-associative AND its precedence is equal to that of o2,
            // OR o1 has precedence less than that of o2,
            const std::string o1 = token;

            if ( !stack.empty() )
            {
                std::string o2 = stack.top();

                while ( isOperator( o2 ) &&
                        ( ( isAssociative( o1, LEFT_ASSOC ) &&  cmpPrecedence( o1, o2 ) == 0 ) ||
                        ( cmpPrecedence( o1, o2 ) < 0 ) ) )
                {
                    // pop o2 off the stack, onto the output queue;
                    stack.pop();
                    out.push_back( o2 );

                    if ( !stack.empty() )
                        o2 = stack.top();
                    else
                        break;
                }
            }

            // push o1 onto the stack.
            stack.push( o1 );
        }
        // If the token is a left parenthesis, then push it onto the stack.
        else if ( token == "(" )
        {
            // Push token to top of the stack
            stack.push( token );
        }
        // If token is a right bracket ')'
        else if ( token == ")" )
        {
            // Until the token at the top of the stack is a left parenthesis,
            // pop operators off the stack onto the output queue.
            std::string topToken  = stack.top();

            while ( topToken != "(" )
            {
                out.push_back(topToken );
                stack.pop();

                if ( stack.empty() ) break;
                topToken = stack.top();
            }

            // Pop the left parenthesis from the stack, but not onto the output queue.
            if ( !stack.empty() ) stack.pop();

            // If the stack runs out without finding a left parenthesis,
            // then there are mismatched parentheses.
            if ( topToken != "(" )
            {
                return false;
            }
        }
        // If the token is a number, then add it to the output queue.
        else
        {
            out.push_back( token );
        }
    }

    // While there are still operator tokens in the stack:
    while ( !stack.empty() )
    {
        const std::string stackToken = stack.top();

        // If the operator token on the top of the stack is a parenthesis,
        // then there are mismatched parentheses.
        if ( isParenthesis( stackToken )   )
        {
            return false;
        }

        // Pop the operator onto the output queue./
        out.push_back( stackToken );
        stack.pop();
    }

    strArray.assign( out.begin(), out.end() );

    return success;
}
*/
