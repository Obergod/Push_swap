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
		sort_three_bot_a(stack, chunk, s, max);
	else if (chunk->loc == TOP_B)
		sort_three_top_b(stack, chunk, s, max);
	else if (chunk->loc == BOT_B)
		sort_three_bot_b(stack, chunk, s, max);
}

void	sort_three_top_a(t_stacks *stack, t_chunk *chunk, t_circ_buff *a, int max)
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
	chunk->size -= 1;
	two_digit_sort(stack, chunk);
}

void	sort_three_bot_a(t_stacks *stack, t_chunk *chunk, t_circ_buff *a, int max)
{
	int	next;

	next = next_pos(a->tail, a->size);
	rr_ab(&stack->a, 'a');
	rr_ab(&stack->a, 'a');
	if (a->buff[a->tail] == max)
	{
		s_ab(&stack->a, 'a');
		rr_ab(&stack->a, 'a');
	}
	else if (a->buff[next] == max)
		rr_ab(&stack->a, 'a');
	else
	{
		pb(&stack->b, &stack->a);
		rr_ab(&stack->a, 'a');
		s_ab(&stack->a, 'a');
		pa(&stack->a, &stack->b);
	}
	chunk->loc = TOP_A;
	chunk->size -= 1;
	two_digit_sort(stack, chunk);
}
void	sort_three_top_b(t_stacks *stack, t_chunk *chunk, t_circ_buff *b, int max)
{
	int	next;

	next = next_pos(b->tail, b->size);
	pa(&stack->a, &stack->b);
	if (b->buff[b->tail] == max)
	{
		pa(&stack->a, &stack->b);
		s_ab(&stack->a, 'a');
	}
	else if (b->buff[next] == max)
	{
		s_ab(&stack->b, 'b');
		pa(&stack->a, &stack->b);
		s_ab(&stack->a, 'a');
	}
	else
		pa(&stack->a, &stack->b);
	pa(&stack->a, &stack->b);
	chunk->loc = TOP_A;
	chunk->size -= 1;
	two_digit_sort(stack, chunk);
}

void	sort_three_bot_b(t_stacks *stack, t_chunk *chunk, t_circ_buff *b, int max)
{
	int	next;

	next = next_pos(b->tail, b->size);
	rr_ab(&stack->b, 'a');
	rr_ab(&stack->b, 'a');
	if (b->buff[b->tail] == max)
	{
		pa(&stack->a, &stack->b);
		rr_ab(&stack->b, 'a');
	}
	else if (b->buff[next] == max)
	{
		s_ab(&stack->b, 'b');
		pa(&stack->a, &stack->b);
		rr_ab(&stack->b, 'a');
	}
	else
	{
		rr_ab(&stack->b, 'a');
		pa(&stack->a, &stack->b);
	}
	chunk->loc = TOP_B;
	chunk->size -= 1;
	two_digit_sort(stack, chunk);
}








