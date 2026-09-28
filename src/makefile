all:
	g++ -std=c++11 -Werror -Wall *.cpp -o campusguard

run: all
	./campusguard

memory:
	g++ -std=c++11 -Werror -Wall *.cpp -o campusguard
	valgrind --leak-check=full --show-leak-kinds=all ./campusguard
