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

t_circ_buff	*circ_init(int size)
{
	int			*buff;
	t_circ_buff	*c;
	
	c = (t_circ_buff *)malloc(sizeof(t_circ_buff));
	if (!c)
		return (NULL);
	buff = (int *)malloc(sizeof(int) * size);
		if (!buff)
	{
		free(c);
		return (NULL);
	}
	c->buff = buff;
	c->head = 0;
	c->tail = 0;
	c->size = size;
	return (c);
}

t_circ_buff	*get_stack(char *nbr)
{
	char	**nb;
	int		size;
	int		i;
	t_circ_buff *c;

	i = 0;
	nb = ft_split(nbr, ' ');
	size = count_words(nbr, ' ');
	c = circ_init(size + 1);
	while (!circ_full(c))
	{
		circ_push(c, ft_atoi(nb[i]));
		i++;
	}
	free(nb);
	return (c);
}
