#include <stdio.h>

int ft_atoi(const char *str)
{
        int sign = 1;
        int nbr = 0;

        while (*str == ' ' || (*str >= 9 && *str <= 13))
            str++;
        if (*str == '-')
            sign = -1;
        if (*str == '-' || *str == '+')
            str++;
        while (*str >= '0' && *str <= '9')
        {
            nbr = nbr * 10 + (*str - 48);
            str++;
        }
        return (nbr * sign);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int get_digit(char c, int digits_in_base)
{
	int max_digit;
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	return (result);
}

int main(int arc, char **arv)
{
    if (arc == 3)
        printf("str :\"%s\"\nbase: %s\natoi_base: %i\n", arv[1], arv[2], ft_atoi_base(arv[1], ft_atoi(arv[2])));
    return (0);
}
