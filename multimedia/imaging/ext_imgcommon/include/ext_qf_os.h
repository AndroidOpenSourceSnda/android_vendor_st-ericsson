/////////////////////////////////////////////////////////////////////
// Quantum Framework Win32-specific public header file (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA.
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qf_os_h
#define qf_os_h


// Win32-specific event object, event-queue and thread types...
#define QF_OS_EVENT(x_)  HANDLE  x_;
#define QF_EQUEUE(x_)    QEQueue x_;
#define QF_THREAD(x_)    HANDLE  x_;
#define Q_STATIC_CAST(type_, expr_) static_cast<type_>(expr_)

// include framework elements...
#include "ext_qevent.h"
#include "ext_qfpkg.h"
//#include "qfsm.h"
#include "ext_qhsm.h"
//#include "qequeue.h"                       // Win32 needs event-queue
//#include "qepool.h"                         // Win32 needs event-pool
//#include "qactive.h"
//#include "qtimer.h"
//#include "qf.h"

#endif                                                  // qf_os_h
