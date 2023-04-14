/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:07 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/15 07:15:26 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_setting	*set;
	char		*input;
	int			i;

	set = (t_setting *)malloc(sizeof(t_setting));
	set->exit = 0;
	i = 0;
	init_env(envp, &set);
	while (1)
	{
		input = get_input();
		if (!input)
			break ;
		add_history(input);
		operation(input, &set);
		printf("%d %s\n", i++, input);
		free(input);
		if (set->exit == 1)
			break ;
	}
	return (0);
}
