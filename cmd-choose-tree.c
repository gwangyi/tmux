/* $OpenBSD$ */

/*
 * Copyright (c) 2012 Thomas Adam <thomas@xteddy.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>

#include "tmux.h"

/*
 * Enter session, window or pane choose mode.
 */

static enum cmd_retval	cmd_choose_tree_exec(struct cmd *, struct cmdq_item *);

const struct cmd_entry cmd_choose_tree_entry = {
	.name = "choose-tree",
	.alias = NULL,

	.args = { "st:w", 0, 1 },
	.usage = "[-sw] " CMD_TARGET_PANE_USAGE,

	.target = { 't', CMD_FIND_PANE, 0 },

	.flags = 0,
	.exec = cmd_choose_tree_exec
};

static enum cmd_retval
cmd_choose_tree_exec(struct cmd *self, struct cmdq_item *item)
{
	struct args		*args = self->args;
	struct window_pane	*wp = item->target.wp;

	window_pane_set_mode(wp, &window_tree_mode, &item->target, args);

	return (CMD_RETURN_NORMAL);
}
