/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:09:10 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/03/28 15:00:59 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_null(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || s1 == NULL || s2 == NULL)
		return (handle_null(s1, s2, n));
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	handle_null(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || (s1 == NULL && s2 == NULL))
		return (0);
	else if (s1 != NULL && s2 == NULL)
		return (s1[0]);
	else if (s1 == NULL && s2 != NULL)
		return (s2[0]);
	return (0);
}

/* 
int main()
{
	
	char s1[] = "abcdefg";
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, "abcefg", i));
		printf("%d\n", ft_strncmp(s1, "abcefg",i));
	}
	
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, "abcefg", i));
		printf("%d\n", ft_strncmp(s1, "abcefg", i));
	}
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, "", i));
		printf("%d\n", ft_strncmp(s1, "", i));
	}
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp("", "abcefg", i));
		printf("%d\n", ft_strncmp("", "abcefg", i));
	}

	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, s1 + 2, i));
		printf("%d\n", ft_strncmp(s1, s1 + 2, i));
	}

	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1 + 2, s1, i));
		printf("%d\n", ft_strncmp(s1 + 2, s1, i));
	}

	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp("012345", "012", i));
		printf("%d\n", ft_strncmp("012345", "012", i));
	}
	
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
 */
