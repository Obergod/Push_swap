/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:55:35 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/18 18:55:36 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_range(int *data)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = data[i];
	max = data[i];
	while (data[i])
	{
		if (data[i] < min)
			min = data[i];
		if (data[i] > max)
			max = data[i];
		i++;
	}
	return (max - min);
}
// maybe not good
int	sorted(int *data)
{
	int	i;
	int	stock;

	i = 0;
	stock = data[i];
	while (data[i])
	{
		if (stock < data[i] && data[i + 1] < stock)
			return (0);
		if (stock > data[i] && data[i + 1] > stock)
			return (0);
		i++;
	}
	return (1);
}

int	*sort_100(int *data)
{
	int	range;

	range = get_range(data);
	while (!sorted)
}

int	main (int ac, char **av)
{
	t_circ_buff	*data;
	int	*res;
	
	data = get_data(av[1]);
	if (cout_word(av[1]) == 100)
	{
		res = sort_100(data->buff);
	}
}
