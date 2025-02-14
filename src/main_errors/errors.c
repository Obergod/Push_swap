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

void	ft_print_errors(int error)
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
		if (nb_long < INT_MIN || nb_long > INT_MAX)
			return (-1);
		while (nb[++j])
		{
			if (nb_long == ft_atol(nb[j]))
				return (-2);
		}
	}
	return (0);
}

static int	check_char_errors(char **nb, int ac)
{
	int	i;
	int	j;

	i = -1;
	while (nb[++i])
	{
		j = -1;
		while (nb[i][++j])
		{
			if (!ft_isdigit(nb[i][j]) && nb[i][j] != ' ' && nb[i][j] != '-')
			{
				if (ac == 2)
					free_split(nb);
				return (-3);
			}
			if (nb[i][j] == '-' && nb[i][j + 1] == '-')
			{
				if (ac == 2)
					free_split(nb);
				return (-3);
			}
		}
	}
	return (0);
}

int	check_errors(char **av, int ac)
{
	int		error;
	char	**nb;

	nb = av;
	if (ac == 2)
		nb = ft_split(av[0], ' ');
	if (!nb)
		return (-1);
	error = check_char_errors(nb, ac);
	if (error)
		return (error);
	error = check_nb_errors(nb);
	if (ac == 2)
		free_split(nb);
	return (error);
}
