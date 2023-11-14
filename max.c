/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:44:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/09/18 15:31:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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
/*
int	main(void)
{
	int				tab[5] = {-1, 3, 0, 1, 4};

	unsigned int	len = 5;

	printf("max:%i\n", max(tab, len));
	return (0);
}*/
