/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:55:35 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/18 18:55:36 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	t_chunk	first_chunk;

	first_chunk.size = stacks->a.size;
	first_chunk.loc = TOP_A;
	if (first_chunk.size == 1 || is_sorted(&stacks->a))
		return ;
	else if (first_chunk.size == 3)
		sort_three_only(stacks, &first_chunk);
	else if (first_chunk.size == 5)
		sort_five_only(stacks, &first_chunk);
	else
		rec_sort(stacks, &first_chunk);
}

void	split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOT_B;
		mid->loc = TOP_B;
		max->loc = BOT_A;
	}
	else if (loc == BOT_A)
	{
		min->loc = BOT_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOT_B;
		mid->loc = BOT_A;
		max->loc = TOP_A;
	}
	else if (loc == BOT_B)
	{
		min->loc = TOP_B;
		mid->loc = BOT_A;
		max->loc = TOP_A;
	}
}

void	rec_sort(t_stacks *stacks, t_chunk *chunk)
{
	t_split_it	split;

	if (chunk->loc == BOT_B && chunk->size == stacks->b.size)
		chunk->loc = TOP_B;
	else if (chunk->loc == BOT_A && chunk->size == stacks->a.size)
		chunk->loc = TOP_A;
	if (chunk->size <= 3)
	{
		if (chunk->size == 3)
			sort_three(stacks, chunk);
		if (chunk->size == 2)
			two_digit_sort(stacks, chunk);
		else if (chunk->size == 1)
			one_digit_sort(stacks, chunk);
		return ;
	}
	sort_it(stacks, &split, chunk);
	rec_sort(stacks, &split.max);
	rec_sort(stacks, &split.mid);
	rec_sort(stacks, &split.min);
}

void	sort_it(t_stacks *stacks, t_split_it *split, t_chunk *chunk)
{
	int	p1;
	int	p2;
	int	next;
	int	max;

	size_init(&split->min, &split->mid, &split->max);
	split_loc(chunk->loc, &split->min, &split->mid, &split->max);
	get_pivots(chunk->loc, chunk->size, &p1, &p2);
	max = chunk_max(stacks, chunk, chunk->size);
	while (chunk->size-- > 0)
	{
		next = get_nb(stacks, chunk, 1);
		if (next > max - p2)
			split->max.size += move_from_to(stacks, chunk->loc, split->max.loc);
		else if (next > max - p1)
			split->mid.size += move_from_to(stacks, chunk->loc, split->mid.loc);
		else
			split->min.size += move_from_to(stacks, chunk->loc, split->min.loc);
	}
}
