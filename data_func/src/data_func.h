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

typedef struct s_circ_buff
{
	int		*buff;
	int		head;
	int		tail;
	int		size;
}t_circ_buff;

#endif
