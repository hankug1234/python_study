#include<stdio.h>

using namespace std;

int main()
{
	auto s = socket(UDP);
	S.bind(8089);
	auto r = s.recvfrom();
	print(r.srcAddrPort,r.data);
	s.close();
	
	return 0;
}
