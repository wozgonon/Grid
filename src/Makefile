
#c:/Qt/Tools/QtCreator/bin/clang/lib/clang/5.0.1/include

BINS=../bin/tsvgrid ../bin/multiplicationgrid
OBJS=Grid.o QtGrid.o Window.o 
GDIR=/cygdrive/c/unix/cygwin64/lib/gcc/x86_64-pc-cygwin/6.4.0
OPTS=-std=c++11 -I${GDIR}/include  -Ic:/unix/cygwin64/usr/include/qt5/
CPP=clang++
QTLIB=/cygdrive/c/Qt/Tools/QtCreator/bin/Qt5Core.dll

#############################################################################
#  Build Executable 
#############################################################################

all: $(BINS)

../bin/multiplicationgrid: Grid.o QtGrid.o Window.o tsvgrid.o multiplicationgrid.o
	$(CPP) $(OPTS) -B${GDIR} -L${GDIR} -o $@ multiplicationgrid.o $(OBJS) -L/cygdrive/c/unix/cygwin64/bin/ -lcygQt5Core-5 -lcygQt5Widgets-5 -lcygQt5Gui-5

../bin/tsvgrid: Grid.o QtGrid.o Window.o tsvgrid.o tsvgrid.o
	$(CPP) $(OPTS) -B${GDIR} -L${GDIR} -o $@ tsvgrid.o $(OBJS) -L/cygdrive/c/unix/cygwin64/bin/ -lcygQt5Core-5 -lcygQt5Widgets-5 -lcygQt5Gui-5

#############################################################################
#  Build C++ object files
#############################################################################

tsvgrid.o: TsvGrid.cpp
	$(CPP) $(OPTS) -c  $<

multiplicationgrid.o: multiplicationgrid.cpp
	$(CPP) $(OPTS) -c  $<

Window.o: Window.cpp
	$(CPP) $(OPTS) -c  $<

Grid.o: Grid.cpp
	$(CPP) $(OPTS) -c  $<

QtGrid.o: QtGrid.cpp
	$(CPP) $(OPTS) -c  $<


test:  ../bin/tsvgrid
	echo RUN xinit &
	(cd ../bin; cat test.tsv | ./tsvgrid)

#############################################################################
#  List all symbols in object files, demangle C++ names
#############################################################################

list-symbols: ${OBJS}
	nm  ${OBJS} | c++filt

ldd:	$(BINS)
	ldd $(BINS)

#############################################################################
#  Clean up generated files
#############################################################################

clean:
	rm -f *.o $(BINS)
