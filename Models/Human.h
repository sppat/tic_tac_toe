#ifndef HUMAN_H
#define HUMAN_H

class human{
	public:
		human();
		human(human &ob, bool in_shape);
		char* get_name();
		char get_shape();
		bool get_in_shape();
	private:
		char name[50];
		char shape;
		bool in_shape;
};

#endif