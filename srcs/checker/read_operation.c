/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:56:21 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/22 11:21:25 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	put_error_with_clear(t_list *result, char *operation)
{
	if (operation)
		free(operation);
	ft_lstclear(&result, free);
	ft_putendl_fd("Error", 2);
	exit(1);
}

t_list	*read_operation(void)
{
	int		gnl_status;
	char	*operation;
	t_list	*operations;
	t_list	*tmp;

	operations = NULL;
	gnl_status = get_next_line(0, &operation);
	while (gnl_status > 0)
	{
		tmp = ft_lstnew(operation);
		if (tmp == NULL)
			put_error_with_clear(operations, operation);
		ft_lstadd_back(&operations, tmp);
		gnl_status = get_next_line(0, &operation);
	}
	if (ft_strlen(operation) || gnl_status == -1)
		put_error_with_clear(operations, NULL);
	free(operation);
	return (operations);
}
