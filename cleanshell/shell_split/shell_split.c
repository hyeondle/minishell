/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:26:25 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/29 14:41:10 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**shell_split(char const *s)
{
	char	**tab;
	char	*temp;

	if (!s)
		return (NULL);
	temp = (char *)s;
	tab = (char **)malloc(sizeof(char *) * (tab_size(temp) + 1));
	if (!tab)
		return (NULL);
	tab = do_split(tab, temp);
	return (tab);
}