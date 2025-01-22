/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:47:28 by mafioron          #+#    #+#             */
/*   Updated: 2025/01/22 14:47:31 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	how_to_stack(t_stacks **stacks, int ac, char **av)
{
	char		**nb;
	int			i;
	int			error;
	int			size;

	i = 0;
	size = 0;
	while (++i < ac)
		size += count_words(av[i], ' ');
	error = check_errors(av + 1, ac);
	if (error < 0)
		return (error);
	if (ac == 2)
	{
		nb = ft_split(av[1], ' ');
		*stacks = get_stack(nb, size);
		free_split(nb);
	}
	else if (ac > 2)
	{
		*stacks = get_stack(av + 1, size);
	}
	return (0);
}
