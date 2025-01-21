/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:26:48 by mafioron          #+#    #+#             */
/*   Updated: 2025/01/17 18:26:49 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

#include "data_func.h"
#include "push_swap.h"

enum		e_op
{
	null_op,
	epa,
	epb,
	ra,
	rb,
	err,
	rra,
	rrb,
	errr,
	sa,
	sb,
	ess
};

/****		checker_bonus		******/
void		error_op(t_stacks *stack, char *line);
int			checker(t_stacks *stacks, int fd);

/****		checker_utils_bonus ******/
void		error(t_stacks *stack);
void		pa_no_print(t_circ_buff *a, t_circ_buff *b);
void		pb_no_print(t_circ_buff *b, t_circ_buff *a);
enum e_op	string_to_op(char *str);
void		call_op(t_stacks *stack, enum e_op op);

#endif
