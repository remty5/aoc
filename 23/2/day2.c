/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:17:59 by remty             #+#    #+#             */
/*   Updated: 2023/12/13 12:32:46 by remty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

#define RED 12
#define GREEN 13
#define BLUE 14

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		sum;
	int		rgb[128];
	int		game;
	char	**rolls;
	char	**colors;
	char	**color;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1) 
			return (1);
		sum = 0;
		game = 1;
		while ((line = get_next_line(fd)))
		{
			line = ft_split(line, ':')[1];
			rgb['v'] = 1;
			rolls = ft_split(line, ';');
			while (*rolls)
			{
				*rolls = ft_strtrim(*rolls, " \n");
				rgb['r'] = 0;
				rgb['g'] = 0;
				rgb['b'] = 0;
				colors = ft_split(*rolls, ',');
				while (*colors)
				{
					color = ft_split(*colors, ' ');
					rgb[(int)*color[1]] += ft_atoi(*color);
					colors++;
				}
				if (rgb['r'] > RED \
				 || rgb['g'] > GREEN \
				 || rgb['b'] > BLUE)
				{
					rgb['v'] = 0;
					break ;
				}
				rolls++;
			}
			if (rgb['v'])
				sum += game;
			game++;
		}
		ft_putnbr_fd(sum, 1);
		ft_putchar_fd('\n', 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("Usage: ", 1);
		ft_putstr_fd(*argv, 1);
		ft_putendl_fd(" <input file>", 1);
		return (1);
	}
}
