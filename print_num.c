/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:46:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/16 11:02:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Recreo un programa que imprima los numeros del 1 al 100 seguidos de un '\n' */
/*funciones permitidas: write */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	i = 1;

	while (i < 100)
	{
		if (i <= 9)
			ft_putchar(i + 48);
		else
		{
			ft_putchar((i / 10) + 48);
			ft_putchar((i % 10) + 48);
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "100\n", 4);
	return (0);
}
