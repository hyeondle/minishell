/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:04:58 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/06 15:05:29 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_setting	*set;
	char *input;
	int i = 0;

	set = (t_setting *)malloc(sizeof(t_setting));
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
	}

	return 0;
}
/*
아마 작은 따옴표 혹은 큰 따옴표의 인덱싱 부분에서 에러가 발생하는 것 같음.
따옴표 안에 빈 문자열일 경우를 체크해 보도록
*/