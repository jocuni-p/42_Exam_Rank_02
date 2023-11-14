/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:34:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/09/11 13:50:03 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 4 && ft_strlen(av[2]) == 1 && ft_strlen(av[3]) == 1) 
//	if (av[2][0] < 65 || av[2][0] > 122 || (av[2][0] > 90 && av[2][0] < 97))
	{
	    while (av[1][i] != '\0')
	    {
		    if (av[1][i] == av[2][0])
			    av[1][i] = av[3][0];
		    write(1, &av[1][i], 1);
		    i++;
	    }
    }
	write(1, "\n", 1);
	return (0);
}
