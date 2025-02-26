/*
**
**  Purpose:
**    Define application configurations for the LC application
**
**  Notes:
**    Includes parameters defined in the config/default_lc_*.h files
**    in the effort of porting the LC app to be compatible with
**    Basecamp App development (based on app_c_fw), including EDS definitions    
*/

#ifndef _app_cfg_
#define _app_cfg_

/*
** Includes
*/

#include "app_c_fw.h"
#include "lc_eds_typedefs.h"

/******************************************************************************
** Versions
**
** 0.0 - Initial version
*/
#define  LC_MAJOR_VER   0
#define  LC_MINOR_VER   0
#define  LC_REVISION    0

/******************************************************************************
** App level definitions that don't need to be in the ini file
**
*/

/* --- From default_lc_interface_cfg.h --- */

#define LC_MAX_WATCHPOINTS 176
#define LC_MAX_ACTIONPOINTS 176
#define LC_MAX_ACTION_TEXT 32
#define LC_MAX_RPN_EQU_SIZE 20

/* --- From default_lc_msgdefs.h --- */
#define LC_ALL_ACTIONPOINTS 0xFFFF // Special number indicating all actionpoints 
#define LC_ALL_WATCHPOINTS  0xFFFF // Special number indicating all watchpoints 
#define LC_HKWR_NUM_BYTES                                                         \
    (((LC_MAX_WATCHPOINTS + 15) / 16) * 4) // 2 bits per WP and keeping array on longword boundary 
#define LC_HKAR_NUM_BYTES                                                        \
    (((LC_MAX_ACTIONPOINTS + 7) / 8) * 4) // 4 bits per AP and keeping array on longword boundary

/* --- From default_lc_internal_cfg.h --- */
#define LC_MAX_VALID_ADT_RTSID 0xFFF0
#define LC_FLOAT_TOLERANCE (1.0e-25)
#define LC_WDT_TABLENAME "LC_WDT"
#define LC_ADT_TABLENAME "LC_ADT"
#define LC_WRT_TABLENAME "LC_WRT"
#define LC_ART_TABLENAME "LC_ART"

/* ---  From default_lc_tbldefs --- */ 
#define LC_CDS_SAVED     0xF0F0 // CDS saved on exit 
#define LC_CDS_NOT_SAVED 0x0F0F // CDS not saved on exit
#define LC_BITMASK_NONE 0xFFFFFFFF // Use for no masking

/* Many parameters from default_lc_msgdefs.h are now defined in lc.xml, thus are part of lc_eds_typedefs.h  
   The naming convention is different, so these parameters are redifined here to 
   try limit changes in the rest of the source code (as a start, this can be changed later on)
*/
#define LC_STATE_ACTIVE   LC_State_ACTIVE
#define LC_STATE_PASSIVE  LC_State_PASSIVE
#define LC_STATE_DISABLED LC_State_DISABLED
#define LC_STATE_FROM_CDS LC_State_FROM_CDS

#define LC_STATE_POWER_ON_RESET LC_State_DISABLED 
#define LC_STATE_WHEN_CDS_RESTORED LC_State_FROM_CDS

#define LC_APSTATE_NOT_USED LC_ApState_NOT_USED
#define LC_APSTATE_ACTIVE   LC_ApState_ACTIVE
#define LC_APSTATE_PASSIVE  LC_ApState_PASSIVE
#define LC_APSTATE_DISABLED LC_ApState_DISABLED
#define LC_APSTATE_PERMOFF  LC_ApState_PERMOFF

#define LC_HKWR_FALSE LC_WpRes_FALSE 
#define LC_HKWR_TRUE  LC_WpRes_TRUE 
#define LC_HKWR_ERROR LC_WpRes_ERROR 
#define LC_HKWR_STALE LC_WpRes_FALSE 

#define LC_HKAR_PASS  LC_ApRes_PASS 
#define LC_HKAR_FAIL  LC_ApRes_FAIL
#define LC_HKAR_ERROR LC_ApRes_ERROR
#define LC_HKAR_STALE LC_ApRes_STALE

