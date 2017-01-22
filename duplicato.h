#ifndef ERR_H
#define ERR_H
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class duplicato{
	private:
		string errmsg;
		string errfunc;
		string code;
	public:
		duplicato(const string a, const string b, const string c){errmsg = a; errfunc = b; code = c;}
		friend ostream & operator<<(ostream & os, const duplicato & d){
			os << d.errmsg << d.errfunc << d.code;
			return os;
		}
};

#endif //ERR_H
