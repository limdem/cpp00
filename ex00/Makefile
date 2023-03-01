CC = c++
RM = rm -f
C++FLAGS = -Wall -Wextra -Werror
C++STDFLAGS= -std=c++98
INCLUDES = 
NAME = megaphone
SRCS_DIR = ./
SRCS = megaphone.cpp
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(SRCS:.cpp=.o)

%.o: %.c
	${CC} -c ${C++FLAGS} ${C++STDFLAGS} ${INCLUDES} ${SRCS_PATH} $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
		c++ -o $(NAME) $(OBJS)

$(OBJS): $(SRCS_PATH)
	c++ -c ${C++FLAGS} ${C++STDFLAGS} ${INCLUDES} ${SRCS_PATH}

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: fclean re all clean