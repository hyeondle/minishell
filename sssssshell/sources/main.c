/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:07 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/16 00:06:18 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler(int sig, siginfo_t *info, void *oldsiga)
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

void    init_signalaction(void)
{
	struct sigaction    act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

// void	init_signalsetting(t_setting **setting)
// {
// 	struct termios	new_termios;

// 	tcgetattr(STDIN_FILENO, &((*setting)->saved_termios));
// 	new_termios = (*setting)->saved_termios;

// 	new_termios.c_lflag &= ~(ICANON);
// 	// new_termios.c_cc[VEOF] = _POSIX_VDISABLE;
// 	// new_termios.c_cc[VINTR] = _POSIX_VDISABLE;
// 	// new_termios.c_cc[VQUIT] = _POSIX_VDISABLE;

// 	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
// 	// tcsetattr(STDIN_FILENO, TCSANOW, &((*setting)->saved_termios));
// }

t_setting	*init_set(char **envp)
{
	t_setting	*set;

	set = (t_setting *)malloc(sizeof(t_setting));
	if (!set)
		return (NULL);
	set->exit = 0;
	init_env(envp, &set);
	rl_catch_signals = 0;
	//init_signalsetting(&set);
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
	// set = (t_setting *)malloc(sizeof(t_setting));
	// set->exit = 0;
	i = 0;
	// init_env(envp, &set);
	while (1)
	{
		input = get_input(&set);
		if (!input)
			break ;
		add_history(input);
		operation(input, &set);
		free(input);
		if (set->exit == 1)
			break ;
	}
	//tcsetattr(STDIN_FILENO, TCSANOW, &(set->saved_termios));
	return (0);
}
