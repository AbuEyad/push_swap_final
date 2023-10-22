/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:26:31 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/22 11:21:19 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	switch_operation(char *operation, t_push_swap *data)
{
	if (!ft_strcmp(operation, "pa") || !ft_strcmp(operation, "pb") || \
		!ft_strcmp(operation, "sa") || !ft_strcmp(operation, "sb") || \
		!ft_strcmp(operation, "ss") || !ft_strcmp(operation, "ra") || \
		!ft_strcmp(operation, "rb") || !ft_strcmp(operation, "rr") || \
		!ft_strcmp(operation, "rra") ||!ft_strcmp(operation, "rrb") || \
		!ft_strcmp(operation, "rrr"))
	{
		operator(operation, data, 0);
		return (0);
	}
	return (1);
}

int	exec_operation(t_list *operations, t_push_swap *data)
{
	int		operation_err;

	while (operations)
	{
		operation_err = switch_operation(operations->content, data);
		if (operation_err)
			return (0);
		operations = operations->next;
	}
	return (1);
}
