/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:50:36 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/19 18:50:39 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"


void	get_min_max(t_circ_buff *c, int *min, int *max)
{
	int	i;

	i = -1;
	*min = c->buff[c->tail];
	*max = c->buff[c->tail];
	while (++i < c->size)
	{
		if (c->buff[c->head] < *min)
			*min = c->buff[c->head];
		if (c->buff[c->head] > *max)
			*max = c->buff[c->head];
		c->head = (c->head + 1) % c->size;
	}
}

int	sorted(int *data)
{
	int	i;
	int	stock;

	i = 0;
//	if (size < 2)
//		return (1);
	while (data[i])
	{
		stock = data[i];
		if (stock < data[i] && data[i + 1] < stock)
			return (0);
		if (stock > data[i] && data[i + 1] > stock)
			return (0);
		i++;
	}
	return (1);
}

void	get_pivots(t_stacks *stack, enum e_loc loc, int *p1, int *p2)
{
	int	min;
	int	max;
	int	range;

	if (loc == TOP_A || loc == BOT_A)
		get_min_max(&stack->a, &min, &max);
	else if (loc == TOP_B || loc == BOT_B)
		get_min_max(&stack->b, &min, &max);
	range = max - min;

	*p1 = min + (range / 3);
	*p2 = min + ((range * 2) / 3);
}
/*
t_split_it	*split_it_init()
{
	t_split_it	*s;

	s = malloc(sizeof(t_split_it));
	if (!s)
		return (NULL);
	s->min.loc = BOTTOM_B;
	s->min.size = 0;
	s->mid.loc = TOP_B;
	s->mid.size = 0;
	s->max.loc = TOP_A;
	s->max.size = 0;
	return (s);
}*/
