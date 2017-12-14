
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

const char *ship_print_ipaddr(ship_t *s)
{
  static char ret_buf[1024];

  memset(ret_buf, 0, sizeof(ret_buf));
  sprintf(ret_buf, "%s\n", s->ip_addr);

  return ((const char *)ret_buf);
}

const char *ship_print_geo(ship_t *s)
{
  static char ret_buf[1024];
  shnum_t lat, lon;

  lat = lon = 0;
  shgeo_loc(&s->geo, &lat, &lon, NULL);
  memset(ret_buf, 0, sizeof(ret_buf));
  if (lat != 0.00000 || lon != 0.00000)
    sprintf(ret_buf, "%-5.5Lf %-5.5Lf\n", lat, lon);
  else
    strcpy(ret_buf, "\n"); /* unknown */

  return ((const char *)ret_buf);
}

