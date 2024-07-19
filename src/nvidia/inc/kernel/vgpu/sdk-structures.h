/*
 * SPDX-FileCopyrightText: Copyright (c) 2020-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */


#ifndef _RPC_SDK_STRUCTURES_H_
#define _RPC_SDK_STRUCTURES_H_

#include <ctrl/ctrl83de.h>
#include <ctrl/ctrla080.h>
#include <ctrl/ctrlc36f.h>
#include <ctrl/ctrlc637.h>
#include <ctrl/ctrl0000/ctrl0000system.h>
#include <ctrl/ctrl0080/ctrl0080nvjpg.h>
#include <ctrl/ctrl0080/ctrl0080bsp.h>
#include <ctrl/ctrl0080/ctrl0080dma.h>
#include <ctrl/ctrl0080/ctrl0080fb.h>
#include <ctrl/ctrl0080/ctrl0080gr.h>
#include <ctrl/ctrl2080/ctrl2080ce.h>
#include <ctrl/ctrl2080/ctrl2080bus.h>
#include <ctrl/ctrl2080/ctrl2080fifo.h>
#include <ctrl/ctrl2080/ctrl2080gr.h>
#include <ctrl/ctrl2080/ctrl2080fb.h>
#include <ctrl/ctrl2080/ctrl2080internal.h>
#include <ctrl/ctrl83de/ctrl83dedebug.h>
#include <ctrl/ctrl0080/ctrl0080fifo.h>
#include <ctrl/ctrl2080/ctrl2080nvlink.h>
#include <ctrl/ctrl2080/ctrl2080fla.h>
#include <ctrl/ctrl2080/ctrl2080internal.h>
#include <ctrl/ctrl2080/ctrl2080mc.h>
#include <ctrl/ctrl2080/ctrl2080grmgr.h>
#include <ctrl/ctrl2080/ctrl2080ecc.h>
#include <ctrl/ctrl0090.h>
#include <ctrl/ctrl9096.h>
#include <ctrl/ctrlb0cc.h>
#include <ctrl/ctrla06f.h>
#include <ctrl/ctrl00f8.h>
#include <ctrl/ctrl90e6.h>

#include <class/cl2080.h>
#include <class/cl0073.h>
#include <class/clc670.h>
#include <class/clc673.h>
#include <class/clc67b.h>
#include <class/clc67d.h>
#include <class/clc67e.h>
#include "rpc_headers.h"
#include "nvctassert.h"
#include "nv_vgpu_types.h"



typedef struct vmiopd_SM_info {
    NvU32 version;
    NvU32 regBankCount;
    NvU32 regBankRegCount;
    NvU32 maxWarpsPerSM;
    NvU32 maxThreadsPerWarp;
    NvU32 geomGsObufEntries;
    NvU32 geomXbufEntries;
    NvU32 maxSPPerSM;
    NvU32 rtCoreCount;
} VMIOPD_GRSMINFO;

// NV_SCAL_FAMILY_MAX_FBPS 16
#define MAX_FBPS 16 //Maximum number of FBPs

#define OBJ_MAX_HEADS_v03_00 4
#define OBJ_MAX_HEADS_v24_08 8

// NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_MAX_DEVICES(256) / NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_MAX_ENTRIES(32)
#define MAX_ITERATIONS_DEVICE_INFO_TABLE 8

// NV2080_CTRL_FB_DYNAMIC_BLACKLIST_MAX_PAGES(512) / NV2080_CTRL_FB_DYNAMIC_BLACKLIST_MAX_ENTRIES(64)
#define MAX_ITERATIONS_DYNAMIC_BLACKLIST 8

#define NV0000_GPUACCT_RPC_PID_MAX_QUERY_COUNT      1000

#define NV2080_CTRL_CLK_ARCH_MAX_DOMAINS_v1E_0D     32

#define NV_RM_RPC_NO_MORE_DATA_TO_READ      0
#define NV_RM_RPC_MORE_RPC_DATA_TO_READ     1

//Maximum EXEC_PARTITIONS
#define NVC637_CTRL_MAX_EXEC_PARTITIONS_v18_05      8

//Maximum ECC Addresses
#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_MAX_COUNT_v18_04   32

#define NV2080_CTRL_NVLINK_MAX_LINKS_v15_02  6
#define NV2080_CTRL_NVLINK_MAX_LINKS_v1A_18 12
#define NV2080_CTRL_NVLINK_MAX_LINKS_v23_04 24

