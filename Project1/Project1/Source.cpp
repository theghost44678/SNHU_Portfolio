/*
 * Calculator.cpp
 *
 *  Date: 11/05/2024
 *  Author: Anthony Shewmake
 */

#include <iostream>

using namespace std;

int main() // switched this over to int instead of void
{
	//char statement[100] removed 
	int op1, op2;
	char operation;
	char answer = 'Y'; // changed "" to '' and added ;
		while (answer == 'Y') // changed to Y 
		{
			cout << "Enter expression" << endl; // left as is 
			cin >> op1 >> operation >> op2; // changed order 
			if (operation == '+') { // added braces and changed "" to '' also removed ;
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; // changed >> to << 
			}// closed out the statement
			if (operation == '-') { // added opening brace removed ;
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // switched >> to <<
			} // added close brace
			if (operation == '*') { // added opening brace
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; // changed / to * added ; after endl
			} // added closing brace
			if (operation == '/') { // added open brace
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; // changed * to /
			} // added closeing brace

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
		}
}