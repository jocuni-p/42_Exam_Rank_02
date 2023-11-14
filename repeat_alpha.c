/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:43:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/09/11 16:06:10 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