#define NV0000_CTRL_P2P_CAPS_INDEX_TABLE_SIZE_v15_02   8
#define NV0000_CTRL_P2P_CAPS_INDEX_TABLE_SIZE_v1F_0D   9

#define NV0000_CTRL_SYSTEM_MAX_ATTACHED_GPUS_v21_02    32
#define VM_UUID_SIZE_v21_02                            16

#define NV2080_CTRL_FB_FS_INFO_MAX_QUERIES_v1A_1D       96
#define NV2080_CTRL_FB_FS_INFO_MAX_QUERIES_v24_00       120
#define NV2080_CTRL_FB_FS_INFO_MAX_QUERY_SIZE_v1A_1D    24
#define NV2080_CTRL_GRMGR_GR_FS_INFO_MAX_QUERIES_v1A_1D 96
#define NV2080_CTRL_GRMGR_MAX_SMC_IDS_v1A_1D            8

#define NV0080_CTRL_GR_INFO_MAX_SIZE_1B_04                                      (0x0000002C)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_1C_01                                      (0x00000030)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_1E_02                                      (0x00000032)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_21_01                                      (0x00000033)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_22_02                                      (0x00000034)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_23_00                                      (0x00000035)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_24_02                                      (0x00000036)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_24_03                                      (0x00000037)
#define NV0080_CTRL_GR_INFO_MAX_SIZE_24_07                                      (0x00000038)
#define NV2080_CTRL_INTERNAL_GR_MAX_ENGINES_1B_04                               8
#define NV2080_CTRL_INTERNAL_GR_MAX_SM_v1B_05                                   256
#define NV2080_CTRL_INTERNAL_GR_MAX_SM_v1E_03                                   240
#define NV2080_CTRL_INTERNAL_GR_MAX_GPC_v1B_05                                  8
#define NV2080_CTRL_INTERNAL_ENGINE_CONTEXT_PROPERTIES_ENGINE_ID_COUNT_v1B_05   0x19
#define NV2080_CTRL_INTERNAL_ENGINE_CONTEXT_PROPERTIES_ENGINE_ID_COUNT_v25_07   0x1a
#define NV2080_CTRL_INTERNAL_MAX_TPC_PER_GPC_COUNT_v1C_03                       10
#define NV2080_CTRL_INTERNAL_GR_MAX_GPC_v1C_03                                  12
#define NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_MAX_v1E_09                         32
#define NV2080_CTRL_PERF_GPUMON_SAMPLE_COUNT_PERFMON_UTIL_v1F_0E                72
#define NV2080_CTRL_GPU_PARTITION_FLAG_COMPUTE_SIZE__SIZE_v20_04                6
#define NVB0CC_MAX_CREDIT_INFO_ENTRIES_v21_08                                   63
#define NV2080_CTRL_MIGRATABLE_OPS_ARRAY_MAX_v21_07                             50
#define NV2080_CTRL_MAX_PCES_v21_0A                                             32
#define NV2080_CTRL_CE_CAPS_TBL_SIZE_v21_0A                                     2
#define NV2080_CTRL_NVLINK_INBAND_MAX_DATA_SIZE_v26_05                          1024

// Host USM type
#define NV_VGPU_CONFIG_USM_TYPE_DEFAULT                  0x00000000 /* R-XVF */
#define NV_VGPU_CONFIG_USM_TYPE_NVS                      0x00000001 /* R-XVF */
#define NV_VGPU_CONFIG_USM_TYPE_QUADRO                   0x00000002 /* R-XVF */
#define NV_VGPU_CONFIG_USM_TYPE_GEFORCE                  0x00000003 /* R-XVF */
#define NV_VGPU_CONFIG_USM_TYPE_COMPUTE                  0x00000004 /* R-XVF */

#define NV_ALLOC_STRUCTURE_SIZE_v26_00                   56

// Defined this intermediate RM-RPC structure for making RPC call from Guest as
// we have the restriction of passing max 4kb of data to plugin and the
// NV0000_CTRL_GPUACCT_GET_ACCOUNTING_PIDS_PARAMS is way more than that.
// This structure is similar to NV0000_CTRL_GPUACCT_GET_ACCOUNTING_PIDS_PARAMS
// RM control structure.
// Added passIndex member to identify from which index (in the full RM pid list
// on host)onwards the data needs to be read. Caller should initialize passIndex
// to NV_RM_RPC_MORE_RPC_DATA_TO_READ, and keep making RPC calls until the
// passIndex value is returned as NV_RM_RPC_NO_MORE_DATA_TO_READ by the RPC.
typedef struct
{
    NvU32 gpuId;
    NvU32 passIndex;
    NvU32 pidTbl[NV0000_GPUACCT_RPC_PID_MAX_QUERY_COUNT];
    NvU32 pidCount;
} NV0000_CTRL_GPUACCT_GET_ACCOUNTING_PIDS_PARAMS_RPC_EX;

