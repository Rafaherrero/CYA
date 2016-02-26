#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <string>
#include "tape.hpp"
#include "tm.hpp"

using namespace std;

void show_menu(void);
char *open_file(char* file);
vector<char> read_chain(void);
void space(void);

int main(void){
	
	char option;
	char* file = NULL;
	tm_t myturingmachine;
	vector<char> chain;
	

	do{
		system("clear");
		//sleep(1);
		show_menu();
		//sleep(1);
		cin >> option;
		
		switch(option){
			case('o'): space(); file = open_file(file); myturingmachine.update(file);						break;
			case('i'): space(); myturingmachine.show_info(cout); 									break;
			case('s'): space(); cout << "Input chain: "; chain=read_chain(); myturingmachine.simulate_machine(cout, chain);		break;
			case('t'): space(); cout << "Input chain: "; chain=read_chain(); myturingmachine.simulate_machine(cout, cin, chain);	break;
			case('q'):														break;
			default: space(); cerr << "That option doesn't exist";									break;
		}
		if(option != 'q' && option != 't')
			cin.ignore().get();
		if(option == 't')
			cin.ignore();
		
	}while(option != 'q');
	
}

void show_menu(void)
{
	cout << "==============Practica 10 CYA==============\n" << endl;
	cout << "o. [o]pen Turing Machine file (.tm)" << endl;
	cout << "i. show Turing Machine [i]nfo" << endl;
	cout << "s. [s]imulate Turing Machine" << endl;
	cout << "t. simulate Turing Machine s[t]ep by step" << endl;
	cout << "q. [q]uit" << endl;
	cout << "  >";
}

char *open_file(char* file)
{
	if(file != NULL)
		delete [] file;
	file = new char[80];
	cout << "Enter file name:" << endl;
	cout << ">";
	cin >> file;
	
	ifstream test;
	
	test.open(file);
	if( test.fail() )
		cout << "Couldn't find that file!" << endl;
	else
		cout << "File founded succesfuly" << endl;
	
	test.close();
	return file;
}

vector<char> read_chain(void)
{
	vector<char> bar;
	string input;
	
	cin >> input;
	for(int i = 0; i < input.length(); i++){
		bar.push_back(input[i]);
	}
	return bar;
}

void space(void)
{
	cout << "\n==========================================" << endl;
}