#define LC_HKAR_STATE_NOT_USED LC_ApResState_NOT_USED 
#define LC_HKAR_STATE_ACTIVE   LC_ApResState_ACTIVE
#define LC_HKAR_STATE_PASSIVE  LC_ApResState_PASSIVE
#define LC_HKAR_STATE_DISABLED LC_ApResState_DISABLED

#ifndef LC_OMIT_DEPRECATED
#define LC_ACTION_NOT_USED LC_ApState_NOT_USED
#endif

/* Similarly for default_lc_tbldefs.h types, now defined in lc.xml, and thus part of lc_eds_typedefs.h  
   The naming convention is different, so these parameters are redifined here to 
   try limit changes in the rest of the source code (as a start, this can be changed later on)
*/
#define LC_DATA_WATCH_NOT_USED  LC_WdtDataType_NOT_USED   
#define LC_DATA_WATCH_BYTE      LC_WdtDataType_BYTE       
#define LC_DATA_WATCH_UBYTE     LC_WdtDataType_UBYTE     
#define LC_DATA_WATCH_WORD_BE   LC_WdtDataType_WORD_BE   
#define LC_DATA_WATCH_WORD_LE   LC_WdtDataType_WORD_LE   
#define LC_DATA_WATCH_UWORD_BE  LC_WdtDataType_UWORD_BE  
#define LC_DATA_WATCH_UWORD_LE  LC_WdtDataType_UWORD_LE  
#define LC_DATA_WATCH_DWORD_BE  LC_WdtDataType_DWORD_BE  
#define LC_DATA_WATCH_DWORD_LE  LC_WdtDataType_DWORD_LE  
#define LC_DATA_WATCH_UDWORD_BE LC_WdtDataType_UDWORD_BE 
#define LC_DATA_WATCH_UDWORD_LE LC_WdtDataType_UDWORD_LE 
#define LC_DATA_WATCH_FLOAT_BE  LC_WdtDataType_FLOAT_BE 
#define LC_DATA_WATCH_FLOAT_LE  LC_WdtDataType_FLOAT_LE 

#define LC_OPER_NONE   LC_WdtOperatorID_NONE   
#define LC_OPER_LT     LC_WdtOperatorID_LT     
#define LC_OPER_LE     LC_WdtOperatorID_LE     
#define LC_OPER_NE     LC_WdtOperatorID_NE     
#define LC_OPER_EQ     LC_WdtOperatorID_EQ     
#define LC_OPER_GE     LC_WdtOperatorID_GE     
#define LC_OPER_GT     LC_WdtOperatorID_GT     
#define LC_OPER_CUSTOM LC_WdtOperatorID_CUSTOM 

#define LC_RPN_AND   LC_AdtRPNOperator_AND   
#define LC_RPN_OR    LC_AdtRPNOperator_OR    
#define LC_RPN_XOR   LC_AdtRPNOperator_XOR   
#define LC_RPN_NOT   LC_AdtRPNOperator_NOT   
#define LC_RPN_EQUAL LC_AdtRPNOperator_EQUAL 

#define LC_WATCH_STALE LC_WrtWatchResult_STALE  
#define LC_WATCH_FALSE LC_WrtWatchResult_FALSE  
#define LC_WATCH_TRUE  LC_WrtWatchResult_TRUE   
#define LC_WATCH_ERROR LC_WrtWatchResult_ERROR  

#define LC_ACTION_STALE  LC_ArtActionResult_STALE
#define LC_ACTION_PASS   LC_ArtActionResult_PASS 
#define LC_ACTION_FAIL   LC_ArtActionResult_FAIL 
#define LC_ACTION_ERROR  LC_ArtActionResult_ERROR

