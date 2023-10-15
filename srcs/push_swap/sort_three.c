/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:26 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/14 19:24:52 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_a(t_push_swap *data)
{
	operator("ra", data);
	operator("sa", data);
}

static void	case_b(t_push_swap *data)
{
	operator("sa", data);
	operator("ra", data);
}

void	sort_three(t_push_swap *data)
{
	if (check_sort_n(data->a, ASC, 3))
		return ;
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content && \
		data->a->content > data->a->next->next->content)
		return (operator("rra", data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content && \
		data->a->content < data->a->next->next->content)
		return (operator("sa", data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content && \
		data->a->content > data->a->next->next->content)
		return (operator("ra", data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content > data->a->next->next->content)
		return (case_a(data));
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content && \
		data->a->content < data->a->next->next->content)
		return (case_b(data));
}
