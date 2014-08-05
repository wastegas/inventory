CC=	gcc
INCLUDES=	-I./include
CFLAGS=	-std=gnu11	-Wall	-O3	-g	$(INCLUDES)
LDFLAGS=	-dynamiclib
LFLAGS=	-L./build/lib
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
