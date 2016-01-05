#ifndef _CANOPEN_HEARTBEAT_H
#define _CANOPEN_HEARTBEAT_H

#include <linux/can.h>
#include "canopen/nmt.h"

static inline int heartbeat_is_valid(const struct can_frame* frame)
{
	return frame->can_dlc == 1;
}

static inline enum nmt_state heartbeat_get_state(const struct can_frame* frame)
{
	return frame->data[0] & 0x7f;
}

static inline int heartbeat_is_bootup(const struct can_frame* frame)
{
	return heartbeat_get_state(frame) == NMT_STATE_BOOTUP;
}

static inline void heartbeat_set_state(struct can_frame* frame,
				       enum nmt_state state)
{
	frame->data[0] = state & 0x7f;
}

#endif /* _CANOPEN_HEARTBEAT_H */

