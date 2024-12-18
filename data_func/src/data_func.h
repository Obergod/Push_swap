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
#include <stdio.h>

typedef struct s_circ_buff
{
	int		*buff;
	int		head;
	int		tail;
	int		size;
}t_circ_buff;


t_circ_buff	*get_stack(char *nbr);
t_circ_buff	*circ_init(int size);
int	circ_pop(t_circ_buff *c, int *data);
int	circ_push(t_circ_buff *c, int data);
int	circ_full(t_circ_buff *c);
int	circ_empty(t_circ_buff *c);
void	ft_swap(int	*a, int *b);
int	next_pos(int pos, int size);
int	prev_pos(int pos, int size);

#endif
