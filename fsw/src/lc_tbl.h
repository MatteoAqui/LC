/*******************************************************************************
**
**      GSC-18128-1, "Core Flight Executive Version 6.7"
**
**      Copyright (c) 2006-2019 United States Government as represented by
**      the Administrator of the National Aeronautics and Space Administration.
**      All Rights Reserved.
**
**      Licensed under the Apache License, Version 2.0 (the "License");
**      you may not use this file except in compliance with the License.
**      You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
**      Unless required by applicable law or agreed to in writing, software
**      distributed under the License is distributed on an "AS IS" BASIS,
**      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**      See the License for the specific language governing permissions and
**      limitations under the License.
**
*******************************************************************************/

/* Define LC tables */

#ifndef LC_TABLE_H
#define LC_TABLE_H

#include "lc_eds_typedefs.h"

/*
 * The EDS defines the table types names differently than the types
 * referred to in the source code due to different conventions used
 *
 * This discrepancy can be worked around with a typedef for now
 */
typedef LC_WdtEntry_t LC_WDTEntry_t;
typedef LC_AdtEntry_t LC_ADTEntry_t;

typedef LC_WrtEntry_t LC_WRTEntry_t;
typedef LC_ArtEntry_t LC_ARTEntry_t;

// typedef LC_MultiType LC_MultiType_t;

#endif /* LC_TABLE_H */