typedef NvBool   NV2080_CTRL_CMD_FB_GET_FB_REGION_SURFACE_MEM_TYPE_FLAG_v03_00[NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_MEM_TYPES];

typedef NvV32 NvRmctrlCmd;

struct pte_desc
{
    NvU32 idr:2;
    NvU32 reserved1:14;
    NvU32 length:16;
    union {
        NvU64 pte; // PTE when IDR==0; PDE when IDR > 0
        NvU64 pde; // PTE when IDR==0; PDE when IDR > 0
    } pte_pde[]  NV_ALIGN_BYTES(8); // PTE when IDR==0; PDE when IDR > 0
};

typedef struct VGPU_BSP_CAPS
{
    NvU8 capsTbl[NV0080_CTRL_BSP_CAPS_TBL_SIZE];
} VGPU_BSP_CAPS;

#define NV2080_CTRL_GPU_ECC_UNIT_COUNT_v15_01 (0x00000014)
#define NV2080_CTRL_GPU_ECC_UNIT_COUNT_v1A_04 (0x00000014)
#define NV2080_CTRL_GPU_ECC_UNIT_COUNT_v1C_09 (0x00000016)
#define NV2080_CTRL_GPU_ECC_UNIT_COUNT_v20_03 (0x00000018)
#define NV2080_CTRL_GPU_ECC_UNIT_COUNT_v24_06 (0x00000019)
#define NV2080_CTRL_GPU_ECC_UNIT_COUNT_v26_02 (0x0000001E)
#define NV2080_CTRL_GPU_ECC_UNIT_COUNT_v27_04 (0x0000001F)

#define NV2080_ENGINE_TYPE_LAST_v18_01      (0x0000002a)
#define NV2080_ENGINE_TYPE_LAST_v1C_09      (0x00000034)
#define NV2080_ENGINE_TYPE_LAST_v27_02      (0x00000054)

#define NV2080_ENGINE_TYPE_LAST_v1A_00      (0x2a)

#define NV2080_ENGINE_TYPE_COPY_SIZE_v1A_0D  (10)
#define NV2080_ENGINE_TYPE_COPY_SIZE_v22_00  (10)
#define NV2080_ENGINE_TYPE_COPY_SIZE_v24_09  (64)

#define NV2080_CTRL_BUS_INFO_MAX_LIST_SIZE_v1A_0F   (0x00000033)
#define NV2080_CTRL_BUS_INFO_MAX_LIST_SIZE_v1C_09   (0x00000034)

//Maximum GMMU_FMT_LEVELS
#define GMMU_FMT_MAX_LEVELS_v05_00 5
#define GMMU_FMT_MAX_LEVELS_v1A_12 6

//Maximum MMU FMT sub levels
#define MMU_FMT_MAX_SUB_LEVELS_v09_02 2

//Maximum number of supported TDP clients
#define NV2080_CTRL_PERF_RATED_TDP_CLIENT_NUM_CLIENTS_v1A_1F 5

//Maximum number of SMs whose error state can be read in single call
#define NV83DE_CTRL_DEBUG_MAX_SMS_PER_CALL_v16_03 100

// Workaround for bug 200702083 (#15)
#define NV2080_CTRL_FB_INFO_MAX_LIST_SIZE_1A_15 0x2F
#define NV2080_CTRL_FB_INFO_MAX_LIST_SIZE_1A_24 0x33
#define NV2080_CTRL_FB_INFO_MAX_LIST_SIZE_1E_01 0x35
#define NV2080_CTRL_FB_INFO_MAX_LIST_SIZE_1F_0F 0x36
#define NV2080_CTRL_FB_INFO_MAX_LIST_SIZE_24_0A 0x37
#define NV2080_CTRL_FB_INFO_MAX_LIST_SIZE_27_00 0x39

#define NV2080_CTRL_PERF_MAX_LIMITS_v1C_0B 0x100

// Maximum guest address that can we queried in one RPC.
// Below number is calculated as per Max. Guest Adrresses and their
// state can be returned in a single 4K (RPC Page size) iteration
#define GET_PLCABLE_MAX_GUEST_ADDRESS_v1D_05    60

