

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


if HAVE_SYSTEMCTL
SYSD_FILE = /etc/systemd/system/shipd.service

install-exec-hook:
	echo "[Unit]" > $(SYSD_FILE) 
	echo "Description=Share IP-Addr Discovery Daemon" >> $(SYSD_FILE) 
	echo "After=network.target" >> $(SYSD_FILE) 
	echo "[Service]" >> $(SYSD_FILE) 
	echo "ExecStart=$(sbindir)/shipd -nf" >> $(SYSD_FILE)
	systemctl daemon-reload 
	@echo "Run 'systemctl enable shipd' to enable on system startup."

uninstall-hook:
	rm -f $(SYSD_FILE)
	systemctl daemon-reload 
endif

