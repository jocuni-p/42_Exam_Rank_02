/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:44:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/15 14:54:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

#include <stdio.h>

/*-----------------OPCION 1----------------------*/
int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	unsigned int	aux;

	i = 0;
	aux = i + 1;
	while (aux < len)
	{
		if (tab[i] >= tab[aux])
			aux++;
		else
			i = aux;
			aux++;
	}
	return (tab[i]);
}

/*------------------OPCION 2--------------------*/
int max(int *tab, unsigned int len)
{
    int max = 0;
    int i = 1;

    max = tab[0];
    len--;
    while (len > 0)
    {
        if (tab[i] > max)
            max = tab[i];
        len--;
        i++;
    }
    return (max);
}
/*
int	main(void)
{
	int				tab[5] = {-100, 83, 10, 1, 4};

	unsigned int	len = 5;

	printf("max:%i\n", max(tab, len));
	return (0);
}*/
