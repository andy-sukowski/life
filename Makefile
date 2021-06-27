# See LICENSE file for copyright and license details.

include config.mk

SRC = life.c
OBJ = ${SRC:.c=.o}

all: options life

options:
	@echo life build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

life: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f life ${OBJ}

install: all
	mkdir -p ${PREFIX}/bin
	cp -f life ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/life

uninstall:
	rm -f ${PREFIX}/bin/life

.PHONY: all options clean install uninstall
