/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:46:45 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 21:18:48 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

char	**free_splited(char ***tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		ft_free_tab(tab[i]);
	free(tab);
	return (NULL);
}

char	**copy_over(char **tab, char *num)
{
	static int	i;

	tab[i] = ft_strdup(num);
	if (!tab[i])
		return (ft_free_tab(tab));
	i++;
	return (tab);
}

char	**set_tabs(char ***tab, int len)
{
	char	**tabs;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	tabs = ft_calloc(sizeof(char *), len + 1);
	if (!tabs)
		return (NULL);
	while (tab[++i])
	{
		while (tab[i][++j])
			if (!copy_over(tabs, tab[i][j]))
				return (free_splited(tab));
		j = -1;
	}
	free_splited(tab);
	return (tabs);
}

char	**get_args(int argc, char **argv)
{
	int		i;
	char	***tab;
	int		tablen;
	char	**tabs;

	i = -1;
	tablen = 0;
	tab = malloc(sizeof(char **) * argc);
	if (!tab)
		return (NULL);
	tab[argc - 1] = 0;
	while (++i < argc - 1)
	{
		tab[i] = ft_split(argv[i + 1], ' ');
		if (!tab[i])
			return (free_splited(tab));
	}
	i = -1;
	while (tab[++i])
		tablen += ft_tab_len(tab[i]);
	tabs = set_tabs(tab, tablen);
	return (tabs);
}
