#ATM MACHINE USING C++
#include<iostream>
#include<ctime>
using namespace std;
int deposit(int x);
int withdraw(int x);
int main()
{
	int pin,x=0,bal=100000;        
	cout<<"\tWelcome To ABC BANK\n\tServing With Pleasure";
	cout<<"\n\tPlease Insert Your Card\n";
	sleep(2);
	cout<<"\nHi Sir/Madam!Please Donot Remove Your Card During The Entire Transaction Process.";
	sleep(2);
	cout<<"\n\nPlease Enter Any Number Between 10 To 99\n\t\tEx:25:";
	cin>>x;
	if(x>=10&&x<=99)
	{
		cout<<"\nPlease Enter Your Pin : ";
		cin>>pin;			/*pin is 1234. Please be noted*/
		cout<<"\nVerifying Pin......\n";
		sleep(2);
		if(pin==1234)
		{
			int n=0;
			do
			{
				cout<<"\nPlease Select Your Transaction";
				cout<<"\n1.Deposit\n2.Withdrawal\n3.Balance Enquiry\n4.Exit\n";
				cin>>n;
				if(n==1)
				{
					bal=deposit(bal);
				}
				else if(n==2)
				{
					bal=withdraw(bal);
				}
				else if(n==3)
				{
					cout<<"\nThe Current Balance in your account is : Rs."<<bal;
				}
				else if(n==4)
				{
					cout<<"\n\nTRANSACTION_COMPLETE\nPlease Remove Your Card";
				}
				else
				{
					cout<<"\n\nTRANSACTION_DECLINED:ENTERED_WRONG_OPTION\nPlease Remove Your Card";
				}
			}
			while(n!=4&&(n>=1&&n<=3));
		}
		else
		{
			cout<<"\n\nTRANSACTION_DECLINED:ENTERED_WRONG_PIN\nPlease Remove Your Card";
		}
	}
	else
	{
		cout<<"\n\nTRANSACTION_DECLINED:ENTERED_WRONG_NUMBER\nPlease Remove Your Card";
	}
}

int deposit(int bal)
{
	char a;
	int dep;
	do
	{
		cout<<"\nPlease Insert The Cash You Want To Deposit In Multiples Of Rs.100, Rs.200, Rs.500\n";
		cin>>dep;
		cout<<"\nChecking The Notes And Validating Transaction.....\n";
		sleep(2);
		if(dep%100==0||dep%200==0||dep%500==0)
		{
			cout<<"\nYour Deposit Amount is: Rs."<<dep;
			bal=bal+dep;
			cout<<"\nTotal Balance : Rs."<<bal;
		}
		else
		{
			cout<<"\nPlease Enter Correct Deposit Amount Into The Machine In Multiples Of Rs.100, Rs.200 Or Rs.500";
		}
		cout<<"\nDo You Want To Continue?\nPlease Enter 'y' or 'n' : ";
		cin>>a;
	}
	while(a=='y');
	return bal;
}

int withdraw(int bal)
{
	int with,x=0,y=0,z=0;
	char a;
	do
	{
		cout<<"\nEnter The Amount You Want To Withdraw In Multiples Of Rs.100, Rs.200, Rs.500\n";
		cin>>with;
		cout<<"\nValidating Transaction.......\n";
		sleep(2);
		if(with<=bal&&(with%100==0||with%200==0||with%500==0))
		{
			cout<<"\nThe Withdrawn Amount is : Rs."<<with;
			bal=bal-with;
			while(with%500==0&&with!=0)
			{
				with=with-500;
				x++;
			}
			while(with%200==0&&with!=0)
			{
				with=with-200;
				y++;
			}
			while(with%100==0&&with!=0)
			{
				with=with-100;
				z++;
			}
			cout<<"\nThe Notes Withdrawn Are :";
			cout<<"\nRs.500 : "<<x<<"Notes";
			cout<<"\nRs.200 : "<<y<<"Notes";
			cout<<"\nRs.100 : "<<z<<"Notes";
			cout<<"\nTotal Balance Is : Rs."<<bal;
		}
		else
		{
			cout<<"\nNo Sufficient Balance In The Account OR You Have Entered The Amount Which Are Not Multiples Of Rs.100,Rs.200 Or Rs.500";
			cout<<"\nPlease Check The Amount You Have Enetered";
		}
		cout<<"\nDo You Want To Continue.Please Select 'y' Or 'n' : ";
		cin>>a;
	}
	while(a=='y');
	return bal;
}
