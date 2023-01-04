/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2023/01/04 16:05:05 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->columns = ft_count_columns(data->map);
	data->rows = ft_count_rows(data->map);
	data->scale = 12;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->w_pressed = 0;
	data->a_pressed = 0;
	data->s_pressed = 0;
	data->d_pressed = 0;
	data->ri_pressed = 0;
	data->le_pressed = 0;
}

void	init_player_data(t_data *data, int x, int y)
{
	data->scale_3d = data->text.no_hei;
	data->width = data->columns * data->scale_3d;
	data->height = data->rows * data->scale_3d;
	data->player.x = x * data->scale_3d + (data->scale_3d / 2);
	data->player.y = y * data->scale_3d + (data->scale_3d / 2);
	data->player.x1 = x * data->scale + (data->scale / 2);
	data->player.y1 = y * data->scale + (data->scale / 2);
	data->player.rot_speed = 1.5 * (M_PI / 180);
	data->player.move_speed = 50;
	if (data->map[y][x] == 'N')
		data->player.rot_angle = 3 * M_PI / 2;
	else if (data->map[y][x] == 'S')
		data->player.rot_angle = M_PI / 2;
	else if (data->map[y][x] == 'E')
		data->player.rot_angle = 0;
	else if (data->map[y][x] == 'W')
		data->player.rot_angle = M_PI;
}

void	search_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				init_player_data(data, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = param;
	(void)y;
	if (x < WIDTH / 2)
		data->player.rot_angle = fmod(data->player.rot_angle - 0.05 + 2 * M_PI,
				2 * M_PI);
	else if (x >= WIDTH / 2)
		data->player.rot_angle = fmod(data->player.rot_angle + 0.05, 2 * M_PI);
	all_draw(data);
	mlx_mouse_move(data->win, WIDTH / 2, HEIGHT);
	mlx_mouse_hide();
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0 || valide_path(av[1], ".cub") == 0)
		{
			write(2, "Wrong path\n", 11);
			return (0);
		}
		fill_spl(&data, fd);
	// 	if (!check_elements(&data) || !map_check(&data))
	// 	{
	// 		free_all(&data);
	// 		write(2, "Error\nNot valid", 15);
	// 		return (0);
	// 	}
	// 	init_data(&data);
	// 	if (!get_add_image(&data))
	// 		return (0);
	// 	search_player(&data);
	// 	all_draw(&data);
	// 	mlx_hook(data.win, 17, 0, close_win, &data);
	// 	mlx_hook(data.win, 2, 0, ft_pressed, &data);
	// 	mlx_hook(data.win, 3, 0, ft_released, &data);
	// 	mlx_hook(data.win, 6, 0, mouse_move, &data);
	// 	mlx_loop_hook(data.mlx, ft_keys, &data);
	// 	mlx_loop(data.mlx);
	// }
	// else
	// {
	// 	write(2, "Check your arguments !\n", 23);
	// 	return (0);
	}
	// free_all(&data);
	return (1);
}
