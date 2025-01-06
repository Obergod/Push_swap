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
	t_chunk basic_chunk;

	basic_chunk.size = stacks->a.size;
	basic_chunk.loc = TOP_A;
	rec_sort(stacks, &basic_chunk);
}

void	split_loc (enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOT_B;
		mid->loc = TOP_B;
		max->loc = BOT_A;
	}
	else if (loc == BOT_A)
	{
		min->loc = BOT_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOT_B;
		mid->loc = BOT_A;
		max->loc = TOP_A;
	}
	else if (loc == BOT_B)
	{
		min->loc = TOP_B;
		mid->loc = BOT_A;
		max->loc = TOP_A;
	}
}

void	size_init(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	rec_sort(t_stacks *stacks, t_chunk *chunk)
{
	t_split_it	split;

	if (chunk->size <= 3)
	{
		if (chunk->size == 3)
			sort_three(stacks, chunk);
		else if (chunk->size == 2)
			two_digit_sort(stacks, chunk);
		else if (chunk->size == 1)
			one_digit_sort(stacks, chunk);
		return ;
	}
	sort_it(stacks, &split, chunk);

	rec_sort(stacks, &split.max);
	rec_sort(stacks, &split.mid);
	rec_sort(stacks, &split.min);
}

void	sort_it(t_stacks *stacks, t_split_it *split, t_chunk *chunk)
{
	int	p1;
	int	p2;
	int	next;
	
	size_init(&split->min, &split->mid, &split->max);
	split_loc (chunk->loc, &split->min, &split->mid, &split->max);
	get_pivots(stacks, chunk->size, chunk->loc, &p1, &p2);
	printf("p1 %d, p2 %d\n", p1, p2);
	while (chunk->size-- > 0)
	{
		printf("size %d\n", chunk->size);
		next = get_nb(stacks, chunk, 1);
		printf("nb %d\n", next);
		if (next > p2)
		{
			move_from_to(stacks, chunk->loc, split->max.loc);
			split->max.size++;
		}
		else if (next > p1)
		{
			move_from_to(stacks, chunk->loc, split->mid.loc);
			split->mid.size++;
		}
		else
		{
			move_from_to(stacks, chunk->loc, split->min.loc);
			split->min.size++;
		}
	}
}



int	main (int ac, char **av)
{
	t_stacks	*stacks;
	//t_split_it	*split;
	int		size;
	char	**nb;
	
	if (ac == 2)
	{
		size = count_words(av[1], ' ');
		nb = ft_split(av[1], ' ');
		stacks = get_stack(nb, size);
	}
	if (ac > 2)
	{
		size = ac - 1;
		stacks = get_stack(av + 1, size);
	}
	if (size >= 6)
		first_sort(stacks);
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
