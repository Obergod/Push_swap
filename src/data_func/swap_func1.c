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


void pa(t_circ_buff *a, t_circ_buff *b)
{
    int dst;

	if (circ_full(a))
        return;
	dst = prev_pos(a->tail, a->size);     // Make space in A top
	a->buff[dst] = b->buff[b->tail];       // Add to A top
	a->tail  = dst;                        // Update A tail
	b->tail = next_pos(b->tail, b->size);  // Update B tail

	ft_printf("pa\n");
}

void pb(t_circ_buff *b, t_circ_buff *a)
{
    int dst;

	if (circ_full(b))
	    return;
	dst = prev_pos(b->tail, b->size);     // Make space in B top
	b->buff[dst] = a->buff[a->tail];       // Add to B top
	b->tail  = dst;                        // Update A tail
	a->tail = next_pos(a->tail, a->size);  // Update B tail
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
		c->head = prev_pos(c->head, c->size);
	}
	if (stack == 'a')
		ft_printf("rra\n");
	else if (stack == 'b')
		ft_printf("rrb\n");
}
/*
void r_ab(t_circ_buff *c, char stack)
{
    int temp;
    
    if (!c || c->size < 2)
        return;
        
    temp = c->buff[c->tail];
    c->tail = next_pos(c->tail, c->size);
    c->head = next_pos(c->head, c->size);
    c->buff[c->head] = temp;
    
    if (stack == 'a')
        ft_printf("ra\n");
    else if (stack == 'b')
        ft_printf("rb\n");
}

void rr_ab(t_circ_buff *c, char stack)
{
    int temp;
    
    if (!c || c->size < 2)
        return;
        
    temp = c->buff[prev_pos(c->head, c->size)];
    c->tail = prev_pos(c->tail, c->size);
    c->head = prev_pos(c->head, c->size);
    c->buff[c->tail] = temp;
    
    if (stack == 'a')
        ft_printf("rra\n");
    else if (stack == 'b')
        ft_printf("rrb\n");
}*/