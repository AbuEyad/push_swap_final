/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_with_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:47 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/14 21:05:59 by habu-zua         ###   ########.fr       */
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

static void	put_error_with_clear(t_stack *result, char **split)
{
	stack_clear(&result);
	ft_putendl_fd("Error", 2);
	ft_split_clean(split);
	exit(1);
}

static long	atoi_check(char *s, t_stack *result, char **split)
{
	t_stack		*curr;
	char		flag;
	long long	n;

	flag = 0;
	n = 0;
	((*s == '-') && (flag = 1) && (++s));
	if (ft_strlen(s) > 10 || ft_strlen(s) == 0)
		put_error_with_clear(result, split);
	while (ft_isdigit(*s))
	{
		n *= 10;
		n += *s++ - '0';
	}
	((flag == 1) && (n *= -1));
	if (*s != '\0' || (n < FT_INT_MIN) || (n > FT_INT_MAX))
		put_error_with_clear(result, split);
	curr = result;
	while (curr)
	{
		if (curr->content == n)
			put_error_with_clear(result, split);
		curr = curr->next;
	}
	return (n);
}

t_stack	*create_stack_with_arg(int argc, char *argv[])
{
	int		iv[2];
	char	**split;
	t_stack	*result;
	t_stack	*tmp;

	result = NULL;
	iv[0] = 0;
	while (++iv[0] < argc)
	{
		split = ft_split(argv[iv[0]], ' ');
		if (split == NULL)
			put_error_with_clear(result, split);
		iv[1] = -1;
		while (split[++iv[1]])
		{
			tmp = stack_new(atoi_check(split[iv[1]], result, split));
			if (tmp == NULL)
				put_error_with_clear(result, split);
			stack_add_back(&result, tmp);
		}
		ft_split_clean(split);
	}
	return (result);
}
