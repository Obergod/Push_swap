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

void	s(t_circ_buff *c, char n)
{
	int	next;

	if (!c || circ_empty(c))
		return ;
	next = (c->tail + 1) % c->size;
	ft_swap(&c->buff[c->tail], &c->buff[next]);
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
}

void	ss(t_circ_buff *a, t_circ_buff *b)
{

}

void	pa(t_circ_buff *a, t_circ_buff *b)
{
	int	value;

	if (!b)
		return ;
	value = b->buff[b->tail];
	b->tail = (b->tail + 1) % a->size;
	a->tail = prev_pos(a->tail, a->size);
	a->buff[a->tail] = value;
}

void	pb(t_circ_buff *b, t_circ_buff *a)
{
	int	value;

	if (!a)
		return ;
	value = a->buff[a->tail];
	a->tail = (a->tail + 1) % b->size;
	b->tail = prev_pos(b->tail, b->size);
	b->buff[b->tail] = value;
}

void	ra(t_circ_buff *a)
{
	int	i;
	int	next;

	i = -1;
	a->head = a->tail;
	while (++i < a->size - 1)
	{
		next = next_pos(a->head, a->size); 
		ft_swap(&a->buff[a->head], &a->buff[next]);
		a->head = next_pos(a->head, a->size);
	}
}

void	rra(t_circ_buff *a)
{
	int	i;
	int	prev;

	i = -1;
	a->head = prev_pos(a->size - 1, a->size);
	while (++i < a->size)
	{
		prev = prev_pos(a->head, a->size);
		ft_swap(&a->buff[a->head], &a->buff[prev]);
		a->head = next_pos(a->head, a->size);
	}
}
