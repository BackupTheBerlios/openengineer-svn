CC=g++
CXXFLAGS=`wx-config --cflags` -ggdb -I /usr/X11R6/include -I . -c
LDFLAGS=`wx-config --libs` -lwx_gtk2_gl-2.6 -lwx_gtk2_foldbar-2.6 -lGL -lGLU
OEHOMEDIR=..
BUILDDIR=$(OEHOMEDIR)/build
SRCDIR=$(OEHOMEDIR)/src

OpenEngineer:$(BUILDDIR)/OEApp.o $(BUILDDIR)/OEBasicFrame.o $(BUILDDIR)/OEDebug.o $(BUILDDIR)/OENewDialog.o $(BUILDDIR)/OESketcher.o $(BUILDDIR)/OEGKCanvas.o $(BUILDDIR)/OEGKLine.o $(BUILDDIR)/OEGKPoint.o
	$(CC) $(LDFLAGS) $(BUILDDIR)/OEApp.o $(BUILDDIR)/OEBasicFrame.o $(BUILDDIR)/OEDebug.o $(BUILDDIR)/OENewDialog.o $(BUILDDIR)/OESketcher.o $(BUILDDIR)/OEGKCanvas.o $(BUILDDIR)/OEGKLine.o $(BUILDDIR)/OEGKPoint.o -o $(BUILDDIR)/OpenEngineer

$(BUILDDIR)/OEApp.o:OEApp.cpp OEApp.h
	$(CC) $(CXXFLAGS) OEApp.cpp -o $(BUILDDIR)/OEApp.o

$(BUILDDIR)/OEBasicFrame.o:OEBasicFrame.cpp OEBasicFrame.h
	$(CC) $(CXXFLAGS) OEBasicFrame.cpp -o $(BUILDDIR)/OEBasicFrame.o

$(BUILDDIR)/OEDebug.o:OEDebug.cpp OEDebug.h
	$(CC) $(CXXFLAGS) OEDebug.cpp -o $(BUILDDIR)/OEDebug.o

$(BUILDDIR)/OENewDialog.o:OENewDialog.cpp OENewDialog.h
	$(CC) $(CXXFLAGS) OENewDialog.cpp -o $(BUILDDIR)/OENewDialog.o

clean:
	rm $(BUILDDIR)/*.o
	rm $(BUILDDIR)/OpenEngineer
