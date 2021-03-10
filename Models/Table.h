#ifndef TABLE_H
#define TABLE_H

class table{
	public:
		table();
		char check_winner();
		bool set_table(char pos, char sh);
		void print_table();
	private:
		int tab[3][3];
		char tabl[3][3];
};

#endif