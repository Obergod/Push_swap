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

void	sa(t_circ_buff *a)
{
	int	next;

	if (!a || circ_empty(a))
		return ;
	next = (a->tail + 1) % a->size;
	ft_swap(&a->buff[a->tail], &a->buff[next]);
}

void	pa(t_circ_buff *a, t_circ_buff *b)
{
	int	value;

	if (!a || !b || )
		return ;
	value = b->buff[b->tail];
	b->tail = (b->tail + 1) % a->size;
	a->tail = prev_pos(a->tail, a->size);
	a->buff[a->tail] = value;
}
