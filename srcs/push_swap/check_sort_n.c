/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:59:36 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/14 19:22:42 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_n(t_stack *stack, int type, int n)
{
	int		check;

	if (stack == NULL)
		return (1);
	check = stack->content;
	stack = stack->next;
	while (--n > 0 && stack)
	{
		if (type == DESC)
		{
			if (stack->content > check)
				return (0);
			check = stack->content;
		}
		else if (type == ASC)
		{
			if (stack->content < check)
				return (0);
			check = stack->content;
		}
		stack = stack->next;
	}
	return (1);
}
