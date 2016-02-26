#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "tape.hpp"

#include <unistd.h>

using namespace std;

typedef struct
{
	char			read_;
	char			write_;
	char			movement_;
	unsigned int		next_state_;
} state_transition_t;

typedef struct
{
	vector<state_transition_t> transitions_;
	bool final_;
	int n_transition_;
} state_t;

class tm_t{
private:
	unsigned int	n_;
	unsigned int	initial_state_;
	unsigned int	final_limit_;
	
	bool error_;
	
	vector<state_t>	state_;
	vector<char>	tape_alphabet_;
	vector<char>	input_alphabet_;
public:
	tm_t(void);
	tm_t(char filename[]);
	~tm_t(void);
	
	void update(char filename[]);
	ostream& show_info(ostream& os);
	ostream& simulate_machine(ostream& os, vector<char> chain);
	ostream& simulate_machine(ostream& os, istream& is, vector<char> chain);
	
	void error(int code);
};

