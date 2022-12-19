/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:12:39 by sismaili          #+#    #+#             */
/*   Updated: 2022/12/19 20:53:36 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_spl(t_data *data, int fd)
{
	int	i;

	i = 0;
	data->line = get_next_line(fd);
	data->spl = ft_split(data->line, '\n');
	while(data->spl[i])
		i++;
	data->elements = malloc(sizeof(char *) * 6);
	data->map = malloc(sizeof(char *) * (i - 6));
	if (!data->elements || !data->map)
		return ;
	i = 0;
	while (data->spl[i])
	{
		if (i < 6)
			data->elements[i] = ft_strdup(data->spl[i]);
		else
			data->map[i - 6] = ft_strdup(data->spl[i]);
		i++;
	}
	data->elements[6] = 0;
	data->map[i] = 0;
}