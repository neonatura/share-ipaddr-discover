
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

#ifndef __SHIP_H__
#define __SHIP_H__


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <signal.h>

#include "share.h"


typedef struct ship_t
{
  int sk;
  char ip_addr[MAXHOSTNAMELEN+1];
  shgeo_t geo;
} ship_t;


#include "ship_init.h"
#include "ship_term.h"
#include "ship_discover.h"
#include "ship_print.h"
#include "ship_socket.h"


#endif /* ndef __SHIP_H__ */

