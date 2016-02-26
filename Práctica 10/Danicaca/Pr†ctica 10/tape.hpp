#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef long int	head_t;
typedef char		data_t;

class tape_t{
private:
	vector<data_t> tape_;
	head_t head_;
public:
	tape_t(vector<data_t> chain);
	tape_t(vector<data_t> chain, head_t head);
	~tape_t(void);

	void set_on_tape(data_t data);
	data_t get_of_tape(void);

	void move_head(char mov);
	
	void write(ostream& os);
	void unwrite(ostream& os);
};
