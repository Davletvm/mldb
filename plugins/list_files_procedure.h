/**
 * list_files.h
 * Mich, 2016-05-10
 * This file is part of MLDB. Copyright 2016 Datacratic. All rights reserved.
 **/

#pragma once
#include "mldb/core/procedure.h"
#include "mldb/core/function.h"
#include "mldb/core/dataset.h"
#include "mldb/sql/sql_expression.h"

namespace Datacratic {
namespace MLDB {

struct ListFilesProcedureConfig : ProcedureConfig {
    static constexpr const char * name = "list.files";

    ListFilesProcedureConfig();

    std::string path;
    Date modifiedSince;
    PolyConfigT<Dataset> outputDataset;
};

DECLARE_STRUCTURE_DESCRIPTION(ListFilesProcedureConfig);

struct ListFilesProcedure: public Procedure {

    ListFilesProcedure(
        MldbServer * owner,
        PolyConfig config,
        const std::function<bool (const Json::Value &)> & onProgress);

    virtual RunOutput run(
        const ProcedureRunConfig & run,
        const std::function<bool (const Json::Value &)> & onProgress) const;

    virtual Any getStatus() const;

    ListFilesProcedureConfig procedureConfig;
};

} // namespace MLDB
} // namespace Datacratic