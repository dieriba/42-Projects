/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:51:59 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/08 15:27:42 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	check_space(char *str)
{
	size_t	i;
	size_t	len;
	int		flags;

	len = ft_strlen(str);
	i = 0;
	flags = 1;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i] && flags)
			return (0);
		if (i != 0 && (str[i] == '-' || str[i] == '+') && str[i - 1] != ' ')
			return (0);
		else if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] && !ft_isdigit(str[i]) && i < len)
			return (0);
		flags = 0;
		i++;
	}
	if (str[len - 1] == '-' || str[len] == '+')
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strlen(argv[i]))
			return (0);
		if (argv[i][0] == '-' && !argv[i][1])
			return (0);
		if (!check_space(argv[i]))
			return (0);
	}
	return (1);
}

int	check_double(char **argv)
{
	int		i;
	int		j;
	long	first;
	long	second;
	int		len;

	j = 0;
	i = -1;
	len = ft_tab_len(argv);
	while (++i < len - 1)
	{
		first = ft_atoi(argv[i]);
		j = i + 1;
		while (j < len)
		{
			second = ft_atoi(argv[j]);
			if (first == second)
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_number(char **argv)
{
	int		i;
	long	num;

	i = -1;
	while (argv[++i])
	{
		num = ft_atoi(argv[i]);
		if (num > 2147483647)
			return (0);
		else if (num < -2147483648)
			return (0);
	}
	return (1);
}

int	check(int argc, char **argv, char **tab)
{
	if (!check_args(argc, argv))
		return (0);
	if (!check_number(tab))
		return (0);
	if (!check_double(tab))
		return (0);
	return (1);
}
