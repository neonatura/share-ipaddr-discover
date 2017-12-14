
/*
 *  Copyright 2017 Neo Natura 
 *
 *  This file is part of the Share Library.
 *  (https://github.com/neonatura/share)
 *        
 *  The Share Library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version. 
 *
 *  The Share Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Share Library.  If not, see <http://www.gnu.org/licenses/>.
 */  

#include "ship.h"

static ship_t _ship_client;
static int run_state;
static int opt_nofork;

#define RUN_NONE 0
#define RUN_IDLE 1

void ship_version(char *prog_name)
{
  fprintf(stdout,
      "Usage: shipd [OPTIONS]\n"
      "IP Discovery daemon for the Share Library Suite.\n");
}
void ship_usage(char *prog_name)
{
  fprintf(stdout,
      "shipd version %s\n"
      "\n"
      "Copyright 2013 Neo Natura\n"
      "Licensed under the GNU GENERAL PUBLIC LICENSE Version 3\n"
      "This product includes software developed by the OpenSSL Project for use in the OpenSSL Toolkit. (http://www.openssl.org/)\n",
      get_libshare_version());
}

static void sig_term(int sig_no)
{
  run_state = RUN_NONE;
}

int main(int argc, char *argv[])
{
  int err;
  int i;

  for (i = 1; i < argc; i++) {
    if (0 == strcasecmp(argv[i], "-v") ||
        0 == strcasecmp(argv[i], "--version")) {
      ship_version(argv[0]);
      return (0);
    }
    if (0 == strcasecmp(argv[i], "-h") ||
        0 == strcasecmp(argv[i], "--help")) {
      ship_usage(argv[0]);
      return (0);
    }
    if (0 == strcasecmp(argv[i], "-nf") ||
        0 == strcasecmp(argv[i], "--nofork")) {
      opt_nofork = TRUE;
    }
  }

  if (!opt_nofork)
    daemon(TRUE, TRUE);

  signal(SIGINT, sig_term);
  signal(SIGQUIT, sig_term);
  signal(SIGTERM, sig_term);

  err = ship_init(argc, argv, &_ship_client);
  if (err) {
    fprintf(stderr, "initialization error: %s\n", sherrstr(err));
    return (1);
  }

  run_state = RUN_IDLE;
  while (run_state != RUN_NONE) {
    ship_cycle(&_ship_client);
  }

  ship_term(&_ship_client);

  return (0);
}

