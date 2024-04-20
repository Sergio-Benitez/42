#include<unistd.h>

//void ft_putchar(char c)
//{
//	write(1, &c,1);
//}


void rush(int x, int y)
{
 	int a=0;
	while(a<=x)
	{
	if (a==1)
	{
	write(1,"A",1);
	}
	if(a>1 && a<x)
	{
	write(1, "B",1);
	}
	
	if(a==x)
	{
    write(1, "C\n",2);
	}
		a++;
	}
}
int main()
{	
	rush(5, 5); 
	return (0);
}
