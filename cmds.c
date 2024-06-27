/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:28:12 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/27 06:30:52 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_chdir(t_data *data)
{
	if (strlen(data->path) == 0 || ft_strncmp(data->path, "~", 2) == 0)
	{
		data->path = getenv("HOME");
		if (data->path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
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
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		perror("minihsell");
	return;
}
