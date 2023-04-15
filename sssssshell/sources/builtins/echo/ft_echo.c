/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:48:28 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/15 21:03:14 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_echo_with_option_n(char **inputs)
{
	int	i;

	i = 2;
	if (inputs[i] == NULL || *(inputs[i]) == '\0')
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (0);
	}
	while (inputs[i])
	{
		if (!inputs[i + 1])
		{
			ft_putstr_fd(inputs[i], STDOUT_FILENO);
			break ;
		}
		ft_putstr_fd(inputs[i], STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	return (0);
}

int	ft_echo(char **inputs)
{
	int	i;

	i = 1;
	if (inputs[i] == NULL || *(inputs[i]) == '\0')
	{
		printf("\n");
		return (1);
	}
	if (ft_strcmp(inputs[i], "-n") == 0)
		ft_echo_with_option_n(inputs);
	else
	{
		while (inputs[i])
		{
			if (!inputs[i + 1])
			{
				printf("%s\n", inputs[i]);
				break ;
			}
			printf("%s ", inputs[i]);
			i++;
		}
	}
	return (0);
}