#define LC_WDTVAL_ERR_NONE     LC_WdtValErr_NONE    
#define LC_WDTVAL_ERR_DATATYPE LC_WdtValErr_DATATYPE
#define LC_WDTVAL_ERR_OPER     LC_WdtValErr_OPER    
#define LC_WDTVAL_ERR_MID      LC_WdtValErr_MID     
#define LC_WDTVAL_ERR_FPNAN    LC_WdtValErr_FPNAN   
#define LC_WDTVAL_ERR_FPINF    LC_WdtValErr_FPINF   

#define LC_ADTVAL_ERR_NONE     LC_AdtValErr_NONE     
#define LC_ADTVAL_ERR_DEFSTATE LC_AdtValErr_DEFSTATE 
#define LC_ADTVAL_ERR_RTSID    LC_AdtValErr_RTSID    
#define LC_ADTVAL_ERR_FAILCNT  LC_AdtValErr_FAILCNT  
#define LC_ADTVAL_ERR_EVTTYPE  LC_AdtValErr_EVTTYPE  
#define LC_ADTVAL_ERR_RPN      LC_AdtValErr_RPN      

#ifndef LC_OMIT_DEPRECATED

#define LC_NO_OPER       LC_OPER_NONE
#define LC_NO_BITMASK    LC_BITMASK_NONE
#define LC_ADTVAL_NO_ERR LC_ADTVAL_ERR_NONE
#define LC_WDTVAL_NO_ERR LC_WDTVAL_ERR_NONE

#define LC_DATA_NOT_USED  LC_DATA_WATCH_NOT_USED
#define LC_DATA_BYTE      LC_DATA_WATCH_BYTE
#define LC_DATA_UBYTE     LC_DATA_WATCH_UBYTE
#define LC_DATA_WORD_BE   LC_DATA_WATCH_WORD_BE
#define LC_DATA_WORD_LE   LC_DATA_WATCH_WORD_LE
#define LC_DATA_UWORD_BE  LC_DATA_WATCH_UWORD_BE
#define LC_DATA_UWORD_LE  LC_DATA_WATCH_UWORD_LE
#define LC_DATA_DWORD_BE  LC_DATA_WATCH_DWORD_BE
#define LC_DATA_DWORD_LE  LC_DATA_WATCH_DWORD_LE
#define LC_DATA_UDWORD_BE LC_DATA_WATCH_UDWORD_BE
#define LC_DATA_UDWORD_LE LC_DATA_WATCH_UDWORD_LE
#define LC_DATA_FLOAT_BE  LC_DATA_WATCH_FLOAT_BE
#define LC_DATA_FLOAT_LE  LC_DATA_WATCH_FLOAT_LE

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

#define CFG_APP_CFE_NAME  APP_CFE_NAME  // TODO: check if something equivalent is used anywhere
#define CFG_APP_PERF_ID   APP_PERF_ID  // Passed to LC_AppData.PerfId in code

#define CFG_APP_CMD_PIPE_NAME   APP_CMD_PIPE_NAME   // Retrieved in CFE_SB_CreatePipe call
#define CFG_APP_CMD_PIPE_DEPTH  APP_CMD_PIPE_DEPTH  // Retrieved in CFE_SB_CreatePipe call
 
#define CFG_LC_CMD_TOPICID       LC_CMD_TOPICID       // Passed to LC_AppData.CmdMid in code
#define CFG_LC_SEND_HK_TOPICID   LC_SEND_HK_TOPICID   // Passed to LC_AppData.SendHkMid in code
#define CFG_LC_SAMPLE_AP_TOPICID LC_SAMPLE_AP_TOPICID // Passed to LC_AppData.SampleApMid in code
#define CFG_LC_HK_TLM_TOPICID    LC_HK_TLM_TOPICID    // Passed to LC_AppData.HkTlmMid in code

#define CFG_WDT_SEARCH_PERF_ID  LC_WDT_SEARCH_PERF_ID  // Passed to LC_AppData.WDTSearchPerfId in code

