/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:41:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/19 13:15:53 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/

/*--------------------PRIMERA FORMA DE HACERLO---------------------*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i = 0;

	while (str[i])
		i++;

	return (i);
}

int	char_to_digit(char c)//asumo que solo entraran argumentos unsigned char y hasta base 16
{
	if (c >= '0' && c <= '9')
		return (c - '0');

	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);

	else if (c >= 'a' && c<= 'f')
		return (c - 'a' + 10);
	return (-1);//per si entra un arg no valid, poguer saltarlo
}

int	ft_atoi_base(const char *str, int str_base)
{
//	int	i = 0;
	int	sign = 1;
//	int	str_len = 0;
	int	res = 0;
	int	digit;
	
//por si hay args no validos
	if (str == NULL || str_base < 2 || str_base > 16)
		return (0);

//manejamos el signo
	if (*str == '-')
	{
		sign = -1;
		str++;
	}

//	str_len = ft_strlen(str);

//	while (i < str_len)
	while (str)
	{
	digit = char_to_digit(*str);//caracter donde esta apuntando ahora el *str
//		digit = char_to_digit(str[i]);
		if (digit == -1 || digit > str_base)//filtra args no validos o numeros mayores que su base
//			return (0);
            str++;//lo saltamos si no encaja como argumento
        else
		    res = res * str_base + digit; 
		    str++;
	}
	printf("res = %i\n", res);
	return (res * sign);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("string = %s\nbase = %s\n", av[1], av[2]);
		printf("atoi_base = %i\n", ft_atoi_base(av[1], atoi(av[2])));
	}
	return (0);
}// He seguit el ChatGPT com a guia.

/*------------------------OTRA FORMA DE HACERLO----------------------*/

//#include <stdio.h>
/*
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

char    to_lower(char c)
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
        result = result * str_base + (digit * sign);
        ++str;
    }
    return (result);
}

int main(int arc, char **arv)
{
    if (arc == 3)
        printf("str :\"%s\"\nbase: %s\natoi_base: %i\n", arv[1], arv[2], ft_atoi_base(arv[1], ft_atoi(arv[2])));
    return (0);
}*/

