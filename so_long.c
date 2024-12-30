#include "so_long.h"

int	expose_hook(void *param)
{
	(void)param;
	return ft_printf("expose_hook\n");
}

int	key_hook(int keycode, void *param)
{
	(void)param;
	return ft_printf("key_hook %i\n", keycode);
}

int	mouse_hook(int keycode, void *param)
{
	(void)param;
	return ft_printf("mouse_hook %i\n", keycode);
}

int	loop_hook(void *param)
{
	(void)param;
	return ft_printf("loop_hook\n");
}

int	main(int argc, char **argv)
{
	void	*map;
	void	*mlx;
	void	*win;

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <ber_file_name>", 1), 0);
	(void)map;
	(void)argv;
	mlx = mlx_init();
	if (!mlx)
		return (ft_putendl_fd("Error: Failed to initialize mlx.", 2), 2);
	win = mlx_new_window(mlx, 200, 200, "Test MLX");
	if (!win)
		return (ft_putendl_fd("Error: Failed to open a window.", 2), 3);
	mlx_key_hook(win, key_hook, NULL);
	mlx_mouse_hook(win, mouse_hook, NULL);
	mlx_expose_hook(win, expose_hook, NULL);
	mlx_loop_hook(win, loop_hook, NULL);
//	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
