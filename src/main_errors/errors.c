/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:51 by mafioron          #+#    #+#             */
/*   Updated: 2025/01/15 13:37:54 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"
#include "push_swap.h"

void	ft_print_errors(int	error)
{
	ft_putstr_fd("Error : ", 2);
	if (error == -1)
		ft_putstr_fd("More than integer\n", 2);
	else if (error == -2)
		ft_putstr_fd("duplicate digit\n", 2);
	else if (error == -3)
		ft_putstr_fd("Invalid args\n", 2);
}

int	check_nb_errors(char **nb)
{
	int		i;
	int		j;
	long	nb_long;

	i = -1;
	while (nb[++i])
	{
		j = i;
		nb_long = ft_atol(nb[i]);
		if (nb_long < INT_MIN ||nb_atol > INT_MAX)
			return (-1);
		while (nb[++j])
			if (nb[i] == nb[j])
				return (-2);
	}
	return (0);
}

int	check_errors(char **av, int ac)
{
	int		i;
	int		j;
	int		error;
	char	**nb;

	j = -1;
	i = 0;
	error = 0;
	nb = av;
	if (ac == 2)
		nb = ft_split(av[1], ' ');
	while (nb[++i])
	{
		while (nb[i][++j])
		{
			if (!ft_isdigit(nb[i][j]) && nb[i][j] != ' ' && nb[i][j] != '-')
				return (-3);
		}
	}
	error = check_nb_errors(nb);
	return (error);
}
