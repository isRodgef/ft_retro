all:
	clang++ -Wall -Werror -Wextra Arena.class.cpp Empty.class.cpp Enemy.class.cpp GameEntity.class.cpp Player.class.cpp main.cpp  Arena.hpp  Empty.hpp Enemy.hpp GameEntity.hpp Player.hpp   -lncurses
	cp a.out ft_retro
clean:
	rm Arena.hpp.gch Empty.hpp.gch Enemy.hpp.gch GameEntity.hpp.gch Player.hpp.gch

fclean: clean
	rm a.out ft_retro
re: fclean all
