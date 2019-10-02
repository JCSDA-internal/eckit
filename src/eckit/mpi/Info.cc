/*
 * (C) Copyright 2019 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#include "eckit/mpi/Info.h"

namespace eckit {
namespace mpi {

//----------------------------------------------------------------------------------------------------------------------

int info_null() {
    MPI_Info info_c = MPI_INFO_NULL;
    MPI_Fint info_f = MPI_Info_c2f(info_c);
    return info_f;
}

//----------------------------------------------------------------------------------------------------------------------

}  // namespace mpi
}  // namespace eckit
