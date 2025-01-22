/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:24:25 by mafioron          #+#    #+#             */
/*   Updated: 2025/01/17 18:24:26 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_op(t_stacks *stack, char *line)
{
	if (line)
		free(line);
	error(stack);
}

int	checker(t_stacks *stacks, int fd)
{
	char		*line;
	enum e_op	op;

	line = malloc(sizeof(char) * 5);
	if (!line)
		error(stacks);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		op = string_to_op(line);
		call_op(stacks, op);
		if (op == null_op)
			break ;
	}
	if (line)
		free(line);
	return (is_sorted(&stacks->a));
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			fd;

	fd = how_to_stack(&stacks, ac, av);
	if (fd < 0)
	{
		error(stacks);
		return (-1);
	}
	fd = 0;
	if (checker(stacks, fd))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(stacks);
	return (0);
}
