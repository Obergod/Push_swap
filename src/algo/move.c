/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:21:55 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/22 22:21:56 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	move_from_to(t_stacks *stacks, enum e_loc from, enum e_loc to)
{
	if (from == TOP_A)
		move_from_top_a(stacks, to);
	if (from == BOT_A)
		move_from_bot_a(stacks, to);
	if (from == TOP_B)
		move_from_top_b(stacks, to);
	if (from == BOT_B)
		move_from_bot_b(stacks, to);
}

void	move_from_top_a(t_stacks *stacks, enum e_loc to)
{
	if (to == TOP_B)
		pb(&stacks->b, &stacks->a);
	else if (to == BOT_A)
		r_ab(&stacks->a, 'a');
	else if (to == BOT_B)
	{
		pb(&stacks->b, &stacks->a);
		r_ab(&stacks->b, 'b');
	}
}


void	move_from_bot_a(t_stacks *stacks, enum e_loc to)
{
	if (to == TOP_B)
	{
		rr_ab(&stacks->a, 'a');
		pb(&stacks->b, &stacks->a);
	}
	else if (to == BOT_B)
	{
		rr_ab(&stacks->a, 'a');
		pb(&stacks->b, &stacks->a);
		r_ab(&stacks->b, 'b');
	}
	else if (to == TOP_A)
		rr_ab(&stacks->a, 'a');
}

void	move_from_top_b(t_stacks *stacks, enum e_loc to)
{
	if (to == TOP_A)
		pa(&stacks->a, &stacks->b);
	else if (to == BOT_A)
	{
		pa(&stacks->a, &stacks->b);
		r_ab(&stacks->a, 'a');
	}
	else if (to == BOT_B)
		r_ab(&stacks->b, 'b');
}

void	move_from_bot_b(t_stacks *stacks, enum e_loc to)
{
	if (to == TOP_B)
		rr_ab(&stacks->b, 'b');
	else if (to == TOP_A)
	{
		rr_ab(&stacks->b, 'b');
		pa(&stacks->a, &stacks->b);
	}
	else if (to == BOT_A)
	{
		rr_ab(&stacks->b, 'b');
		pa(&stacks->a, &stacks->b);
		r_ab(&stacks->a, 'a');
	}
}
