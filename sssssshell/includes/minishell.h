/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:34 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 00:57:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
readline.h	=	readline
history.h	=	re_clear_history, rl_on_new_line, rl_replace_line, re_redisplay, add_history
stdio.h		=	printf, strerror, perror
stdlib.h	=	malloc, free
sys/stat.h	=	getcwd, chdir, stat, lstat, fstat, unlink, execve
dirent.h	=	opendir, readdir, closedir
unistd.h	=	write, access, dup, dup2, pipe
signal.h	=	fork, wait, waitpid, wait3, wiat4, signal, sigaction, sigemptyset, sigaddset, kill, exit
sys/ioctl.h	=	isatty, ttyname, ttyslot, ioctl
stdlib.h	=	getenv
termios.h	=	tcsetattr, tcgetattr
termcap		=	tgetnet, tgetflag, tgetnum, tgetstr, tgoto, tputs
fcntl.h		=	open, read, close
*/


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/mylibft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>

# define	HISTORY_FILE	".minishell_history"
# ifndef	HISTORY_SIZE
#  define	HISTORY_SIZE	1024
# endif

/*		typedef			*/

typedef enum e_quote
{
	NONE,
	SINGLE,
	DOUBLE
}	t_quote;

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

typedef struct s_env_list
{
	t_env				env;
	char				*pair;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_setting
{
	t_env_list	*env_list;
}				t_setting;

/*			environment			*/
void	init_env(char **envp, t_setting **set);
int		add_env(t_env_list **env, const char *key_value_pair);
int		remove_env(t_env_list **env, const char *key);
void	free_env(t_env_list	*env);




#endif