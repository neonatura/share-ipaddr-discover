

ship_headers = \
	ship.h \
	ship_init.h \
	ship_term.h \
	ship_cycle.h \
	ship_socket.h \
	ship_discover.h \
	ship_print.h

ship_sources = \
	ship.c \
	ship_init.c \
	ship_term.c \
	ship_cycle.c \
	ship_socket.c \
	ship_discover.c \
	ship_print.c



sbin_PROGRAMS = shipd

shipd_SOURCES = $(ship_headers) $(ship_sources)
shipd_LDADD = -lshare
shipd_CFLAGS = -DSHIP_DAMEON 

