# libmat
This is a C matrix library.

In this library, matrices are defined as the following structures

typedef struct s_matrix
{
	double	**values;
	size_t	row;
	size_t	col;
}			t_matrix;
