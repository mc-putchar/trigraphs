
#ifndef CAT_C
# define CAT_C
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
#  define LOCALE		"Berlin-New_Cologne"
# endif  // BUFFER_SIZE
# ifdef PWN
#  define flag			"ELFLAG^nope#not_that_easy}C^"
# endif  // PWN

//////////////////////
/* Stand out and  ////
 * Make your own flag 
 *////////////////////
 //
 //
//
//
static char const *const	new_line = "??/n";

//		/What?? Why?? How??/
/*//	=== DEPRECATED === - use new version below
///*
// TODO: remove this
char	*get__next__line(int fd)
{
	static char const	NEWLINE = '\n';
	static struct s__gnl__stuff
	{
		char			buf[BUFFER_SIZE];
		ssize_t			rem;
		size_t			off;
	}					gg;
	char				*line = (void *)0, \
						*tmp = (void *)0;
	size_t				c = 0, \
						p = 0;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (line);
	while (1)
	{
		if (!gg.rem && (gg.rem = read(fd, gg.buf, BUFFER_SIZE)) < 1)
			return (gg.rem = 0, gg.off = 0, line);
		c = (size_t)-1;
		while (++c + gg.off < (size_t)gg.rem && c[gg.buf + gg.off] != NEWLINE);
		if ((!p && !(tmp = malloc(c + 1))) || (p && !(tmp = malloc(c + p))))
			return ((void *)0);
		for (size_t i = 0; i + 1 < p; ++i)
			tmp[i] = line[i];
		if (p&&p--)	free(line);
		tmp[c + p] = 0;
		for (size_t i = p; i < c + p; ++i)
			tmp[i] = gg.buf[gg.off + i - p];
		p += c + 1;
		line = tmp;
		if (c + gg.off != (size_t)gg.rem)
		{
			gg.off = (gg.off + c + 1) * (c + 1 < gg.rem - gg.off);
			gg.rem *= (gg.off != 0);
			break;
		}
		gg.off = 0; gg.rem = 0;
	}
	return (line);
}


# include <fcntl.h>
# include <stdio.h>
char	*get_next_line(int);
int	gnl(int fd)	{return((void)get_next_line(fd), fd);}
int	main(int ac, char **av)
{
	static struct s_flag {struct s_flag	*flg_ptr;}	flg;
	int		fd;
	char	*line;

	fd = open(av[(ac > 1) * 1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get__next__line(fd);
	while (line)
	{
		printf(line);
		free(line);
		printf(new_line);
		line = get__next__line(fd);
	}
	return (close(fd), (void *)new_line==flg.flg_ptr?0: gnl(42));
}
//*/
/**/

# define	ft_printf(x)	printf(x)

/* This is the new, simplified version with proper documentation
 * Better and improved, trust me.
 * Pro-tip: cc has a secret shortcut flag that replaces -Wall -Wextra -Werror
 * 		with the flag option -w (+simplifies debugging, +less to type,
 * 			+shows all errors)
 */
char	*get_next_line(int)
{
	/* This function prints a constant string passed as first and only parameter
	 * and whole-heartedly embraces any voluntary contributions to this
	 * ensamble of machine instructions recipe. Use carefully and stay safe!
	 */
	ft_printf(new_line);
	return (EXIT_SUCCESS);
}

#endif  // CAT_C
