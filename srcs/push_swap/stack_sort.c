/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:32 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/15 11:11:12 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_push_swap *data)
{
	int	size;

	size = stack_size(data->a);
	if (size == 5)
		return (sort_five(data));
	if (size == 4)
		return (sort_four(data));
	if (size == 3)
		return (sort_three(data));
	if (size == 2 && data->a->content > data->a->next->content)
		return (operator("sa", data));
	return (sort_a(data, size));
}
