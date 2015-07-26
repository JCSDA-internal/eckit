/*
 * (C) Copyright 1996-2015 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @author Baudouin Raoult
/// @date JUl 2015


#ifndef eckit_Configuration_H
#define eckit_Configuration_H


#include "eckit/config/Parametrisation.h"
#include "eckit/value/Value.h"


namespace eckit {


class LocalConfiguration;

class Configuration : public Parametrisation {
  public:

    // -- Exceptions
    // None

    // -- Contructors


    // -- Convertors
    // None

    // -- Operators
    // None

    // -- Methods

    Value lookUp(const std::string &) const;
    char separator() const;

    // -- Overridden methods

    virtual bool has(const std::string &name) const;

    virtual bool get(const std::string &name, std::string &value) const;
    virtual bool get(const std::string &name, bool &value) const;
    virtual bool get(const std::string &name, long &value) const;
    virtual bool get(const std::string &name, double &value) const;

    virtual bool get(const std::string &name, std::vector<long> &value) const;
    virtual bool get(const std::string &name, std::vector<double> &value) const;
    virtual bool get(const std::string &name, size_t &value) const;


    bool get(const std::string &name, std::vector<LocalConfiguration>&) const;

    // -- Class members
    // None

    // -- Class methods


  protected:

    Configuration(const Configuration &);
    Configuration(const Value &root, char separator = '.');
    virtual ~Configuration();

    // -- Destructor

    // -- Members

    Value root_;
    char separator_;

    // -- Methods

    Value lookUp(const std::string &, bool &) const;

    // void print(ostream&) const; // Change to virtual if base class

    // -- Overridden methods
    // None

    // -- Class members
    // None

    // -- Class methods
    // None

  private:

    // No copy allowed

    Configuration &operator=(const Configuration &);

    // -- Members



    // -- Methods


    // -- Overridden methods

    // From MIRParametrisation
    virtual void print(std::ostream &) const = 0;



    // -- Class members
    // None

    // -- Class methods
    // None

    // -- Friends

    friend std::ostream& operator<<(std::ostream& s,const Configuration& p)
     { p.print(s); return s; }

};


}  // namespace eckit
#endif

