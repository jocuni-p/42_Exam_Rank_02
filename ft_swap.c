/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:21:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/10/09 15:59:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

/*	printf("a=%d\n", *a);
	printf("b=%d\n", *b);
*/
	tmp = *a;
	*a = *b;
	*b = tmp;
/*			
	printf("a=%d\n", *a);
	printf("b=%d\n", *b);*/
}
/*
int	main(void)
{
	int	a = 5;
	int	b = 3;

	ft_swap(&a, &b);
	return (0);
}*/
