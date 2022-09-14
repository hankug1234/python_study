#include<stdio.h>

using namespace std;

int main()
{
	s = socket(UDP);
	S.bind(8088);
	s.sendTo("127.0.0.1:8089","HELLO");
	s.close();
}
