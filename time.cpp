#include<iostream>
#include<time.h>
using namespace std;

struct dateValue
{
	int year;
	int month;
	int date;
};

struct returnValue
{
	dateValue first;
	dateValue second;
};

int isLeapYear(int year)
{
	if(year%4 == 0)
	{
		if(year%100 == 0)
		{
			if(year%400 == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}


//Business Logic
returnValue calculateDate(dateValue x, dateValue y)
{
	returnValue p;
	p.first = x;
	p.second = y;
	
   int i = isLeapYear(y.year);
   
   
   if(i == 1)
   {
   	  int j = y.month;
   	  switch(j)
   	  {
   	  	case 1 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 2 :
   	  		p.first.date = 1;
   	  		p.second.date = 28;
   	  		return p;
   	  	case 3 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 4 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 5 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 6 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 7 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 8 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 9 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 10 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 11 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 12 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	default :
   	  		cout<<"invalid number";
   	  		break;
	  }
   }
   
   else
   {
   	 int j = y.month;
   	  switch(j)
   	  {
   	  	case 1 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 2 :
   	  		p.first.date = 1;
   	  		p.second.date = 29;
   	  		return p;
   	  	case 3 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 4 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 5 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 6 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 7 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 8 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 9 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 10 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	case 11 :
   	  		p.first.date = 1;
   	  		p.second.date = 30;
   	  		return p;
   	  	case 12 :
   	  		p.first.date = 1;
   	  		p.second.date = 31;
   	  		return p;
   	  	default :
   	  		cout<<"invalid number";
   	  		break;
	  }
	}
	return p;
}

//Driver Program
int main()
{
	dateValue from_date, to_date;
	returnValue value;
	time_t r_time;
    tm* t_info;
	
	cout << "enter the From_date in formate year:month:date" << endl;
	cin >> from_date.year >> from_date.month >> from_date.date;

	//checking if date and month is valid or not for FromDate
	while( (from_date.date > 31 || from_date.date < 1) || (from_date.month > 12 || from_date.month <1) )
	{
		
		cerr << "please provide date between 1-31 and month between 1-12";
		
		cout << endl << "please enter again" << endl;
		
		cin >> from_date.year >> from_date.month >> from_date.date;
	}
	
	cout << "enter the to_date in formate year:month:date" << endl;
	
	cin >> to_date.year >> to_date.month >> to_date.date;
	
	//checking if date and month is valid or not for ToDate
	
	while( (to_date.date > 31 || to_date.date < 1) || (to_date.month > 12 || to_date.month <1) )
	{
		
		cerr << "please provide date between 1-31 and month between 1-12";
		
		cout << endl << "please enter again" << endl;
		
		cin >> to_date.year >> to_date.month >> to_date.date;
	}
  
    //Calling to date calculation function
    
	value = calculateDate(from_date,to_date);
	
	//Getting Current time
	
	time( &r_time );
    
	t_info = localtime( &r_time );
    
    //Checking Condition whether year of Todate is greater than Current year or not.
    
	if( value.second.year > (t_info->tm_year + 1900))  
		{
	
			cout << "first day from FromDate is:" << endl << value.first.year << ":" << value.first.month << ":" << value.first.date << endl;
    		
			cout << "Last day from ToDate is:" << endl << (t_info->tm_year + 1900) << ":" << t_info->tm_mon+1 << ":" << (t_info->tm_mday) << endl; 
		} 

    //Checking Condition if ToDate year is same year as Current year then whether month of Todate is greater than Current month or not.
	
	else if((t_info->tm_mon+1) < value.second.month && (t_info->tm_year + 1900) <= value.second.year)
		{
	 
	 		cout << "first day from FromDate is:" << endl << value.first.year << ":" << value.first.month << ":" << value.first.date << endl;
    	
			cout << "Last day from ToDate is:" << endl << (t_info->tm_year + 1900) << ":" << t_info->tm_mon+1  << ":" << (t_info->tm_mday) <<  endl;
		}	
	
	// checking if both year and month is same as ToDate then date is greater or not.
	
	else if((t_info->tm_mon+1) <= value.second.month && (t_info->tm_year + 1900) <= value.second.year && (t_info->tm_mday+1) < value.second.date)
		{
			cout << "first day from FromDate is:" << endl << value.first.year << ":" << value.first.month << ":" << value.first.date << endl;
  		 
		   	cout << "Last day from ToDate is:" << endl << (t_info->tm_year + 1900) << ":" << t_info->tm_mon+1  << ":" << (t_info->tm_mday) << endl;
		}
	
	//if todate is less than current date 
	
	else
		{
	
			cout << "first day of the month is:" << endl << value.first.year << ":" << value.first.month << ":" << value.first.date;
			cout << endl << "Last day of the month is:" << endl << value.second.year << ":" << value.second.month << ":" << value.second.date;
		}
	return 0;
}
