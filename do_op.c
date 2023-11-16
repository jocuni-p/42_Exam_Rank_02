/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:59:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/16 10:29:08 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : do_op
Expected files   : do_op.c
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/

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
