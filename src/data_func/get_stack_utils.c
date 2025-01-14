/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:56:06 by mafioron          #+#    #+#             */
/*   Updated: 2025/01/14 18:56:07 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

int	ft_in_str(char *s, char *to_find)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (to_find[i])
		{
			if (to_find[i] == *s)
				return (1);
			i++;
		}
		i = 0;
		s++;
	}
	return (0);
}

int	only_space(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	*init_and_allocate(t_stacks **stacks, int size)
{
	int	*original_numbers;

	*stacks = stacks_init(size);
	if (!*stacks)
		return (NULL);
	original_numbers = malloc(sizeof(int) * size);
	if (!original_numbers)
	{
		cleanup_stacks(*stacks);
		return (NULL);
	}
	return (original_numbers);
}

void	process_split_numbers(char *str, int **original_numbers)
{
	int		j;
	char	**nb_split;

	j = -1;
	nb_split = ft_split(str, ' ');
	while (nb_split[++j])
		*(*original_numbers)++ = ft_atoi(nb_split[j]);
	free_split(nb_split);
}

int	circ_pop(t_circ_buff *c, int *data)
{
	if (circ_empty(c))
		return (-1);
	*data = c->buff[c->tail];
	c->tail = (c->tail + 1) % c->size;
	return (0);
}
