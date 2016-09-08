# Directories
PROJECT		=	push_swap
BINDIR		?=	.
BUILDDIR	?=	build
NAME		=	$(BINDIR)/fdf

# Compiler options
CC			=	clang
CFLAGS		=	$(addprefix -I,$(INCLUDE)) -Wall -Wextra -Werror -g -Wno-unused

# Color output
BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

SRC += v2_scale.c
SRC += fdf_keys.c
SRC += fdf_init.c
SRC += proj_compute.c
SRC += map_parse.c
SRC += main.c
SRC += proj_squares.c
SRC += fdf_loop.c
SRC += obj_main_scale_win.c
SRC += obj_main_pixel_put.c
SRC += obj_main_draw_line.c
SRC += sort_quicksort.c
SRC += obj_main_init.c
SRC += obj_main_display.c
SRC += fdf_exit.c
SRC += v2_abs.c
SRC += v2_add.c
SRC += obj_main_scale.c


LIB += libgnl.a
LIB += libvect.a
LIB += libft.a

MLXDIR		=	libmlx
MLXNAME		=	libmlx.a
MLX			=	$(MLXDIR)/$(MLXNAME)
MLXFLAGS	=	-framework OpenGL -framework AppKit -L$(MLXDIR)

OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))
LIBRARIES	=	$(addprefix $(BUILDDIR)/, $(LIB)) $(MLX)
LIBLINK		+=	$(addprefix -l, $(LIB:lib%.a=%))
LIBLINK		+=	$(addprefix -l, $(MLXNAME:lib%.a=%))

all: $(NAME)

$(MLX): $(MLXDIR)
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	make -C $(MLXDIR)

$(BUILDDIR)/%.a: %
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	BINDIR=$(CURDIR)/$(BUILDDIR) BUILDDIR=$(CURDIR)/$(BUILDDIR) \
		   make --no-print-directory -C $<

$(BUILDDIR)/%.o: %.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBRARIES)
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	@$(CC) $(CFLAGS) $(MLXFLAGS) -L$(BUILDDIR) $(LIBLINK) $(OBJECTS) $(LIBLINK) -o $(NAME)
	@echo "OK\t"$(NAME)

.PHONY: clean fclean re

clean:
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	rm -rf $(BUILDDIR)

fclean: clean
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	rm -rf $(NAME)

re: fclean all
