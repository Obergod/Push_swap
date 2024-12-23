/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:59:06 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/23 14:59:07 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	sort_top_a(t_stacks *s, t_split_it *split)
{
	int	nb_read;

	nb_read = 0;
		while	(nb_read < s.a->size - 1)
		{
			if (s.a->buff[s.a->tail] > p2)
			{
				r_ab(a, 'a');
				split->min.size++;
			}
			else if (s.a->buff[s.a->tail] > p1)
			{	
				pb(b, a);
				split->mid.size++;
			}
			else
			{
				pb(b, a);
				r_ab(b, 'b');
				split->max.size++;
			}
			nb_read++;
		}
}

void	sort_bot_a(t_stacks *s, t_split_it *split)
{
	int	nb_read;

	nb_read = 0;
	while	(nb_read < split->mi - 1)
	{
		nb_read++;
	}

}
