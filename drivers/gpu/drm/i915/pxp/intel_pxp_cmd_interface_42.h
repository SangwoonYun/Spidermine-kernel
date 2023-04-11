/* SPDX-License-Identifier: MIT */
/*
 * Copyright(c) 2020, Intel Corporation. All rights reserved.
 */

#ifndef __INTEL_PXP_FW_INTERFACE_42_H__
#define __INTEL_PXP_FW_INTERFACE_42_H__

#include <linux/types.h>
#include "intel_pxp_cmd_interface_cmn.h"

/* PXP-Opcode for Init Session */
#define PXP42_CMDID_INIT_SESSION 0x1e

/* PXP-Input-Packet: Init Session (Arb-Session) */
struct pxp42_create_arb_in {
	struct pxp_cmd_header header;
	u32 protection_mode;
#define PXP42_ARB_SESSION_MODE_HEAVY 0x2
	u32 session_id;
} __packed;

/* PXP-Output-Packet: Init Session */
struct pxp42_create_arb_out {
	struct pxp_cmd_header header;
} __packed;

#endif /* __INTEL_PXP_FW_INTERFACE_42_H__ */
