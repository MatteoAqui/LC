/*
**
**  Purpose:
**    Define application configurations for the LC application
**
**  Notes:
**    Includes parameters defined in the config/default_lc_*.h files
**    in the effort of porting the LC app to be compatible with:
**    - EDS pipeline
**    - Basecamp App development (based on app_c_fw)
**    
*/

#ifndef _app_cfg_
#define _app_cfg_

/*
** Includes
*/

#include "app_c_fw.h"
// #include "lc_eds_typedefs.h"

/******************************************************************************
** Versions
**
** 0.0 - Initial version
*/

#define  LC_MAJOR_VER   0
#define  LC_MINOR_VER   0

/* --- From default_lc_interface_cfg.h  --- */
#define LC_RTS_REQ_MID 0x18A9
#define LC_RTS_REQ_CC 4
#define LC_MAX_WATCHPOINTS 176
#define LC_MAX_ACTIONPOINTS 176
#define LC_MAX_ACTION_TEXT 32
#define LC_MAX_RPN_EQU_SIZE 20
/* --- From default_lc_msgdefs.h  --- */
#define LC_STATE_ACTIVE   1 // LC Application State Active 
#define LC_STATE_PASSIVE  2 // LC Application State Pasive 
#define LC_STATE_DISABLED 3 // LC Application State Disabled 
#define LC_STATE_FROM_CDS 4 // Used for reset processing, not valid state 
#define LC_APSTATE_NOT_USED 0xFF // Actionpoint unused, not valid command argument 
#define LC_APSTATE_ACTIVE   1    // Actionpoint state active 
#define LC_APSTATE_PASSIVE  2    // Actionpoint state passive 
#define LC_APSTATE_DISABLED 3    // Actionpoint state disabled 
#define LC_APSTATE_PERMOFF  4    // Actionpoint state permanently off, see #LC_SET_AP_PERM_OFF_CC 
#define LC_ALL_ACTIONPOINTS 0xFFFF // Special number indicating all actionpoints 
#define LC_ALL_WATCHPOINTS  0xFFFF // Special number indicating all watchpoints 
#define LC_HKWR_FALSE 0x00 // Two bit value used for FALSE        
#define LC_HKWR_TRUE  0x01 // Two bit value used for TRUE         
#define LC_HKWR_ERROR 0x02 // Two bit value used for ERROR        
#define LC_HKWR_STALE 0x03 // Two bit value used for STALE        
#define LC_HKAR_PASS  0x00 // Two bit value used for PASS         
#define LC_HKAR_FAIL  0x01 // Two bit value used for FAIL         
#define LC_HKAR_ERROR 0x02 // Two bit value used for ERROR        
#define LC_HKAR_STALE 0x03 // Two bit value used for STALE        
#define LC_HKAR_STATE_NOT_USED 0x00 // Two bit value used for NOT USED and PERMOFF 
#define LC_HKAR_STATE_ACTIVE   0x01 // Two bit value used for ACTIVE       
#define LC_HKAR_STATE_PASSIVE  0x02 // Two bit value used for PASSIVE      
#define LC_HKAR_STATE_DISABLED 0x03 // Two bit value used for DISABLED     
#define LC_HKWR_NUM_BYTES                                                         \
    (((LC_MAX_WATCHPOINTS + 15) / 16) * 4) // 2 bits per WP and keeping array on longword boundary 
#define LC_HKAR_NUM_BYTES                                                        \
    (((LC_MAX_ACTIONPOINTS + 7) / 8) * 4) // 4 bits per AP and keeping array on longword boundary 
/* --- From default_lc_internal_cfg.h  (TODO: some should be part of ini json table) --- */
#define LC_APP_NAME "LC"
#define LC_PIPE_DEPTH 12
#define LC_STATE_POWER_ON_RESET LC_STATE_DISABLED
#define LC_STATE_WHEN_CDS_RESTORED LC_STATE_FROM_CDS
#define LC_WDT_FILENAME "/cf/lc_def_wdt.tbl"
#define LC_ADT_FILENAME "/cf/lc_def_adt.tbl"
#define LC_MAX_VALID_ADT_RTSID 0xFFF0
#define LC_FLOAT_TOLERANCE (1.0e-25)
#define LC_WDT_TABLENAME "LC_WDT"
#define LC_ADT_TABLENAME "LC_ADT"
#define LC_WRT_TABLENAME "LC_WRT"
#define LC_ART_TABLENAME "LC_ART"
/* --- From default_lc_msgdefs.h  --- */
#define LC_CMD_MID       0x18A4 // Msg ID for cmds to LC                
#define LC_SEND_HK_MID   0x18A5 // Msg ID to request LC housekeeping    
#define LC_SAMPLE_AP_MID 0x18A6 // Msg ID to request actionpoint sample 
#define LC_HK_TLM_MID 0x08A7 // LC Housekeeping Telemetry 


/* TODO: default_lc_tbldefs and default_lc_tblstruct (possibly in lc.xml)*/


/* ---------- TODO/REVIEW (from app_c_demo) ---------- */

