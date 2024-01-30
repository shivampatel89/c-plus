#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Check{
	public:
		string name;
		int balance,ac_no,i,ac_type;
		int n;//for asking that consumer have account or not
		void asking()
		{
			balance=0;
			   do{
			   	
			   
				cout<<"WelCome To Bank Application"<<endl;
				cout<<endl;				
				cout<<"Select One Choice (1 Or 2)"<<endl<<"1.Open Bank Account"<<endl<<"2.Already Have An Account"<<endl;
				cin>>n;
				if(n!=1&&n!=2)
				{
					cout<<"Please Enter Valid Choice."<<endl;
					cout<<endl;
				}
			}
			while(n!=1&&n!=2);
			
		
		}
};
class Record:public Check{
	public:
		void check_record()
		{
			if(n==1)
			{
				cout<<"To Open Your Account Give Some Information."<<endl;
				cout<<"Enter Your Name:";
				cin>>name;				
				cout<<"Select Your Account Type (Press 1 Or 2)"<<endl<<"1.Saving"<<endl<<"2.Current"<<endl;
				cin>>ac_type;
				if(ac_type!=1&&ac_type!=2)
					{
						for(i=3;i>=1;i--)
						{
							cout<<"You Have "<<i<<" Attempts Left!!"<<endl;
							cout<<"Please Enter Valid Choice :";
							cin>>ac_type;
							if(ac_type==1||ac_type==2)
							break;
						}
					}
				switch(ac_type)
				{
					case 1:
						cout<<name<<" How Many Rupees You Want To Deposite (Minimum 10000):";
						cin>>balance;
						if(balance<10000)
						{
							for(i=3;i>=1;i--)
							{
								cout<<"You Have "<<i<<" Attempts Left!!"<<endl;
								cout<<"Sorry Sir We Are Not Able To Open Current Acoount Less Than 10000"<<endl;
								cout<<"Please Enter Minimum Amount :";
								cin>>balance;
								if(balance>=10000)
								break;
							}
						}
						if(balance>=10000)
						{
						 srand((unsigned) time(0));
						 ac_no = rand();
					     cout <<"Your Account Number Is "<< ac_no << endl;
					 	}
						break;
				
					case 2:
				 		cout<<name<<" How Many Rupees You Want To Deposite (Minimum 50000):";
						cin>>balance;
						if(balance<50000)
						{
							for(i=3;i>=1;i--)
							{
							
								cout<<"You Have "<<i<<" Attempts Left!!"<<endl;
								cout<<"Sorry Sir We Are Not Able To Open Current Acoount Less Than 50000"<<endl;
								cout<<"Please Enter Minimum Amount :";
								cin>>balance;
								if(balance>=50000)
								break;
							}
						
						}
						if(balance>=50000)
						{
						 srand((unsigned) time(0));
						 ac_no = rand();
					     cout <<"Your Account Number Is "<< ac_no << endl;
					 	}
						break;	
				
					default :
						cout<<("Please Enter Valid Choice.");
				}
			}
			else
			{
				cout<<"Enter Your Account Number:";
				cin>>ac_no;
				cout<<"Sorry We Can't Find Your Data!!"<<endl;
				
			}			
		}
};

class AccessAccount:public Record{
	public:
		int uea,ui;//-->User Enter AccountNumber-->ui-->User i/p for deposite and withdrawl ammount
		int j;//for aking user to handle account
		void display()
		{
		do
		{
			if(n==1)
			{
				if(ac_no!=NULL)
				{
				
					do
					{				
					 	cout<<"Select Any One "<<endl<<"1.View Accout Details"<<endl<<"2.Deposite Amount"<<endl<<"3.Withdrawl An Amount"<<endl<<"4.Exit"<<endl;
						cin>>j;
						if((j!=1)&&(j!=2)&&(j!=3)&&(j!=4))
					 	{
					 		cout<<"Please Enter Valid Choice."<<endl;
					 		cout<<endl;
					    }		 
					}
				    while((j!=1)&&(j!=2)&&(j!=3)&&(j!=4));
				    
				    switch(j)
				{
					case 1:
						cout<<"Enter Your Account Number:";
						cin>>uea;
						
						if(ac_no!=uea)
						{
							for(i=3;i>=1;i--)
							{
							
								cout<<"You Have "<<i<<" Attempts Left!!"<<endl;
								cout<<"Enter Your Account Number:";
								cin>>uea;
								if(ac_no==uea)
								break;
										
							}
						}
						if(ac_no==uea)
						{
							cout<<endl;
							cout<<"Account Holder Name : "<<name<<endl;
							cout<<"Account Number      : "<<ac_no<<endl;
							if(ac_type==1)
							{
							cout<<"Account Type    	: Saving"<<endl;	
							}
							else
							{
							cout<<"Account Type     : Current"<<endl;
							}																
							cout<<"Account Balance     : "<<balance<<endl;								
							}
							break;
					case 2:
						
						
						cout<<"Enter Your Account Number:";
						cin>>uea;
						
						if(ac_no!=uea)
						{
							for(i=3;i>=1;i--)
							{
							
								cout<<"You Have "<<i<<" Attempts Left!!"<<endl;
								cout<<"Enter Your Account Number:";
								cin>>uea;
								if(ac_no==uea)
								break;
										
							}
						}
						if(ac_no==uea)
						{
							cout<<"Account Balance : "<<balance<<endl;
							cout<<"How Many Rupees You Want To Deposite : ";
							cin>>ui;
							balance+=ui;
							cout<<"Account Balance : "<<balance<<endl;
						}
						break;
						
						case 3:
							cout<<"Enter Your Account Number:";
						cin>>uea;
						
						if(ac_no!=uea)
						{
							for(i=3;i>=1;i--)
							{
							
								cout<<"You Have "<<i<<" Attempts Left!!"<<endl;
								cout<<"Enter Your Account Number:";
								cin>>uea;
								if(ac_no==uea)
								break;
										
							}
						}
						if(ac_no==uea)
						{
							cout<<"Account Balance : "<<balance<<endl;
							cout<<"How Many Rupees You Want To Withdrawl : ";
							cin>>ui;
							if(ui>balance)
							{
								cout<<"Insufficient Bank Balance."<<endl;
							}
							else
							{
								balance-=ui;
								cout<<"Account Balance : "<<balance<<endl;
							}
						}
						break;
						case 4:
							exit(0);
							break;
				}	
						
				}
				
			}
		}
		while(j!=4);
		}						
};



main()
{
    AccessAccount r;
	r.asking();
	r.check_record();
	r.display();

}							
