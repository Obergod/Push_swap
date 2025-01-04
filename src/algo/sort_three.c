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

void	sort_three(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->loc == TOP_A)
		sort_three_top_a();
	else if (chunk->loc == BOT_A)
		sort_three_bot_a();
	else if (chunk->loc == TOP_B)
		sort_three_top_b();
	else if (chunk->loc == BOT_B)
		sort_three_bot_b();
}

void	sort_three_top_a(t_stacks *stack, t_chunk *chunk);
{
	int	max;
	int	cur;

	cur = stack->a.buff[stack->a.tail];
	max = chunk_max(stack, chunk, 3);
	if (cur == max)
	{
		r_ab(&stack->a, 'a');
		pb(&stack->a, 'a');
		pb(&stack->a, 'a');
		rr_ab(&stack->a, 'a');
		pa(&stack->b, 'b');
		pa(&stack->b, 'b');
	}
	sort_two
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








