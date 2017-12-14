
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



int ship_discover_ipaddr(ship_t *s)
{
  struct sockaddr *addr;
  sa_family_t in_fam;

  if (s->sk == 0)
    return (SHERR_BADF);

  memset(s->ip_addr, 0, sizeof(s->ip_addr));

  addr = shaddr(s->sk);
  if (!addr)
    return (0);

  in_fam = *((sa_family_t *)addr);
  inet_ntop(in_fam, (unsigned char *)addr + sizeof(uint32_t), 
      s->ip_addr, sizeof(s->ip_addr)-1);

  return (0);
}

int ship_discover_geo(ship_t *s)
{
  int err;

  memset(&s->geo, 0, sizeof(s->geo));
  err = shgeodb_host(s->ip_addr, &s->geo);
  if (err)
    return (err);

  return (0);
}
 