//
// Versioned define for
// NVA06C_CTRL_INTERNAL_PROMOTE_FAULT_METHOD_BUFFERS_MAX_RUNQUEUES
//
#define NVA06C_CTRL_INTERNAL_PROMOTE_FAULT_METHOD_BUFFERS_MAX_RUNQUEUES_v1E_07 2

// Versioned define for
// NV2080_CTRL_PCIE_SUPPORTED_GPU_ATOMICS_OP_TYPE_COUNT
#define NV2080_CTRL_PCIE_SUPPORTED_GPU_ATOMICS_OP_TYPE_COUNT_v1F_08 13

#define MAX_NVDEC_ENGINES_V1A_07 5
#define MAX_NVDEC_ENGINES_V25_00 8
#define NV0080_CTRL_MSENC_CAPS_TBL_SIZE_V25_00 4
#define NV0080_CTRL_NVJPG_CAPS_TBL_SIZE_V18_0C 9
#define NV0080_CTRL_BSP_CAPS_TBL_SIZE_V09_10 8
#define NV2080_CTRL_GPU_MAX_CONSTRUCTED_FALCONS_V25_01 0x40
#define NV2080_CTRL_CMD_INTERNAL_DEVICE_INFO_MAX_ENTRIES_V25_05 256

#define NV0080_CTRL_GR_CAPS_TBL_SIZE_v25_0E     23
#define NV2080_CTRL_CMD_GR_CTXSW_PREEMPTION_BIND_BUFFERS_CONTEXT_POOL_v25_0E   5
#define RPC_GR_BUFFER_TYPE_GRAPHICS_MAX_v25_0E  13
#define NV9096_CTRL_ZBC_CLEAR_TABLE_TYPE_COUNT_v1A_07   4

#define NV2080_CTRL_GPU_INFO_MAX_LIST_SIZE_v25_11 0x00000041

#define NV2080_CTRL_BOARDOBJGRP_E255_MAX_OBJECTS_v06_01 (255U)
#define NVGPU_VGPU_ENGINE_LIST_MASK_ARRAY_MAX            4
#define NVGPU_VGPU_ENGINE_LIST_MASK_ARRAY_MAX_v27_01     4
#define NVGPU_VGPU_ENGINE_LIST_MASK_BITS_SHIFT           6
#define NVGPU_VGPU_ENGINE_LIST_MASK_BITS                (1 << NVGPU_VGPU_ENGINE_LIST_MASK_BITS_SHIFT)
#define NVGPU_VGPU_ENGINE_LIST_MASK_BITS_MASK           (NVGPU_VGPU_ENGINE_LIST_MASK_BITS - 1)
#define NVGPU_VGPU_ENGINE_LIST_LAST                     (NVGPU_VGPU_ENGINE_LIST_MASK_ARRAY_MAX * \
                                                         NVGPU_VGPU_ENGINE_LIST_MASK_BITS)

//
// Engine Type capability mask bit-array helper MACROS to support on growing number of engine types
// The enginelist is defined as
// NvU64 engineList[NVGPU_VGPU_ENGINE_LIST_MASK_ARRAY_MAX_v27_01]
//

// To check whether the bit is set for the particular ID in enginelist.
#define NVGPU_VGPU_GET_ENGINE_LIST_MASK(enginelist, id)      \
    (enginelist[(id) >> NVGPU_VGPU_ENGINE_LIST_MASK_BITS_SHIFT] &   NVBIT64((id) & NVGPU_VGPU_ENGINE_LIST_MASK_BITS_MASK))
// To set the bit for the particular ID in enginelist.
#define NVGPU_VGPU_SET_ENGINE_LIST_MASK(enginelist, id)      \
    (enginelist[(id) >> NVGPU_VGPU_ENGINE_LIST_MASK_BITS_SHIFT] |=  NVBIT64((id) & NVGPU_VGPU_ENGINE_LIST_MASK_BITS_MASK))
// To unset the bit for the particular ID in the enginelist.
#define NVGPU_VGPU_UNSET_ENGINE_LIST_MASK(enginelist, id)    \
    (enginelist[(id) >> NVGPU_VGPU_ENGINE_LIST_MASK_BITS_SHIFT] &= ~NVBIT64((id) & NVGPU_VGPU_ENGINE_LIST_MASK_BITS_MASK))

