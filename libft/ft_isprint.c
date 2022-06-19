int	ft_isprint(int c)
{
	/* printable characters are everything but the control characters in ascii */

	return((c > 31 && c < 127));
}

