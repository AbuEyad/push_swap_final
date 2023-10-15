/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:15 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:01:16 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rrotate(t_stack **stack)
{
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = stack_last(*stack);
	(*stack)->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = (*stack);
	*stack = last;
}
