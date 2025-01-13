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

t_stacks	*how_to_stack(int *size, int ac, char **av)
{
	char		**nb;
	t_stacks	*stacks;

	if (ac == 2)
	{
		*size = count_words(av[1], ' ');
		nb = ft_split(av[1], ' ');
		stacks = get_stack(nb, *size);
	}
	if (ac > 2)
	{
		*size = ac - 1;
		stacks = get_stack(av + 1, *size);
	}
	return (stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			size;

	stacks = how_to_stack(&size, ac, av);
	if (ac > 1)
		sort(stacks);
	return (0);
}
