
#c:/Qt/Tools/QtCreator/bin/clang/lib/clang/5.0.1/include

BIN=grid
OBJS=Grid.o QtGrid.o Window.o main.o
GDIR=/cygdrive/c/unix/cygwin64/lib/gcc/x86_64-pc-cygwin/6.4.0
OPTS=-std=c++11 -I${GDIR}/include  -Ic:/unix/cygwin64/usr/include/qt5/
CPP=clang++
QTLIB=/cygdrive/c/Qt/Tools/QtCreator/bin/Qt5Core.dll

#############################################################################
#  Build Executable 
#############################################################################

all: $(BIN)

$(BIN): Grid.o QtGrid.o Window.o main.o
	$(CPP) $(OPTS) -B${GDIR} -L${GDIR} -o $@ $(OBJS) -L/cygdrive/c/unix/cygwin64/bin/ -lcygQt5Core-5 -lcygQt5Widgets-5 -lcygQt5Gui-5

#############################################################################
#  Build C++ object files
#############################################################################

main.o: main.cpp
	$(CPP) $(OPTS) -c  $<

Window.o: Window.cpp
	$(CPP) $(OPTS) -c  $<

Grid.o: Grid.cpp
	$(CPP) $(OPTS) -c  $<

QtGrid.o: QtGrid.cpp
	$(CPP) $(OPTS) -c  $<

#############################################################################
#  List all symbols in object files, demangle C++ names
#############################################################################

list-symbols: ${OBJS}
	nm  ${OBJS} | c++filt

ldd:	$(BIN)
	ldd $(BIN)

#############################################################################
#  Clean up generated files
#############################################################################

clean:
	rm -f *.o $(BIN)



