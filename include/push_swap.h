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
	BOT_A,
	TOP_B,
	BOT_B
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
t_split_it	*split_it_init();
void		get_min_max(t_circ_buff *c, int *min, int *max);
void		first_sort(t_stacks *stacks);
void		get_pivots(t_stacks *stack, enum e_loc loc, int *p1, int *p2);
int			sorted(int *data);

/*******		move			*********/
void	move_from_to(t_stacks *stacks, enum e_loc from, enum e_loc to);
void	move_from_top_a(t_stacks *stacks, enum e_loc to);
void	move_from_bot_a(t_stacks *stacks, enum e_loc to);
void	move_from_top_b(t_stacks *stacks, enum e_loc to);
void	move_from_bot_b(t_stacks *stacks, enum e_loc to);

/******			A TRIER			********/
t_circ_buff *wich_stack(t_stacks *stack, enum e_loc loc);
void		rec_sort(t_stacks *stacks, t_chunk *chunk);
void		sort_it(t_stacks *stacks, t_split_it *split, t_chunk *chunk);
void		three_digit_sort(t_stacks *stack, t_chunk *chunk);
void		two_digit_sort(t_stacks *stack, t_chunk *chunk);
int			get_nb(t_stacks *stack, t_chunk *chunk, int i);
int			chunk_max(t_stacks *stack, t_chunk *chunk, int i);
void	one_digit_sort(t_stacks *stack, t_chunk *chunk);

#endif
