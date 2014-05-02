CC=	cc
INCLUDES=	-I./include
CFLAGS=	-std=c99	-Wall	-g	$(INCLUDES)
LDFLAGS=	-dynamiclib
LFLAGS=	-L./lib
LIBS=	-lprod
LDIR=./lib
SDIR=./src
BUILDDIR=./build
LTARGET=$(LDIR)/libprod
TARGET=$(BUILDDIR)/prodinv
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
		menu.o

LOBJ=	$(patsubst	%,$(LDIR)/%,$(_LOBJ))

$(LDIR)/%.o: $(SDIR)/%.c
	$(CC)	$(CFLAGS)	-c	-fPIC	-o	$@	$<	$(INCLUDES)

$(LTARGET).dylib:	$(LOBJ)
	$(CC)	$(CFLAGS)	$(LDFLAGS)	-o	$@	$^	$(INCLUDES)	-lm

clean:
	rm	-rf	$(LDIR)/*	$(BUILDDIR)/*
