#include <iostream>
using namespace std;

int main() {

	int t1Hours, t1Minutes, t1Seconds, t2Hours, t2Minutes, t2Seconds; // input for both times (1 and 2)
	char sep = ':';		//separator for time input

	cout << "Time1 (hours:minutes:seconds) ? ";
	cin >> t1Hours >> sep >> t1Minutes >> sep >> t1Seconds;

	cout << "Time2 (hours:minutes:seconds) ? ";
	cin >> t2Hours >> sep >> t2Minutes >> sep >> t2Seconds;

	//Calculates the sum of both times and converts it to seconds
	int totalSeconds = (t1Hours + t2Hours) * (60 * 60) + (t1Minutes + t2Minutes) * 60 + (t1Seconds + t2Seconds);

	int finalDays, finalHours, finalMinutes, remainingTime;

	finalDays = totalSeconds / (60 * 60 * 24); 
	totalSeconds -= finalDays * 60 * 60 * 24;

	finalHours = totalSeconds / (60 * 60);
	totalSeconds -= finalHours * 60 * 60;

	finalMinutes = totalSeconds / 60;
	totalSeconds -= finalMinutes * 60;

	cout << "Time1 + Time2 = " << finalDays << ((finalDays == 1) ? " day, " : " days, ")
		<< finalHours << ((finalHours == 1) ? " hour, " : " hours, ")
		<< finalMinutes << ((finalMinutes == 1) ? " minute and " : " minutes and ")
		<< totalSeconds << ((totalSeconds == 1) ? " second" : " seconds") << endl;

	return 0;
}