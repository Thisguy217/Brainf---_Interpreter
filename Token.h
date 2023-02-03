#pragma once

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

enum TokenType {
	INCREMENT, DECREMENT, SHIFT_FOR, SHIFT_REV, OPEN_WHILE, CLOSE_WHILE, INPUT, OUTPUT, COMMENT, EOFILE
};

class Token {
	private:
		TokenType type;
		string value;
		int lineStart;
	public:
		Token(TokenType type, string value, int lineStart) : type(type), value(value), lineStart(lineStart) { }

		string toString() const {
			stringstream out;
			out << "(" << TypeName(type) << "," << "\"" << value << "\"" << "," << lineStart << ")";
			return out.str();
		}

		string TypeName(TokenType type) const {
			switch (type) {
				case INCREMENT: return "INCREMENT"; break;
				case DECREMENT: return "DECREMENT"; break;
				case SHIFT_FOR: return "SHIFT_FOR"; break;
				case SHIFT_REV: return "SHIFT_REV"; break;
				case OPEN_WHILE: return "OPEN_WHILE"; break;
				case CLOSE_WHILE: return "CLOSE_WHILE"; break;
				case EOFILE: return "EOFILE"; break;
				case INPUT: return "INPUT"; break;
				case OUTPUT: return "OUTPUT"; break;
				case COMMENT: return "COMMENT"; break;
			}
			return "ERROR";
		}
};
