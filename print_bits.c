/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:42:29 by joan              #+#    #+#             */
/*   Updated: 2023/10/29 22:57:48 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
//#include <stdlib.h>

void    print_bits(unsigned char octet)
{
    int i = 8;

    while (i--)
    {
        if (octet & (1 << i))
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
}
/*
int main(int ac, char **av)
{
    unsigned int    nbr;

    if (ac == 2)
    {
        nbr = atoi(av[1]);
        print_bits(nbr);
    }
    return (0);
}*/
