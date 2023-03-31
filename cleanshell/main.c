/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:04:58 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/30 13:01:17 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_setting	set;
	char *input;
	int i = 0;

	env_init(&set, envp);
	while (1) {
		input = get_input();
		if (!input)
			break;
		add_history(input);
		// 여기서 input을 파싱하고 명령어를 실행.
		operation(input);
		printf("%d %s\n",i++,input);
		free(input);
	}

	return 0;
}
