/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:50:36 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/19 18:50:39 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"


void	get_min_max(t_circ_buff *a, int *min, int *max)
{
	int	i;

	i = -1;
	*min = a->buff[a->tail];
	*max = a->buff[a->tail];
	while (++i < a->size)
	{
		if (a->buff[a->head] < *min)
			*min = a->buff[a->head];
		if (a->buff[a->head] > *max)
			*max = a->buff[a->head];
		a->head = (a->head + 1) % a->size;
	}
}

int	sorted(int *data)
{
	int	i;
	int	stock;

	i = 0;
//	if (size < 2)
//		return (1);
	while (data[i])
	{
		stock = data[i];
		if (stock < data[i] && data[i + 1] < stock)
			return (0);
		if (stock > data[i] && data[i + 1] > stock)
			return (0);
		i++;
	}
	return (1);
}

void	get_pivots(t_circ_buff *a, int *p1, int *p2)
{
	int	min;
	int	max;
	int	range;

	get_min_max(a, &min, &max);
	range = max - min;

	*p1 = min + (range / 3);
	*p2 = min + ((range * 2) / 3);
}

t_split_it	*split_it_init()
{
	t_split_it	*s;

	s = malloc(sizeof(t_split_it));
	if (!s)
		return (NULL);
	s->min.loc = BOTTOM_B;
	s->min.size = 0;
	s->mid.loc = TOP_B;
	s->mid.size = 0;
	s->max.loc = TOP_A;
	s->max.size = 0;
	return (s);
}
