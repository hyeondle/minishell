/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:47:50 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/15 05:51:02 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//현재 경로 보여주기
#include "../../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*cwd;
	int		size;

	size = 1;
	cwd = (char *)malloc(size);
	while (cwd != NULL)
	{
		if (getcwd(cwd, size) != NULL)
		{
			printf("%s\n", cwd);
			break ;
		}
		else
		{
			size *= 2;
			free(cwd);
		}
		cwd = (char *)malloc(size);
	}
	free(cwd);
	return (0);
}
