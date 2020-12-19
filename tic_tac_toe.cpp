#include <iostream>
#include <cstring>
using namespace std;


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

int main(){
	human p1, p2(p1, p1.get_in_shape());
	cout<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"-> "<<p1.get_name()<<" plays with "<<p1.get_shape()<<"."<<endl;
	cout<<"-> "<<p2.get_name()<<" plays with "<<p2.get_shape()<<"."<<endl;
	cout<<"Press enter, to continnue..."<<endl;
	cout<<"------------------------------"<<endl;
	getchar();
	
	table tab;
	char player[20], sh, num;
	int counter=0;

	if (p1.get_shape()=='X' || p1.get_shape()=='x')
	 strcpy(player, p1.get_name());
	else 
	 strcpy(player, p2.get_name());
	
	while(true){
 
		do{
			cout<<endl<<player<<" choose a number(from 1 to 9): ";
			num=getchar();	
			while(getchar()!='\n'){};
		}while((num-48)<1 || (num-48)>9);
		if(strcmp(player, p1.get_name()))
			sh=p2.get_shape();
		else 
			sh=p1.get_shape();
	
		if(!tab.set_table(num, sh))
		{	
			cout<<"!Wrong move, play again!"<<endl;
			continue;
		}
		tab.print_table();

		if(strcmp(player, p1.get_name()))
			strcpy(player, p1.get_name());
		else 
			strcpy(player, p2.get_name());
		
		if (tab.check_winner()!='-')
		{
			if (tab.check_winner()==p1.get_shape())
			{
				cout<<p1.get_name();
				cout<<" wins!"<<endl;
				break;
			}
			else 
			{
				cout<<p1.get_name();
				cout<<" wins!"<<endl;
				break;
			}
		}
		if (counter==8)
		{
			cout<<"It's a draw!"<<endl;
			break;
		}
		counter++;	
	}	
	return 0;
}

human::human(){
	do{
    	cout<<"Player 1 what's your name?: ";
    	cin.getline(name, 20);
		if (strlen(name) == 0)
			cout<<"Name is required!"<<endl;
	}while(strlen(name) == 0);
	do{
		cout<<"Which shape do you want?(x or o): ";
		shape=getchar();
	    	while(shape!='\n' && getchar()!='\n'){};
	}while(shape!='X' && shape!='x' && shape!='O' && shape!='o');
	cout<<endl;
	if (shape=='X' || shape=='x')
		in_shape = true;
	else 
		in_shape = false;	
}

human::human(human &ob, bool in_shape){
	do{
		do{
			cout<<"Player 2 what's your name?: ";
			cin.getline(name, 20);
			if (strlen(name) == 0)
				cout<<"Name is required!"<<endl;
		}while(strlen(name) == 0);
		if (!(strcmp(name, ob.get_name())))
			cout<<"Name already exists!"<<endl;
	}while(!(strcmp(name, ob.get_name())));
	if(in_shape)
		shape='o';
	else
		shape='x';
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

table::table(){
	int num=1;
	
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++){
			tab[i][j]=num;
			num++;
		}

	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			tabl[i][j]='-';

	cout<<endl;
	cout<<"\t***************************************************"<<endl;
	cout<<"\t*Instructions:\t\t\t\t\t  *"<<endl;
	cout<<"\t*-> Choose a number from 1 to 9 to make your move!*"<<endl;
	cout<<"\t***************************************************"<<endl;
	cout<<endl;
	cout<<"\t\t\t|\t\t|"<<endl;
	cout<<"\t\t"<<tab[0][0]<<"\t|"<<"\t"<<tab[0][1]<<"\t|"<<"\t"<<tab[0][2]<<endl;
	cout<<"\t-------------------------------------------------"<<endl;
	cout<<"\t\t\t|\t\t|"<<endl;
	cout<<"\t\t"<<tab[1][0]<<"\t|"<<"\t"<<tab[1][1]<<"\t|"<<"\t"<<tab[1][2]<<endl;
	cout<<"\t-------------------------------------------------"<<endl;
	cout<<"\t\t\t|\t\t|"<<endl;
	cout<<"\t\t"<<tab[2][0]<<"\t|"<<"\t"<<tab[2][1]<<"\t|"<<"\t"<<tab[2][2]<<endl;
	cout<<endl;
	
}

char table::check_winner(){
	for (int i=0; i<3; i++)
		if(tabl[i][0]==tabl[i][1] && tabl[i][1]==tabl[i][2])
			return tabl[i][0];
	
	for (int j=0; j<3; j++)
		if(tabl[0][j]==tabl[1][j] && tabl[1][j]==tabl[2][j])
			return tabl[0][j];
	
	if (tabl[0][0]==tabl[1][1] && tabl[1][1]==tabl[2][2])
		return tabl[1][1];
	else if (tabl[0][2]==tabl[1][1] && tabl[1][1]==tabl[2][0])
		return tabl[1][1];
		
	return '-';
}

bool table::set_table(char pos, char sh){
	switch (pos){
		case '1':
			if (tabl[0][0]=='-')
			{			
				tabl[0][0]=sh;
				return true;
			}
			else
				return false;
		case '2':
			if (tabl[0][1]=='-')
			{			
				tabl[0][1]=sh;
				return true;
			}
			else
				return false;
		case '3':
			if (tabl[0][2]=='-')
			{			
				tabl[0][2]=sh;
				return true;
			}
			else
				return false;
		case '4':
			if (tabl[1][0]=='-')
			{			
				tabl[1][0]=sh;
				return true;
			}
			else
				return false;
		case '5':
			if (tabl[1][1]=='-')
			{			
				tabl[1][1]=sh;
				return true;
			}
			else
				return false;
		case '6':
			if (tabl[1][2]=='-')
			{			
				tabl[1][2]=sh;
				return true;
			}
			else
				return false;
		case '7':
			if (tabl[2][0]=='-')
			{			
				tabl[2][0]=sh;
				return true;
			}
			else
				return false;
		case '8':
			if (tabl[2][1]=='-')
			{			
				tabl[2][1]=sh;
				return true;
			}
			else
				return false;
		case '9':
			if (tabl[2][2]=='-')
			{			
				tabl[2][2]=sh;
				return true;
			}
			else
				return false;
		default:
			return false;
	}
}

void table::print_table(){
	cout<<"\t\t\t|\t\t|"<<endl;
	cout<<"\t\t"<<tabl[0][0]<<"\t|"<<"\t"<<tabl[0][1]<<"\t|"<<"\t"<<tabl[0][2]<<endl;
	cout<<"\t-------------------------------------------------"<<endl;
	cout<<"\t\t\t|\t\t|"<<endl;
	cout<<"\t\t"<<tabl[1][0]<<"\t|"<<"\t"<<tabl[1][1]<<"\t|"<<"\t"<<tabl[1][2]<<endl;
	cout<<"\t-------------------------------------------------"<<endl;
	cout<<"\t\t\t|\t\t|"<<endl;
	cout<<"\t\t"<<tabl[2][0]<<"\t|"<<"\t"<<tabl[2][1]<<"\t|"<<"\t"<<tabl[2][2]<<endl;
}
