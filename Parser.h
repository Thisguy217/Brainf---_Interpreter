#pragma once

#include <vector>
#include "Token.h"

class Parser {
	private:
		vector<Token> tokens;
	public:
		Parser(const vector<Token>& tokens) : tokens(tokens) { }

		TokenType tokenType() const {
			return tokens.at(0).getType();
		}

		void advanceToken() {
			tokens.erase(tokens.begin());
		}

		void throwError() {
			cout << "Syntax Error" << endl;
		}

		void match(TokenType t) {
			cout << "match: " << t << endl;
			if (t == tokens.at(0).getType()) {
				advanceToken();
			} else {
				throwError();
			}
		}

		void Start() {
			in_decrement();
			shifter();
			while_init();
			in_output();
			comment();
		}

		void in_decrement() {
			if (tokenType() == INCREMENT) {
				match(INCREMENT);
				Start();
			} else if (tokenType() == DECREMENT) {
				match(DECREMENT);
				Start();
			} else {
				;
			}
		}

		void shifter() {
			if (tokenType() == SHIFT_FOR) {
				match(SHIFT_FOR);
				Start();
			} else if (tokenType() == SHIFT_REV) {
				match(SHIFT_REV);
				Start();
			} else {
				;
			}
		}

		void while_init() {
			if (tokenType() == OPEN_WHILE) {
				match(OPEN_WHILE);
				Start();
				match(CLOSE_WHILE);
			} else {
				;
			}
		}

		void in_output() {
			if (tokenType() == INPUT) {
				match(INPUT);
				Start();
			} else if (tokenType() == OUTPUT) {
				match(OUTPUT);
				Start();
			} else {
				;
			}
		}

		void comment() {
			if (tokenType() == COMMENT) {
				match(COMMENT);
				Start();
			} else {
				;
			}
		}
};
