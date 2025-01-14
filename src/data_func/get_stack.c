/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:02 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/14 16:55:04 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	circ_init(int size, t_circ_buff *c)
{
	int	i;

	i = -1;
	c->buff = (int *)malloc(sizeof(int) * size);
	if (!c->buff)
		return ;
	c->head = 0;
	c->tail = 0;
	c->size = size;
	while (++i < size)
		c->buff[i] = 0;
}

t_stacks	*stacks_init(int size)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	circ_init(size, &stacks->a);
	circ_init(size, &stacks->b);
	if (!stacks->a.buff || !stacks->b.buff)
	{
		cleanup_stacks(stacks);
		return (NULL);
	}
	return (stacks);
}

void	random_to_rank(int *numbers, int *rank, int size)
{
	int	i;
	int	j;
	int	count_smaller;

	i = -1;
	while (++i < size)
	{
		j = -1;
		count_smaller = 0;
		while (++j < size)
			if (numbers[j] <= numbers[i])
				count_smaller++;
		rank[i] = count_smaller;
	}
}

void	cleanup_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		free(stacks->a.buff);
		free(stacks->b.buff);
		free(stacks);
	}
}

t_stacks	*get_stack(char **nbr, int size)
{
	int			i;
	int			*stock;
	t_stacks	*stacks;
	int			*original_numbers;

	i = 0;
	original_numbers = init_and_allocate(&stacks, size);
	if (!original_numbers)
		return (NULL);
	stock = original_numbers;
	while (nbr[i])
	{
		if (!only_space(nbr[i]))
			process_split_numbers(nbr[i], &original_numbers);
		i++;
	}
	random_to_rank(stock, stacks->a.buff, size);
	free(stock);
	stacks->a.head = size - 1;
	return (stacks);
}
