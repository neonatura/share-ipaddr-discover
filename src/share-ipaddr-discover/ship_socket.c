
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

#define SHIP_PORT 411

static int _listen_socket;

int net_bind(void)
{
  int err;
  int sk;

  if (_listen_socket != 0) {
    shclose(_listen_socket);
    _listen_socket = 0;
  }

  sk = shnet_sk();
  if (sk < 0)
    return (-errno);

  err = shnet_bindsk(sk, NULL, SHIP_PORT);
  if (err < 0)
    return (-errno);

  _listen_socket = sk;
  return (0);
}

int net_accept(ship_t *s)
{
  int err;

  err = shnet_accept_nb(_listen_socket);
  if (err < 0)
    return (err);

  /* retain socket descriptor */
  s->sk = err;

  return (0);
}

int net_write(ship_t *s, unsigned char *data, size_t data_len)
{
  int err;

  err = shnet_write(s->sk, data, data_len);
  if (err < 0)
    return (err);

  return (0);
}

void net_close(ship_t *s)
{

  if (s->sk == 0)
    return;

  shclose(s->sk);
  s->sk = 0;

}

void net_idle(double f)
{
  struct timeval tv;
  fd_set r_set;

  if (_listen_socket == 0)
    return;

  FD_ZERO(&r_set);
  FD_SET(_listen_socket, &r_set);

  memset(&tv, 0, sizeof(tv));
  tv.tv_sec = floor(f);
  tv.tv_usec = (f - (double)tv.tv_sec) * 1000000;
  (void)shselect(_listen_socket, &r_set, NULL, NULL, &tv);

}

void net_unbind(void)
{

  if (_listen_socket == 0)
    return;

  shclose(_listen_socket);
  _listen_socket = 0;
}
