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


// Either other function or add "if" depending on whre you are to split 
// example : first sort max = BOT_A  mid = TOP_B min = BOT_B
// then sort again max until all split with recursion

void	first_sort(t_stacks *stacks)
{
	t_chunk *basic_chunk;

	basic_chunk.size = stacks.a.size;
	basic_chunk.loc = TOP_A;
	rec_sort(stacks, basic_chunk);
}

int	rec_sort(t_stacks *stacks, t_chunk *chunk)
{
	t_split_it	*split;

	//split = split_it init(a->size)
	if (split->size <= 3)
	{

	}
	sort_it(stacks, &sort_it);

	rec_sort(stacks, &sort_it.max);
	rec_sort(stacks, &sort_it.mid);
	rec_sort(stacks, &sort_it.min);
}

void	sort_it(t_stacks *stacks, t_split_it *split)
{
	int	nb_read;
	int	p1;
	int	p2;

	nb_read = 0;
	get_pivots(stacks.a, &p1, &p2);
	if (split->loc == TOP_A)
		sort_top_a(stacks->a, stacks->b, &split);
	else if (split->loc == TOP_B)
		
}



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
