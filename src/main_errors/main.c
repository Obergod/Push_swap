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

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			error;

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
