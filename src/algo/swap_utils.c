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
	int	cur;

	cur = c->tail;
	*min = c->buff[cur];
	*max = c->buff[cur];
	while (cur != c->head)
	{
		if (c->buff[cur] < *min)
			*min = c->buff[cur];
		if (c->buff[cur] > *max)
			*max = c->buff[cur];
		cur = next_pos(cur, c->size);
	}
}
//         --A REFAIRE--
/*
int	sorted(t_circ_buff *stack)
{
	int	i;
	int	stock;

	i = 0;
//	if (size < 2)
//		return (1);
	while (data[i])
	{
		stock = [i];
		if (stock < data[i] && data[i + 1] < stock)
			return (0);
		if (stock > data[i] && data[i + 1] > stock)
			return (0);
		i++;
	}
	return (1);
}
*/
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

int	chunk_max(t_stacks *stack, t_chunk *chunk, int i)
{
	int	max;
	int	cur;
	t_circ_buff *s;

	s = wich_stack(stack, chunk->loc);
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
	{
		cur = s->tail;
		max = s->tail;
	}
	else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
	{
		cur = s->head;
		max = s->head;
	}
	while (--i > 0)
	{
		if (max < s->buff[cur])
			max = s->buff[cur];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			next_pos(s->size, cur);
		else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
			prev_pos(s->size, cur);
	}
	return (max);
}

int	get_nb(t_stacks *stack, t_chunk *chunk, int i)
{
	int	value;
	t_circ_buff *s;

	s = wich_stack(stack, chunk->loc);
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
	{
		value = s->tail;
		while (--i > 0)
			next_pos(s->size, value);
	}
	else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
	{
		value = s->head;
		while (--i > 0)
			prev_pos(s->size, value);
	}
	return (s->buff[value]);
}
