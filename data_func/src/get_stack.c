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

#include "data_func.h"
#include <stdlib.h>
#include <stdio.h>


int	circ_push(t_circ_buff *c, int data)
{
	if (circ_full(c))
		return(-1);
	c->buff[c->head] = data;
	c->head = (c->head + 1) % c->size;
	return (0);
}


int	circ_pop(t_circ_buff *c, int *data)
{
	if (circ_empty(c))
		return (-1);
	*data = c->buff[c->tail];
    c->tail = (c->tail + 1) % c->size;
    return (0);
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

	i = 0;
	nb = ft_split(nbr, ' ');
	size = count_words(nbr, ' ');
	c = circ_init(size + 1);
	while (!circ_full(c))
	{
		circ_push(c, ft_atoi(nb[i]));
		i++;
	}
	free(nb);
	return (c);
}

int main(int ac, char **av)
{
    t_circ_buff *a;
    t_circ_buff *b;
    int i;

    if (ac != 2)
        return (1);

    // Initialize stacks
    a = get_stack(av[1]);
    b = circ_init(count_words(av[1], ' '));

    // Print initial state
    printf("Initial stack A:\n");
    i = 0;
    while (i < a->size)
    {
        printf("%d ", a->buff[i]);
        i++;
    }
    printf("\n");

    // Test operations
    s_ab(a, 'a');     // sa
    printf("After sa\n");
    // Print stack

    pb(b, a);         // pb
    printf("After pb\n");
    // Print both stacks

    r_ab(a, 'a');     // ra
    printf("After ra\n");
    // Print stack

    rr_ab(a, 'a');    // rra
    printf("After rra\n");
    // Print stack

    pa(a, b);         // pa
    printf("After pa\n");
    // Print both stacks

    // Clean up
    free(a->buff);
    free(a);
    free(b->buff);
    free(b);

    return (0);
}
