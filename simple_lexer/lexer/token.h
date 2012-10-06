/*
 * token.h
 *
 *  Created on: Oct 6, 2012
 *      Author: chjd
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class TokenType
{
public:
	TokenType():_EOF(0),TEXT(1),NUMBER(2),name({"EOF","TEXT","NUMBER"}){
	}
	string Name(int t) {
		return name.at(t);
	}
public:
	const int _EOF;
	const int TEXT;
	const int NUMBER;
	vector<string> name;// = {"EOF","TEXT"};
}TokenType;

class Token
{
public:
	Token(){}
	Token(int tp, string tx) {
		type = tp;
		text = tx;
	}
	int Type() const {
		return type;
	}
	string Text() const {
		return text;
	}
	friend ostream& operator << (ostream& out,const Token& token){
		out << "<" << TokenType.Name(token.Type()) << "," << token.Text() << ">" << endl;
	}
protected:
	int type;
	string text;
};

#endif /* TOKEN_H_ */
