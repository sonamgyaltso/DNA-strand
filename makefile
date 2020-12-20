build_app:
	rm -f application.exe
	g++ -g -std=c++11 -Wall application.cpp -o application.exe
	
run_app:
	./application.exe

valgrind_app:
	valgrind --tool=memcheck --leak-check=yes ./application.exe
