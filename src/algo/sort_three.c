/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:34:04 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/31 18:34:05 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	sort_three(t_stacks *stack, t_chunk *chunk)
{
	t_circ_buff *s;
	int			max;

	s = wich_stack(stack, chunk->loc);
	max = chunk_max(stack, chunk, 3);
	if (chunk->loc == TOP_A)
		sort_three_top_a(stack, chunk, s, max);
	else if (chunk->loc == BOT_A)
		sort_three_bot_a();
	else if (chunk->loc == TOP_B)
		sort_three_top_b();
	else if (chunk->loc == BOT_B)
		sort_three_bot_b();
}

void	sort_three_top_a(t_stacks *stack, t_chunk *chunk, t_circ_buff *a, int max);
{
	int	next;

	next = next_pos(a->tail, a->size);
	if (a->buff[a->tail] == max)
	{
		s_ab(&stack->a, 'a');
		r_ab(&stack->a, 'a');
		s_ab(&stack->a, 'a');
		rr_ab(&stack->a, 'a');
	}
	else if (a->buff[next] == max)
	{
		r_ab(&stack->a, 'a');
		s_ab(&stack->a, 'a');
		rr_ab(&stack->a, 'a');
	}
	two_digit_sort(stack, chunk);
}

/*
void	sort_three_bot_a(t_stacks *stacks, t_chunk *chunk);
{

}

void	sort_three_top_b(t_stacks *stacks, t_chunk *chunk);
{

}

void	sort_three_bot_b(t_stacks *stacks, t_chunk *chunk);
{
 
}
*/








