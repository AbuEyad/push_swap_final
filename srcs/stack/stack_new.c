/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:42 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:01:44 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_new(int content)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (lst == NULL)
		return (0);
	lst->next = 0;
	lst->prev = 0;
	lst->content = content;
	return (lst);
}
