/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:28 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:01:29 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_add_front(t_stack **lst, t_stack *new_list)
{
	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	new_list->next = *lst;
	(*lst)->prev = new_list;
	*lst = new_list;
}
