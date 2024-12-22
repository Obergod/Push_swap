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
#include "push_swap.h" 


// Either other function or add if in function of whre you are to split 
// example : first sort max = BOP_A  mid = TOP_B min = BOT_B
// then sort again max until all split with recursion
t_split_it	*first_split(t_circ_buff *a, t_circ_buff *b)
{
	t_split_it	*split;
	int	nb_read;
	int	p1;
	int	p2;

	nb_read = 0;
	split = split_it_init();
	get_pivots(a, &p1, &p2);
	while	(nb_read < a->size - 1)
	{
		if (a->buff[a->tail] > p2)
		{
			r_ab(a, 'a');
			split->min.size++;
		}
		else if (a->buff[a->tail] > p1)
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
	return (split);
}
/*
int	*sort_100(t_circ_buff *a, t_circ_buff *b)
{
}
*/

int	main (int ac, char **av)
{
	t_stacks	*stacks;
	//t_split_it	*split;
	int	size;

	size = count_words(av[1], ' ');
	stacks = get_stack(av[1]);
	if (ac > 1)
	{
		if (size >= 6)
		{
			first_split(stacks->a, stacks->b);
		}
	}
}
/*****		RECURSIVE SORT EX		*****/
/*
		void recursive_chunk_sort(t_chunk *chunk_to_sort)
		{
			if (base_case == true)
		  	{
		    perform_very_simple_sort();
		    return;
	  		}
	 
		 	split_chunk(chunk_to_sort, &split_chunks);
		 
			 recursive_chunk_sort(&split_chunks.max);
			 recursive_chunk_sort(&split_chunks.mid);
		 	 recursive_chunk_sort(&split_chunks.min);
		}
*/
