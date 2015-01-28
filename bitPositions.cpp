#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
	string n, p1, p2, input;
	int num, pos1, pos2;
	int index;

	ifstream file(argv[1], ifstream::in);

	while(file.good()&&!file.eof()){
		/* input the variables */
		getline(file, input);
		if (input.find(",")!=-1)
		{
			/* Find first comma, get the chars before it and remove them from index */
			index = input.find(",");
			n = (input.substr(0,index));
			input = input.substr(index+1);

			index = input.find(",");
			p1 = (input.substr(0,index));
			p2 = (input.substr(index+1));

			num = stol(n, nullptr, 10);
			pos1 = stol(p1, nullptr, 10);
			pos2 = stoi(p2, nullptr, 10);

			/* Where the magic happens. Chooses pos1 and pos2 in num, and XOR returns if different or not */
			if( !(((1<<(pos1-1))&num) != 0  ^ ((1<<(pos2-1))&num) != 0) )
				cout << "true"<< endl;
			else 
				cout << "false" << endl;
		}
		
	}
	
	return 0;
}

