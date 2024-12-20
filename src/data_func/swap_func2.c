/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:43:12 by mafioron          #+#    #+#             */
/*   Updated: 2024/12/18 14:43:16 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_func.h"

void	ss(t_circ_buff *a, t_circ_buff *b)
{
	s_ab(a, 's');
	s_ab(b, 's');
	ft_printf("ss\n");
}

void	rr(t_circ_buff *a, t_circ_buff *b)
{
	r_ab(a, 's');
	r_ab(b, 's');
	ft_printf("rr\n");
}

void	rrr(t_circ_buff *a, t_circ_buff *b)
{
	rr_ab(a, 's');
	rr_ab(b, 's');
	ft_printf("rrr\n");
}
