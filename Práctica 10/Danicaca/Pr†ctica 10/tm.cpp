#include "tm.hpp"

tm_t::tm_t(void):
error_(true){}

tm_t::tm_t(char filename[])
{
	update(filename);
}

tm_t::~tm_t(void)
{
	
}

void tm_t::update(char filename[])
{
	//==================================================================================================================================================
	//================================================= TM Cleanup
	//==================================================================================================================================================
	if(state_.size()!=0)
		state_.clear();

	tape_alphabet_.clear();
	tape_alphabet_.push_back('$');

	if(input_alphabet_.size()!=0)
		input_alphabet_.clear();
	
	n_ = 0;
	initial_state_ = 0;
	error_ = false;
	
	//==================================================================================================================================================
	//================================================= Error checking
	//==================================================================================================================================================
	ifstream file;
	int aux;
	
	file.open(filename);
	if( file.fail() )
		error(1);
	
	if(!error_){ //check for errors in number of states
		string foo;
		char *bar = new char[foo.length()];
		
		file >> foo;
		
		for(int i = 0; i < foo.length(); i++){ //transform string to char array and check for possible non-number character
			bar[i]=foo[i];
			if( (foo[i] < 48) || ( foo[i] > 57 ) ){
				error(2);
			}
		}
		if(!error_)
			aux = atoi(bar); //remeber the maximum number of states for later use
		delete [] bar;
	}
	
	if(!error_){ // check for errors in the number of final states
		string foo;
		char *bar = new char[foo.length()];
		
		file >> foo;
		
		for(int i = 0; i < foo.length(); i++){ //transform string to char array and check for possible non-number character
			bar[i]=foo[i];
			if( (foo[i] < 48) || ( foo[i] > 57 ) )
				error(3);
		}
		if(!error_)
			if ( atoi(bar) > (aux-1) )
				error(4);
		delete [] bar;
	}
	
	if(!error_){ //check for errors in transitions
		string	state, destination, dummy, movement;
		
		while( !file.eof() ){
			char *foo = new char[state.length()];
			char *bar = new char[state.length()];
			
			file >> state >> dummy >> dummy >> movement >> destination;
			
			for(int i = 0; i < state.length(); i++){//transform string to char array and check for possible non-number character
				foo[i] = state[i];
				if( (state[i] < 48) || ( state[i] > 57 ) ){
					error(5);
				}
			}
			if( atoi(foo) > aux) //check if maximum state number exeeded
				error(9);
			
			for(int i = 0; i < destination.length(); i++){//transform string to char array and check for possible non-number character
				bar[i] = destination[i];
				if( (destination[i] < 48) || ( destination[i] > 57 ) )
					error(6);
			}
			if( atoi(bar) > aux)//check if maximum state number exeeded
				error(10);
			
			if( movement.length() > 1 )//Check if the movement string length is larger than a character.
				error(7);
			if( (movement[0] != 'R') && (movement[0] != 'L') & (movement[0] != 'S') ) //check for possible non-movement character
				error(8);

			delete [] foo;
			delete [] bar;
			
		}
	}
	
	file.seekg (0, file.beg);
	
	//==================================================================================================================================================
	//================================================= Construction
	//==================================================================================================================================================
	
	if(!error_){
		file >> n_ >> final_limit_;
		
		for(int i = 0; i < n_; i++){ //Vector resizing. Also setting if final
 			state_t dummy;
			state_.push_back(dummy);
		}
		
		while(!file.eof()){ //Pushing all the transitions data
			state_transition_t dummy;
			int state_dummy;
			
			file >> state_dummy >> dummy.read_ >> dummy.write_ >> dummy.movement_ >> dummy.next_state_;
			state_[state_dummy].transitions_.push_back(dummy);
		}

		for(int i = 0; i < n_; i++){ //Introducing the numbers of stransitions of each state
			state_[i].n_transition_ = state_[i].transitions_.size();
		}
	}
	file.close();
}

