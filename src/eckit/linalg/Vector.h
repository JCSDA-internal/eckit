/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

/// @file   Vector.h
/// @author Florian Rathgeber
/// @date   June 2015

#ifndef eckit_linalg_Vector_h
#define eckit_linalg_Vector_h

#include "eckit/exception/Exceptions.h"
#include "eckit/linalg/types.h"

namespace eckit {
class Stream;
}

namespace eckit {
namespace linalg {

//-----------------------------------------------------------------------------

// TODO: provide a const view
class Vector {
public:  // methods

    // -- Constructors

    /// Default constructor (empty vector)
    Vector();

    /// Construct vector of given size (allocates memory, not initialised)
    Vector(Size s);

    /// Construct vector from existing data (does NOT take ownership)
    Vector(Scalar* v, Size s);

    /// Constructor from Stream
    Vector(Stream&);

    /// Copy constructor
    Vector(const Vector&);

    // TODO: make virtual if used as base class
    ~Vector();

    // -- Mutators

    Vector& operator=(const Vector&);

    /// Swap this vector for another
    void swap(Vector& v);

    /// Resize vector to given size (invalidates data)
    void resize(Size s);

    /// Set data to zero
    void setZero();

    /// Fill vector with given scalar
    void fill(Scalar);

    // -- Serialisation

    /// Serialise to a Stream
    void encode(Stream&) const;

    // -- Accessors

    /// @returns size (rows * cols)
    Size size() const { return size_; }
    /// @returns number of rows (i.e. size)
    Size rows() const { return size_; }
    /// @returns number of columns (always 1)
    Size cols() const { return 1; }

    Scalar& operator[](Size i) { return v_[i]; }
    const Scalar& operator[](Size i) const { return v_[i]; }

    /// @returns modifiable view of the data
    Scalar* data() { return v_; }
    /// @returns read-only view of the data
    const Scalar* data() const { return v_; }

    /// @returns iterator to beginning of the data
    Scalar* begin() { return v_; }
    /// @returns const iterator to beginning of the data
    const Scalar* begin() const { return v_; }
    /// @returns iterator to end of the data
    Scalar* end() { return v_ + size_; }
    /// @returns const iterator to end of the data
    const Scalar* end() const { return v_ + size_; }

protected:  // members

    /// Container
    Scalar* v_;

    /// Vector length/size
    Size size_;

    /// Indicate ownership
    bool own_;

};

//-----------------------------------------------------------------------------

Stream& operator<<(Stream&, const Vector&);

//-----------------------------------------------------------------------------

}  // namespace linalg
} // namespace eckit

#endif
