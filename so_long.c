#include "so_long.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_putendl_fd("Error: Failed to initialize mlx.", 2);
		return (2);
	}
}
