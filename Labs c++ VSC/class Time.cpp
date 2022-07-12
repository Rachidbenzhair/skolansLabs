#include <string>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h, int m, int s)
	{
		/*hour = h;
		minute = m;
		second = s;*/
		setHour(h);
		setMinute(m);
		setSecond(s);

	}
	void setHour(int h)
	{
		if (h >= 1 && h <= 24)
			hour = h;
	}
	void setMinute(int m)
	{
		if (m >= 0 && m <= 60)
			minute = m;
	}
	void setSecond(int s)
	{
		if (s >= 0 && s <= 60)
			second = s;
	}
	int getHour()
	{
		return hour;
	}
	int getMinute()
	{
		return minute;
	}
	int getsecond()
	{
		return second;
	}
};

//int main()
//{
//	Time time1(12, 13, 54);
//	time1.setHour(16);
//
//	cout << time1.getHour() << ":" << time1.getMinute() << ":" << time1.getsecond() << endl;
//
//}