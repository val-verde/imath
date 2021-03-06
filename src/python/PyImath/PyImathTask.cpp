//
// SPDX-License-Identifier: BSD-3-Clause
// Copyright Contributors to the OpenEXR Project.
//

// clang-format off

#include "PyImathTask.h"

namespace PyImath {

static WorkerPool *_currentPool = nullptr;

// Its not worth dispatching parallel tasks unless the iteration count
// is high enough.  The time to create and launch parallel tasks takes
// longer than to just do the iterations directly.  This value of '200'
// is actually very conservative; in some tests, this number should
// probably be in the thousands.
static const size_t _minIterations = 200;

WorkerPool *
WorkerPool::currentPool()
{
    return _currentPool;
}

void
WorkerPool::setCurrentPool(WorkerPool *pool)
{
    _currentPool = pool;
}

void
dispatchTask(Task &task,size_t length)
{
    if (length > _minIterations)
    {
        WorkerPool *curpool = WorkerPool::currentPool();
        if (curpool && !curpool->inWorkerThread())
        {
            curpool->dispatch(task,length);
            return;
        }
    }
    task.execute(0,length,0);
}


size_t
workers()
{
    WorkerPool *curpool = WorkerPool::currentPool();
    if (curpool && !curpool->inWorkerThread())
        return curpool->workers();
    return 1;
}

}
