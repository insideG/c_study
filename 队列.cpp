#include<iostream>
using namespace std;
class X
{
public:
	static int g_iMem;
};

class Y
{
public:
	virtual void Feature();
	char m_c1;
};

class Z : public Y
{
public:
	char m_c2;
	X x;
	int m_i1;
};

int main(char argc,char *argv[])
{

	Z z;
	int k = sizeof(Z);
	cout << k << endl;
	return 0;
}