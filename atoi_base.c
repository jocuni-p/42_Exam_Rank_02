/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:41:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/17 16:57:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (c >= '0' && c >= '9')
		return (c - '0');

	else if (c >= 'A' && c <= 'F')
		return (c - 'A' - 10);

	else if (c >= 'a' && c<= 'f')
		return (c - 'a' - 10);
	return (-1);//per si entra un arg no valid
}

int	ft_atoi_base(const char *str, int str_base)
{
//	int	i = 0;
	int	sign = 1;
	int	str_len = 0;
	int	res;
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

	str_len = ft_strlen(str);

//	while (i < str_len)
	while (str)
	{
		digit = char_to_digit(*str);//caracter donde esta apuntando ahora el *str
//		digit = char_to_digit(str[i]);
		if (digit == -1 || digit > str_base)//filtra args no validos o numeros mayores que su base
			return (0);
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
		printf("str = %s\nbase = %s\n", av[1], av[2]);
		ft_atoi_base(av[1], atoi(av[2]));
	}
	return (0);
}// He seguit el ChatGPT com a guia.
