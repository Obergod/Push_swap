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
    printf("\n=== Stack %c state ===\n", stack_name);
    printf("head=%d, tail=%d, size=%d\n", c->head, c->tail, c->size);
    printf("Values: ");
    
    int pos = c->tail;
    do {
        printf("%d ", c->buff[pos]);
        pos = next_pos(pos, c->size);
    } while (pos != next_pos(c->head, c->size));
    printf("\n===================\n");
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
    print_stack_state(a, 'A');
    print_stack_state(b, 'B');
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
    print_stack_state(a, 'A');
    print_stack_state(b, 'B');
}

void r_ab(t_circ_buff *c, char stack)
{
    int first_value;

    if (circ_empty(c) || c->size < 2)
        return;

    // Save first value (at tail)
    first_value = c->buff[c->tail];
    
    // Move tail forward
    c->tail = next_pos(c->tail, c->size);
    
    // Move head forward and place first value
    c->head = next_pos(c->head, c->size);
    c->buff[c->head] = first_value;

    print_stack_state(c, stack);
    if (stack == 'a')
        ft_printf("ra\n");
    else if (stack == 'b')
        ft_printf("rb\n");
}

void	rr_ab(t_circ_buff *c, char stack)
{
    int last_value;

    if (circ_empty(c) || c->size < 2)
        return;

    // Save last value (at head)
    last_value = c->buff[c->head];
    
    // Move head backward
    c->head = prev_pos(c->head, c->size);
    
    // Move tail backward and place last value
    c->tail = prev_pos(c->tail, c->size);
    c->buff[c->tail] = last_value;

    print_stack_state(c, stack);
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