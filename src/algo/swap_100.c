/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:55:35 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/18 18:55:36 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"

t_circ_buff	first_split(t_circ_buff *a, t_circ_buff *b)
{
	t_split_it	split;
	int	nb_read;
	int	p1;
	int	p2;

	split = split_it_init(split);
	get_pivots(a, &p1, &p2);
	while	(nb_read < a->size)
	{
		if (a->buff[a->head] > p2)
		{
			r_ab(a, 'a');
			split.min.size++;
		}
		else if (a->buff[a->head] > p1)
		{
			pb(a, b);
			split.mid.size++;
		}
		else
		{
			pb(a, b);
			r_ab(b, 'b');
			split.max.size++;
		}
		i++;
	}
	return (split);
}

int	*sort_100(t_circ_buff *c)
{
	int	range;

	range = get_range(c);
	while (!sorted(c->buff))
	{

	}
}


int	main (int ac, char **av)
{
	t_circ_buff	*c;
	int	*res;
	
	c = get_data(av[1]);
	if (count_word(av[1]) >= 6)
	{
		res = sort_100(c);
	}
}
