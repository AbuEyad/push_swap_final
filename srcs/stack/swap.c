/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:53 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:01:55 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	int	content_tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	content_tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = content_tmp;
}
