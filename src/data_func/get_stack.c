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
#include <stdio.h>
#include <stdlib.h>

int	circ_push(t_circ_buff *c, int data)
{
	if (circ_full(c))
		return (-1);
	c->buff[c->head] = data;
	c->head = (c->head + 1) % c->size;
	return (0);
}

int	circ_pop(t_circ_buff *c, int *data)
{
	if (circ_empty(c))
		return (-1);
	*data = c->buff[c->tail];
	c->tail = (c->tail + 1) % c->size;
	return (0);
}

t_stacks	*stacks_init(int size)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	circ_init(size, &stacks->a);
	circ_init(size, &stacks->b);
	if (!&stacks->a || !&stacks->b)
	{
		free(stacks);
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

t_stacks	*get_stack(char **nbr, int size)
{
	int			i;
	t_stacks	*stacks;
	int			*original_numbers;

	i = 0;
	stacks = stacks_init(size);
	if (!stacks)
		return (NULL);
	original_numbers = malloc(sizeof(int) * size);
	if (!original_numbers)
	{
		free(stacks);
		return (NULL);
	}
	while (nbr[i])
	{
		original_numbers[i] = ft_atoi(nbr[i]);
		i++;
	}
	random_to_rank(original_numbers, stacks->a.buff, size);
	free(original_numbers);
	stacks->a.head = size - 1;
	return (stacks);
}
