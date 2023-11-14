/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:42:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/14 19:44:28 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);

	char	c = nbr % 10 + 48;
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	nbr = 0;

	while (str[i] != '\0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

void	tab_mult(int nbr)
{
	int	i = 1;

	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nbr);
		write(1, " = ", 3);
		ft_putnbr(nbr * i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	nbr;

	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	nbr = ft_atoi(av[1]);
	tab_mult(nbr);
	return (0);
}
