/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:13:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/03 13:13:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				pos = av[1][i] - 65;
				av[1][i] = 90 - pos;
				write(1, &av[1][i], 1);
			}
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				pos = av[1][i] - 97;
				av[1][i] = 122 - pos;
				write(1, &av[1][i], 1);
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
