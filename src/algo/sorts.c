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

t_circ_buff *wich_stack(t_stacks *stack, enum e_loc loc)
{
	if (loc == TOP_A || loc == BOT_A)
		return (&stack->a);
	else
		return (&stack->b);
}


void	sort_three_a(t_stacks *stack, t_chunk *chunk)
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

	n1 = get_nb(stack, chunk, 1);
	n2 = get_nb(stack, chunk, 2);
	if (chunk->loc == BOT_A || chunk->loc == TOP_B || chunk->loc == BOT_B)
	{
		move_from_to(stack, chunk->loc, TOP_A);
		move_from_to(stack, chunk->loc, TOP_A);
	}
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
