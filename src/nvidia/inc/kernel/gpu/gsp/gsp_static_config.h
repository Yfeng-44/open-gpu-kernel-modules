/*
 * SPDX-FileCopyrightText: Copyright (c) 2019-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

#ifndef GSP_STATIC_CONFIG_H
#define GSP_STATIC_CONFIG_H

//
// This header describes the set of static GPU configuration information
// that is collected during GSP RM init and made available to the
// CPU RM (aka GSP client) via NV_RM_RPC_GET_GSP_STATIC_INFO() call.

#include "ctrl/ctrl0080/ctrl0080gpu.h"
#include "ctrl/ctrl0080/ctrl0080gr.h"
#include "ctrl/ctrl2080/ctrl2080bios.h"
#include "ctrl/ctrl2080/ctrl2080fb.h"
#include "ctrl/ctrl2080/ctrl2080gpu.h"

#include "gpu/gpu.h" // COMPUTE_BRANDING_TYPE
#include "gpu/gpu_acpi_data.h" // ACPI_METHOD_DATA
#include "vgpu/rpc_headers.h" // MAX_GPC_COUNT
#include "platform/chipset/chipset.h" // BUSINFO
#include "gpu/nvbitmask.h" // NVGPU_ENGINE_CAPS_MASK_ARRAY_MAX

// VF related info for GSP-RM
typedef struct GSP_VF_INFO
{
    NvU32  totalVFs;
    NvU32  firstVFOffset;
    NvU64  FirstVFBar0Address;
    NvU64  FirstVFBar1Address;
    NvU64  FirstVFBar2Address;
    NvBool b64bitBar0;
    NvBool b64bitBar1;
    NvBool b64bitBar2;
} GSP_VF_INFO;

typedef struct GspSMInfo_t
{
    NvU32 version;
    NvU32 regBankCount;
    NvU32 regBankRegCount;
    NvU32 maxWarpsPerSM;
    NvU32 maxThreadsPerWarp;
    NvU32 geomGsObufEntries;
    NvU32 geomXbufEntries;
    NvU32 maxSPPerSM;
    NvU32 rtCoreCount;
} GspSMInfo;

typedef struct
{
    NvU32 ecidLow;
    NvU32 ecidHigh;
    NvU32 ecidExtended;
} EcidManufacturingInfo;

// Fetched from GSP-RM into CPU-RM
typedef struct GspStaticConfigInfo_t
{
    NvU8 grCapsBits[NV0080_CTRL_GR_CAPS_TBL_SIZE];
    NV2080_CTRL_GPU_GET_GID_INFO_PARAMS gidInfo;
    NV2080_CTRL_GPU_GET_FERMI_GPC_INFO_PARAMS gpcInfo;
    NV2080_CTRL_GPU_GET_FERMI_TPC_INFO_PARAMS tpcInfo[MAX_GPC_COUNT];
    NV2080_CTRL_GPU_GET_FERMI_ZCULL_INFO_PARAMS zcullInfo[MAX_GPC_COUNT];
    NV2080_CTRL_BIOS_GET_SKU_INFO_PARAMS SKUInfo;
    NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS fbRegionInfoParams;

    NV0080_CTRL_GPU_GET_SRIOV_CAPS_PARAMS sriovCaps;
    NvU32 sriovMaxGfid;

    NvU32 engineCaps[NVGPU_ENGINE_CAPS_MASK_ARRAY_MAX];

    GspSMInfo SM_info;

    NvBool poisonFuseEnabled;

    NvU64 fb_length;
    NvU64 fbio_mask;
    NvU32 fb_bus_width;
    NvU32 fb_ram_type;
    NvU64 fbp_mask;
    NvU32 l2_cache_size;

    NvU32 gfxpBufferSize[NV2080_CTRL_CMD_GR_CTXSW_PREEMPTION_BIND_BUFFERS_CONTEXT_POOL];
    NvU32 gfxpBufferAlignment[NV2080_CTRL_CMD_GR_CTXSW_PREEMPTION_BIND_BUFFERS_CONTEXT_POOL];

    NvU8 gpuNameString[NV2080_GPU_MAX_NAME_STRING_LENGTH];
    NvU8 gpuShortNameString[NV2080_GPU_MAX_NAME_STRING_LENGTH];
    NvU16 gpuNameString_Unicode[NV2080_GPU_MAX_NAME_STRING_LENGTH];
    NvBool bGpuInternalSku;
    NvBool bIsQuadroGeneric;
    NvBool bIsQuadroAd;
    NvBool bIsNvidiaNvs;
    NvBool bIsVgx;
    NvBool bGeforceSmb;
    NvBool bIsTitan;
    NvBool bIsTesla;
    NvBool bIsMobile;
    NvBool bIsGc6Rtd3Allowed;
    NvBool bIsGcOffRtd3Allowed;
    NvBool bIsGcoffLegacyAllowed;

    /* "Total Board Power" refers to power requirement of GPU,
     * while in GC6 state. Majority of this power will be used
     * to keep V-RAM active to preserve its content.
     * Some energy maybe consumed by Always-on components on GPU chip.
     * This power will be provided by 3.3v voltage rail.
     */
    NvU16  RTD3GC6TotalBoardPower;

    /* PERST# (i.e. PCI Express Reset) is a sideband signal
     * generated by the PCIe Host to indicate the PCIe devices,
     * that the power-rails and the reference-clock are stable.
     * The endpoint device typically uses this signal as a global reset.
     */
    NvU16  RTD3GC6PerstDelay;

    NvU64 bar1PdeBase;
    NvU64 bar2PdeBase;

    NvBool bVbiosValid;
    NvU32 vbiosSubVendor;
    NvU32 vbiosSubDevice;

    NvBool bPageRetirementSupported;

    NvBool bSplitVasBetweenServerClientRm;

    NvBool bClRootportNeedsNosnoopWAR;

    VIRTUAL_DISPLAY_GET_NUM_HEADS_PARAMS displaylessMaxHeads;
    VIRTUAL_DISPLAY_GET_MAX_RESOLUTION_PARAMS displaylessMaxResolution;
    NvU64 displaylessMaxPixels;

    // Client handle for internal RMAPI control.
    NvHandle hInternalClient;

    // Device handle for internal RMAPI control.
    NvHandle hInternalDevice;

    // Subdevice handle for internal RMAPI control.
    NvHandle hInternalSubdevice;

    NvBool bSelfHostedMode;
    NvBool bAtsSupported;

    NvBool bIsGpuUefi;
    NvBool bIsEfiInit;

    EcidManufacturingInfo ecidInfo[2];
} GspStaticConfigInfo;

