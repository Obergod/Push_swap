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
	int	dst;

	if (circ_full(a))
		return ;
	dst = prev_pos(a->tail, a->size);
	a->buff[dst] = b->buff[b->tail];
	a->tail = dst;
	b->tail = next_pos(b->tail, b->size);
	ft_printf("pa\n");
}

void	pb(t_circ_buff *b, t_circ_buff *a)
{
	int	dst;

	if (circ_full(b))
		return ;
	dst = prev_pos(b->tail, b->size);
	b->buff[dst] = a->buff[a->tail];
	b->tail = dst;
	a->tail = next_pos(a->tail, a->size);
	ft_printf("pb\n");
}

void	r_ab(t_circ_buff *c, char stack)
{
	int	first_value;

	if (circ_empty(c) || c->size < 2)
		return ;
	first_value = c->buff[c->tail];
	c->tail = next_pos(c->tail, c->size);
	c->head = next_pos(c->head, c->size);
	c->buff[c->head] = first_value;
	if (stack == 'a')
		ft_printf("ra\n");
	else if (stack == 'b')
		ft_printf("rb\n");
}

void	rr_ab(t_circ_buff *c, char stack)
{
	int	last_value;

	if (circ_empty(c) || c->size < 2)
		return ;
	last_value = c->buff[c->head];
	c->head = prev_pos(c->head, c->size);
	c->tail = prev_pos(c->tail, c->size);
	c->buff[c->tail] = last_value;
	if (stack == 'a')
		ft_printf("rra\n");
	else if (stack == 'b')
		ft_printf("rrb\n");
}