typedef struct _GPU_PARTITION_INFO
{
    NvU32      swizzId;
    NvU32      grEngCount;
    NvU32      veidCount;
    NvU32      ceCount;
    NvU32      gpcCount;
    NvU32      virtualGpcCount;
    NvU32      gfxGpcCount;
    NvU32      gpcsPerGr[NV2080_CTRL_GPU_MAX_SMC_IDS];
    NvU32      virtualGpcsPerGr[NV2080_CTRL_GPU_MAX_SMC_IDS];
    NvU32      gfxGpcPerGr[NV2080_CTRL_GPU_MAX_SMC_IDS];
    NvU32      veidsPerGr[NV2080_CTRL_GPU_MAX_SMC_IDS];
    NvU32      nvDecCount;
    NvU32      nvEncCount;
    NvU32      nvJpgCount;
    NvU32      partitionFlag;
    NvU32      smCount;
    NvU32      nvOfaCount;
    NvU64      memSize;
    NvBool     bValid;
    NV2080_CTRL_GPU_PARTITION_SPAN span;
    NvU64      validCTSIdMask;
} GPU_PARTITION_INFO;

typedef struct _GPU_EXEC_PARTITION_INFO
{
    NvU32 execPartCount;
    NvU32 execPartId[NVC637_CTRL_MAX_EXEC_PARTITIONS];
    NVC637_CTRL_EXEC_PARTITIONS_INFO execPartInfo[NVC637_CTRL_MAX_EXEC_PARTITIONS];
} GPU_EXEC_PARTITION_INFO;

typedef struct
{
    NvBool bGpuSupportsFabricProbe;
} VGPU_P2P_CAPABILITY_PARAMS;

typedef struct _GPU_EXEC_SYSPIPE_INFO {
    NvU32 execPartCount;
    NvU32 execPartId[NVC637_CTRL_MAX_EXEC_PARTITIONS];
    NvU32 syspipeId[NVC637_CTRL_MAX_EXEC_PARTITIONS];
} GPU_EXEC_SYSPIPE_INFO;

typedef struct _VGPU_STATIC_PROPERTIES
{
    NvU32 encSessionStatsReportingState;
    NvBool bProfilingTracingEnabled;
    NvBool bDebuggingEnabled;
    NvU32 channelCount;
    NvBool bPblObjNotPresent;       //Valid only in case of GA100 SRIOV Heavy
    NvU64 vmmuSegmentSize;
} VGPU_STATIC_PROPERTIES;

