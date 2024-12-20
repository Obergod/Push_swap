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
	enum	e_loc;
	int		size;
}	t_chunk;

typedef struct	s_split_it
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split_it;


/*********		swap_utils		**********/
t_split_it	*split_it_init(t_split_it *s);

#endif
