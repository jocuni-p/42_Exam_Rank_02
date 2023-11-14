/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:25:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/14 16:59:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
*/


#include<unistd.h>

void    ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

int main(int ac, char **av)
{
    int i = 0;

	if (ac == 2)
	{
    	while (av[1][i] != '\0')
    	{
       		if (av[1][i] >= 65 && av[1][i] <= 90)
            	av[1][i] = av[1][i] + 32;
        	else if (av[1][i] >= 97 && av[1][i] <= 122)
            	av[1][i] = av[1][i] - 32;
			write(1, &av[1][i], 1);
        	i++;
    	}

/*-------------------OTRA MANERA VALIDA---------------------*/
/*
		while (av[1][i] != '\0')
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                ft_putchar(av[1][i] + 32);
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
                ft_putchar(av[1][i] - 32);
            else
                write(1, &av[1][i], 1);
            i++;
        }
*/
	}
    ft_putchar('\n', 1);
   	return (0);
}
