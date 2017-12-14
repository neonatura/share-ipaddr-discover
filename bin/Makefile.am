

noinst_SCRIPTS = \
	.notice

noinst_PROGRAMS = shipd

.notice:
	@echo > .notice
	@echo ""
	@echo "The share ipaddr discover daemon (shipd) has been built."
	@echo ""
	@echo "It is now safe to perform a 'make install'."
	@echo "Perform a 'make check' for additional tests afterwards."
	@echo ""

shipd$(EXEEXT):
	ln -sf $(top_builddir)/src/share-ipaddr-discover/shipd$(EXEEXT) .


