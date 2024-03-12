/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:41:22 by siychoi           #+#    #+#             */
/*   Updated: 2023/07/23 17:05:36 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_midline(char *mid, char width)
{
	char	x;

	x = 0;
	while (x < width - 2)
	{
		ft_putchar(mid[1]);
		x++;
	}
}

void	ft_put_line(char *alphabet, char width, char line_num)
{
	if (line_num == 1)
	{
		ft_putchar(alphabet[0]);
		ft_put_midline(alphabet, width);
		if (width > 1)
			ft_putchar(alphabet[2]);
	}
	else
	{
		ft_putchar(alphabet[2]);
		ft_put_midline(alphabet, width);
		if (width > 1)
			ft_putchar(alphabet[0]);
	}
	ft_putchar(10);
}

void	rush(int width, int length)
{
	char	x;
	char	y;
	char	alphabet[3];
	char	separator[2];

	y = 0;
	alphabet[0] = 'A';
	alphabet[1] = 'B';
	alphabet[2] = 'C';
	separator[0] = 10;
	separator[1] = ' ';
	ft_put_line(alphabet, width, 1);
	while (y < length - 2)
	{
		x = 0;
		ft_putchar(alphabet[1]);
		ft_put_midline(separator, width);
		if (width > 1)
			ft_putchar(alphabet[1]);
		ft_putchar(separator[0]);
		y++;
	}
	if (length > 1)
		ft_put_line(alphabet, width, 2);
}