struct _vgpu_static_info
{
    NvU32 gfxpBufferSize[NV2080_CTRL_CMD_GR_CTXSW_PREEMPTION_BIND_BUFFERS_CONTEXT_POOL];
    NvU32 gfxpBufferAlignment[NV2080_CTRL_CMD_GR_CTXSW_PREEMPTION_BIND_BUFFERS_CONTEXT_POOL];
    NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS fbLtcInfoForFbp[MAX_FBPS];
    NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_PARAMS mcStaticIntrTable;
    NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS grZcullInfo;
    NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_PARAMS fifoDeviceInfoTable[MAX_ITERATIONS_DEVICE_INFO_TABLE];
    NV2080_CTRL_FB_GET_DYNAMIC_OFFLINED_PAGES_PARAMS fbDynamicBlacklistedPages[MAX_ITERATIONS_DYNAMIC_BLACKLIST];
    NV0080_CTRL_FIFO_GET_LATENCY_BUFFER_SIZE_PARAMS fifoLatencyBufferSize[NV2080_ENGINE_TYPE_LAST];
    NV2080_CTRL_CE_GET_CAPS_V2_PARAMS ceCaps[NV2080_ENGINE_TYPE_COPY_SIZE];
    NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS nvlinkCaps;
    NV2080_CTRL_BUS_GET_INFO_V2_PARAMS busGetInfoV2;
    NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS grSmIssueRateModifier;
    NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS_PARAMS pcieSupportedGpuAtomics;
    NV2080_CTRL_CE_GET_ALL_CAPS_PARAMS ceGetAllCaps;
    NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS c2cInfo;
    NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS vgxSystemInfo;
    NVA080_CTRL_VGPU_GET_CONFIG_PARAMS vgpuConfig;
    NV2080_CTRL_BIOS_GET_SKU_INFO_PARAMS SKUInfo;
    NvU64 engineList[NVGPU_VGPU_ENGINE_LIST_MASK_ARRAY_MAX];
    NvU32 pcieGpuLinkCaps;
    NvBool bFlaSupported;
    NV2080_CTRL_FLA_GET_RANGE_PARAMS flaInfo;
    NvBool bPerRunlistChannelRamEnabled;
    NvU32 subProcessIsolation;
    VGPU_STATIC_PROPERTIES vgpuStaticProperties;
    NvU64 maxSupportedPageSize; // Only used pre-SRIOV/SRIOV-heavy
    GPU_PARTITION_INFO gpuPartitionInfo; // Default (Admin created) EXEC-I PARTITION INFO
    NvBool bC2CLinkUp;
    NvBool bSelfHostedMode;
    NvBool bLocalEgmEnabled;
    NvU32  localEgmPeerId;
    NvU32 ceFaultMethodBufferDepth;
    NvU8 grCapsBits[NV0080_CTRL_GR_CAPS_TBL_SIZE];
    NvBool bPerSubCtxheaderSupported;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS grInfoParams;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_CONTEXT_BUFFERS_INFO_PARAMS ctxBuffInfo;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_PPC_MASKS_PARAMS ppcMaskParams;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS globalSmOrder;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS smIssueRateModifier;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS floorsweepMaskParams;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_RECORD_SIZE_PARAMS fecsRecordSize;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_TRACE_DEFINES_PARAMS fecsTraceDefines;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS pdbTableParams;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_ROP_INFO_PARAMS ropInfoParams;
    NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS zcullInfoParams;
    NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS ciProfiles;
    NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS mcEngineNotificationIntrVectors;
    NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS eccStatus;
    NvBool guestManagedHwAlloc;
    NvU8 jpegCaps[NV0080_CTRL_NVJPG_CAPS_TBL_SIZE];
    NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS nvencCaps;
    VGPU_BSP_CAPS vgpuBspCaps[NV2080_CTRL_CMD_INTERNAL_MAX_BSPS];
    NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS constructedFalconInfo;
    GPU_EXEC_PARTITION_INFO execPartitionInfo;
    NV2080_CTRL_GPU_GET_GID_INFO_PARAMS gidInfo;
    NvU64 fbTaxLength;
    NvU64 fbLength;
    NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS fbRegionInfoParams;
    NvU32 grBufferSize[RPC_GR_BUFFER_TYPE_GRAPHICS_MAX];
    NvU64 fbioMask;
    NvBool bSplitVasBetweenServerClientRm;
    NvU8 adapterName[NV2080_GPU_MAX_NAME_STRING_LENGTH];
    NvU16 adapterName_Unicode[NV2080_GPU_MAX_NAME_STRING_LENGTH];
    NvU8 shortGpuNameString[NV2080_GPU_MAX_NAME_STRING_LENGTH];
    NvBool poisonFuseEnabled;
    NvBool bAtsSupported;
    NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS deviceInfoTable;
    NV2080_CTRL_INTERNAL_MEMSYS_GET_STATIC_CONFIG_PARAMS memsysStaticConfig;
    VGPU_P2P_CAPABILITY_PARAMS p2pCaps;
    NvU32 fbBusWidth;
    NvU32 fbpMask;
    NvU64 ltcMask;
    NvU32 ltsCount;
    NvU32 sizeL2Cache;
    NV9096_CTRL_GET_ZBC_CLEAR_TABLE_SIZE_PARAMS zbcTableSizes[NV9096_CTRL_ZBC_CLEAR_TABLE_TYPE_COUNT];
    NV2080_CTRL_CMD_BUS_GET_PCIE_REQ_ATOMICS_CAPS_PARAMS busGetPcieReqAtomicsCaps;
    NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS masterGetVfErrCntIntMsk;
    GPU_EXEC_SYSPIPE_INFO execSyspipeInfo;
};

typedef struct _vgpu_static_info VGPU_STATIC_INFO, VGPU_STATIC_INFO2;
typedef struct _vgpu_static_info VGPU_STATIC_DATA;

typedef NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS VGPU_FB_GET_LTC_INFO_FOR_FBP[MAX_FBPS];
typedef VGPU_BSP_CAPS VGPU_BSP_GET_CAPS[NV2080_CTRL_CMD_INTERNAL_MAX_BSPS];
typedef NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_PARAMS VGPU_FIFO_GET_DEVICE_INFO_TABLE[MAX_ITERATIONS_DEVICE_INFO_TABLE];
typedef NV2080_CTRL_FB_GET_DYNAMIC_OFFLINED_PAGES_PARAMS VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES[MAX_ITERATIONS_DYNAMIC_BLACKLIST];
typedef NV0080_CTRL_FIFO_GET_LATENCY_BUFFER_SIZE_PARAMS VGPU_GET_LATENCY_BUFFER_SIZE[NV2080_ENGINE_TYPE_LAST];
typedef NV2080_CTRL_CE_GET_CAPS_V2_PARAMS VGPU_CE_GET_CAPS_V2[NV2080_ENGINE_TYPE_COPY_SIZE];

