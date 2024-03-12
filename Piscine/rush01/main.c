/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:30:29 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/29 19:59:52 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		isvalid(int **out, int x, int y, int num);
void	make_arr(int **out, int x, int y, int **index);

int	ft_push_detect_error(int **index, char	**argv, int idx, int num_count)
{
	while (argv[1][idx] != 0)
	{
		if (num_count >= 16)
			num_count++;
		else if ((argv[1][idx] >= '1' && argv[1][idx] <= '4') && idx % 2 == 0)
		{
			index[num_count / 8][num_count % 8] = argv[1][idx] - '0';
			num_count++;
		}
		else if (argv[1][idx] != 32 && idx % 2 == 1)
			return (0);
		idx++;
	}
	if (num_count != 16)
		return (0);
	return (1);
}

int	**allocation(int **array, int y, int x)
{
	int	i;

	i = 0;
	array = (int **)malloc(sizeof(int *) * y);
	while (i < y)
	{
		array[i] = (int *)malloc(sizeof(int) * x);
		i++;
	}
	return (array);
}

int	main(int argc, char *argv[])
{
	int	**out;
	int	**index;

	out = 0;
	out = allocation(out, 4, 4);
	index = 0;
	index = allocation(index, 3, 8);
	if (argc != 2 || out == 0 || index == 0
		|| !ft_push_detect_error(index, argv, 0, 0))
	{
		write(1, "Error\n", 6);
		free(out);
		free(index);
		return (0);
	}
	index[2][0] = 0;
	make_arr(out, 0, 0, index);
	if (index[2][0] == 0)
		write(1, "Error\n", 6);
	free(out);
	free(index);
	return (0);
}
