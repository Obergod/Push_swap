/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:10:43 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/16 20:10:47 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"

void	s_ab(t_circ_buff *c, char stack)
{
	int	next;

	if (circ_empty(c) || c->size < 2)
		return ;
	next = (c->tail + 1) % c->size;
	ft_swap(&c->buff[c->tail], &c->buff[next]);
	if (stack == 'a')
		ft_printf("sa\n");
	else if (stack == 'b')
		ft_printf("sb\n");
}


void	pa(t_circ_buff *a, t_circ_buff *b)
{
	int	value;

	if (circ_empty(b) || b->size < 2)
		return ;
	circ_pop(b, &value);
	circ_push(a, value);
	ft_printf("pa\n");
}

void	pb(t_circ_buff *b, t_circ_buff *a)
{
	int	value;

	if (circ_empty(a))
		return ;
	circ_pop(a, &value);
	circ_push(b, value);
	ft_printf("pb\n");
}

void	r_ab(t_circ_buff *c, char stack)
{
	int	next;
	int	cur;

	cur = c->tail;
	while (cur != c->head && c->size >= 2)
	{
		next = next_pos(cur, c->size);
		ft_swap(&c->buff[cur], &c->buff[next]);
		cur = next_pos(cur, c->size);
	}
	if (stack == 'a')
		ft_printf("ra\n");
	else if (stack == 'b')
		ft_printf("rb\n");
}

void	rr_ab(t_circ_buff *c, char stack)
{
	int	prev;
	int	cur;

	cur = c->head;
	while (cur != c->tail && c->size >= 2)
	{
		prev = prev_pos(cur, c->size);
		ft_swap(&c->buff[cur], &c->buff[prev]);
		cur = prev_pos(cur, c->size);
	}
	if (stack == 'a')
		ft_printf("rra\n");
	else if (stack == 'b')
		ft_printf("rrb\n");
}
