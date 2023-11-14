/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:19:40 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/11/14 15:53:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list  *sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
    return (a <= b);
} */

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

int ascending(int a, int b)
{
	return (a <= b);
}*/

#include "list.h"

void	swap_contents(t_list *node1, t_list *node2)
{
	int	tmp;

	tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*aux = lst;
	int		flag = 1;

	while (flag == 1)
	{
		flag = 0;
		while (aux->next)
		{
			if (cmp(aux->data, aux->next->data) == 0)
			{
				swap_contents(aux, aux->next);
				flag = 1;
			}
			aux = aux->next;
		}
		aux = lst;
	}
	return (lst);
}
/*
int	main(void)
{
	t_list *c = malloc(sizeof(t_list));
	c->next = 0;
	c->data = 45;

	t_list *b = malloc(sizeof(t_list));
	b->next = c;
	b->data = 18;

	t_list *a = malloc(sizeof(t_list));
	a->next = b;
	a->data = 108;

	t_list *cur = a;
	while (cur)
	{
		printf("%d", cur->data);
		if (cur->next != 0)
			printf(", ");
		cur = cur->next;
	}
	printf("\n");

	cur = sort_list(a, ascending);

	while (cur)
	{
		printf("%d", cur->data);
		if (cur->next != 0)
			printf(", ");
		cur = cur->next;
	}
	printf("\n");
}*/