// Pushed from CPU-RM to GSP-RM
typedef struct GspSystemInfo
{
    NvU64 gpuPhysAddr;
    NvU64 gpuPhysFbAddr;
    NvU64 gpuPhysInstAddr;
    NvU64 gpuPhysIoAddr;
    NvU64 nvDomainBusDeviceFunc;
    NvU64 simAccessBufPhysAddr;
    NvU64 notifyOpSharedSurfacePhysAddr;
    NvU64 pcieAtomicsOpMask;
    NvU64 consoleMemSize;
    NvU64 maxUserVa;
    NvU32 pciConfigMirrorBase;
    NvU32 pciConfigMirrorSize;
    NvU32 PCIDeviceID;
    NvU32 PCISubDeviceID;
    NvU32 PCIRevisionID;
    NvU32 pcieAtomicsCplDeviceCapMask;
    NvU8 oorArch;
    NvU64 clPdbProperties;
    NvU32 Chipset;
    NvBool bGpuBehindBridge;
    NvBool bFlrSupported;
    NvBool b64bBar0Supported;
    NvBool bMnocAvailable;
    NvBool bUpstreamL0sUnsupported;
    NvBool bUpstreamL1Unsupported;
    NvBool bUpstreamL1PorSupported;
    NvBool bUpstreamL1PorMobileOnly;
    NvU8   upstreamAddressValid;
    BUSINFO FHBBusInfo;
    BUSINFO chipsetIDInfo;
    ACPI_METHOD_DATA acpiMethodData;
    NvU32 hypervisorType;
    NvBool bIsPassthru;
    NvU64 sysTimerOffsetNs;
    GSP_VF_INFO gspVFInfo;
    NvBool bIsPrimary;
    NvBool isGridBuild;
    NvU32 gridBuildCsp;
    NvBool bPreserveVideoMemoryAllocations;
    NvBool bTdrEventSupported;
    NvBool bFeatureStretchVblankCapable;
    NvBool bClockBoostSupported;
} GspSystemInfo;


#endif /* GSP_STATIC_CONFIG_H */
