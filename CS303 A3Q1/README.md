 

This program converts an infix expression inputted by the user to a postfix by a ConvertInfix class. The program begins with prompting the user for the expression they would like to convert to postfix form, and passing that string to the constructor of the class to be initialized as a private data member to be processed in functions. 


The program then sends that class object to the checkParen() function to make sure the any parenthesis in the expression are balanced.  

It does this by iterating through the infix expression and pushing any open parenthesis to the parenthesis stack. If a closing parenthesis is encountered,  it checks if the top of the stack has the matching one. If yes, it keeps going, but if not the expression is unbalanced. The function returns a boolean to indicate balance.  

 

Back in the main, if the expression is unbalanced, a message is outputted to the user that it cannot be converted to postfix and the program terminates. If it is balanced, however, the expression is converted to postfix form in the convertToPostfix() function of the class.  

There is a private data member (string postfix) of the class that is initialized as empty so that characters can be added to it as the postfix form is built. Inside the covertToPostfix() function, the infix expression is iterated through.  

If the character is a digit, it is appended to postfix 

If the character is an operator it is sent to a processOp() function that compares it to a stack and handles pushing, or appending to postfix accordingly. 

processOp() calls upon another function getPrecedence() to determine the precedences of the operators being dealt with 

If the character is an open parenthesis, it is pushed to a stack 

If the character is a closed parenthesis, it the references the stack and appends operators to postfix until it encounters its matching parenthesis. The parenthesis are then popped so they do not appear in the postfix expression.  

 

The postfix expression is then returned to the main and outputted to the user and the program terminates.  

 

3 examples are shown below. 

![Screenshre shown below. ot (46)](https://user-images.githubusercontent.com/98354701/232258693-d7939f25-625c-4cf9-8261-728c52b2c0de.png)
![Screenshot (47)](https://user-images.githubusercontent.com/98354701/232258694-c2d9d29a-c3f0-4c75-84d3-ac3198834938.png)
![Screenshot (48)](https://user-images.githubusercontent.com/98354701/232258695-0de86fa5-10e8-45f8-8596-39f7849025d1.png)


