/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:07 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/14 22:48:39 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_setting	*set;
	char *input;
	int i = 0;

	set = (t_setting *)malloc(sizeof(t_setting));
	set->exit = 0;

	i = 0;
	init_env(envp, &set);
	while (1) {
		input = get_input();
		if (!input)
			break;
		add_history(input);
		// 여기서 input을 파싱하고 명령어를 실행.
		operation(input, &set);
		printf("%d %s\n",i++,input);
		free(input);
		if (set->exit == 1)
			break;
	}
	return (0);
}
