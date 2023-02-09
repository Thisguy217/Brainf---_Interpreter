#pragma once

#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

class Scanner {
    private:
        string input;

    public:
        Scanner(const string& input) : input(input) { }

        vector<Token> scanToken() {
            vector<Token> returnVec;
            int line = 1;
            while (input.length() != 0) {
                while (isspace(input.at(0))) {
                    if (input.at(0) == '\n') {
                        line++;
                    }
                    input = input.substr(1);
                    if (input.length() == 0) {
                        Token eof = Token(EOFILE, "", line);
                        returnVec.push_back(eof);
                        return returnVec;
                    }
                }

                if (input.at(0) == ',') {
                    Token comma = Token(INPUT, ",", line);
                    returnVec.push_back(comma);
                    input = input.substr(1);
                } else if (input.at(0) == '.') {
                    Token period = Token(OUTPUT, ".", line);
                    returnVec.push_back(period);
                    input = input.substr(1);
                } else if (input.at(0) == '+') {
                    Token plus = Token(INCREMENT, "+", line);
                    returnVec.push_back(plus);
                    input = input.substr(1);
                } else if (input.at(0) == '[') {
                    Token left_bracket = Token(OPEN_WHILE, "[", line);
                    returnVec.push_back(left_bracket);
                    input = input.substr(1);
                } else if (input.at(0) == ']') {
                    Token right_bracket = Token(CLOSE_WHILE, "]", line);
                    returnVec.push_back(right_bracket);
                    input = input.substr(1);
                } else if (input.at(0) == '-') {
                    Token minus = Token(DECREMENT, "-", line);
                    returnVec.push_back(minus);
                    input = input.substr(1);
                } else if (input.at(0) == '<') {
                    Token shift_back = Token(SHIFT_REV, "<", line);
                    returnVec.push_back(shift_back);
                    input = input.substr(1);
                } else if (input.at(0) == '>') {
                    Token shift_forward = Token(SHIFT_FOR, ">", line);
                    returnVec.push_back(shift_forward);
                    input = input.substr(1);
                } else {
                    int eos = -1;
                    for (long unsigned int i = 1; i < input.length(); i++) {
                        if (input.at(i) == '+' || input.at(i) == '-' || input.at(i) == ',' || input.at(i) == '.' || input.at(i) == '<' || input.at(i) == '>' || input.at(i) == '[' || input.at(i) == ']') {
                            eos = i;
                            break;
                        }
			if ((input.length() - 1 - i) == 0) {
                            eos = i;
                            break;
                        }
                    }
                    Token comment = Token(COMMENT, input.substr(0,eos), line);
                    returnVec.push_back(comment);
                    input = input.substr(eos);
                }
            }
            Token eof = Token(EOFILE, "", line);
            returnVec.push_back(eof);
            return returnVec;
        }
};
