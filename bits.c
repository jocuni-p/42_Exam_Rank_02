/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:57:23 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/13 10:10:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;

	while (i--)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res = 0;
	int				i = 8;

	while (i--)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
	}
	return (res);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4) | (octet >> 4));
}


int	main(int ac, char **av)
{
	int	octet;

	if (ac == 2)
	{
		octet = atoi(av[1]);
		print_bits(octet);
		write(1, "\n", 1);
		print_bits(reverse_bits(octet));
		write(1, "\n", 1);
		print_bits(swap_bits(octet));
		write(1, "\n", 1);
	}
	return (0);
}
