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
# define PUSH_SWAP_H

enum			e_loc
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B
};

typedef struct s_chunk
{
	enum e_loc	loc;
	int			size;
}				t_chunk;

typedef struct s_split_it
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}				t_split_it;

/*********		swap_utils		**********/
t_split_it		*split_it_init(void);
t_circ_buff		*wich_stack(t_stacks *stack, enum e_loc loc);
void			get_pivots(enum e_loc loc, int size, int *p1, int *p2);
void			size_init(t_chunk *min, t_chunk *mid, t_chunk *max);
int				get_nb(t_stacks *stack, t_chunk *chunk, int i);
int				chunk_max(t_stacks *stack, t_chunk *chunk, int i);

/*******		move			*********/
int				move_from_to(t_stacks *stacks, enum e_loc from, enum e_loc to);
void			move_from_top_a(t_stacks *stacks, enum e_loc to);
void			move_from_bot_a(t_stacks *stacks, enum e_loc to);
void			move_from_top_b(t_stacks *stacks, enum e_loc to);
void			move_from_bot_b(t_stacks *stacks, enum e_loc to);

/*****			sort			********/
void			sort(t_stacks *stacks);
void			rec_sort(t_stacks *stacks, t_chunk *chunk);
void			sort_it(t_stacks *stacks, t_split_it *split, t_chunk *chunk);
void			one_digit_sort(t_stacks *stack, t_chunk *chunk);
void			two_digit_sort(t_stacks *stack, t_chunk *chunk);
void			sort_three_only(t_stacks *stack, t_chunk *chunk);
void			sort_five_only(t_stacks	*stack, t_chunk *chunk);
void			sort_three(t_stacks *stack, t_chunk *chunk);
void			sort_three_top_a(t_stacks *stack, t_chunk *chunk,
					t_circ_buff *a, int max);
void			sort_three_bot_a(t_stacks *stacks, t_chunk *chunk,
					t_circ_buff *a, int max);
void			sort_three_bot_b(t_stacks *stack, t_chunk *chunk,
					t_circ_buff *b, int max);
void			sort_three_top_b(t_stacks *stack, t_chunk *chunk,
					t_circ_buff *b, int max);

/*****		cleanup_stacks		********/
void			cleanup_stacks(t_stacks *stacks);

#endif
