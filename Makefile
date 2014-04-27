CC=	cc
INCLUDES=	-I./include
CFLAGS=	-std=c99	-Wall	-g	$(INCLUDES)
LDFLAGS=	-shared
LFLAGS=	-L./lib
LIBS=	-lprod
LDIR=./lib
SDIR=./src
BUILDDIR=./build
LTARGET=$(LDIR)/libprod
TARGET=$(BUILDDIR)/prodinv
vpath	%.c	./src
vpath	%.h	./include

$(TARGET):	$(SDIR)/main.c	$(LTARGET).so
	$(CC)	$(CFLAGS)	$(OBJS)	-o	$@	$^	$(INCLUDES)	$(LFLAGS)	$(LIBS)

_LOBJ=	\
		add.o	\
		print.o

LOBJ=	$(patsubst	%,$(LDIR)/%,$(_LOBJ))

$(LDIR)/%.o: $(SDIR)/%.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<	$(INCLUDES)

$(LTARGET).so:	$(LOBJ)
	$(CC)	$(CFLAGS)	-shared	-o	$@	$^	$(INCLUDES)	-lm

clean:
	rm	-rf	$(LDIR)/*	$(BUILDDIR)/*
