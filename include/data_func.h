/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:37:24 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/14 17:37:25 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_FUNC_H
# define DATA_FUNC_H

#include <stdint.h>
#include "libft.h"
# include "ft_printf.h"

typedef struct s_circ_buff
{
	int		*buff;
	int		head;
	int		tail;
	int		size;
}t_circ_buff;

typedef struct s_stacks
{
	t_circ_buff	a;
	t_circ_buff	b;
}t_stacks;


/******      get stack    *************/
t_stacks	*get_stack(char *nbr);
void	circ_init(int size, t_circ_buff *c);
int	circ_pop(t_circ_buff *c, int *data);
int	circ_push(t_circ_buff *c, int data);

/******		swap_utils		**********/
int	circ_full(t_circ_buff *c);
int	circ_empty(t_circ_buff *c);
void	ft_swap(int	*a, int *b);
int	next_pos(int pos, int size);
int	prev_pos(int pos, int size);

/******		swap_func	**************/
void	s_ab(t_circ_buff *c, char stack);
void	pa(t_circ_buff *a, t_circ_buff *b);
void	pb(t_circ_buff *b, t_circ_buff *a);
void	r_ab(t_circ_buff *c, char stack);
void	rr_ab(t_circ_buff *c, char stack);
void	ss(t_circ_buff *a, t_circ_buff *b);
void	rr(t_circ_buff *a, t_circ_buff *b);
void	rrr(t_circ_buff *a, t_circ_buff *b);


#endif
