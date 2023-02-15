CC=g++ -std=c++17
EXECUTABLE=result_file
APP = viewer.app

all:  install clean

install:
	qmake viewer.pro -o Makefile_qt
	make -f Makefile_qt
	mkdir $(HOME)/Desktop/3Dviewer_v2/
	cp -rf $(APP) $(HOME)/Desktop/3Dviewer_v2/
	
uninstall:
	rm -rf $(HOME)/Desktop/3Dviewer_v2/

tests: clean
	g++ -c tests.cc -lgtest -lstdc++
	./test

dist:
	cp -rf main.cpp viewer.pro Makefile controller/*.cpp controller/*.h view/*.ui view/*.cpp view/*.h model/*.h model/*.cpp 3Dviewer_v2/src
	cd ..; tar czvf 3Dviewer_v2.tgz 3Dviewer_v2/*
	mv ../3Dviewer_v2.tgz $(HOME)/Desktop/
	rm -rf ../3Dviewer_v2

clang:
	cp -f ../materials/linters/.clang-format clang-format
	clang-format -i controller/*.* view/*.cpp view/*.h model/*.*
	clang-format -n controller/*.* view/*.cpp view/*.h model/*.*
	rm -rf clang-format

cppcheck:
	@cppcheck --enable=all --suppress=unusedFunction --language=c++ --suppress=missingInclude ../src/*.cpp ../src/*.h ../src/controller/* ../src/view/*.cpp ../src/view/*.h ../src/model/*

clean:
	rm -rf viewer.app .qmake.stash Makefile_qt moc_viewer.cpp moc_mainwindow.cpp moc_predefs.h moc_glview.cpp
	rm -rf a.out *.o *.a *.gcda *.gcno *.gcov *.info tests gcov_report report man.pdf man.dvi man.log man result_file
	rm -rf ../3Dviewer_v2.tgz
	rm -rf ui_mainwindow.h

dvi:
	open ./manual/dvi.html

rebuild: clean all
