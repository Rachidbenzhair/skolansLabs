#include "Counter.h"

int Counter::get_count()
{
	return count;
}

Counter Counter::operator++()
{
	++count; 
	return Counter(count);
}

Counter Counter::operator--()
{
	--count; 
	return Counter(count);
}

Counter Counter::operator++(int)
{
	count++; 
	return Counter(count);
}

Counter Counter::operator--(int)
{
	count--; 
	return Counter(count);
}
