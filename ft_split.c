/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:31:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/22 12:43:18 by jocuni-p         ###   ########.fr       */
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

	while (str[i])//recorro el str para contar las palabras
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;//salto espacios/tabs/saltos de linia

		if (str[i])
			wc++;

		while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != '\n'))
			i++;
	}
	char **split = (char **)malloc(sizeof(char *) * (wc + 1));
	split[wc] = NULL;//cierro el array de strings

	i = 0;
	while (str[i])//recorro str para meter cada palabra en mi array de strings
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;//salto espacios/tabs/saltos de linia

		j = i;//inicializo j donde empieza la palabra

		while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != '\n'))
			i++;//cuento los bytes/chars de la palabra

		if (i > j)//si la palabra tiene 1 o mas bytes
		{
			split[k] = (char *)malloc(sizeof(char) * (i - j) + 1);//alojo memoria para contener la palabra
			ft_strncpy(split[k], &str[j], i - j);//relleno la memoria del array con la palabra
			printf("despues del strncpy\n");
			k++;
		}
	}
//El cerramiento del array de strings ya lo he hecho arriba despues de declararlo
//	split[k] = '\0';
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
		printf("0 = %s\n", split[0]);
		printf("1 = %s\n", split[1]);
		printf("2 = %s\n", split[2]);
		printf("3 = %s\n", split[3]);
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
