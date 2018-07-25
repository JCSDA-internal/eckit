/*
 * (C) Copyright 1996-2012 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @author Baudouin Raoult
/// @author Simon Smart
/// ECMWF Dec 03

#ifndef eckit_sql_BitColumnExpression_H
#define eckit_sql_BitColumnExpression_H

#include "eckit/sql/expression/ColumnExpression.h"

namespace eckit {
namespace sql {
namespace expression {

//----------------------------------------------------------------------------------------------------------------------

class BitColumnExpression : public ColumnExpression {
public:
	BitColumnExpression(const std::string&, const std::string&, SQLTable*);
	BitColumnExpression(const std::string&, const std::string&, const std::string&);
	BitColumnExpression(const BitColumnExpression&);
	~BitColumnExpression(); 

private:
// No copy allowed
	BitColumnExpression& operator=(const BitColumnExpression&);

protected:
	unsigned long mask_;
	unsigned long bitShift_;

	std::string field_;
	std::string name_;

// -- Overridden methods
	virtual void prepare(SQLSelect& sql);
	virtual double eval(bool& missing) const;
    virtual void expandStars(const std::vector<std::reference_wrapper<SQLTable>>&,expression::Expressions&);
    virtual const eckit::sql::type::SQLType* type() const;

	//friend std::ostream& operator<<(std::ostream& s,const BitColumnExpression& p)
	//	{ p.print(s); return s; }
	friend class SQLSelectFactory;
};

//----------------------------------------------------------------------------------------------------------------------

} // namespace expression 
} // namespace SQL
} // namespace odb 

#endif
