#include "./Models/Human.h"
#include <iostream>
#include <cstring>

human::human(){
	do{
    	std::cout << "Player 1 what's your name?: ";
    	std::cin.getline(name, 20);
		if (strlen(name) == 0)
			std::cout << "Name is required!" << std::endl;
	}while(strlen(name) == 0);
	do{
		std::cout << "Which shape do you want?(x or o): ";
		shape = getchar();
	    while(shape != '\n' && getchar()!= '\n'){};
	}while(shape != 'X' && shape != 'x' && shape != 'O' && shape != 'o');
	std::cout << std::endl;
	if (shape == 'X' || shape == 'x')
		in_shape = true;
	else 
		in_shape = false;	
}

human::human(human &ob, bool in_shape){
	do{
		do{
			std::cout << "Player 2 what's your name?: ";
			std::cin.getline(name, 20);
			if (strlen(name) == 0)
				std::cout << "Name is required!" << std::endl;
		}while(strlen(name) == 0);
		if (!(strcmp(name, ob.get_name())))
			std::cout << "Name already exists!" << std::endl;
	}while(!(strcmp(name, ob.get_name())));
	if(in_shape)
		shape = 'o';
	else
		shape = 'x';
}

char* human::get_name(){
	return name;
}

char human::get_shape(){
	return shape;
}

bool human::get_in_shape(){
	return in_shape;
}