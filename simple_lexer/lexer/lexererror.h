/*
 * lexererror.h
 *
 *  Created on: Oct 6, 2012
 *      Author: chjd
 */

#ifndef LEXERERROR_H_
#define LEXERERROR_H_

#include "error.h"

/*! \brief A simple class for showing lexer error
 *
 */
class LexerError : public Error
{
public:
	LexerError(char x,char c,int p){
		string info = "expecting char:";
		info += toString(x);
		info += ",but found:";
		info += toString(c);
		info += " at column ";
		info += toString(p);
		ShowInfo(info);
	}
	LexerError(char c,int p){
		string info = "unexpected char:";
		info += toString(c);
		info += " at column ";
		info += toString(p);
		ShowInfo(info);
	}
};

#endif /* LEXERERROR_H_ */
