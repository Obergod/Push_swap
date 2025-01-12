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


void	get_min_max(t_circ_buff *c, t_chunk *chunk, int *min, int *max)
{
	int	cur;
	int	i;

	i = -1;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		cur = c->tail;
	else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
		cur = c->head;
	*min = c->buff[cur];
	*max = c->buff[cur];
	while (++i < chunk->size)
	{
		if (c->buff[cur] < *min)
			*min = c->buff[cur];
		if (c->buff[cur] > *max)
			*max = c->buff[cur];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			cur = next_pos(cur, c->size);
		else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
			cur = prev_pos(cur, c->size);
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

void	get_pivots(t_stacks *stack, t_chunk *chunk, int *p1, int *p2)
{
	int	min;
	int	max;
	int	range;

	if (chunk->loc == TOP_A || chunk->loc == BOT_A)
		get_min_max(&stack->a, chunk, &min, &max);
	else if (chunk->loc == TOP_B || chunk->loc == BOT_B)
		get_min_max(&stack->b, chunk, &min, &max);
	
	range = max - min;
	
	if (chunk->loc == TOP_A || chunk->loc == BOT_A)
	{
		*p2 = max - (range / 3);
		*p1 = max - ((2 * range) / 3);
	}
	else if (chunk->loc == TOP_B || chunk->loc == BOT_B)
	{
		*p2 = min + ((2 * range) / 3);
		*p1 = min + (range / 3);
	}
}



int chunk_max(t_stacks *stack, t_chunk *chunk, int size)
{
    int max;
    int i;
    int cur;

    i = 0;
    max = get_nb(stack, chunk, 1);
    while (++i < size)
    {
        cur = get_nb(stack, chunk, i + 1);
        if (cur > max)
            max = cur;
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
			value = next_pos(value, s->size);
	}
	else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
	{
		value = s->head;
		while (--i > 0)
			value = prev_pos(value, s->size);
	}
	return (s->buff[value]);
}

int	is_chunk_sorted(t_stacks *stacks, t_chunk *chunk)
{
	int	i;
	int	current;
	int	next;

	if (chunk->loc != TOP_A && chunk->loc != BOT_A)
		return (0);
	
	if (chunk->size <= 1)
		return (1);
	
	i = 1;
	while (i < chunk->size)
	{
		current = get_nb(stacks, chunk, i);
		next = get_nb(stacks, chunk, i + 1);
		if (current > next)
			return (0);
		i++;
	}
	return (1);
}

int current_size(t_circ_buff *c)
{
    if (c->head >= c->tail)
        return (c->head - c->tail);
    return (c->size - (c->tail - c->head));
}
