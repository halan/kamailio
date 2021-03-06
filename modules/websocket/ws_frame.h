/*
 * $Id$
 *
 * Copyright (C) 2012 Crocodile RCS Ltd
 *
 * This file is part of Kamailio, a free SIP server.
 *
 * Kamailio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * Kamailio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef _WS_FRAME_H
#define _WS_FRAME_H

#include "../../config.h"
#include "../../sr_module.h"
#include "../../str.h"
#include "../../lib/kmi/tree.h"
#include "ws_conn.h"

typedef enum
{
	LOCAL_CLOSE = 0,
	REMOTE_CLOSE
} ws_close_type_t;

#define DEFAULT_KEEPALIVE_TIMEOUT		180 /* seconds */
extern int ws_keepalive_timeout;

enum
{
	KEEPALIVE_MECHANISM_NONE = 0,
	KEEPALIVE_MECHANISM_PING = 1,
	KEEPALIVE_MECHANISM_PONG = 2
};
#define DEFAULT_KEEPALIVE_MECHANISM		KEEPALIVE_MECHANISM_PING
extern int ws_keepalive_mechanism;

extern str ws_ping_application_data;
#define DEFAULT_PING_APPLICATION_DATA		SERVER_HDR
#define DEFAULT_PING_APPLICATION_DATA_LEN	SERVER_HDR_LEN

extern stat_var *ws_failed_connections;
extern stat_var *ws_local_closed_connections;
extern stat_var *ws_received_frames;
extern stat_var *ws_remote_closed_connections;
extern stat_var *ws_transmitted_frames;

int ws_frame_receive(void *data);
int ws_frame_transmit(void *data);
struct mi_root *ws_mi_close(struct mi_root *cmd, void *param);
struct mi_root *ws_mi_ping(struct mi_root *cmd, void *param);
struct mi_root *ws_mi_pong(struct mi_root *cmd, void *param);
void ws_keepalive(unsigned int ticks, void *param);

#endif /* _WS_FRAME_H */
