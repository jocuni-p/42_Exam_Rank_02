/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/10/27 10:46:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/

#include <unistd.h>
//#include <stdio.h>

int	ft_atoi(const char *str)
{
		int	signe = 1;
		int	nbr = 0;

		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-')
			signe = -1;
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			nbr = nbr * 10 + (*str - 48);
			str++;
		}
		return (nbr * signe);
}
/*
int	main(int arc, char **arv)
{
	if (arc == 2)
		printf("arg :\"%s\"\natoi:%i\n", arv[1], ft_atoi(arv[1]));
	return (0);
}*/
