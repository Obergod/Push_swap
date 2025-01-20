/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:24:12 by mafioron          #+#    #+#             */
/*   Updated: 2025/01/17 18:24:15 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

enum e_op	string_to_op(const char *str)
{
	if (!ft_strcmp(str, "pa"))
		return (pa);
	else if (!ft_strcmp(str, "pb"))
		return (pb);
	else if (!ft_strcmp(str, "rra"))
		return (rra);
	else if (!ft_strcmp(str, "rrb"))
		return (rrb);
	else if (!ft_strcmp(str, "rrr"))
		return (rrr);
	else if (!ft_strcmp(str, "ra"))
		return (ra);
	else if (!ft_strcmp(str, "rb"))
		return (rb);
	else if (!ft_strcmp(str, "rr"))
		return (rr);
	else if (!ft_strcmp(str, "sa"))
		return (sa);
	else if (!ft_strcmp(str, "sb"))
		return (sb);
	else if (!ft_strcmp(str, "ss"))
		return (ss);
	else
		return (null_op);
}

void	call_op(t_stacks *stack, enum e_op op)
{
	if (op == pa)
		push_a(data);
	else if (op == pb)
		push_b(data);
	else if (op == rra)
		rr_ab(&stack->a, 'n');
	else if (op == rrb)
		rr_ab(&stack->b, 'n');
	else if (op == rrr)
		rrr(&stack->a, &stack->b, 'n');
	else if (op == ra)
		r_ab(&stack->a, 'n');
	else if (op == rb)
		r_ab(&stack->b, 'n');
	else if (op == rr)
		rr(&stack->a, &stack->b, 'n');
	else if (op == sa)
		s_ab(&stack->a, 'n');
	else if (op == sb)
		s_ab(&stack->b, 'n');
	else if (op == ss)
		ss(&stack->a, &stack->b, 'n');
	else
		error(data);
}
