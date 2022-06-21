SRCS = ft_printf.c ft_printf_utils.c ft_printf_fsf.c
OBJS = ${SRCS:.c=.o}
bSRCS = ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_fsf_bonus.c
bOBJS = ${bSRCS:.c=.o}
NAME = libftprintf.a
bNAME = libftprintf_bonus.a
LIB = libft.a
CC = gcc
CFLAGS =  -Wall -Wextra -Werror -g
AR = ar vrcs
RM = rm -vf
MK =  make --directory=libft/
MV = mv -v


$(NAME): $(LIB) $(OBJS)
	$(AR)   libft/$(LIB) $(OBJS)
	$(MV) libft/$(LIB) $(NAME)
bonus:  $(bNAME)
$(bNAME): $(LIB) $(bOBJS)
	$(AR)   libft/$(LIB) $(bOBJS)
	$(MV) libft/$(LIB) $(bNAME)
$(LIB):
	$(MK) all
all: $(NAME)
clean:
	$(RM) $(OBJS) $(bOBJS)
	$(MK) clean
fclean:
	$(RM) $(NAME)  $(OBJS) $(bOBJS)
	$(MK) fclean
re: fclean all
.PHONY: fclean all re clean
