#include "tape.hpp"

tape_t::tape_t(vector<data_t> chain):
head_(0)
{
	tape_ = chain;
}

tape_t::tape_t(vector<data_t> chain, head_t head):
head_(head)
{
	tape_ = chain;
	while ( head_ > tape_.size() ){
		tape_.push_back('$');
	}
	while (head_ < 0){
		head++;
		tape_.insert( tape_.begin(), '$' );
	}
}

tape_t::~tape_t(void)
{}


void tape_t::set_on_tape(data_t data)
{
	tape_[head_] = data;
}

data_t tape_t::get_of_tape(void)
{
	return tape_[head_];
}


void tape_t::move_head(char mov)
{
	switch(mov){
		case 'R': head_++; break;
		case 'L': head_--; break;
		case 'S': /*stay*/ break;
		default: cerr << "Wrong movement. You tried to move the head in " << mov << " direction." << endl;
	}
	
	if( head_ < 0 ){
		head_ = 0;
		tape_.insert( tape_.begin(), '$' );
	}
	else if( head_ >= tape_.size() ) {
		tape_.push_back('$');
	}
}


void tape_t::write(ostream& os)
{
	os << "...$$$";
	
	for(int i = 0; i < tape_.size(); i++ ){ //print vector
		os << tape_[i];
	}
	
	os << "$$$..." << endl;
	os << "      ";
	
	for(int i = 0; i < head_; i++){ //print head position
		os << " ";
	}
	
	os << "^" << endl;
}

void unwrite(ostream& os)
{
	
}