#define CFG_WDT_TBL_FILE  LC_WDT_FILENAME  // Retrieved in CFE_TBL_Load and CFE_EVS_SendEvent calls
#define CFG_ADT_TBL_FILE  LC_ADT_FILENAME  // Retrieved in CFE_TBL_Load and CFE_EVS_SendEvent calls

#define APP_CONFIG(XX) \
   XX(APP_CFE_NAME,char*) \
   XX(APP_PERF_ID,uint32) \
   XX(APP_CMD_PIPE_NAME,char*) \
   XX(APP_CMD_PIPE_DEPTH,uint32) \
   XX(LC_CMD_TOPICID,uint32) \
   XX(LC_SEND_HK_TOPICID,uint32) \
   XX(LC_SAMPLE_AP_TOPICID,uint32) \
   XX(LC_HK_TLM_TOPICID,uint32) \
   XX(LC_WDT_SEARCH_PERF_ID,uint32)\
   XX(LC_WDT_FILENAME,char*) \
   XX(LC_ADT_FILENAME,char*) 

DECLARE_ENUM(Config,APP_CONFIG)

/******************************************************************************
** Event Macros
**
** Define the  event message IDs used by each object/component used by the
** application
**
** Adapted from inc/lc_eventids.h
*/

#define LC_RESERVED_EID              (APP_C_FW_APP_BASE_EID + 0)  // Reserved EID
#define LC_TASK_EXIT_EID             (APP_C_FW_APP_BASE_EID + 1)  // CRITICAL: exits due to a fatal error condition
#define LC_INIT_INF_EID              (APP_C_FW_APP_BASE_EID + 2)  // INFORMATION: completed initialization
#define LC_CR_PIPE_ERR_EID           (APP_C_FW_APP_BASE_EID + 3)  // ERROR: unable to create its command pipe
#define LC_SUB_HK_REQ_ERR_EID        (APP_C_FW_APP_BASE_EID + 4)  // ERROR: unable to subscribe to its Housekeeping Request message
#define LC_SUB_GND_CMD_ERR_EID       (APP_C_FW_APP_BASE_EID + 5)  // ERROR: unable to subscribe to its ground commands
#define LC_SUB_SAMPLE_CMD_ERR_EID    (APP_C_FW_APP_BASE_EID + 6)  // ERROR: unable to subscribe to its actionpoint sample command
#define LC_WDT_REGISTER_ERR_EID      (APP_C_FW_APP_BASE_EID + 7)  // ERROR: watchpoint definition table (WDT) could not be registered
#define LC_WDT_REREGISTER_ERR_EID    (APP_C_FW_APP_BASE_EID + 8)  // ERROR: watchpoint definition table (WDT) could not be registered non-critical
#define LC_ADT_REGISTER_ERR_EID      (APP_C_FW_APP_BASE_EID + 9)  // ERROR: actionpoint definition table (ADT) could not be registered
#define LC_WRT_REGISTER_ERR_EID      (APP_C_FW_APP_BASE_EID + 10) // ERROR: watchpoint results table (WRT) could not be registered
#define LC_ART_REGISTER_ERR_EID      (APP_C_FW_APP_BASE_EID + 11) // ERROR: actionpoint results table (ART) could not be registered
#define LC_WRT_CDS_REGISTER_ERR_EID  (APP_C_FW_APP_BASE_EID + 12) // ERROR: the CDS area for the watchpoint results table (WRT) data could not be registered
#define LC_ART_CDS_REGISTER_ERR_EID  (APP_C_FW_APP_BASE_EID + 13) // ERROR: the CDS area for the actionpont results table (ART) data could not be registered
#define LC_APP_CDS_REGISTER_ERR_EID  (APP_C_FW_APP_BASE_EID + 14) // ERROR: the CDS area for the LC application data could not be registered
#define LC_WDT_LOAD_ERR_EID          (APP_C_FW_APP_BASE_EID + 15) // ERROR: error is encountered loading the watchpoint definition table (WDT) from the default file image
#define LC_ADT_LOAD_ERR_EID          (APP_C_FW_APP_BASE_EID + 16) // ERROR: error is encountered loading the actionpoint definition table (ADT) from the default file image
#define LC_WRT_GETADDR_ERR_EID       (APP_C_FW_APP_BASE_EID + 17) // ERROR: the address can't be obtained from table services for the watchpoint results table (WRT)
#define LC_ART_GETADDR_ERR_EID       (APP_C_FW_APP_BASE_EID + 18) // ERROR: the address can't be obtained from table services for the actionpoint results table (ART)
#define LC_WDT_GETADDR_ERR_EID       (APP_C_FW_APP_BASE_EID + 19) // ERROR: the address can't be obtained from table services for the watchpoint definition table (WDT)
#define LC_ADT_GETADDR_ERR_EID       (APP_C_FW_APP_BASE_EID + 20) // ERROR: the address can't be obtained from table services for the actionpoint definition table (ADT)
#define LC_CDS_RESTORED_INF_EID      (APP_C_FW_APP_BASE_EID + 21) // INFORMATION: a processor reset when the entire LC execution state has been successfully restored from the Critical Data Store (CDS)
#define LC_CDS_UPDATED_INF_EID       (APP_C_FW_APP_BASE_EID + 22) // INFORMATION: LC startup initialization when the entire LC execution state has been set to default values successfully stored to the Critical Data Store (CDS)
#define LC_CDS_DISABLED_INF_EID      (APP_C_FW_APP_BASE_EID + 23) // INFORMATION: LC startup initialization when the entire LC execution state has been set to default values successfully stored to the Critical Data Store (CDS)
#define LC_CC_ERR_EID                (APP_C_FW_APP_BASE_EID + 24) // ERROR: a software bus message is received  with an invalid command code
#define LC_APSAMPLE_APNUM_ERR_EID    (APP_C_FW_APP_BASE_EID + 25) // ERROR: #LC_SAMPLE_AP_MID message has been received with an invalid actionpoint start or end number specified
#define LC_NOOP_INF_EID              (APP_C_FW_APP_BASE_EID + 26) // INFORMATION: a NOOP command has been received
#define LC_RESET_INF_EID             (APP_C_FW_APP_BASE_EID + 27) // INFORMATION: a reset counters command has been received
#define LC_LCSTATE_INF_EID           (APP_C_FW_APP_BASE_EID + 28) // INFORMATION: #LC_SET_LC_STATE_CC command has been successfully executed
#define LC_LCSTATE_ERR_EID           (APP_C_FW_APP_BASE_EID + 29) // ERROR: #LC_SET_LC_STATE_CC command has been received with an invalid state argument specified
#define LC_APSTATE_NEW_ERR_EID       (APP_C_FW_APP_BASE_EID + 30) // ERROR: #LC_SET_AP_STATE_CC command has been received with an invalid state argument specified
#define LC_APSTATE_CURR_ERR_EID      (APP_C_FW_APP_BASE_EID + 31) // ERROR: #LC_SET_AP_STATE_CC commandhas been received and the current actionpoint state is either #LC_APSTATE_NOT_USED or #LC_APSTATE_PERMOFF
#define LC_APSTATE_APNUM_ERR_EID     (APP_C_FW_APP_BASE_EID + 32) // ERROR: #LC_SET_AP_STATE_CC command has been received with an invalid actionpoint number specified
#define LC_APSTATE_INF_EID           (APP_C_FW_APP_BASE_EID + 33) // INFORMATION: #LC_SET_AP_STATE_CC command has been successfully executed
#define LC_APOFF_APNUM_ERR_EID       (APP_C_FW_APP_BASE_EID + 34) // ERROR: #LC_SET_AP_PERM_OFF_CC command has been received with an invalid actionpoint number specified
#define LC_APOFF_CURR_ERR_EID        (APP_C_FW_APP_BASE_EID + 35) // ERROR: #LC_SET_AP_PERM_OFF_CC command has been received and the current actionpoint state is not #LC_APSTATE_DISABLED
#define LC_APOFF_INF_EID             (APP_C_FW_APP_BASE_EID + 36) // INFORMATION: #LC_SET_AP_PERM_OFF_CC command has been successfully executed
#define LC_APSTATS_APNUM_ERR_EID     (APP_C_FW_APP_BASE_EID + 37) // ERROR: #LC_RESET_AP_STATS_CC command has been received with an invalid actionpoint number specified
#define LC_APSTATS_INF_EID           (APP_C_FW_APP_BASE_EID + 38) // INFORMATION: #LC_RESET_AP_STATS_CC command has been successfully executed
#define LC_WPSTATS_WPNUM_ERR_EID     (APP_C_FW_APP_BASE_EID + 39) // ERROR: #LC_RESET_WP_STATS_CC command has been received with an invalid watchpoint number specified
#define LC_WPSTATS_INF_EID           (APP_C_FW_APP_BASE_EID + 40) // INFORMATION: #LC_RESET_WP_STATS_CC command has been successfully executed
#define LC_HKREQ_LEN_ERR_EID         (APP_C_FW_APP_BASE_EID + 41) // ERROR: a housekeeping request is received with a message length that doesn't match the expected value
#define LC_APSAMPLE_LEN_ERR_EID      (APP_C_FW_APP_BASE_EID + 42) // ERROR: an actionpoint sample request is received with a message length that doesn't match the expected value
#define LC_CMD_LEN_ERR_EID           (APP_C_FW_APP_BASE_EID + 43) // ERROR: a ground command message is received with a message length that doesn't match the expected value
#define LC_UNSUB_WP_ERR_EID          (APP_C_FW_APP_BASE_EID + 44) // ERROR: an error is encountered unsubscribing to a watchpoint message ID
#define LC_SUB_WP_ERR_EID            (APP_C_FW_APP_BASE_EID + 45) // ERROR: an error is encountered when subscribing to a watchpoint message iD
#define LC_WRT_NO_SAVE_ERR_EID       (APP_C_FW_APP_BASE_EID + 46) // ERROR: the watchpoint results table (WRT) data could not be saved to the CDS on application exit
#define LC_ART_NO_SAVE_ERR_EID       (APP_C_FW_APP_BASE_EID + 47) // ERROR: the actionpoint results table (ART) data could not be saved to the CDS on application exit
#define LC_APP_NO_SAVE_START_ERR_EID (APP_C_FW_APP_BASE_EID + 48) // ERROR: the LC application data could not be saved to the CDS on application startup
#define LC_MID_INF_EID               (APP_C_FW_APP_BASE_EID + 49) // INFORMATION: a software bus message has been received that isn't a recognized LC message and has no defined watchpoints referencing it's message ID
#define LC_WP_DATATYPE_ERR_EID       (APP_C_FW_APP_BASE_EID + 50) // ERROR: an undefined watchpoint data type identifier is detected
#define LC_WP_OPERID_ERR_EID         (APP_C_FW_APP_BASE_EID + 51) // ERROR: an undefined watchpoint operator identifier is detected
#define LC_WP_NAN_ERR_EID            (APP_C_FW_APP_BASE_EID + 52) // ERROR: a watchpoint is defined as a float type, but the extracted value would equate to a floating point NAN (not-a-number) value
#define LC_WP_OFFSET_ERR_EID         (APP_C_FW_APP_BASE_EID + 53) // ERROR: a watchpoint offset value extends past the end of the message as reported by the #CFE_MSG_GetSize function
#define LC_WDTVAL_FPERR_EID          (APP_C_FW_APP_BASE_EID + 54) // ERROR: table validation fails for a watchpoint definition table (WDT) load and the error is a failed floating point check
#define LC_WDTVAL_ERR_EID            (APP_C_FW_APP_BASE_EID + 55) // ERROR: a table validation fails for a watchpoint definition table (WDT) load and the error is NOT a failed floating point check
#define LC_WDTVAL_INF_EID            (APP_C_FW_APP_BASE_EID + 56) // INFORMATION: a table validation has been completed for a watchpoint definition table (WDT) load
#define LC_APSAMPLE_CURR_ERR_EID     (APP_C_FW_APP_BASE_EID + 57) // ERROR: #LC_SAMPLE_AP_MID message has been received and the current state for the specified actionpoint state is either #LC_APSTATE_NOT_USED or #LC_APSTATE_PERMOFF
#define LC_AP_PASSTOFAIL_INF_EID     (APP_C_FW_APP_BASE_EID + 58) // INFORMATION: an actionpoint evaluation transitions from #LC_ACTION_PASS to #LC_ACTION_FAIL
#define LC_PASSIVE_FAIL_DBG_EID      (APP_C_FW_APP_BASE_EID + 59) // DEBUG: an actionpoint fails evaluation while  the LC task operating state is #LC_STATE_PASSIVE
#define LC_AP_PASSIVE_FAIL_INF_EID   (APP_C_FW_APP_BASE_EID + 60) // INFORMATION: an actionpoint fails evaluation while the actionpoint state is #LC_APSTATE_PASSIVE
#define LC_AP_FAILTOPASS_INF_EID     (APP_C_FW_APP_BASE_EID + 61) // INFORMATION: an actionpoint evaluation transitions from #LC_ACTION_FAIL to #LC_ACTION_PASS
#define LC_ACTION_ERROR_ERR_EID      (APP_C_FW_APP_BASE_EID + 62) // ERROR: an actionpoint evaluation results in #LC_ACTION_ERROR
#define LC_INVALID_RPN_ERR_EID       (APP_C_FW_APP_BASE_EID + 63) // ERROR: an illegal Reverse Polish Notation (RPN) expression is detected during an actionpoint evaluation
#define LC_ADTVAL_RPNERR_EID         (APP_C_FW_APP_BASE_EID + 64) // ERROR: a table validation fails for an actionpoint definition table (ADT) load and the error is a failed RPN equation check
#define LC_ADTVAL_ERR_EID            (APP_C_FW_APP_BASE_EID + 65) // ERROR: a table validation fails for an actioinpoint definition table (ADT) load and the error is NOT a failed RPN equation check
#define LC_ADTVAL_INF_EID            (APP_C_FW_APP_BASE_EID + 66) // INFORMATION: a table validation has been completed for an actionpoint definition table (ADT) load 
#define LC_CFCALL_ERR_EID            (APP_C_FW_APP_BASE_EID + 67) // ERROR: the mission specific custom function #LC_CustomFunction is called with an unexpected watchpoint ID
#define LC_WDT_REGISTER_CRIT_ERR_EID (APP_C_FW_APP_BASE_EID + 68) // ERROR: the watchpoint definition table (WDT) could not be registered as a critical table
#define LC_ADT_REGISTER_CRIT_ERR_EID (APP_C_FW_APP_BASE_EID + 69) // ERROR: the actionpoint definition table (ADT) could not be registered as a critical table
/**
 *  The actionpoint base event ID is designed to avoid conflicts
 *  between the event ID's defined above for use by the LC application
 *  and the user defined event ID's in the actionpoint table.
 *
 *  These events are generated when the evaluation of an actionpoint
 *  results in sending a command to the stored command (SC) processor
 *  to start a real time command sequence (RTS). The event text is
 *  user defined and specific to the particular actionpoint.
 *
 *  Note that user defined event ID's can be easily recognized if the
 *  base number is easily recognizable. For example, using the value
 *  1000 for the base event ID and using the actionpoint table index as
 *  the offset portion creates an obvious correlation.  Thus, if an LC
 *  event ID is 1025 then it is immediately apparent that the event is
 *  the user defined event for actionpoint table index 25.
 */
#define LC_BASE_AP_EID (APP_C_FW_APP_BASE_EID + 1000)

#endif /* _app_cfg_ */
