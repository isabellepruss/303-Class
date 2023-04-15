#include"header.h"

using namespace std;

//constructor
InfixConvert::InfixConvert(string userExp) {

	expression = userExp; // assign expression data field to the expression entered by user

}

//checks for balanced parenthesis
bool InfixConvert::checkParen() {

	for (int i = 0; i < expression.size(); i++) {

		//push any open parenthesis to the stack
		if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{')) {
			parenthesis.push(expression[i]);

		}

		//if there is a closed parenthesis
		else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {

			if (parenthesis.empty()) { //if stack is empty, there are no opening parenthesis and expression is unbalanced

				return false;
			}

			else if ((expression[i] == ')' && parenthesis.top() == '(') || (expression[i] == ']' && parenthesis.top() == '[') || (expression[i] == '}' && parenthesis.top() == '{')) {
				//if the top character on the stack is the opening parenthesis to the closing, they match, keep iterating
				parenthesis.pop();

			}

			else {
				return false;
			}


		}


	}
	return parenthesis.empty(); // if stack is empty, every parenthesis matches, so it'll return true.

}

//converts the infix expression to postfix form
string InfixConvert::convertToPostfix() {


	
	for (char token : expression) {

		if (isdigit(token)) {

			postfix += token; //if token is a digit, append to postfix

		}

		if ((token == '+') || (token == '-') || (token == '*') || (token == '/') || (token == '%')) {

			char op = token;
			processOperator(op); //if token is an operator, process the operator
		}

		if ((token == '(') || (token == '[') || (token == '{')) {

			operators.push(token); //if token is an open parenthesis, push to operators stacak

		}

		if ((token == ')') || (token == ']') || (token == '}')) {

			//while the operators stack is not empty...
			while (!operators.empty()) {

				//if top element of stack is a closing parenthesis, break the while loop
				if ((operators.top() == '(') || (operators.top() == '[') || (operators.top() == '{')) {

					break;
				}

				else {
					postfix += operators.top(); //append operator to postfix
					operators.pop(); //pop operator from stack

				}
				

			}

			operators.pop(); // pop closing parenthesis from stack;

		}

	}

	//now the entire infix expression has been iterated through, so now the operators stack needs to be processed
	//so while it still has elements in it...
	while (!operators.empty()) {
		
		postfix += operators.top(); //append them to the postfix expression
		operators.pop(); //and pop from stack
	}

	return postfix; //return postfix expression
}

//determines what to do with an operator coming from the infix expression
void InfixConvert::processOperator(char op) {

	//if operators stack is empty, push operator to it
	if (operators.empty()) {
		operators.push(op);
	}

	//if not...
	else {

		//get operator from top of stack and its precedence
		char topOp = operators.top();
		int topPrecedence = getPrecedence(topOp);

		//get precedence of current operator
		int currentPrecedence = getPrecedence(op);

		//if the current operator has higher precedence, push it to the stack
		if (currentPrecedence > topPrecedence) {

			operators.push(op);
		}


		else {

			//while the current operator has lower or equal precedence to the top operator and stack isn't empty,
			while (currentPrecedence <= topPrecedence && operators.empty() == false) {

				postfix.push_back(topOp); //append operators from stack into postfix expression
				operators.pop();

			}

			operators.push(op); //then push the current operator to the operators stack


		}


	}

}

//determines precedence of the operators
int InfixConvert::getPrecedence(char op) {


	if (op == '*' || op == '/' || op == '%') {
		return 2;
	}

	else if (op == '+' || op == '-') {
		return 1;
	}

	else {
		return 0;
	}

}