ostream& tm_t::show_info(ostream& os)
{
	if(!error_){
		bool stop = false;
		os << n_ << endl;
		os << final_limit_ << endl;
		for(int i = 0; i < n_; i++){
			for(int j = 0; j < state_[i].n_transition_; j++){
				os << i << " " << state_[i].transitions_[j].read_ << " " << state_[i].transitions_[j].write_ << " " << state_[i].transitions_[j].movement_ << " " << state_[i].transitions_[j].next_state_ << endl;
			}
		}
	}
	else{
		cerr << "[ERR] There isn't any TM loaded!" << endl;
	}
	
}

ostream& tm_t::simulate_machine(ostream& os, vector<char> chain)
{
	bool keep = true;
	tape_t tape(chain);
	int actual_state = initial_state_;
	
	while(keep){
		bool transition_found = false;
		int read_location;
		
		for(int i = 0; i < state_[actual_state].n_transition_; i++){
			if( (state_[actual_state].transitions_[i].read_ == tape.get_of_tape()) || state_[actual_state].transitions_[i].read_ == '!'){
				transition_found = true;
				read_location = i;
			}
		}
		if(!transition_found)
			keep = false;
		else{
			tape.set_on_tape(state_[actual_state].transitions_[read_location].write_);
			tape.move_head(state_[actual_state].transitions_[read_location].movement_);
			actual_state = state_[actual_state].transitions_[read_location].next_state_;
		}
	}
	if(actual_state >= final_limit_)
		os << "Chain accepted" << endl;
	else
		os << "Chain rejected" << endl;
}

ostream& tm_t::simulate_machine(ostream& os, istream& is, vector<char> chain)
{
	bool keep = true;
	tape_t tape(chain);
	int actual_state = initial_state_;
	int iteration = 0;
	
	while(keep){
		system("clear");
		
		//============================================= Muero por dentro
		cout << "==============Practica 10 CYA==============\n" << endl;
		
		cout << "o. [o]pen Turing Machine file (.tm)" << endl;
		cout << "i. show Turing Machine [i]nfo" << endl;
		cout << "s. [s]imulate Turing Machine" << endl;
		cout << "t. simulate Turing Machine s[t]ep by step" << endl;
		cout << "q. [q]uit" << endl;
		cout << "  >t" << endl;
		
		cout << "\n==========================================" << endl;
		cout << "Input chain: ";
	
		for(int i = 0; i < chain.size(); i++){cout << chain[i];}
		
		cout << endl;
		//============================================ :'(
		
		tape.write(os);
		if(iteration)
			cin.ignore();
		else
			cin.ignore().get();
		
		bool transition_found = false;
		int read_location;
		
		for(int i = 0; i < state_[actual_state].n_transition_; i++){
			if( (state_[actual_state].transitions_[i].read_ == tape.get_of_tape()) || ((state_[actual_state].transitions_[i].read_ == '!') && (tape.get_of_tape() != '$'))){
				transition_found = true;
				read_location = i;
			}
		}
		if(!transition_found)
			keep = false;
		else{
			tape.set_on_tape(state_[actual_state].transitions_[read_location].write_);
			tape.move_head(state_[actual_state].transitions_[read_location].movement_);
			actual_state = state_[actual_state].transitions_[read_location].next_state_;
		}
		iteration++;
	}
	if(actual_state >= final_limit_)
		os << "Chain accepted" << endl;
	else
		os << "Chain rejected" << endl;
}

void tm_t::error(int code)
{
	error_ = true;
	switch(code){
		case 1: cerr << "[ERR] Bad name" << endl; break;
		case 2: cerr << "[ERR] Wrong characters in number of states" << endl; break;
		case 3: cerr << "[ERR] Wrong characters in final states" << endl; break;
		case 4: cerr << "[ERR] Final state is bigger than number of states" << endl; break;
		case 5: cerr << "[ERR] Wrong characters in state" << endl; break;
		case 6: cerr << "[ERR] Wrong characters in destination" << endl; break;
		case 7: cerr << "[ERR] Wrong number of characters in movement" << endl; break;
		case 8: cerr << "[ERR] Wrong characters in movement" << endl; break;
		case 9: cerr << "[ERR] A state is bigger than the number of states" << endl; break;
		case 10: cerr << "[ERR] A destination is bigger than the number of states" << endl; break;
	}
}