#include <iostream>
#include <fstream>
#include <sstream>
#include "Token.h"
#include "Scanner.h"
#include "Parser.h"
using namespace std;

int main(int args, char** argv) {
	if (args <= 1) {
		throw invalid_argument("No arguments provided");
		return 1;
	}
        string filename = argv[1];
	if (filename.substr(filename.length() - 3) != ".bf" ) {
		throw invalid_argument("Invalid file type");
		return 1;
	}

	ifstream in;
	in.open(filename);
	stringstream ss;
	ss << in.rdbuf();
	string input = ss.str();
	in.close();

	Scanner s = Scanner(input);
	//Scanner s = Scanner("+\n-\n<\n>\n[\n]\n,\n.\n");
	vector<Token> t = s.scanToken();

	Parser p = Parser(t);

	p.Start();//TODO: write the rules for parsing

	return 0;
}
