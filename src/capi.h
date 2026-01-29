#ifndef __CAPI_H__
#define __CAPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* This is not apart of the original PySqlite Source code but 
was added in to allow others to extend and speedup 
it's functionality elsewhere, examples: C, Rust (pyo3), Cython */

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <sqlite3.h>
#include "blob.h"
#include "cache.h"
#include "connection.h"
#include "cursor.h"
#include "microprotocols.h"
#include "module.h"
#include "prepare_protocol.h"
#include "row.h"
#include "statement.h"
#include "util.h"



#define PYSQLITE_MODULE_NAME "pysqlite3._sqlite3"
#define PYSQLITE_CAPI_NAME "CAPI"
#define PYSQLITE_CAPSULE_NAME PYSQLITE_MODULE_NAME "." PYSQLITE_CAPI_NAME

typedef struct _pysqlite_capi {
    /* Types */
    PyTypeObject* BlobType;
    PyTypeObject* CacheType;
    PyTypeObject* ConnectionType;
    PyTypeObject* CursorType;
    PyTypeObject* PrepareProtocolType;
    PyTypeObject* RowType;
    PyTypeObject* StatementType;

    /* Exceptions */
    PyObject* Error;
    PyObject* Warning;
    PyObject* InterfaceError;
    PyObject* DatabaseError;
    PyObject* InternalError;
    PyObject* OperationalError;
    PyObject* ProgrammingError;
    PyObject* IntegrityError;
    PyObject* DataError;
    PyObject* NotSupportedError;




} PySqlite_CAPI;

static inline PySqlite_CAPI*
PySqlite_Import()
{
    return (PySqlite_CAPI*)PyCapsule_Import(PYSQLITE_CAPSULE_NAME, 0);
}


#ifdef __cplusplus
}
#endif


#endif // __CAPI_H__