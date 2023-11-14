/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:37:09 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/09/18 17:01:58 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*range;

	len = start - end;
//	if (len == 0)
//si vacio return ????			
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

int	main(void)
{
	int	i = 5;
	int	end = 3;
	int	start = 7;
	int	*range;

	range = ft_rrange(start, end);
	while (i <= 4)
	{
		printf("%i\n", range[i]);
		i++;
	}
	return (0);
}
