// Copyright (c) 2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#define INCL_BASE
#include <os2.h>

#include "base/sys_info.h"
#include "base/basictypes.h"

#include "base/logging.h"

namespace base {

// static
int SysInfo::NumberOfProcessors() {
  ULONG ul;
  APIRET arc = DosQuerySysInfo(QSV_NUMPROCESSORS, QSV_NUMPROCESSORS, &ul, sizeof(ul));
  if (arc != NO_ERROR) {
    NOTREACHED();
    return 1;
  }

  return static_cast<int>(static_cast<uint>(ul));
}

// static
int64 SysInfo::AmountOfPhysicalMemory() {
  ULONG ul;
  APIRET arc = DosQuerySysInfo(QSV_TOTPHYSMEM, QSV_TOTPHYSMEM, &ul, sizeof(ul));
  if (arc != NO_ERROR) {
    NOTREACHED();
    return 0;
  }

  return static_cast <int64>(static_cast<uint64>(ul));
}

}  // namespace base