typedef struct GSP_FIRMWARE GSP_FIRMWARE;

ct_assert(NV2080_CTRL_GPU_ECC_UNIT_COUNT == NV2080_CTRL_GPU_ECC_UNIT_COUNT_v27_04);
ct_assert(NV2080_ENGINE_TYPE_LAST == 0x54);
ct_assert(NV2080_CTRL_BUS_INFO_MAX_LIST_SIZE == NV2080_CTRL_BUS_INFO_MAX_LIST_SIZE_v1C_09);
ct_assert(NV2080_CTRL_FB_FS_INFO_MAX_QUERIES == NV2080_CTRL_FB_FS_INFO_MAX_QUERIES_v24_00);
ct_assert(NV2080_CTRL_FB_FS_INFO_MAX_QUERY_SIZE == NV2080_CTRL_FB_FS_INFO_MAX_QUERY_SIZE_v1A_1D);
ct_assert(NV2080_CTRL_GRMGR_GR_FS_INFO_MAX_QUERIES == NV2080_CTRL_GRMGR_GR_FS_INFO_MAX_QUERIES_v1A_1D);
ct_assert(NV2080_CTRL_GRMGR_MAX_SMC_IDS == NV2080_CTRL_GRMGR_MAX_SMC_IDS_v1A_1D);
ct_assert((NV0080_CTRL_GR_INFO_INDEX_MAX + 1) == NV0080_CTRL_GR_INFO_MAX_SIZE_24_07);
ct_assert(NV2080_CTRL_INTERNAL_GR_MAX_ENGINES == NV2080_CTRL_INTERNAL_GR_MAX_ENGINES_1B_04);
ct_assert(NV2080_CTRL_INTERNAL_GR_MAX_SM == NV2080_CTRL_INTERNAL_GR_MAX_SM_v1E_03);
ct_assert(NV2080_CTRL_INTERNAL_GR_MAX_GPC == NV2080_CTRL_INTERNAL_GR_MAX_GPC_v1C_03);
ct_assert(NV2080_CTRL_INTERNAL_ENGINE_CONTEXT_PROPERTIES_ENGINE_ID_COUNT ==
          NV2080_CTRL_INTERNAL_ENGINE_CONTEXT_PROPERTIES_ENGINE_ID_COUNT_v25_07);
