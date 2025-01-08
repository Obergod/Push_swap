/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:10:43 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/16 20:10:47 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"

void print_stack_state(t_circ_buff *c, char stack_name) 
{
    printf("\nDEBUG: Stack %c state:\n", stack_name);
    printf("head=%d, tail=%d, size=%d\n", c->head, c->tail, c->size);
    printf("Values: ");
    
    // Print all values from tail to head
    int pos = c->tail;
    while (pos != c->head) 
    {
        printf("%d ", c->buff[pos]);
        pos = next_pos(pos, c->size);
    }
    printf("\n");
}
void	s_ab(t_circ_buff *c, char stack)
{
	int	next;

	if (circ_empty(c) || c->size < 2)
		return ;
	next = (c->tail + 1) % c->size;
	ft_swap(&c->buff[c->tail], &c->buff[next]);
	if (stack == 'a')
		ft_printf("sa\n");
	else if (stack == 'b')
		ft_printf("sb\n");
}


void	pa(t_circ_buff *a, t_circ_buff *b)
{
	int	value;

	if (circ_empty(b))
		return ;
	circ_pop(b, &value);
	circ_push(a, value);
	ft_printf("pa\n");
}

void	pb(t_circ_buff *b, t_circ_buff *a)
{
	int	value;

	if (circ_empty(a))
		return ;
	circ_pop(a, &value);
	circ_push(b, value);
	printf("DEBUG: pb - value=%d, b->head=%d, b->tail=%d\n", value, b->head, b->tail);
	
	ft_printf("pb\n");
}

void	r_ab(t_circ_buff *c, char stack)
{
	if (circ_full(c))
	{
		c->head = c->tail;
		c->tail = next_pos(c->tail, c->size);
	}
	else 
	{
		c->head = next_pos(c->head, c->size);
		c->buff[c->head] = c->buff[c->tail];
		c->buff[c->tail] = 0;
		c->tail = next_pos(c->tail, c->size);
	}
	if (stack == 'a')
		ft_printf("ra\n");
	else if (stack == 'b')
		ft_printf("rb\n");
}

void	rr_ab(t_circ_buff *c, char stack)
{

	if (circ_full(c))
	{
		c->tail = c->head;
		c->head = prev_pos(c->head, c->size);
	}
	else 
	{
		c->tail = prev_pos(c->tail, c->size);
		c->buff[c->tail] = c->buff[c->head];
		c->buff[c->head] = 0;
		c->head = prev_pos(c->head, c->size);
	}
	if (stack == 'a')
		ft_printf("rra\n");
	else if (stack == 'b')
		ft_printf("rrb\n");
}