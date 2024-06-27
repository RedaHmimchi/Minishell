/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:07:09 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/27 09:08:17 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_command_in_bin(t_data *data)
{
    char *path;
    char *cmd;
    char **bins;
    pid_t pid;
    int slash = 0;

    bins = data->bins;
    int i = 0;
    while (data->cmd[i] != '\0')
    {
        if (data->cmd[i] == '/')
        {
            slash = 1;
            break ;
        }
        i++;
    }
    pid = fork();
    if (pid < 0)
    {
        perror("minishell");
        exit(1);
    }
    if (pid == 0)
    {
        if (slash == 1)
        {
            execve(data->cmd, data->args, environ);
            perror("minishell");
            exit(1);
        }
        while (*bins)
        {
            path = ft_strjoin(*bins, "/");
            cmd = ft_strjoin(path, data->cmd);
            if (access(cmd, F_OK) == 0)
            {
                execve(cmd, data->args, environ);
                perror("minishell");
                exit(1);
            }
            // free(path);
            // free(cmd);
            bins++;
        }
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(data->cmd, 2);
        ft_putstr_fd(": command not found\n", 2);
    }
    if (pid > 0)
        waitpid(pid, NULL, 0); // an7tajha mn b3d 3la wed l parent (bach n catcher signals)
}