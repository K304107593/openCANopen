/* Copyright (c) 2018, Marel
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _TRACE_BUFFER_H
#define _TRACE_BUFFER_H

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

#include "socketcan.h"

struct tb_frame {
	uint64_t timestamp;
	struct can_frame cf;
};

struct tracebuffer {
	size_t length;
	size_t index;
	size_t count;
	int is_blocked;
	struct tb_frame* data;
};

int tb_init(struct tracebuffer* self, size_t size);
void tb_destroy(struct tracebuffer* self);
void tb_append(struct tracebuffer* self, const struct can_frame* frame);
void tb_dump(struct tracebuffer* self, FILE* stream);

#endif /* _TRACE_BUFFER_H */
