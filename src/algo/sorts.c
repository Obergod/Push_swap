/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:59:06 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/23 14:59:07 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	sort_five_only(t_stacks *stack, t_chunk *chunk)
{
	int	count;
	int	cur;

	count = 0;
	while (count < 2)
	{
		cur = get_nb(stack, chunk, 1);
		if (cur == 1 || cur == 2)
		{
			pb(&stack->b, &stack->a);
			count++;
		}
		else
			r_ab(&stack->a, 'a');
	}
	sort_three_only(stack, chunk);
	pa(&stack->a, &stack->b);
	pa(&stack->a, &stack->b);
	cur = get_nb(stack, chunk, 1);
	if (cur == 2)
		s_ab(&stack->a, 'a');
}

void	sort_three_only(t_stacks *stack, t_chunk *chunk)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = get_nb(stack, chunk, 1);
	n2 = get_nb(stack, chunk, 2);
	n3 = get_nb(stack, chunk, 3);
	if (n3 > n2 && n2 > n1 && n3 > n1)
		return ;
	else if (n3 > n2 && n3 > n1 && n1 > n2)
		s_ab(&stack->a, 'a');
	else if (n3 > n2 && n1 > n3 && n1 > n2)
		r_ab(&stack->a, 'a');
	else if (n3 < n1 && n1 > n2 && n2 > n3)
	{
		s_ab(&stack->a, 'a');
		rr_ab(&stack->a, 'a');
	}
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		s_ab(&stack->a, 'a');
		r_ab(&stack->a, 'a');
	}
	else if (n3 < n1 && n1 < n2 && n2 > n3)
		rr_ab(&stack->a, 'a');
}

void	two_digit_sort(t_stacks *stack, t_chunk *chunk)
{
	int	n1;
	int	n2;

	if (chunk->loc == BOT_A || chunk->loc == TOP_B || chunk->loc == BOT_B)
	{
		move_from_to(stack, chunk->loc, TOP_A);
		move_from_to(stack, chunk->loc, TOP_A);
	}
	n1 = stack->a.buff[stack->a.tail];
	n2 = stack->a.buff[next_pos(stack->a.tail, stack->a.size)];
	if (n1 > n2)
		s_ab(&stack->a, 'a');
	chunk->size -= 2;
}

void	one_digit_sort(t_stacks *stack, t_chunk *chunk)
{
	if (chunk->loc == BOT_A || chunk->loc == TOP_B || chunk->loc == BOT_B)
		move_from_to(stack, chunk->loc, TOP_A);
	chunk->size -= 1;
}

int	is_sorted(t_circ_buff *a)
{
	int	cur;
	int	next;

	cur = a->tail;
	while (cur < a->size - 1)
	{
		next = next_pos(cur, a->size);
		if (a->buff[cur] > a->buff[next])
			return (0);
		cur = next;
	}
	return (1);
}