ct_assert(NV2080_CTRL_INTERNAL_MAX_TPC_PER_GPC_COUNT == NV2080_CTRL_INTERNAL_MAX_TPC_PER_GPC_COUNT_v1C_03);
ct_assert(NV2080_CTRL_PERF_RATED_TDP_CLIENT_NUM_CLIENTS == NV2080_CTRL_PERF_RATED_TDP_CLIENT_NUM_CLIENTS_v1A_1F);
ct_assert(NV83DE_CTRL_DEBUG_MAX_SMS_PER_CALL == NV83DE_CTRL_DEBUG_MAX_SMS_PER_CALL_v16_03);
ct_assert(VGPU_RPC_CTRL_DEBUG_READ_ALL_SM_ERROR_STATES_PER_RPC_v21_06 < NV83DE_CTRL_DEBUG_MAX_SMS_PER_CALL_v16_03);
ct_assert(NV2080_CTRL_FB_INFO_MAX_LIST_SIZE == NV2080_CTRL_FB_INFO_MAX_LIST_SIZE_27_00);
ct_assert(NV2080_CTRL_GPU_MAX_SMC_IDS == 8);
ct_assert(NV2080_GPU_MAX_GID_LENGTH == 0x000000100);
ct_assert(NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_MAX_ENTRIES == 16);
ct_assert(NV2080_GPU_MAX_NAME_STRING_LENGTH == 0x0000040);
ct_assert(NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_MAX_ENGINES == 256);
ct_assert(NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_MAX == NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_MAX_v1E_09);
ct_assert(NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_MAX_DEVICES == 256);
ct_assert(NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_MAX_ENTRIES == 32);
ct_assert(NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_ENGINE_DATA_TYPES == 16);
ct_assert(NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_ENGINE_MAX_PBDMA == 2);
ct_assert(NV2080_CTRL_FIFO_GET_DEVICE_INFO_TABLE_ENGINE_MAX_NAME_LEN == 16);
ct_assert(NV2080_CTRL_FB_DYNAMIC_BLACKLIST_MAX_ENTRIES == 64);
ct_assert(NV2080_CTRL_CE_CAPS_TBL_SIZE == NV2080_CTRL_CE_CAPS_TBL_SIZE_v21_0A);
ct_assert(NV2080_ENGINE_TYPE_COPY_SIZE == NV2080_ENGINE_TYPE_COPY_SIZE_v24_09);
ct_assert(NV2080_ENGINE_TYPE_NVENC_SIZE <= 4);
ct_assert(NV2080_ENGINE_TYPE_NVDEC_SIZE == 8);
ct_assert(NV2080_ENGINE_TYPE_NVJPEG_SIZE == 8);
ct_assert(NV2080_ENGINE_TYPE_GR_SIZE == 8);
ct_assert(NV0000_CTRL_P2P_CAPS_INDEX_TABLE_SIZE == NV0000_CTRL_P2P_CAPS_INDEX_TABLE_SIZE_v1F_0D);
ct_assert(NV0000_CTRL_SYSTEM_MAX_ATTACHED_GPUS == NV0000_CTRL_SYSTEM_MAX_ATTACHED_GPUS_v21_02);
ct_assert(VM_UUID_SIZE == VM_UUID_SIZE_v21_02);
ct_assert(NV2080_CTRL_MAX_PCES == NV2080_CTRL_MAX_PCES_v21_0A);
ct_assert(NV0080_CTRL_MSENC_CAPS_TBL_SIZE_V25_00 == NV0080_CTRL_MSENC_CAPS_TBL_SIZE);
ct_assert(MAX_NVDEC_ENGINES_V1A_07 <= NV2080_CTRL_CMD_INTERNAL_MAX_BSPS);
ct_assert(MAX_NVDEC_ENGINES_V25_00 == NV2080_CTRL_CMD_INTERNAL_MAX_BSPS);
ct_assert(NV0080_CTRL_NVJPG_CAPS_TBL_SIZE_V18_0C == NV0080_CTRL_NVJPG_CAPS_TBL_SIZE);
ct_assert(NV0080_CTRL_BSP_CAPS_TBL_SIZE_V09_10 == NV0080_CTRL_BSP_CAPS_TBL_SIZE);
ct_assert(NV2080_CTRL_GPU_MAX_CONSTRUCTED_FALCONS_V25_01 == NV2080_CTRL_GPU_MAX_CONSTRUCTED_FALCONS);
ct_assert(NV2080_CTRL_CMD_INTERNAL_DEVICE_INFO_MAX_ENTRIES_V25_05 == NV2080_CTRL_CMD_INTERNAL_DEVICE_INFO_MAX_ENTRIES);
ct_assert(NV0080_CTRL_GR_CAPS_TBL_SIZE_v25_0E == NV0080_CTRL_GR_CAPS_TBL_SIZE);
ct_assert(NV2080_CTRL_CMD_GR_CTXSW_PREEMPTION_BIND_BUFFERS_CONTEXT_POOL_v25_0E == NV2080_CTRL_CMD_GR_CTXSW_PREEMPTION_BIND_BUFFERS_CONTEXT_POOL);
ct_assert(RPC_GR_BUFFER_TYPE_GRAPHICS_MAX_v25_0E == RPC_GR_BUFFER_TYPE_GRAPHICS_MAX);
ct_assert(NV9096_CTRL_ZBC_CLEAR_TABLE_TYPE_COUNT_v1A_07 == NV9096_CTRL_ZBC_CLEAR_TABLE_TYPE_COUNT);
ct_assert(NVC637_CTRL_MAX_EXEC_PARTITIONS_v18_05 == NVC637_CTRL_MAX_EXEC_PARTITIONS);
ct_assert(NV2080_CTRL_GPU_INFO_MAX_LIST_SIZE_v25_11 == NV2080_CTRL_GPU_INFO_MAX_LIST_SIZE);
ct_assert(NVGPU_VGPU_ENGINE_LIST_MASK_ARRAY_MAX_v27_01 == NVGPU_VGPU_ENGINE_LIST_MASK_ARRAY_MAX);

#endif /*_RPC_SDK_STRUCTURES_H_*/
