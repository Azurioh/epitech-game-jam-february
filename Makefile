##
## EPITECH PROJECT, 2025
## epitech-game-jam-january
## File description:
## Makefile
##

NAME = BloonsIllusionTowerDefense7+PremiumDeluxeDefinitiveEditionCollectorReloaded

SRC         =   $(shell find . -name "*.cpp" -type f)

OBJ         =   $(SRC:.cpp=.o)

FLAGS       =   -W -Wall -Wextra -g -std=c++20

COMMON_LIBS =   -lraylib -lm -lpthread -ldl

LINUX_LIBS  =   -lGL -lrt -lX11 -lconfig++

MACOS_LIBS  =   -framework OpenGL -framework CoreFoundation

MACOS_INCLUDE_PATH = -I/opt/homebrew/opt/raylib/include
MACOS_INCLUDE_PATH += -I/opt/homebrew/Cellar/libconfig/1.7.3/include
MACOS_LIB_PATH = -L/opt/homebrew/opt/raylib/lib
MACOS_LIB_PATH +=  -L/opt/homebrew/Cellar/libconfig/1.7.3/lib -lconfig++

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    LIBS = $(COMMON_LIBS) $(LINUX_LIBS)
else ifeq ($(UNAME_S), Darwin)
    LIBS = $(COMMON_LIBS) $(MACOS_LIBS) $(MACOS_LIB_PATH)
    CXXFLAGS += $(MACOS_INCLUDE_PATH)
endif

CXXFLAGS    +=  $(FLAGS)

$(NAME):    $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) $(LIBS) $(LDFLAGS)

all:        $(NAME)

clean:
	rm -f $(OBJ)

fclean:     clean
	rm -f $(NAME)

re:         fclean all
