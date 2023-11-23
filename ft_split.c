/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:31:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/23 11:15:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *dst, char *src, int len)
{
	int	i = 0;

	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


char	**ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	wc = 0;

/*-------------RECORREMOS str PARA CONTAR LAS PALABRAS-------------*/
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;

		if (str[i])
			wc++;

		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))//OJO con los &&
			i++;
	}
	char **split = (char **)malloc(sizeof(char *) * (wc + 1));
	split[wc] = NULL;//cierro el array a NULL (no uso '\0' porque necesita una direccion de mem, NO un caracter).

/*---------RECORREMOS str PARA METER CADA PALABRA EN SU PROPIO ARRAY---------*/
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;

		j = i;//inicializo j donde empieza la palabra

		while (str[i] && (str[i] != 32 && str[i] != 9 && str[i] != 10))
		{
			i++;
		}
		if (i > j)//si la palabra tiene 1 o mas chars
		{
			split[k] = (char *)malloc(sizeof(char) * (i - j) + 1);
			ft_strncpy(split[k], &str[j], i - j);//relleno el array con la palabra
			k++;
		}
		j = 0;
	}
	return (split);
}

int	main(int ac, char **av)
{
	int		i = 0;
	int		j = 0;
	char	**split = NULL;

	if (ac == 2)
	{
		split = ft_split(av[1]);
		while(split[i])
		{
			j = 0;
			while(split[i][j])
			{
				write(1, &split[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
		free(split);
	}
	return (0);
}
