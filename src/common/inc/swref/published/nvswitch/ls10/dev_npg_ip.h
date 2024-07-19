/*
 * SPDX-FileCopyrightText: Copyright (c) 2003-2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the Software),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __ls10_dev_npg_ip_h__
#define __ls10_dev_npg_ip_h__
/* This file is autogenerated.  Do not edit */
#define NV_NPG          0x000007FFFF:0x00000000 /* RW--D */
#define NV_NPG_CTRL_CLOCK_GATING                           0x000000c8      /* RW-4R */
#define NV_NPG_CTRL_CLOCK_GATING_CG1_SLCG                  3:0             /* RWEVF */
#define NV_NPG_CTRL_CLOCK_GATING_CG1_SLCG_INIT             0x0000000f      /* RWE-V */
#define NV_NPG_CTRL_CLOCK_GATING_CG1_SLCG__PROD            0x00000000      /* RW--V */
#define NV_NPG_CTRL_CLOCK_GATING_CG1_BLCG                  8:4             /* RWEVF */
#define NV_NPG_CTRL_CLOCK_GATING_CG1_BLCG_INIT             0x0000001f      /* RWE-V */
#define NV_NPG_CTRL_CLOCK_GATING_CG1_BLCG__PROD            0x00000000      /* RW--V */
#define NV_NPG_CONFIG_CLOCK_GATING                         0x000000cc      /* RW-4R */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_IDLE_DLY_CNT   5:0             /* RWEVF */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_IDLE_DLY_CNT_INIT 0x00000000   /* RWE-V */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_IDLE_CG_EN     6:6             /* RWEVF */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_IDLE_CG_EN_INIT 0x00000001     /* RWE-V */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_STALL_CG_EN    7:7             /* RWEVF */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_STALL_CG_EN_INIT 0x00000000    /* RWE-V */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_MONITOR_CG_EN  8:8             /* RWEVF */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_MONITOR_CG_EN_INIT 0x00000000  /* RWE-V */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_WAKEUP_DLY_CNT 12:9            /* RWEVF */
#define NV_NPG_CONFIG_CLOCK_GATING_CG1_BLCG_WAKEUP_DLY_CNT_INIT 0x00000000 /* RWE-V */
#define NV_NPG_NPG_INTERRUPT_STATUS                        0x00000400      /* R--4R */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV0_FNC_OR            0:0             /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV0_FNC_OR_INIT       0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV0_INT_STATUS        3:1             /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV0_INT_STATUS_INIT   0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV0_INT_STATUS_FATAL  0x00000001      /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV0_INT_STATUS_NONFATAL 0x00000002    /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV0_INT_STATUS_CORRECTABLE 0x00000004 /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV1_FNC_OR            4:4             /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV1_FNC_OR_INIT       0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV1_INT_STATUS        7:5             /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV1_INT_STATUS_INIT   0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV1_INT_STATUS_FATAL  0x00000001      /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV1_INT_STATUS_NONFATAL 0x00000002    /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV1_INT_STATUS_CORRECTABLE 0x00000004 /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV2_FNC_OR            8:8             /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV2_FNC_OR_INIT       0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV2_INT_STATUS        11:9            /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV2_INT_STATUS_INIT   0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV2_INT_STATUS_FATAL  0x00000001      /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV2_INT_STATUS_NONFATAL 0x00000002    /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV2_INT_STATUS_CORRECTABLE 0x00000004 /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV3_FNC_OR            12:12           /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV3_FNC_OR_INIT       0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV3_INT_STATUS        15:13           /* R-EVF */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV3_INT_STATUS_INIT   0x00000000      /* R-E-V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV3_INT_STATUS_FATAL  0x00000001      /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV3_INT_STATUS_NONFATAL 0x00000002    /* R---V */
#define NV_NPG_NPG_INTERRUPT_STATUS_DEV3_INT_STATUS_CORRECTABLE 0x00000004 /* R---V */
#define NV_NPG_INTR_RETRIGGER(i)                           (0x00000580+(i)*0x4) /* RW-4A */
#define NV_NPG_INTR_RETRIGGER__SIZE_1                      3               /*       */
#define NV_NPG_INTR_RETRIGGER_TRIGGER                      0:0             /* RWEVF */
#define NV_NPG_INTR_RETRIGGER_TRIGGER_INIT                 0x00000000      /* RWE-V */
#endif // __ls10_dev_npg_ip_h__
