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

void	error(t_stacks *stack)
{
	if (stack->a.buff)
		free(stack->a.buff);
	if (stack->b.buff)
		free(stack->b.buff);
	ft_putendl_fd("Error", 2);
}

void	pa_no_print(t_circ_buff *a, t_circ_buff *b)
{
	int	dst;

	if (circ_full(a))
		return ;
	dst = prev_pos(a->tail, a->size);
	a->buff[dst] = b->buff[b->tail];
	a->tail = dst;
	b->tail = next_pos(b->tail, b->size);
}

void	pb_no_print(t_circ_buff *b, t_circ_buff *a)
{
	int	dst;

	if (circ_full(b))
		return ;
	dst = prev_pos(b->tail, b->size);
	b->buff[dst] = a->buff[a->tail];
	b->tail = dst;
	a->tail = next_pos(a->tail, a->size);
}

enum e_op	string_to_op(char *str)
{
	if (!ft_strcmp(str, "pa") || !ft_strcmp(str, "pa\n"))
		return (epa);
	else if (!ft_strcmp(str, "pb") || !ft_strcmp(str, "pb\n"))
		return (epb);
	else if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rra\n"))
		return (rra);
	else if (!ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrb\n"))
		return (rrb);
	else if (!ft_strcmp(str, "rrr") || !ft_strcmp(str, "rrr\n"))
		return (errr);
	else if (!ft_strcmp(str, "ra") || !ft_strcmp(str, "ra\n"))
		return (ra);
	else if (!ft_strcmp(str, "rb") || !ft_strcmp(str, "rb\n"))
		return (rb);
	else if (!ft_strcmp(str, "rr") || !ft_strcmp(str, "rr\n"))
		return (err);
	else if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sa\n"))
		return (sa);
	else if (!ft_strcmp(str, "sb") || !ft_strcmp(str, "sb\n"))
		return (sb);
	else if (!ft_strcmp(str, "ss") || !ft_strcmp(str, "ss\n"))
		return (ess);
	else
		return (null_op);
}

void	call_op(t_stacks *stack, enum e_op op)
{
	if (op == epa)
		pa_no_print(&stack->a, &stack->b);
	else if (op == epb)
		pb_no_print(&stack->b, &stack->a);
	else if (op == rra)
		rr_ab(&stack->a, 'n');
	else if (op == rrb)
		rr_ab(&stack->b, 'n');
	else if (op == errr)
		rrr(&stack->a, &stack->b, 'n');
	else if (op == ra)
		r_ab(&stack->a, 'n');
	else if (op == rb)
		r_ab(&stack->b, 'n');
	else if (op == err)
		rr(&stack->a, &stack->b, 'n');
	else if (op == sa)
		s_ab(&stack->a, 'n');
	else if (op == sb)
		s_ab(&stack->b, 'n');
	else if (op == ess)
		ss(&stack->a, &stack->b, 'n');
	else
		error(stack);
}
