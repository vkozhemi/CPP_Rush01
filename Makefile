# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 15:58:04 by nkuchyna          #+#    #+#              #
#    Updated: 2018/10/13 15:58:06 by nkuchyna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	ft_gkrellm
OBJ_DIR 	= 	./obj/
SRC_DIR 	= 	./src/
FLAGS 		= 	-Wall -Wextra -Werror
SRC 		= 	main.cpp Display.cpp DataTime.cpp OS_info.cpp Hostname.cpp CPU.cpp RAM.cpp Network.cpp DisNcur.cpp Processes.cpp
OBJ 		= 	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
HDRS 		=	-I ./inc/
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-F./frameworks
INC			=	./inc/Display.hpp ./inc/DataTime.hpp ./inc/IMonitorModule.hpp ./inc/OS_info.hpp\
./inc/Hostname.hpp ./inc/CPU.hpp ./inc/RAM.hpp ./inc/Network.hpp ./inc/DisNcur.hpp ./inc/Processes.hpp
FRAMEWORKS  =   -F./frameworks \
				-rpath ./frameworks \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \

all: $(NAME)

$(NAME): $(OBJ)
		clang++ $(FLAGS) $(OBJ) -o $(NAME) $(HDRS) $(FRAMEWORKS) $(INCLUDES) -lncurses
		
$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:  $(SRC_DIR)%.cpp $(INC)
			clang++ -c $< -o $@ $(FLAGS) $(HDRS) $(INCLUDES)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all