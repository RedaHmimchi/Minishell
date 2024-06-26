/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:00:27 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/26 08:10:28 by rhmimchi         ###   ########.fr       */
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

typedef struct s_data
{
	char    *cmd;
    char    *path;
    int     start_path;
}                t_data;

void    execute_command(char *cmd, t_data *data) ;
void    initialize_shell();
void    cleanup_shell();
int     ft_strncmp(const char *str1, const char *str2, size_t n);
void    parse_command(char *input, t_data *data);
void	parse_path(char *input, t_data *data);
void	parse_rest(char *input, t_data *data);

// commands
void    print_sorted_env();
void    ft_echo(char *cmd);
void    ft_chdir(t_data *data);
void    ft_pwd();
void    ft_ls(char *cmd);

#endif