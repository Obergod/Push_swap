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
	error = check_errors(av, ac);
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

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int	error;

	if (ac < 2)
		return (-1);
	error = how_to_stack(&stacks, ac, av);
	if (error < 0)
	{
		ft_print_errors(error);
		return (-1);
	}
	if (!stacks)
	{
		ft_putstr_fd("Error : stack uninitialized\n", 2);
		cleanup_stacks(stacks);
		return (-1);
	}
	sort(stacks);
	cleanup_stacks(stacks);
	return (0);
}
