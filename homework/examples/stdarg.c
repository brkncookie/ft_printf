 #include <stdio.h>
 #include <stdarg.h>
 #include <stdlib.h>

/* a dumb variadic funtion */
int fmtstr(char *fmt, ...)
{
	va_list ap;
	int i;
	char c;
	char *s;


	va_start(ap, fmt);

	while(*fmt)
		switch(*fmt++)
		{
			case 's':
				s = va_arg(ap, char *);
				printf("string: %s\n", s);
				break;
			case 'c':
				c = (char) va_arg(ap, int);
				printf("char: %c\n", c);
				break;
			case 'i':
				i = va_arg(ap, int);
				printf("int: %i\n", i);
				break;
		}
	va_end(ap);

	return(0);
}

int main(int argc, char **argv)
{
	argc--;
	fmtstr(argv[1], atoi(argv[2]), atoi(argv[3]), argv[4]);
	return(0);
}