/******************************************************************************
** Init JSON file declarations. The following steps show how to define and
** use initialization parameters defined in the JSON ini file. Users don't 
** need to know the structures created by the macros but they are shown for
** completeness. The app's command pipe definitions are used as an example. 
**
** 1. Define configuration parameter names
**
**    #define CFG_CMD_PIPE_NAME   CMD_PIPE_NAME
**    #define CFG_CMD_PIPE_DEPTH  CMD_PIPE_DEPTH
**
** 2. Add the parameter to the APP_CONFIG(XX) macro using the name as defined
**    in step 1
**
**    #define APP_CONFIG(XX) \
**       XX(CMD_PIPE_NAME,char*) \
**       XX(CMD_PIPE_DEPTH,uint32) \
**
** 3. Define the parameterin the JSON ini file's "config" object using the
**    same parameter as defined in step 1
**
**    "config": {
**       "CMD_PIPE_NAME":  "APP_C_DEMO_CMD",
**       "CMD_PIPE_DEPTH": 5,
** 
** 4. Access the parameteres in your code 
**    
**    INITBL_GetStrConfig(INITBL_OBJ, CFG_CMD_PIPE_NAME)
**    INITBL_GetIntConfig(INITBL_OBJ, CFG_CMD_PIPE_DEPTH)
**
** The following declarations are created using the APP_CONFIG(XX) and 
** XX(name,type) macros:
** 
**    typedef enum {
**       CMD_PIPE_DEPTH,
**       CMD_PIPE_NAME
**    } INITBL_ConfigEnum;
**    
**    typedef struct {
**       CMD_PIPE_DEPTH,
**       CMD_PIPE_NAME
**    } INITBL_ConfigStruct;
**
**    const char *GetConfigStr(value);
**    ConfigEnum GetConfigVal(const char *str);
**
*/

// #define CFG_APP_CFE_NAME        APP_CFE_NAME
// #define CFG_APP_PERF_ID         APP_PERF_ID

// #define CFG_APP_CMD_PIPE_NAME   APP_CMD_PIPE_NAME
// #define CFG_APP_CMD_PIPE_DEPTH  APP_CMD_PIPE_DEPTH

// #define CFG_APP_C_DEMO_CMD_TOPICID             APP_C_DEMO_CMD_TOPICID
// #define CFG_APP_C_DEMO_EXE_TOPICID             BC_SCH_1_HZ_TOPICID
// #define CFG_APP_C_DEMO_STATUS_TLM_TOPICID      APP_C_DEMO_STATUS_TLM_TOPICID
// #define CFG_APP_C_DEMO_BIN_PLAYBK_TLM_TOPICID  APP_C_DEMO_BIN_PLAYBK_TLM_TOPICID

// #define CFG_CHILD_NAME        CHILD_NAME
// #define CFG_CHILD_PERF_ID     CHILD_PERF_ID
// #define CFG_CHILD_STACK_SIZE  CHILD_STACK_SIZE
// #define CFG_CHILD_PRIORITY    CHILD_PRIORITY

// #define CFG_DEVICE_DATA_MODULO  DEVICE_DATA_MODULO

// #define CFG_HIST_LOG_FILE_PREFIX    HIST_LOG_FILE_PREFIX
// #define CFG_HIST_LOG_FILE_EXTENSION HIST_LOG_FILE_EXTENSION

// #define CFG_HIST_TBL_LOAD_FILE      HIST_TBL_LOAD_FILE
// #define CFG_HIST_TBL_DUMP_FILE      HIST_TBL_DUMP_FILE


// #define APP_CONFIG(XX) \
//    XX(APP_CFE_NAME,char*) \
//    XX(APP_PERF_ID,uint32) \
//    XX(APP_CMD_PIPE_NAME,char*) \
//    XX(APP_CMD_PIPE_DEPTH,uint32) \
//    XX(APP_C_DEMO_CMD_TOPICID,uint32) \
//    XX(BC_SCH_1_HZ_TOPICID,uint32) \
//    XX(APP_C_DEMO_STATUS_TLM_TOPICID,uint32) \
//    XX(APP_C_DEMO_BIN_PLAYBK_TLM_TOPICID,uint32) \
//    XX(CHILD_NAME,char*) \
//    XX(CHILD_PERF_ID,uint32) \
//    XX(CHILD_STACK_SIZE,uint32) \
//    XX(CHILD_PRIORITY,uint32) \
//    XX(DEVICE_DATA_MODULO,uint32)\
//    XX(HIST_LOG_FILE_PREFIX,char*) \
//    XX(HIST_LOG_FILE_EXTENSION,char*) \
//    XX(HIST_TBL_LOAD_FILE,char*) \
//    XX(HIST_TBL_DUMP_FILE,char*) \

// DECLARE_ENUM(Config,APP_CONFIG)

/******************************************************************************
** App level definitions that don't need to be in the ini file
**
*/

// #define APP_C_DEMO_UNDEF_TLM_STR "Undefined"

// /******************************************************************************
// ** Event Macros
// **
// ** Define the base event message IDs used by each object/component used by the
// ** application. There are no automated checks to ensure an ID range is not
// ** exceeded so it is the developer's responsibility to verify the ranges. 
// */

// #define APP_C_DEMO_BASE_EID     (APP_C_FW_APP_BASE_EID +  0)
// #define DEVICE_BASE_EID         (APP_C_FW_APP_BASE_EID + 20)
// #define HISTOGRAM_BASE_EID      (APP_C_FW_APP_BASE_EID + 40)
// #define HISTOGRAM_LOG_BASE_EID  (APP_C_FW_APP_BASE_EID + 60)
// #define HISTOGRAM_TBL_BASE_EID  (APP_C_FW_APP_BASE_EID + 80)

// /******************************************************************************
// ** Histogram Macros
// */

// #define HISTOGRAM_MAX_BINS  5

// /******************************************************************************
// ** Histogram Log Macros
// */

// #define HISTOGRAM_LOG_FILE_EXT_MAX_LEN  5  /* Includes '.' and null terminator */


// /******************************************************************************
// ** Histogram Table Macros
// */

// #define HISTOGRAM_TBL_JSON_MAX_OBJ          10
// #define HISTOGRAM_TBL_JSON_FILE_MAX_CHAR  4090 
// #define HISTOGRAM_TBL_NAME                "Histogram" 


#endif /* _app_cfg_ */
