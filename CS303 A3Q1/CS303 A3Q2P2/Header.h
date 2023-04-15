#pragma once
#include<string>
#include<stack>

using namespace std;

class InfixConvert {

private:
	string expression; //infix expression to be converted
	string postfix; //postfix form initialized to empty string
	stack<char> parenthesis; //for chekcking balance of parenthesis
	stack<char> operators; //stack of operators/parenthesis in expression when converting to postfix


public:

	InfixConvert(string userExp); //constructor
	bool checkParen(); //checks for balanced parenthesis
	string convertToPostfix(); //converts infix expression to postfix
	void processOperator(char op); //determines what to do operator from infix expression
	int getPrecedence(char op); //determines precedence of operators


};
