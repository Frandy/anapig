/*
 * main.cpp
 *
 *  Created on: Oct 6, 2012
 *      Author: chjd
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "lexer.h"

int main()
{
	cout << "please input some text, both word and number are ok" << endl;
	cout << ">";
	string input;
	getline(cin,input);
	Lexer lexer(input);
	while(1){
		Token t = lexer.NextToken();
		cout << t;
		if(t.Type()==TokenType._EOF)
			break;
	}
	return 0;
}
