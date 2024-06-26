/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:28:12 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/26 08:29:16 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>

void ft_chdir(t_data *data)
{
	printf(">> path : %s\n", data->path);
	if (strlen(data->path) == 0)
	{
		data->path = getenv("HOME");
		if (data->path == NULL)
		{
			printf("minishell: cd: HOME not set\n");
			return;
		}
		if (chdir(data->path) != 0)
			perror("minishell : cd");
	}
	else if (chdir(data->path) != 0)
		perror("minishell : cd");
}
void ft_pwd()
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("minihsell");
	return;
}

void	ft_ls(char *cmd)
{
	char *args[3];
	char *envp;
	char *path;
	int i = 0;

	cmd = cmd + 2;
	envp = NULL;
    while (*cmd == ' ' || *cmd == '\t')
        cmd++;
    if (*cmd == '\0') 
        cmd = ".";
	printf(">> cmd :%s", cmd);
	printf("|\n");
	while (cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != '\0')
		i++;
	printf(">> i : %d\n", i);
	path = (char *)malloc(sizeof(char) * i);
	path[i] = '\0';
	i--;
	while (i >= 0)
	{
		path[i] = cmd[i];
		i--;
	}
	printf(">> path :%s", path);
	printf("|\n");
	args[0] = "/bin/ls";
    args[1] = path;
    args[2] = NULL;
    if (fork() == 0) 
    {
        execve(args[0], args, &envp);
        perror("minishell");
        exit(1);
    }
    wait(NULL);
    return;
}
