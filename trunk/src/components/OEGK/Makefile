CC=g++
CXXFLAGS=`wx-config --cflags` -ggdb -I /usr/X11R6/include -I ../../ -I . -c
LDFLAGS=`wx-config --libs` -lwx_gtk2_gl-2.6 -lGL -lGLU
OEHOMEDIR=../../..
BUILDDIR=$(OEHOMEDIR)/build
SRCDIR=$(OEHOMEDIR)/src

All:$(BUILDDIR)/OEGKCanvas.o $(BUILDDIR)/OEGKLine.o $(BUILDDIR)/OEGKPoint.o


$(BUILDDIR)/OEGKCanvas.o:OEGKCanvas.cpp OEGKCanvas.h OEGKContext.h OEGKView.h
	$(CC) $(CXXFLAGS) OEGKCanvas.cpp -o $(BUILDDIR)/OEGKCanvas.o

$(BUILDDIR)/OEGKPoint.o:OEGKPoint.cpp OEGKPoint.h IOEGKShape.h
	$(CC) $(CXXFLAGS) OEGKPoint.cpp -o $(BUILDDIR)/OEGKPoint.o

$(BUILDDIR)/OEGKLine.o:OEGKLine.cpp OEGKLine.h OEGKPoint.h IOEGKShape.h
	$(CC) $(CXXFLAGS) OEGKLine.cpp -o $(BUILDDIR)/OEGKLine.o
