/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:15 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/05 14:54:13 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_master *m)
{
	mlx_destroy_window(m->cub.mlx, m->cub.win);
	exit_err(m, "Closing Window...\n", 1);
	return (0);
}

int	win_init(t_master *m)
{
	m->cub.mlx = mlx_init();
	m->cub.win = mlx_new_window(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT, "cub3d");
	return (0);
}

// int	input(int keycode, t_master *master)
// {
// 	if (keycode == 53)
// 		exit_free(master);
// 	else if (keycode == 13)
// 		move_char(master, FORWARD);
// 	else if (keycode == 1)
// 		move_char(master, BACKWARD);
// 	else if (keycode == 0)
// 		move_char(master, LEFT);
// 	else if (keycode == 2)
// 		move_char(master, RIGHT);
// 	else if (keycode == 123)
// 		master->m_cub->angle -= ANGLE;
// 	else if (keycode == 124)
// 		master->m_cub->angle += ANGLE;
// 	else
// 		return (0);
// 	// game_loop(master);
// 	printf("posx:%f | posy:%f | angle:%f\n", master->m_cub->posx, master->m_cub->posy, master->m_cub->angle);
// 	return (0);
// }

int	map_init(t_master *m, char *file)
{
	init_map_vars(m);
	map_size(m, file);
	map_assign(m, file);
	if (map_check(m) == 1)
	{
		free_funct(m->map.layout);
		return (1);
	}
	return (0);
}

int	hooks(t_master *master)
{
	mlx_key_hook(master->m_cub->win, input, master);
	// (void)master;
	return (0);
}

int	main(int ac, char **av)
{
	t_master	m;

	if (ac != 2)
	{
		printf("invalid input\n");
		return (1);
	}
	if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		exit_err(&m, "Error\nInvalid Filename\n", 0);
	if (map_init(&m, av[1]) == 1)
		return (1);
	game(&m);
	win_init(&m);
	key_init(&m);
	mlx_hook(m.cub.win, 17, 0, close_window, &m);
	mlx_hook(m.cub.win, 2, 1L<<0, key_press, &m);
	mlx_key_hook(m.cub.win, key_release, &m);
	mlx_loop_hook(m.cub.mlx, actions, &m);
	mlx_loop(m.cub.mlx);
	return (0);
}

void	exit_err(t_master *m, char *message, int code)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	if (code == 1)
		free_funct(m->map.layout);
	exit(0);
}