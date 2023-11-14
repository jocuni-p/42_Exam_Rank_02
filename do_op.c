/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:59:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/10 19:27:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	nbr1;
	int	nbr2;

	if (ac == 4)
	{
		nbr1 = atoi(av[1]);
		nbr2 = atoi(av[3]);

		if (av[2][0] == '+')
			printf("%i\n", nbr1 + nbr2);
		if (av[2][0] == '-')
			printf("%i\n", nbr1 - nbr2);
		if (av[2][0] == '*')
			printf("%i\n", nbr1 * nbr2);
		if (av[2][0] == '/')
			printf("%i\n", nbr1 / nbr2);
		if (av[2][0] == '%')
			printf("%i\n", nbr1 % nbr2);
	}
	else
		printf("\n");
	return (0);
}
