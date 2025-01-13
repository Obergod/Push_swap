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

void	get_pivots(enum e_loc loc, int size, int *p1, int *p2)
{
	*p2 = size / 3;
	if (loc == TOP_A || loc == BOT_A)
		*p1 = 2 * size / 3;
	else if (loc == TOP_B || loc == BOT_B)
		*p1 = size / 2;
}

int	chunk_max(t_stacks *stack, t_chunk *chunk, int size)
{
	int	max;
	int	i;
	int	cur;

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
	int			value;
	t_circ_buff	*s;

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

t_circ_buff	*wich_stack(t_stacks *stack, enum e_loc loc)
{
	if (loc == TOP_A || loc == BOT_A)
		return (&stack->a);
	else
		return (&stack->b);
}

void	size_init(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}
