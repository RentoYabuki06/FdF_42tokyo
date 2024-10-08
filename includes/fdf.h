/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:44:09 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 17:17:43 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>
# include <stdbool.h>

# define WIDTH 1280
# define HEIGHT 920
# define RATE 1.3913043478
# define COS_30 0.86602540378
# define SIN_30 0.52532198881

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	size_t	dr;
	size_t	dg;
	size_t	db;
}				t_rgb;

typedef struct s_line
{
	double	px;
	double	py;
	double	lx;
	double	ly;
	double	dx;
	double	dy;
	size_t	lenght;
	int		lred;
	int		lgreen;
	int		lblue;
	double	dred;
	double	dgreen;
	double	dblue;
}				t_line;

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	double		iso_x;
	double		iso_y;
	double		screen_x;
	double		screen_y;
	uint32_t	color;
}				t_point;

typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_point	*point3d;
	double	max_ix;
	double	min_ix;
	double	max_iy;
	double	min_iy;
	double	d_ix;
	double	d_iy;
}				t_map;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	t_map		*map;
}				t_fdf;

void		ft_initcheck_file(char *filename);
t_fdf		*ft_init_fdf(char **argv);
t_map		*ft_init_map(void);
void		ft_read_map(char *filename, t_map *map);
int			ft_count_col(const char *line, char c);
uint32_t	ft_hextoi(char *str);
void		ft_conv_iso(t_map *map);
void		ft_draw_line(t_fdf *fdf);
void		ft_error_exit(char *str);
uint32_t	ft_abs(int num);
void		ft_put_on_pixel(t_fdf *fdf, int x, int y, uint32_t color);
int			ft_close_win(void *prm);
int			ft_close_esc(int keycode, t_fdf *fdf);

#endif