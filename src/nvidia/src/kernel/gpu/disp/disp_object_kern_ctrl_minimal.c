/*
 * SPDX-FileCopyrightText: Copyright (c) 2021-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

#define RM_STRICT_CONFIG_EMIT_DISP_ENGINE_DEFINITIONS     0

#include "class/cl5070.h"
#include "gpu/disp/disp_objs.h"
#include "gpu/disp/kern_disp.h"
#include "gpu/gpu.h"
#include "gpu/subdevice/subdevice.h"
#include "gpu_mgr/gpu_mgr.h"
#include "mem_mgr/mem.h"
#include "rmapi/client_resource.h"
#include "rmapi/rmapi.h"
#include "rmapi/rs_utils.h"

static NV_STATUS getRgConnectedLockpin(OBJGPU *pGpu,
    KernelDisplay *pKernelDisplay, NvU32 head,
    OBJGPU *pPeerGpu, NvU32 peerHead,
    NvU32 *pMasterScanLock, NvU32 *pSlaveScanLock)
{
    NvBool bMasterScanLock, bSlaveScanLock;
    NvU32 masterScanLockPin, slaveScanLockPin;

    *pMasterScanLock = 0;
    *pSlaveScanLock = 0;

    NV_STATUS status = kdispGetRgScanLock_HAL(pGpu, pKernelDisplay,
                                   head,
                                   pPeerGpu,
                                   peerHead,
                                   &bMasterScanLock,
                                   &masterScanLockPin,
                                   &bSlaveScanLock,
                                   &slaveScanLockPin);
    NV_ASSERT_OK_OR_RETURN(status);

    if (bMasterScanLock)
    {
        *pMasterScanLock =
            FLD_SET_DRF(5070, _CTRL_CMD_GET_RG_CONNECTED_LOCKPIN_STATELESS,
                        _MASTER_SCAN_LOCK_CONNECTED, _YES, *pMasterScanLock);

        *pMasterScanLock =
            FLD_SET_DRF_NUM(5070, _CTRL_CMD_GET_RG_CONNECTED_LOCKPIN_STATELESS,
                            _MASTER_SCAN_LOCK_PIN, masterScanLockPin,
                            *pMasterScanLock);
    }
    else
    {
        *pMasterScanLock =
            FLD_SET_DRF(5070, _CTRL_CMD_GET_RG_CONNECTED_LOCKPIN_STATELESS,
                        _MASTER_SCAN_LOCK_CONNECTED, _NO, *pMasterScanLock);
    }

    if (bSlaveScanLock)
    {
        *pSlaveScanLock =
            FLD_SET_DRF(5070, _CTRL_CMD_GET_RG_CONNECTED_LOCKPIN_STATELESS,
                        _SLAVE_SCAN_LOCK_CONNECTED, _YES, *pSlaveScanLock);

        *pSlaveScanLock =
            FLD_SET_DRF_NUM(5070, _CTRL_CMD_GET_RG_CONNECTED_LOCKPIN_STATELESS,
                            _SLAVE_SCAN_LOCK_PIN, slaveScanLockPin,
                            *pSlaveScanLock);
    }
    else
    {
        *pSlaveScanLock =
            FLD_SET_DRF(5070, _CTRL_CMD_GET_RG_CONNECTED_LOCKPIN_STATELESS,
                        _SLAVE_SCAN_LOCK_CONNECTED, _NO, *pSlaveScanLock);
    }

    return NV_OK;
}

NV_STATUS
dispobjCtrlCmdGetRgConnectedLockpinStateless_IMPL
(
    DispObject *pDispObject,
    NV5070_CTRL_GET_RG_CONNECTED_LOCKPIN_STATELESS_PARAMS *pParams
)
{
    OBJGPU         *pGpu = DISPAPI_GET_GPU(pDispObject);
    KernelDisplay *pKernelDisplay = GPU_GET_KERNEL_DISPLAY(pGpu);
    NvHandle        hClient = RES_GET_CLIENT_HANDLE(pDispObject);
    OBJGPU         *pPeerGpu;

    NV_ASSERT_OR_RETURN(pParams->head < pKernelDisplay->numHeads, NV_ERR_INVALID_ARGUMENT);

    RsResourceRef *pPeerDisplayRef;
    NV_ASSERT_OK_OR_RETURN(serverutilGetResourceRef(hClient, pParams->peer.hDisplay, &pPeerDisplayRef));
    NV_ASSERT_OR_RETURN(pPeerDisplayRef->pParentRef != NULL, NV_ERR_INVALID_STATE);
    NV_ASSERT_OR_RETURN((dynamicCast(pPeerDisplayRef->pResource, DispCommon) != NULL ||
                         dynamicCast(pPeerDisplayRef->pResource, DispObject) != NULL), 
                         NV_ERR_INVALID_OBJECT);

    Subdevice *pPeerSubdevice;
    NV_ASSERT_OK_OR_RETURN(subdeviceGetByInstance(RES_GET_CLIENT(pDispObject), pPeerDisplayRef->pParentRef->hResource,
        pParams->peer.subdeviceIndex, &pPeerSubdevice));
    pPeerGpu = GPU_RES_GET_GPU(pPeerSubdevice);

    NV_ASSERT_OR_RETURN(pPeerGpu != NULL, NV_ERR_INVALID_ARGUMENT);
    NV_ASSERT_OR_RETURN(pParams->peer.head < GPU_GET_KERNEL_DISPLAY(pPeerGpu)->numHeads, NV_ERR_INVALID_ARGUMENT);

    return getRgConnectedLockpin(pGpu, pKernelDisplay, pParams->head, pPeerGpu, pParams->peer.head,
        &pParams->masterScanLock, &pParams->slaveScanLock);
}
