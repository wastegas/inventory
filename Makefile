CC=	gcc
INCLUDES=	-I./include
CFLAGS=	-std=c11	`pkg-config --cflags glib-2.0`	\
			-Wall	-O3	-g	-D_GNU_SOURCE	$(INCLUDES)
LDFLAGS=	-dynamiclib	`pkg-config --libs glib-2.0`
LFLAGS=	-L./build/lib	-L$(DYLD_LIBRARY_PATH)
LIBS=	-lprod
LDIR=./lib
SDIR=./src
BUILDDIR=./build/bin
TARGET=$(BUILDDIR)/prodinv
LTARGET=./build/lib/libprod
vpath	%.c	./src
vpath	%.h	./include

$(TARGET):	$(SDIR)/main.c	$(LTARGET).dylib
	$(CC)	$(CFLAGS)	$(OBJS)	-o	$@	$^	$(INCLUDES)	$(LFLAGS)	$(LIBS)

_LOBJ=	\
		add.o	\
		print.o	\
		delete.o	\
		edit.o	\
		search.o	\
		openfile.o	\
		getinput.o \
		menu.o

LOBJ=	$(patsubst	%,$(LDIR)/%,$(_LOBJ))

$(LDIR)/%.o: $(SDIR)/%.c
	$(CC)	$(CFLAGS)	-c	-fPIC	-o	$@	$<	$(INCLUDES)

$(LTARGET).dylib:	$(LOBJ)
	$(CC)	$(CFLAGS)	$(LDFLAGS)	-o	$@	$^	$(INCLUDES)	-lm

clean:
	rm	-rf	$(LDIR)/*	$(BUILDDIR)/*
