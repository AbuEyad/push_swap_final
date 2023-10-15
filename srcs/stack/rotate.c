/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:10 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/07 15:30:25 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = stack_last(*stack);
	tmp->prev->next = tmp;
}
