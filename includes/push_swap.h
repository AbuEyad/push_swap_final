/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:14:15 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/22 11:04:57 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

# define PUSH	0
# define RA		1
# define RB		2

# define DESC	0
# define ASC	1

# define SML	0
# define BIG	1

void	stack_sort(t_push_swap *data);
void	get_pivot(int pivot[], t_stack *stack, int n);

void	sort_five(t_push_swap *data);
void	sort_three(t_push_swap *data);
void	sort_four(t_push_swap *data);
void	sort_a(t_push_swap *data, int size);
void	sort_three_a(t_push_swap *data);
void	sort_b(t_push_swap *data, int size);
void	sort_three_b(t_push_swap *data);
int		check_sort_n(t_stack *stack, int type, int n);
void	return_stack(t_push_swap *data, int ra_cnt, int rb_cnt);

#endif
