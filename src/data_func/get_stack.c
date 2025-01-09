/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:02 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/14 16:55:04 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include <stdlib.h>
#include <stdio.h>


int	circ_push(t_circ_buff *c, int data)
{
	if (circ_full(c))
		return(-1);
	c->buff[c->head] = data;
	c->head = (c->head + 1) % c->size;
	return (0);
}


int	circ_pop(t_circ_buff *c, int *data)
{
	if (circ_empty(c))
		return (-1);
	*data = c->buff[c->tail];
    c->tail = (c->tail + 1) % c->size;
    return (0);
}

void	circ_init(int size, t_circ_buff *c)
{
	
	c->buff = (int *)malloc(sizeof(int) * size);
	if (!c->buff)
		return ;
	c->head = 0;
	c->tail = 0;
	c->size = size;
}

t_stacks	*stacks_init(int size)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	circ_init(size, &stacks->a);
	circ_init(size, &stacks->b);
	if (!&stacks->a || !&stacks->b)
	{
		free(stacks);
		return (NULL);
	}
	return (stacks);
}

t_stacks	*get_stack(char **nbr, int size)
{
	int		i;
	t_stacks	*stacks;

	i = 0;
	stacks = stacks_init(size);
	while (nbr[i])
	{
		stacks->a.buff[i] = ft_atoi(nbr[i]);
		i++;
	}
	/*i = 0;
	while (i < size)
	{
		printf("stack %d\n", stacks->a.buff[i]);
		i++;
	}*/
	stacks->a.head = size - 1;
	return (stacks);
}
