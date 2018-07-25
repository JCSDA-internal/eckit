/*
 * (C) Copyright 1996-2012 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#ifndef eckit_sql_SQLSelectFactory_H
#define eckit_sql_SQLSelectFactory_H

#include <vector>
#include <memory>

//#include "odb_api/SchemaAnalyzer.h"
#include "eckit/sql/SQLOutputConfig.h"

// Forward declarations

namespace eckit {
    class DataHandle;
    namespace sql {
        class SQLDatabase;
        class SQLSession;
        class SQLTable;
        class SQLSelect;
        namespace expression {
            class Expressions;
            class SQLExpression;
        }
    }
}


namespace eckit { 
namespace sql {

//----------------------------------------------------------------------------------------------------------------------

class SQLSelectFactory {
public:
    SQLSelectFactory(SQLSession& session);

	SQLSelect* create(
        bool distinct,
        bool all,
        const expression::Expressions& select_list,
        const std::string& into,
        const std::vector<std::reference_wrapper<SQLTable>>& from
//        expression::SQLExpression *where,
//        const Expressions& group_by,
//        std::pair<Expressions, std::vector<bool> > order_by);
            );

    expression::SQLExpression* createColumn(
		const std::string& columnName,
		const std::string& bitfieldName,
        const expression::SQLExpression* vectorIndex,
        const SQLTable& table,
        const expression::SQLExpression* pshift);

    eckit::DataHandle* implicitFromTableSource() { return implicitFromTableSource_; }
    void implicitFromTableSource(eckit::DataHandle* h) { implicitFromTableSource_ = h; }

    std::istream* implicitFromTableSourceStream() { return implicitFromTableSourceStream_; }
    void implicitFromTableSourceStream(std::istream* is) { implicitFromTableSourceStream_ = is; }

	SQLDatabase* database() { return database_; }
	void database(SQLDatabase* db) { database_ = db; }

	SQLOutputConfig config() { return config_; }
	void config(const SQLOutputConfig& cfg) { config_ = cfg; }

	std::string csvDelimiter() { return csvDelimiter_; }
	void csvDelimiter(const std::string& d) { csvDelimiter_ = d; }

//    static odb::MetaData toODAColumns(odb::sql::SQLSession&, const odb::sql::TableDef&);

private: // methods

    // No copy allowed
    SQLSelectFactory(const SQLSelectFactory&);
    SQLSelectFactory& operator=(const SQLSelectFactory&);

    std::string index(const std::string& columnName, const expression::SQLExpression* index);

    void reshift(expression::Expressions&);

    std::shared_ptr<expression::SQLExpression> reshift(std::shared_ptr<expression::SQLExpression>&);

    //void resolveImplicitFrom(SQLSession&, std::vector<SQLTable*>& from);
//    std::vector<SQLTable*> resolveImplicitFrom(SQLSession&, std::vector<Table>& from);

private: // members

    SQLSession& session_;

    eckit::DataHandle* implicitFromTableSource_;

    std::istream* implicitFromTableSourceStream_;

    //SchemaAnalyzer& analyzer();
//    MetaData columns(const std::string& tableName);
    SQLOutput* createOutput(SQLSession&, const std::string& into, size_t orderBySize );

    SQLDatabase* database_;
    SQLOutputConfig config_;
    int maxColumnShift_;
    int minColumnShift_;
    std::string csvDelimiter_;

    //friend class eckit::NewAlloc0<SQLSelectFactory>;
};

//----------------------------------------------------------------------------------------------------------------------

} // namespace sql
} // namespace eckit

#endif
