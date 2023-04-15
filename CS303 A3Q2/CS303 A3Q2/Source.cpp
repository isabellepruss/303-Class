#include "Header.h"

//inserts item into queue
void Queue::insert(string item) {

	myQueue.push_back(item); //push item to back of queue;

} 

//removes and returns front item of the queue
string Queue::pop() {

	string toPop = myQueue[0]; //returns first element

	myQueue.erase(myQueue.begin()); //deletes first element

	return toPop;

} 

//returns front item of queue without deleting it
string Queue::top() {

	return myQueue[0]; //return item at index 0 of queue

} 

//checks if the queuee is empty, returning a boolean value
bool Queue::isEmpty() {

	if (myQueue.size() == 0) { //if empty, returns true

		return true;
	}

	else { //if not empty, returns false

		return false;
	}

}

//returns size of the queue
size_t Queue::queueSize() {

	return myQueue.size(); //calls vector function to retreive size
}





