/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:51:51 by siychoi           #+#    #+#             */
/*   Updated: 2023/07/29 19:32:27 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(int **array, int **index);

int	isvalid(int **out, int x, int y, int num);

void	printout(int **out)
{
	int		idx;
	char	o;

	idx = 0;
	while (idx < 16)
	{
		o = out[idx / 4][idx % 4] + 48;
		write(1, &o, 1);
		if (idx % 4 != 3)
			write(1, " ", 1);
		if (idx % 4 == 3)
			write(1, "\n", 1);
		idx++;
	}
}

void	make_arr(int **out, int x, int y, int **index)
{
	int	num;

	num = 1;
	while (num < 5)
	{
		if (isvalid(out, x, y, num))
		{
			out[x][y] = num;
			if (x == 3 && y == 3)
			{
				if (check(out, index) == 1 && index[2][0] == 0)
				{
					index[2][0] = 1;
					printout(out);
				}
				return ;
			}
			if (y == 3)
				make_arr(out, x + 1, 0, index);
			else
				make_arr(out, x, y + 1, index);
		}
		num++;
	}
	return ;
}

int	isvalid(int **out, int x, int y, int num)
{
	int	i;

	i = 0;
	if (x == 0 && y == 0)
		return (1);
	while (i < y)
	{
		if (num == out[x][i])
			return (0);
		i++;
	}
	i = 0;
	while (i < x)
	{
		if (num == out[i][y])
			return (0);
		i++;
	}
	return (1);
}
