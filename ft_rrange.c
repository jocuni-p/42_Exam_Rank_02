/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:37:09 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/16 12:54:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/

#include <stdlib.h>
//#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*range = NULL;

	len = start - end;
	if (len < 0)
	{
		len *= -1;
		range = (int *)malloc(len * sizeof(int));



		if (!range)
			return (NULL);
		while (len >= 0)
		{
			range[len] = start;
			start++;
			len--;
		}
	}
	else if (len > 0)
	{
		range = (int *)malloc(len * sizeof(int));
		if(!range)
			return (NULL);
		while (len >= 0)
		{
			range[len] = start;
			start--;
			len--;
		}
	}
	return (range);
}

/*------------OTRA FORMA VALIDA-----------------*/

// Passed Moulinette 2019.09.01

#include <stdlib.h>
//#include <stdio.h>
i
int     absolute_value(int n)
{
    if (n < 0)
        n *= -1;
    return (n);
}

int     *ft_rrange(int start, int end)
{
    int number_of_ints;
    int *array;
    int step;
    int i;

    number_of_ints = 1 + absolute_value(end - start);
    array = malloc(sizeof(int) * number_of_ints);

    if (start > end)
        step = 1;
    else
        step = -1;

    i = 0;
    while (i < number_of_ints)
    {
        array[i] = end;
        end = end + step;
        ++i;
    }
    return (array);
}

/*--------------------MAIN------------------*/
/*
int	main(void)
{
	int	i = 0;
	int	end = 3;
	int	start = -3;
	int	*range = NULL;

	range = ft_rrange(start, end);
	while (i < 7)
	{
		printf("%i\n", range[i]);
		i++;
	}
	return (0);
}*/
