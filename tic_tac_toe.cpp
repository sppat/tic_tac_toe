#include <iostream>
#include <cstring>
#include "./Models/Human.h"
#include "./Models/Table.h"

int main(){
	human p1, p2(p1, p1.get_in_shape());
	std::cout << std::endl;
	std::cout << "------------------------------" <<std::endl;
	std::cout << "-> " << p1.get_name() <<" plays with " << p1.get_shape() << "." << std::endl;
	std::cout << "-> " << p2.get_name()<<" plays with "<< p2.get_shape() << "." << std::endl;
	std::cout << "Press enter, to continnue..." << std::endl;
	std::cout << "------------------------------" << std::endl;
	getchar();
	
	table tab;
	char player[20], sh, num;
	int counter = 0;

	if (p1.get_shape() == 'X' || p1.get_shape() == 'x')
	 strcpy(player, p1.get_name());
	else 
	 strcpy(player, p2.get_name());
	
	while(true){
 
		do{
			std::cout << std::endl << player << " choose a number(from 1 to 9): ";
			num = getchar();	
			while(getchar() != '\n'){};
		}while((num-48) < 1 || ( num - 48) > 9);
		if(strcmp(player, p1.get_name()))
			sh = p2.get_shape();
		else 
			sh = p1.get_shape();
	
		if(!tab.set_table(num, sh))
		{	
			std::cout << "!Wrong move, play again!" << std::endl;
			continue;
		}
		tab.print_table();

		if(strcmp(player, p1.get_name()))
			strcpy(player, p1.get_name());
		else 
			strcpy(player, p2.get_name());
		
		if (tab.check_winner() != '-')
		{
			if (tab.check_winner() == p1.get_shape())
			{
				std::cout << p1.get_name();
				std::cout << " wins!" << std::endl;
				break;
			}
			else 
			{
				std::cout << p2.get_name();
				std::cout << " wins!"<<std::endl;
				break;
			}
		}
		if (counter == 8)
		{
			std::cout << "It's a draw!" << std::endl;
			break;
		}
		counter++;	
	}	
	return 0;
}
