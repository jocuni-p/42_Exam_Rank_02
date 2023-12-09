/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:51:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/12/09 23:12:02 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i])
            i++;
        i -= 1;
        while (i >= 0)
        {
            write(1, &av[1][i], 1);
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/*-------------ALTERNATIVE------------------*/
int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac != 2)
        return (write(1, "\n", 1));
    while (av[1][i] != '\0')
        i++;
    while (i > 0)
    {
        write(1, &av[1][i - 1], 1);
        i--;
    }
    write(1, "\n", 1);
    return (0);
}

