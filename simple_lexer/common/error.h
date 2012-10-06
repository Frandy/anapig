/*
 * error.h
 *
 *  Created on: Oct 3, 2012
 *      Author: chjd
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "stringenc.h"

/*! \brief A simple class for showing error info.
 *
 */
class Error
{
public:
	Error(){}
	Error(string errinfo)	{
		ShowInfo(errinfo);
	}
	void ShowInfo(string errinfo){
		cerr << errinfo << endl;
	}
};

/*
 * It maybe should inherit from Exception.
 * But if using catch exception, you should use try first.
 * This is not my wanted.
 * Maybe we can use a function instead.
 */

//void Error(string info);


#endif /* ERROR_H_ */
