/*
 * lexer.h
 *
 *  Created on: Oct 6, 2012
 *      Author: chjd
 */

#ifndef LEXER_H_
#define LEXER_H_

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "stringenc.h"
#include "token.h"

#include "lexererror.h"

class Lexer;
class LexerError;

/*! \brief A simple lexer, return text, number token, ignore white space
 *
 */
class Lexer
{
public:
	//Lexer()=default; C++11
	Lexer(){}
	/*! \brief Constructor of the simple lexer,
	 * initialize the text, p and c
	 *
	 * @param input the text to be analyzed
	 */
	Lexer(string input):_eof(char(-1)){
		text = input;
		p = 0;
		c = text.at(p);
	}
	/*! \brief consume the current char, and get the next char
	 * if it is the end of input, set c as EOF
	 */
	void consume(){
		p++;
		if (p >= text.length())
			c = _eof;
		else
			c = text[p];
	}
	/*! \brief match the current char to target char
	 *
	 * @param x
	 */

	void match(char x){
		if(c==x)
			consume();
		else
			LexerError err(x,c,p);
	}

	/*! \brief get token from the text,
	 * here only support text word and digital number,
	 * integer, float or scientific number
	 * @return the next token
	 */
	Token NextToken(){
		while(c!=_eof){
			if(isWS())
				WS();
			else if(isLETTER())
				return TEXT();
			else if(isDIGIT())
				return NUMBER();
			else
				LexerError err(c,p);
		}
		return _EOF();
	}

	bool isWS(){
		return (c==' ' || c=='\t' || c=='\r');
	}
	bool isLETTER(){
		return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
	}
	bool isDIGIT(){
		return (c >= '0' && c <= '9');
	}

	/*! \brief Get all the following digits as an integer
	 *
	 * @return return the integer in the string format
	 */
	string Digit() {
		string buf;
		do {
			buf.push_back(c);
			consume();
		} while (isDIGIT());
		return buf;
	}

	/*! \brief Skip all whitespace
	 *
	 */
	void WS(){
		while(isWS())
			consume();
	}

	Token _EOF(){
		return Token(TokenType._EOF,toString(_eof));
	}
	/*! \brief Get all the following letter into a text word
	 *
	 * @return return the word as a TEXT token
	 */
	Token TEXT() {
		string buf;
		do {
			buf.push_back(c);
			consume();
		} while (isLETTER());
		return Token(TokenType.TEXT, buf);
	}

	/*! \brief Get the number, whether it is a integer, or a float,
	 * or even in scientific format
	 *
	 * @return
	 */
	Token NUMBER() {
			string buf = Digit();
		if (c == '.')
			buf += Digit();
		if (c == 'e' || c == 'E') {
			consume();
			buf.push_back(c);
			if (c == '+' || c == '-') {
				consume();
				buf.push_back(c);
				buf += Digit();
			}
		}
		return Token(TokenType.NUMBER, buf);
	}

	/*! \brief print the target text to analyze
	 *
	 * @param out
	 * @param lexer
	 * @return
	 */
	friend ostream& operator << (ostream& out,const Lexer& lexer){
		out << lexer.text << endl;
		return out;
	}
protected:
	string text; // target string
	int p;	// the current position
	char c;	// the current char
	char _eof; // const menber initialized in list
};




#endif /* LEXER_H_ */
