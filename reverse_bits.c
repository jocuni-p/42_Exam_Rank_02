#include<stdio.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		printf("%d\n", i);
		i--;
	}
	return (res);
}


int main(int argc, char **argv)
{
	unsigned	char c;

	c = argv[1][0];
	printf("el numero %d lo convierte en %d\n", c, reverse_bits(c));
	

}
