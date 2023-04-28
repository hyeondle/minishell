/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:34 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/28 20:05:29 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
readline.h	=	readline
history.h	=	re_clear_history, rl_on_new_line,
				rl_replace_line, re_redisplay, add_history
stdio.h		=	printf, strerror, perror
stdlib.h	=	malloc, free
sys/stat.h	=	getcwd, chdir, stat, lstat, fstat, unlink, execve
dirent.h	=	opendir, readdir, closedir
unistd.h	=	write, access, dup, dup2, pipe
signal.h	=	fork, wait, waitpid, wait3, wiat4, signal,
				sigaction, sigemptyset, sigaddset, kill, exit
sys/ioctl.h	=	isatty, ttyname, ttyslot, ioctl
stdlib.h	=	getenv
termios.h	=	tcsetattr, tcgetattr
termcap		=	tgetnet, tgetflag, tgetnum, tgetstr, tgoto, tputs
fcntl.h		=	open, read, close
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/mylibft.h"
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
# include <readline/readline.h>
# include <readline/history.h>

# define HISTORY_FILE	".minishell_history"
# ifndef HISTORY_SIZE
#  define HISTORY_SIZE	1024
# endif

/*		typedef			*/

typedef enum e_quote
{
	NONE,
	SINGLE,
	DOUBLE
}	t_quote;

typedef	struct s_history
{
	char				*history;
	struct s_history	*next;
}						t_history;

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

typedef struct s_env_list
{
	t_env				env;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_setting
{
	int				exit;
	int				child_exit_status;
	char			**envp;
	t_env_list		*env_list;
	t_history		*s_history;
	t_history		*l_history;
}				t_setting;

/*			actors				*/
void	operation(char *input, t_setting **set);

/*			history				*/
void	init_history(t_setting **setting);
void	ft_add_history(char *input, t_setting **set);
void	save_history(t_setting **setting);

/*			environment			*/
void	init_env(char **envp, t_setting **set);
int		add_env_envp(t_setting **set, const char *str);
int		add_env(t_env_list **env, const char *key_value_pair, t_setting **set);
int		remove_env_envp(t_setting **set, const char *key);
int		remove_env(t_env_list **env, const char *key, t_setting **set);
char	*get_env_value(t_env_list *env, const char *key);
char	*get_env_key(char *str, int i);
int		update_env(t_env_list *env, const char *key, const char *new_value);
void	free_env(t_env_list	*env);
//		env_to_str		//
char	*find_key_and_get_env_value(char *str, int i, t_setting **set);
char	*get_env_to_str(t_setting **set, char *str);
//	temp
char	*split_and_join(char *p_str, int i, char *value);
int		get_third_size(char *str);

/*			input				*/
char	*get_input(t_setting **set);
int		input_check(char *input);
char	*check_input_add(char *additional);

/*			execute				*/
int		execute(char **inputs, t_setting **set);
int		execute_check(char *o);
int		go_execute(char **inputs, t_setting **set, char *o);

/*			tokenize			*/
//			shell split			//
char	**shell_split(char const *s);
char	*put_word(char *str, size_t s);
char	**do_split(char **tab, char *temp);
//			shell split utils	//
size_t	quote_leng(const char *s, size_t k);
size_t	tab_size(char *s);
t_quote	check_quote(char temp);
size_t	new_strlen_m(char *str, size_t k);
//			token split			//
char	**split_by_token(char **str);
char	**split_by_case(char **str, int i, int k);
char	**over_2_delims(char **str, int i, int k);
//			case				//
char	**go_split(char **str, int i, int k);
char	**token_split_case_alone(char **str, int i, int k);
char	**token_split_case_no_back(char **str, int i, int k);
char	**token_split_case_no_front(char **str, int i, int k);
char	**go_split_over_delim(char **str, int i, int k, int j);
char	**token_split_case_no_back_over_delim(char **str, int i, int k, int j);
char	**token_split_case_no_front_over_delim(char **str, int i, int k, int j);
//			token split utils	//
int		split_case_index_check(char **str, int i, int k);
int		token_check(char c);
int		check_delimeter(char *str);
int		check_delimeter_type_i(char	*str);
size_t	dtab_size(char **str);
char	*deli_char(char c);
char	*deli_char_over_delim(char c, int i, int j);
int		over_2_delims_i(char **str, int i, int k);
/*			builtins			*/
int		ft_echo(char **inputs);
int		ft_env(char **envp);
int		ft_exit(char **inputs, t_setting **set);
int		ft_export(t_setting **set, char **inputs);
int		ft_unset(t_setting **set, char **inputs);
int		ft_pwd(void);
int		ft_cd(char **inputs);


void	test_ft(char **argv, char **envp, t_setting **set);

/*temp*/
char	*convertion(t_setting **set, char *str);
char	*del_quotes(t_setting **set, char *str);

#endif