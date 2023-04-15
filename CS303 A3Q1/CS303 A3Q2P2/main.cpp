#include<iostream>
#include<string>
#include "header.h"

using namespace std;

int main() {

	//variables
	string userExpression;
	bool balanced;
	string postfixForm;


	cout << "Please enter the expression you want to convert to postfix : ";
	cin >> userExpression;
	cout << endl;

	InfixConvert infixExpression(userExpression); //create class object using expression entered by user

	cout << "checking for balanced parenthesis..." << endl;
	balanced = infixExpression.checkParen(); //check for balanced parenthesis
	if (balanced == true) {
		cout << "This expression has balanced parenthesis" << endl << endl;

		postfixForm = infixExpression.convertToPostfix();
		cout << "The postfix form of your expression is " << postfixForm << endl;
	}

	else { //output that parenthesis are unbalanced and program ends
		cout << "This expression is unbalanced, and thus cannot be converted to postfix.";
	}

	//convert expression to postfix
	









	return 0;
}