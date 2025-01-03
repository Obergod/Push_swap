/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:24:54 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/22 19:24:58 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"

int	circ_full(t_circ_buff *c)
{
	return ((c->head + 1) % c->size == c->tail);
}

int	circ_empty(t_circ_buff *c)
{
	return (c->head == c->tail);
}

void	ft_swap(int	*a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	prev_pos(int pos, int size)
{
	if (pos == 0)
		return (size - 1);
	return (pos - 1);
}

int	next_pos(int pos, int size)
{
	if (pos == size - 1)
		return (0);
	return (pos + 1);
}
