// Copyright (C) 2024 owoDra

#pragma once

#include "Logging/LogMacros.h"

GCLINTG_API DECLARE_LOG_CATEGORY_EXTERN(LogGCLI, Log, All);

#if !UE_BUILD_SHIPPING

#define GCLILOG(FormattedText, ...) UE_LOG(LogGCLI, Log, FormattedText, __VA_ARGS__)

#define GCLIENSURE(InExpression) ensure(InExpression)
#define GCLIENSURE_MSG(InExpression, InFormat, ...) ensureMsgf(InExpression, InFormat, __VA_ARGS__)
#define GCLIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) ensureAlwaysMsgf(InExpression, InFormat, __VA_ARGS__)

#define GCLICHECK(InExpression) check(InExpression)
#define GCLICHECK_MSG(InExpression, InFormat, ...) checkf(InExpression, InFormat, __VA_ARGS__)

#else

#define GCLILOG(FormattedText, ...)

#define GCLIENSURE(InExpression) InExpression
#define GCLIENSURE_MSG(InExpression, InFormat, ...) InExpression
#define GCLIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) InExpression

#define GCLICHECK(InExpression) InExpression
#define GCLICHECK_MSG(InExpression, InFormat, ...) InExpression

#endif