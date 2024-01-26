#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
using namespace std;
 
class design
{
	public:
		string name;
		int round,i;
		int us,cs;//us-->User score  cs-->Computer score
		int uc,cc;//uc-->User choice cc-->computer choice
		void input() 
	{
		
		
		//user input for name and rounds
		cout<<"*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
		cout<<endl;
		cout<<"		NAME"<<endl;
		cout<<endl;
		cout<<"*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
		cout<<"Enter Your Name :";
		cin>>name;
		cout<<"*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
		cout<<endl;
		cout<<"		ROUND"<<endl;
		cout<<endl;
		cout<<"*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
		cout<<name<<" How Many Rounds You Want To Play? :";
		cin>>round;	
	}
};
class logic:public design
{
  public:
  	void game()
  	{   
  		i=1,us=0,cs=0;
  		do
		{
		    //Round playing
	  		cout<<"*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
			cout<<endl;
			cout<<"		GAME"<<endl;
			cout<<endl;
			cout<<"*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
			cout<<"Round No : "<<i<<"/"<<round<<endl;
			cout<<endl;
			cout<<name<<"'s Score ="<<us<<endl;
			cout<<"Computer's Score ="<<cs<<endl;
			cout<<endl;
			cout<<"1) ROCK"<<endl<<"2) PAPER"<<endl<<"3) SCISSOR"<<endl;
			cout<<"Select your choice :";
			cin>>uc;
			//function for random numbers 
			cc=(rand()%3)+1; 
			cout<<"Computer's choice :"<<cc<<endl;
			cout<<endl;
			//if...else logic for round winner
			//Condition for user's winning
			if((uc==1&&cc==3)||(uc==2&&cc==1)||(uc==3&&cc==2))
			{
				cout<<"You Win This Round !!"<<endl;
				cout<<endl;
				us++;
			}
			//Condition for Computer's winning
			else if((uc==1&&cc==2)||(uc==2&&cc==3)||(uc==3&&cc==1))
			{
				cout<<"Computer Win This Round !!"<<endl;
				cout<<endl;
				cs++;
			}
			else
			{
				cout<<"Draw"<<endl;
				cout<<endl;
			}
			i++;
		}
		while(i<=round);
	}
};
class final_result:public logic
{
	public:
	void result()
	{
		if(us>cs)
		{
			cout<<name<<" Is The Winner."<<endl;
		}
		else if(cs>us)
		{
			cout<<"Computer Is The Winner."<<endl;
		}
		else
		{
			cout<<"Game Is Drawn."<<endl;
			
		}
	}
	
};
	
main()
{
	//object declaration and function calling
	final_result g;
	g.input();
	g.game();
	g.result();
}
