#include "./Models/Table.h"
#include <iostream>

table::table(){
	int num = 1;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			tab[i][j] = num;
			num++;
		}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tabl[i][j] = '-';

	std::cout << std::endl;
	std::cout << "\t***************************************************" << std::endl;
	std::cout << "\t*Instructions:\t\t\t\t\t  *" << std::endl;
	std::cout << "\t*-> Choose a number from 1 to 9 to make your move!*" << std::endl;
	std::cout << "\t***************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\t|\t\t|" << std::endl;
	std::cout << "\t\t" << tab[0][0] << "\t|" << "\t" << tab[0][1] << "\t|" << "\t" << tab[0][2] << std::endl;
	std::cout << "\t-------------------------------------------------" << std::endl;
	std::cout << "\t\t\t|\t\t|" << std::endl;
	std::cout << "\t\t" << tab[1][0] << "\t|" << "\t" << tab[1][1] << "\t|" << "\t" << tab[1][2] << std::endl;
	std::cout << "\t-------------------------------------------------" << std::endl;
	std::cout << "\t\t\t|\t\t|" << std::endl;
	std::cout << "\t\t" << tab[2][0] << "\t|" << "\t" << tab[2][1] << "\t|" << "\t" << tab[2][2] << std::endl;
	std::cout << std::endl;
}

char table::check_winner(){
	for (int i = 0; i < 3; i++)
		if(tabl[i][0] == tabl[i][1] && tabl[i][1] == tabl[i][2])
			return tabl[i][0];
	
	for (int j = 0; j < 3; j++)
		if(tabl[0][j] == tabl[1][j] && tabl[1][j] == tabl[2][j])
			return tabl[0][j];
	
	if (tabl[0][0] == tabl[1][1] && tabl[1][1] == tabl[2][2])
		return tabl[1][1];
	else if (tabl[0][2] == tabl[1][1] && tabl[1][1] == tabl[2][0])
		return tabl[1][1];
		
	return '-';
}

bool table::set_table(char pos, char sh){
	switch (pos){
		case '1':
			if (tabl[0][0] == '-')
			{			
				tabl[0][0] = sh;
				return true;
			}
			else
				return false;
		case '2':
			if (tabl[0][1] == '-')
			{			
				tabl[0][1] = sh;
				return true;
			}
			else
				return false;
		case '3':
			if (tabl[0][2] == '-')
			{			
				tabl[0][2] = sh;
				return true;
			}
			else
				return false;
		case '4':
			if (tabl[1][0] == '-')
			{			
				tabl[1][0] = sh;
				return true;
			}
			else
				return false;
		case '5':
			if (tabl[1][1] == '-')
			{			
				tabl[1][1] = sh;
				return true;
			}
			else
				return false;
		case '6':
			if (tabl[1][2] == '-')
			{			
				tabl[1][2] = sh;
				return true;
			}
			else
				return false;
		case '7':
			if (tabl[2][0] == '-')
			{			
				tabl[2][0] = sh;
				return true;
			}
			else
				return false;
		case '8':
			if (tabl[2][1] == '-')
			{			
				tabl[2][1] = sh;
				return true;
			}
			else
				return false;
		case '9':
			if (tabl[2][2] == '-')
			{			
				tabl[2][2] = sh;
				return true;
			}
			else
				return false;
		default:
			return false;
	}
}

void table::print_table(){
	std::cout << "\t\t\t|\t\t|" << std::endl;
	std::cout << "\t\t" << tabl[0][0] << "\t|" << "\t" << tabl[0][1] << "\t|" << "\t" << tabl[0][2] << std::endl;
	std::cout << "\t-------------------------------------------------" << std::endl;
	std::cout << "\t\t\t|\t\t|" << std::endl;
	std::cout << "\t\t" << tabl[1][0] << "\t|" << "\t" << tabl[1][1] << "\t|" << "\t" << tabl[1][2] << std::endl;
	std::cout << "\t-------------------------------------------------" << std::endl;
	std::cout << "\t\t\t|\t\t|" << std::endl;
	std::cout << "\t\t" << tabl[2][0] << "\t|" << "\t" << tabl[2][1] << "\t|" << "\t" << tabl[2][2] << std::endl;
}