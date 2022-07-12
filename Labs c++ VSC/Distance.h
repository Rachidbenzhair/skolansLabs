#pragma once
class Distance
{
private:
	int feet;
	float inches;
public:
	Distance();
	Distance(int f, float i);
	void setDistance(int f, float i);
	void print();
	~Distance();
	Distance add_distance(Distance pass);//Passing Objects as Arguments
	Distance operator + (Distance d2);
	Distance operator -(Distance d2);

};

