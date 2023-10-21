/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:47 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 15:57:40 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_split_clean(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static void	error_and_clear(t_stack *result, char **split)
{
	stack_clear(&result);
	ft_putendl_fd("Error", 2);
	ft_split_clean(split);
	exit(1);
}

int	is_doublicate(t_stack *stack, int n)
{
	t_stack	*curr;

	curr = stack;
	while (curr)
	{
		if (curr->content == n)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static long	atoi_check(char *s, t_stack *result, char **split)
{
	int			flag;
	long long	n;

	flag = 1;
	n = 0;
	if (*s == '-')
	{
		flag = -1;
		s++;
	}
	if (ft_strlen(s) > 10 || ft_strlen(s) == 0)
		error_and_clear(result, split);
	while (ft_isdigit(*s))
	{
		n *= 10;
		n += *s - '0';
		s++;
	}
	n *= flag;
	if (*s != '\0' || (n < FT_INT_MIN) || (n > FT_INT_MAX))
		error_and_clear(result, split);
	if (is_doublicate(result, n))
		error_and_clear(result, split);
	return (n);
}

t_stack	*create_stack(int argc, char *argv[])
{
	int		i[2];
	char	**split;
	t_stack	*result;
	t_stack	*tmp;

	result = NULL;
	i[0] = 0;
	while (++i[0] < argc)
	{
		split = ft_split(argv[i[0]], ' ');
		if (split == NULL)
			error_and_clear(result, split);
		i[1] = -1;
		while (split[++i[1]])
		{
			tmp = stack_new(atoi_check(split[i[1]], result, split));
			if (tmp == NULL)
				error_and_clear(result, split);
			stack_add_back(&result, tmp);
		}
		ft_split_clean(split);
	}
	return (result);
}
