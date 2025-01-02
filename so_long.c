#include "so_long.h"

void	exit_game(t_game_state *state)
{
	if (state->window)
		mlx_destroy_window(state->mlx, state->window);
	if (state->mlx)
	{
		mlx_destroy_display(state->mlx);
		free(state->mlx);
	}
	exit(0);
}

void	exit_error(t_game_state *state, char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit_game(state);
}

int	destroy_window_hook(void *state)
{
	exit_game((t_game_state *)state);
	return (0);
}

int	expose_hook(void *state)
{
	(void)state;
	return ft_printf("expose_hook\n");
}

int	key_hook(int keycode, void *state)
{
	if (keycode == KEY_ESC)
		exit_game((t_game_state *)state);
	return ft_printf("key_hook %i\n", keycode);
}

int	mouse_hook(int keycode, void *state)
{
	(void)state;
	return ft_printf("mouse_hook %i\n", keycode);
}

int	loop_hook(void *state)
{
	(void)state;
	return ft_printf("loop_hook\n");
}

int	main(int argc, char **argv)
{
	t_game_state	state;

	ft_bzero(&state, sizeof(state));
	if (argc != 2)
		return (ft_printf("Usage: ./so_long <ber_file_name>\n"), 0);
	if (fill_map_from_file(&state.map, argv[1]) < 0)
		exit_error(&state, "Failed to open map file.");
	state.mlx = mlx_init();
	if (!state.mlx)
		exit_error(&state, "Failed to initialize mlx.");
	state.window = mlx_new_window(state.mlx, 200, 200, "Test MLX");
	if (!state.window)
		exit_error(&state, "Failed to open a window.");
	mlx_key_hook(state.window, key_hook, &state);
	mlx_mouse_hook(state.window, mouse_hook, &state);
	mlx_expose_hook(state.window, expose_hook, &state);
	mlx_loop_hook(state.window, loop_hook, &state);
	mlx_hook(state.window, DestroyNotify, None, destroy_window_hook, &state);
	mlx_loop(state.mlx);
}
