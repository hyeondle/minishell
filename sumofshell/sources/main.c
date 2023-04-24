/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:07 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 21:14:35 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handler(int sig, siginfo_t *info, void *oldsiga)
{
	if (sig == SIGQUIT)
		rl_redisplay();
	else if (sig == SIGINT)
	{
		rl_replace_line("", 1);
		rl_on_new_line();
		printf("\n");
		rl_redisplay();
	}
}

static void	init_signalaction(void)
{
	struct sigaction    act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

static t_setting	*init_set(char **envp)
{
	t_setting	*set;

	set = (t_setting *)malloc(sizeof(t_setting));
	if (!set)
		return (NULL);
	set->exit = 0;
	set->l_history = NULL;
	set->s_history = NULL;
	init_env(envp, &set);
	init_history(&set);
	rl_catch_signals = 0;
	init_signalaction();
	return (set);
}

int	main(int argc, char **argv, char **envp)
{
	t_setting	*set;
	char		*input;
	int			i;

	printf("shellstart\n");
	set = init_set(envp);
	if (!set)
		return (1);
	i = 0;
	while (1)
	{
		input = get_input(&set);
		if (!input)
			break ;
		ft_add_history(input, &set);
		operation(input, &set);
		free(input);
		if (set->exit == 1)
			break ;
	}
	save_history(&set);
	return (0);
}
