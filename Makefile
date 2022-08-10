NAME = minilibx_template.out


INC = includes
SRC = src/*.c

LIBX = minilibx
INCS = -I$(LIBX) -I$(INC)
LIBS = minilibx/libmlx.a -L$(LIBX) -lmlx
FLAGS = $(INCS) $(LIBS) -framework OpenGL -framework Appkit

all:
	@clear
	@echo -n Compiling Libs...
	@make -s -C $(LIBX)
	@echo Done
	@echo -n Compiling so_long...
	@gcc $(SRC) $(FLAGS) -o $(NAME)
	@echo Done

run:
	@clear
	@echo -n Compiling Libs...
	@make -s -C $(LIBX)
	@echo Done
	@echo -n Compiling so_long...
	@gcc $(SRC) $(FLAGS) -o $(NAME)
	@echo Done
	@echo Running...
	@echo press esc to exit
	@./$(NAME)
	@echo .


git:
	@clear
	@git add .
	@echo "commit msg" 
	@read COMMIT; \
	git commit -m "$$COMMIT"; \
	git push;

clean:
	@rm -rf $(NAME)
	@make -s clean -C $(LIBX)

norm:
	@clear
	@norminette $(INC) $(SRC)