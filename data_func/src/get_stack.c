/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:02 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/14 16:55:04 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "full_libft.h"
#include "data_func.h"
#include <stdlib.h>
// use count_words ? or modify split to make an int *
int	circ_push(t_circ_buff *c, int data)
{
	int	next;

	next = c->head + 1;
	if (next >= c->size)
		next = 0;
	if (next == c->tail)
		return (-1);
	c->buff[c->head] = data;
	c->head = next;
	return (0);
}

int	circ_buf_pop(t_circ_buff *c, int *data)
{
	int	next;

	if (c->head == c->tail)
		return (-1);
	next = c->tail + 1;
	if (next >= c->size)
		next = 0;

	*data = c->buff[c->tail];  // Read data and then move
    c->tail = next;              // tail to next offset.
    return (0);  // return success to indicate successful push.
}

//int	circ_full()

t_circ_buff	*circ_init(int size)
{
	int			*buff;
	t_circ_buff	*c;
	
	c = (t_circ_buff *)malloc(sizeof(t_circ_buff));
	if (!c)
		return (NULL);
	buff = (int *)malloc(sizeof(int) * size);
		if (!buff)
		{
			free(c);
			return (NULL);
		}
	c->buff = buff;
	c->head = 0;
	c->tail = 0;
	c->size = size;
	return (c);
}

t_circ_buff	*get_stack(char *nbr)
{
	char	**nb;
	int		size;
	int		i;
	t_circ_buff *c;

	nb = ft_split(nbr);
	size = count_words(nbr, ' ');
	c = circ_init(size);
	while (nb[i])
	{
		circ_push(c, ft_atoi(nb[i]));
		i++;
	}
	return (c);
}
