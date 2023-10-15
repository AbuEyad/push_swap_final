/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:02 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:58:28 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	tmp->next = *to;
	*to = tmp;
	(*to)->prev = NULL;
}
