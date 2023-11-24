/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:43:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/23 15:00:01 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include<unistd.h>

void    putchr(char c, int times)
{
    while (times > 0)
    {
        write(1, &c, 1);
        times--;
    }
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                putchr(av[1][i], (av[1][i] - 64));
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
                putchr(av[1][i], (av[1][i] - 96));
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/*-------------------------OTRA FORMA MAS LARGA---------------------*/
void ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

int main(int ac, char **av)
{
    int i;
    int index;

    i = 0;
    if (ac == 2 && av[1][0] != '\0')
    {
        while (av[1][i] != '\0')
        {
            if (av[1][i] >= 65 && av[1][i] <= 90)
            {
                index = av[1][i] - 64;
                while (index > 0)
                {
                    ft_putchar(av[1][i], 1);
                    index--;
                }
            }
            else if (av[1][i] >= 97 && av[1][i] <= 122)
            {
                index = av[1][i] - 96;
                while (index > 0)
                {
                    ft_putchar(av[1][i], 1);
                    index--;
                }
            }
            else
                ft_putchar(av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
