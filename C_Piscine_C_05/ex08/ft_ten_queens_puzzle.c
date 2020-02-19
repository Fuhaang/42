/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:48:47 by amassey           #+#    #+#             */
/*   Updated: 2020/02/19 17:11:19 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_absent_diag1(int row, int col, int echiquier[10][10])
{
	int nbqueens;

	nbqueens = 0;
	while (row != 0 || col != 0)
	{
		col--;
		row--;
	}
	while (row != 9 || col != 9)
	{
		if (echiquier[row][col] == 1)
			return (0);
		row++;
		col++;
	}
	return (1);
}

int		ft_absent_diag2(int row, int col, int echiquier[10][10])
{
	int nbqueens;

	nbqueens = 0;
	while (row != 9 || col != 0)
	{
		col--;
		row++;
	}
	while (row != 0 || col != 9)
	{
		if (echiquier[row][col] == 1)
			return (0);
		row--;
		col++;
	}
	return (1);
}

int		ft_absent_col(int col, int echiquier[10][10])
{
	int row;
	int nbqueens;

	row = 0;
	nbqueens = 0;
	while (row < 10)
	{
		if (echiquier[row][col] == 1)
			return (0);
		row++;
	}
	return (1);
}

int		ft_absent_row(int row, int echiquier[10][10])
{
	int col;
	int nbqueens;

	col = 0;
	nbqueens = 0;
	while (col < 10)
	{
		if (echiquier[row][col] == 1)
			return (0);
		col++;
	}
	return (1);
}

int		ft_valid_diag1(int row, int col, int echiquier[10][10])
{
	int nbqueens;

	nbqueens = 0;
	while (row != 0 || col != 0)
	{
		col--;
		row--;
	}
	while (row != 9 || col != 9)
	{
		if (echiquier[row][col] == 1)
			nbqueens++;
		row++;
		col++;
	}
	if (nbqueens != 1)
		return (0);
	return (1);
}

int		ft_valid_diag2(int row, int col, int echiquier[10][10])
{
	int nbqueens;

	nbqueens = 0;
	while (row != 9 || col != 0)
	{
		col--;
		row++;
	}
	while (row != 0 || col != 9)
	{
		if (echiquier[row][col] == 1)
			nbqueens++;
		row--;
		col++;
	}
	if (nbqueens != 1)
		return (0);
	return (1);
}

int		ft_valid_col(int col, int echiquier[10][10])
{
	int row;
	int nbqueens;

	row = 0;
	nbqueens = 0;
	while (row < 10)
	{
		if (echiquier[row][col] == 1)
			nbqueens++;
		row++;
	}
	if (nbqueens != 1)
		return (0);
	return (1);
}

int		ft_valid_row(int row, int echiquier[10][10])
{
	int col;
	int nbqueens;

	col = 0;
	nbqueens = 0;
	while (col < 10)
	{
		if (echiquier[row][col] == 1)
			nbqueens++;
		col++;
	}
	if (nbqueens != 1)
		return (0);
	return (1);
}

int		ft_valid_echiquier(int echiquier[10][10])
{
	int row;
	int col;

	row = 0;
	while (row < 10)
	{
		if (!(ft_valid_row(row, echiquier)))
			return (0);
		col = 0;
		while (col < 10)
		{
			if (!(ft_valid_col(col, echiquier))
				|| !(ft_valid_diag1(row, col, echiquier))
				|| !(ft_valid_diag2(row, col, echiquier)))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int		ft_solve(int echiquier[10][10], int position)
{
	int row;
	int col;

	if (position == 10 * 10 && ft_valid_echiquier(echiquier))
		return (1);
	row = position / 10;
	col = position % 10;
	if (ft_absent_diag1(row, col, echiquier)
		&& ft_absent_diag2(row, col, echiquier)
		&& ft_absent_col(col, echiquier)
		&& ft_absent_row(row, echiquier))
	{
		echiquier[row][col] = 1;
		if (ft_solve(echiquier, position + 1))
			return (1);
	}
	echiquier[row][col] = 0;
	return (0);
}

void	ft_print_echiquier(int echiquier[10][10])
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < 10)
	{
		while (col < 10)
		{
			write(1, &echiquier[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int j;
	int echiquier[10][10] =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	//echiquier = NULL;
	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			echiquier[i][j] = 0;
		}
	}
	if (ft_solve(echiquier, 0))
		ft_print_echiquier(echiquier);
	return (0);
}

int		main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
