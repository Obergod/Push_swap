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

	*p1 = min + (range / 3);
	*p2 = min + ((range * 2) / 3);
}

/*
void	set_third_pivots(enum e_loc loc, int crt_size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = crt_size / 3;
	if (loc == TOP_A || loc == BOT_A)
		*pivot_1 = 2 * crt_size / 3;
	if (loc == TOP_B || loc == BOT_B)
		*pivot_1 = crt_size / 2;
	if ((loc == TOP_A || loc == BOT_A) && crt_size < 15)
		*pivot_1 = crt_size;
	if (loc == BOT_B && crt_size < 8)
		*pivot_2 = crt_size / 2;
}
*/
int	chunk_max(t_stacks *stack, t_chunk *chunk, int i)
{
	int	max;
	int	cur;
	t_circ_buff *s;

	s = wich_stack(stack, chunk->loc);
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
	{
		cur = s->tail;
		max = s->buff[cur];
	}
	else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
	{
		cur = s->head;
		max = s->buff[cur];
	}
	while (i-- > 0)
	{
		if (max < s->buff[cur])
			max = s->buff[cur];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			cur = next_pos(cur, s->size);
		else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
			cur = prev_pos(cur, s->size);
	}
	return (max);
}

int	get_nb(t_stacks *stack, t_chunk *chunk, int i)
{
	int	value;
	t_circ_buff *s;

	s = wich_stack(stack, chunk->loc);
printf("DEBUG: chunk loc=%d, chunk size=%d, stack head=%d, tail=%d\n",
           chunk->loc, chunk->size, s->head, s->tail);

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
	printf("DEBUG: value=%d\n", value);
	printf("DEBUG: Returning buff[%d] = %d\n", value, s->buff[value]);
	return (s->buff[value]);
}
