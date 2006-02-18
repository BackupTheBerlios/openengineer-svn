CC=g++
CXXFLAGS=`wx-config --cflags` -ggdb -I /usr/X11R6/include -I ../../ -c
LDFLAGS=`wx-config --libs`
BUILDDIR=../../../build
SRCDIR=.

$(BUILDDIR)/OESketcher.o:OESketcher.cpp OESketcher.h
	$(CC) $(CXXFLAGS) OESketcher.cpp -o $(BUILDDIR)/OESketcher.o

debug:OESketcher.cpp OESketcher.h
	$(CC) $(CXXFLAGS) -ggdb OESketcher.cpp -o $(BUILDDIR)/OESketcher.o
