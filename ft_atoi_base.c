/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:57:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/21 18:08:42 by jocuni-p         ###   ########.fr       */
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

int ft_atoi_base(const char *str, int str_base);*/

#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>

int is_valid(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');

    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);

    else if (c >= 'a' && c<= 'f')
        return (c - 'a' + 10);

    return (-1);
}

/*en cuanto detecta un caracter NO reconocible finaliza y retorna lo que leyo hasta ese momento */
int ft_atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int res = 0;
    int digit;

    if (str == NULL || str_base < 2 || str_base > 16)
        return (0);

    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    while (*str)
    {
    	digit = is_valid(*str);
        if (digit == -1 || digit > str_base)//args NO reconocibles o > que str_base
            return (res * sign);
        else
            res = res * str_base + digit;
            str++;
    }
    return (res * sign);
}
/*
int main(int ac, char **av)
{
    if (ac == 3)
    {
        printf("string = %s\nbase = %s\n", av[1], av[2]);
        printf("atoi_base = %i\n", ft_atoi_base(av[1], atoi(av[2])));
    }
    return (0);
}*/
