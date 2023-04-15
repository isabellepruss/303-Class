#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Queue {

private:
	vector<string> myQueue; //implementing Queue as a vector

public:
	Queue() {}; //default constructor

	void insert(string item); //inserts item at back of queue
	string pop(); //removes item from top of queue
	string top(); //outputs top element of queue without removing it
	size_t queueSize(); //returns size of the queue
	bool isEmpty(); //checks to see if queue is empty

};

