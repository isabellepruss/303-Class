#include "Header.h"
#include<string>
#include<cctype>
#include<iostream>

using namespace std;

int main() {

	//variables
	Queue userQueue; // initial a queue
	bool run = true;
	char userChoice;
	string newPerson;
	string toRemove;
	bool empty;
	int numPeople;
	char userChoice2;

	//welcome menu
	while (run) {

		
		cout << endl << "What would you like to do to the waiting list?" << endl;
		cout << "(a) add person" << endl;
		cout << "(r) remove person from front of list" << endl;
		cout << "(t) show who is at the front of the list" << endl;
		cout << "(e) check to see if list is empty" << endl;
		cout << "(n) see number of people in the list" << endl;
		cout << "enter a,r,t,e, or n:  " << endl;

		cin >> userChoice;

		switch (userChoice) {

		case 'a':

			//ask user for name of person they'd like to add
			cout << "Who would you like to add to the list? : ";
			cin >> newPerson;
			cout << endl;

			userQueue.insert(newPerson); //call function to add to queue

			break;

		case 'r':

			//call function to pop top person from queue
			cout << "You removed " << userQueue.pop() << " from the queue." << endl; 

			break;

		case 't':

			//output person at top of the queue
			cout << "The person at the front of the list is : " << userQueue.top() << endl;

			break;

		case'e':

			//call function to see if queue is empty
			empty = userQueue.isEmpty();

			if (empty) { //output message if empty
				cout << "The queue is empty, there is no one in line." << endl;

			}

			else { //output message and size if not empty

				//if/else branch for grammar purposes
				if (userQueue.queueSize() == 1) {
					cout << "The queue is not empty. There is " << userQueue.queueSize() << " person in line." << endl;


				}

				else {
					cout << "The queue is not empty. There are " << userQueue.queueSize() << " people in line." << endl;

				}

			}
			
			break;

		case 'n':

			//output message and call function to get size of queue
			cout << "The number of people in line is : " << userQueue.queueSize() << endl;

			break;

		}

		//ask user if they would like to be taken back to the main menu
		cout << "Would you like to access something else? Y/N : ";
		cin >> userChoice2;
		userChoice2 = toupper(userChoice2);

		if (userChoice2 == 'Y') {
			continue;
		}

		else {
			break;
		}
		
		cout << endl << endl;

	}

	cout << "Thank you, and goodbye!" << endl; //exit statement if user ends program
	

	return 0;
}
