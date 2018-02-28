#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;

struct event
{
	string eventName;
	timeOfDay eventTime;
	appDate eventDate;
	bool isUrgent;
};
struct timeOfDay 
{
	short Hour;
	short Minute;
	short Second;
	
};

struct appDate
{
	short dayOfMonth;
	short month;
	int year;
	

};

int main()
{
	timeOfDay Time;
	Time.Hour = 6;
	Time.Minute = 30;
	Time.Second = 0;
	cout << "\nThe Time of day is: ";
	cout <<"\n"<< Time.Hour << ":" << Time.Minute << ":" << Time.Second << endl;
	
	
	appDate Date;
	Date.dayOfMonth = 27;
	Date.month = 8;
	Date.year = 2018;
	cout << "\nThe Date is";
	cout << "\n" << Date.month << "/" << Date.dayOfMonth << "/" << Date.year << endl;
	
	event BirthdayParty;
	BirthdayParty.eventName = "Helen's Party";
	cout << "The Name of The Event is: " << BirthdayParty.eventName << endl;
	
	BirthdayParty.eventDate.dayOfMonth = 9;
	BirthdayParty.eventDate.month = 6;
	BirthdayParty.eventDate.year = 2018;
	cout << "The Event will take place on the Date of: " << BirthdayParty.eventDate.dayOfMonth << "/" << BirthdayParty.eventDate.month << "/" << BirthdayParty.eventDate.year;

	BirthdayParty.eventTime.Hour = 6;
	BirthdayParty.eventTime.Minute = 30;
	BirthdayParty.eventTime.Second = 0;
	cout << "The Event will take place on the time of: " << BirthdayParty.eventTime.Hour << ":" << BirthdayParty.eventTime.Minute << ":" << BirthdayParty.eventTime.Second << endl;

	if (BirthdayParty.isUrgent == true)
	{
		cout << "I must go to this party" << endl;

	}
	else
	{
		cout << "\n:( I can't go to the party" << endl;
	}
	

	
	
	return 0;
}
