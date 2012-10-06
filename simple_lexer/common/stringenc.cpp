/*
 * stringenc.cpp
 *
 *  Created on: Oct 4, 2012
 *      Author: chjd
 */

#include "stringenc.h"

string toString(char c) {
	string buf;
	buf.push_back(c);
	return buf;
}
string toString(int p) {
	stringstream ss;
	ss << p;
	string buf;
	ss >> buf;
	return buf;
}
