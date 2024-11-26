##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my C project with Epitech formatting and progress bar
##

SRC		=	main.c	\
			open_file.c	\
			read_file.c	\
			rewrite_file.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_program

CC		=	gcc

# Default target to build the project
all:	$(NAME)

# Linking the object files to create the executable
$(NAME):	$(OBJ)
	@echo "Linking..."
	@$(CC) $(OBJ) -o $(NAME)
	@echo "[Done]"

# Compiling the source files into object files
%.o:	%.c
	@echo -n "Compiling $<... "
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[Done]"

# Clean target to remove object files and executable
clean:
	@echo "Cleaning..."
	@rm -f $(OBJ) $(NAME)
	@echo "[Done]"

# Rebuild the project: clean and then all, also runs the Makefile in manage_files
re: clean all
	@echo "Running Makefile in manage_files directory..."
	@echo "[Done]"
