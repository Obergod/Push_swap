/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:56:57 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/20 13:57:00 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

enum	e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
};

typedef struct	s_chunk
{
	enum e_loc	loc;
	int			size;
}	t_chunk;

typedef struct	s_split_it
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split_it;


/*********		swap_utils		**********/
t_split_it	*split_it_init(t_split_it *s);
t_split_it	*first_split(t_circ_buff *a, t_circ_buff *b);
void	get_min_max(int *data, int *min, int *max);
int	sorted(int *data);
void	get_pivots(t_circ_buff *c, int *p1, int *p2);

#endif
