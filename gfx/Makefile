# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: logan  <logan@42.us.org>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 10:03:24 by logan             #+#    #+#              #
#    Updated: 2018/08/12 18:04:33 by nkouris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mappy
LIST = main \
Window \
Map \
ServerMonitor \
Image2D \
ShadingProgram \
Window \
Time

SRC_DIR = src
OBJ_DIR = obj

SRC = $(addsuffix .cpp, $(addprefix src/, $(LIST)))
OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(LIST)))

CPPFLAGS = -std=c++14 \
$(shell pkg-config --cflags glfw3 glm) \
-g -O3 -march=native
#-fsanitize=address

LDFLAGS = -framework OpenGl \
$(shell pkg-config --libs glfw3 glm)
#-fsanitize=address

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\033[34;1mCompiling: \033[0m"$<
	@clang++ $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "\033[32;1mLinking.. \033[0m"
	@clang++ $(LDFLAGS) -o $@ $^
	@echo "\033[32;1mCreated:\033[0m "$(NAME)

clean:
	@echo "\033[31;1mCleaning..\033[0m"
	@rm -f $(OBJ)
	@rm -f lib/lodepng/lodepng.o

fclean:
	@echo "\033[31;1mFull Cleaning..\033[0m"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -f lib/lodepng/liblodepng.a

re:	fclean all



deps:
	@./deps.sh

.PHONY: clean fclean all re docs
