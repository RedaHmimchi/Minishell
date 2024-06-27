/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:00:27 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/27 09:08:21 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

extern char **environ;

typedef struct s_data
{
	char    *cmd;
	char    *path;
	int     start_path;
	char	**bins;
	char	**args;
}	t_data;

// libft
size_t  ft_strlen(const char *str);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putstr_fd(char *s, int fd);

//
void    execute_command(char *cmd, t_data *data) ;
void    initialize_shell();
void    cleanup_shell();
void	execute_command_in_bin(t_data *data);
void    parse_command(char *input, t_data *data);
void	parse_path(char *input, t_data *data);
void	parse_rest(char *input, t_data *data);
void	parse_bin(char *input, t_data *data);

// libft
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s1, size_t n);

void	parse_args(char *input, t_data *data);

// commands
void    print_sorted_env();
void    ft_echo(char *cmd);
void    ft_chdir(t_data *data);
void    ft_pwd();

// signals
void    initialize_signals();
void    sigint_handler(int sig);
void    sigquit_handler(int sig);

#endif