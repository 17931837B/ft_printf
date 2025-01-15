SRCS = ft_printf.c printf_char.c printf_conversion.c \
       printf_decimal.c printf_hex.c printf_string.c printf_unsigned.c \
       printf_pointer.c printf_string.c ft_putchar_fd.c ft_putnbr_fd.c \
       ft_putstr_fd.c ft_strlen.c


NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJC = $(SRCS:.c=.o)
OBJCB = $(SRCSB:.c=.o)
RM = rm -f
AR = ar rc

ifeq ($(MAKECMDGOALS), bonus)
	OBJ = $(OBJC) $(OBJCB)
else
	OBJ = $(OBJC)
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^
	ranlib $(NAME)

cd%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJC) $(OBJCB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
