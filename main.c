/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:15 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/02 22:01:21 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_button(t_master *master)
{
	t_cub *cub;
	
	cub = master->m_cub;
	mlx_destroy_window(cub->mlx, cub->win);
	write(1, "=================================\n", 34);
	write(0, "Exit\n", 5);
	write(1, "=================================\n", 34);
	exit(0);
}

int	win_init(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, MAP_WIDTH, MAP_HEIGHT, "cub3d");
	return (0);
}

int	input(int keycode, t_master *master)
{
	if (keycode == 53)
		exit_free(master);
	else if (keycode == 13)
		move_char(master, FORWARD);
	else if (keycode == 1)
		move_char(master, BACKWARD);
	else if (keycode == 0)
		move_char(master, LEFT);
	else if (keycode == 2)
		move_char(master, RIGHT);
	else if (keycode == 123)
		master->m_cub->angle -= 1;
	else if (keycode == 124)
		master->m_cub->angle += 1;
	else
		return (0);
	game_loop(master);
	printf("posx:%f | posy:%f | angle:%f\n", master->m_cub->posx, master->m_cub->posy, master->m_cub->angle);
	return (0);
}

int	map_init(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\033[0;31mError!\nInvalid File\033[0m\n", 2);
		return (1);
	}
	if (map_size(map, fd) == 1)
		return (1);
	fd = open(file, O_RDONLY);
	map->map_height = 0;
	if (map_assign(map, fd) == 1)
	{
		free_funct(map->map);
		return (1);
	}
	if (map_check(map) == 1)
	{
		free_funct(map->map);
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
	t_map	map;
	t_cub	cub;
	t_master master;

	if (ac != 2)
		return (1);
	if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		ft_putstr_fd("\033[0;31mError!\nInvalid File\033[0m\n", 2);
	if (map_init(&map, av[1]) == 1)
		return (1);
	game(&map, &cub);
	win_init(&cub);
	master.m_cub = &cub;
	master.m_map = &map;
	printf("init pos\nposx:%f | posy:%f | angle:%f\n\n", cub.posx, cub.posy, cub.angle);
	mlx_hook(master.m_cub->win, 17, 0, exit_button, &master);
	// mlx_key_hook(master.m_cub->win, input, &master);
	mlx_loop_hook(master.m_cub->mlx, hooks, &master);
	mlx_loop(master.m_cub->mlx);
	return (0);
}
