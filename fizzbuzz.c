/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:53:58 by joan              #+#    #+#             */
/*   Updated: 2023/11/23 12:05:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> */

#include<unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    int i;

    i = 1;
    while (i <= 100)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write(1, "fizz\n", 5);
        else if (i % 5 == 0)
            write(1, "buzz\n", 5);
        else
        {
            if (i < 10)
            {
                ft_putchar(i + '0');
                write(1, "\n", 1);
            }
            else
            {
                ft_putchar(i / 10 + '0');
                ft_putchar(i % 10 + '0');
                write(1, "\n", 1);
            }
        }
        i++;
    }
}
/*-----------------OTRA OPCION---------------*/

int main(void)
{
    int i = 1;
    int j = 0;
    int k = 0;

    while (i <= 100)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else if (i > 10)
        {
            j = i / 10 + '0';
            k = i % 10 + '0';
            write(1, &j, 1);
            write(1, &k, 1);
        }
        else
        {
            j = i + '0';
            write(1, &j, 1);
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}

