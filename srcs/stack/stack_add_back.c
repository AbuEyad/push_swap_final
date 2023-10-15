/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:21 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:01:23 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_add_back(t_stack **lst, t_stack *new_list)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	last = stack_last(*lst);
	last->next = new_list;
	new_list->prev = last;
}
