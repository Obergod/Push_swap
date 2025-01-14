/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:38 by mafioron          #+#    #+#             */
/*   Updated: 2025/01/13 16:19:40 by mafioron         ###   ########.fr       */
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

t_stacks	*how_to_stack(int *size, int ac, char **av)
{
	char		**nb;
	t_stacks	*stacks;
	int			i;

	i = 0;
	*size = 0;
	while (++i < ac)
		*size += count_words(av[i], ' ');
	i = 0;
	if (ac == 2)
	{
		nb = ft_split(av[1], ' ');
		stacks = get_stack(nb, *size);
		free_split(nb);
	}
	else if (ac > 2)
	{
		stacks = get_stack(av + 1, *size);
	}
	return (stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			size;

	stacks = how_to_stack(&size, ac, av);
	if (!stacks)
		return (1);
	sort(stacks);
	cleanup_stacks(stacks);
	return (0);
}
