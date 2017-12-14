
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


void ship_cycle_request(ship_t *s)
{
  unsigned char *data;
  size_t data_len;

  (void)ship_discover_ipaddr(s);
  data = (unsigned char *)ship_print_ipaddr(s);
  data_len = strlen((char *)data);
  net_write(s, data ? data : "", data_len);

  (void)ship_discover_geo(s);
  data = (unsigned char *)ship_print_geo(s);
  data_len = strlen((char *)data);
  net_write(s, data ? data : "", data_len);

  net_close(s);
}


void ship_cycle(ship_t *s)
{
  int err;

  if (s->sk == 0) {
    (void)net_accept(s);
  }

  if (s->sk != 0) {
    ship_cycle_request(s);
  }

  net_idle(0.1);

}


