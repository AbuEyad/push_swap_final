/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:41 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:00:42 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	check_stack_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	n;

	if (stack_b != NULL || stack_a == NULL)
		return (0);
	n = stack_a->content;
	while (stack_a)
	{
		if (n > stack_a->content)
			return (0);
		n = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}
