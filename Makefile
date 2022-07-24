# d - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c d.c util.c
OBJ = ${SRC:.c=.o}

all: options d

options:
	@echo d build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

d: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f d ${OBJ} d-${VERSION}.tar.gz

dist: clean
	mkdir -p d-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		d.1 drw.h util.h ${SRC} d.png transient.c d-${VERSION}
	tar -cf d-${VERSION}.tar d-${VERSION}
	gzip d-${VERSION}.tar
	rm -rf d-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f d ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/d
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < d.1 > ${DESTDIR}${MANPREFIX}/man1/d.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/d.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/d\
		${DESTDIR}${MANPREFIX}/man1/d.1

.PHONY: all options clean dist install uninstall
