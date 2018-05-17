/**
 * @file pylon_exc.h
 *
 * @description
 *    This file contains the implementation of a tool for
 * converting the exceptions generated by pylon into exceptions
 * that can be read in Python
 *
 */

#ifndef __PYLON_EXC_H__
#define __PYLON_EXC_H__

#include <pylon/PylonIncludes.h>
#include "Python.h"
#include <iostream>

void raise_py_error()
{
  try {
    throw;
  } catch( Pylon::GenericException& exc) {
    const char * desc = exc.what();
    std::cout << "Error: " << desc << std::endl;
    PyErr_SetString(PyExc_RuntimeError, desc);
  }
}

#endif
