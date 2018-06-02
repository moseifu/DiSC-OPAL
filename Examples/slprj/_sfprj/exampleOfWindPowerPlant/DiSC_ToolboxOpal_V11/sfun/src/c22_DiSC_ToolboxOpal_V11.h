#ifndef __c22_DiSC_ToolboxOpal_V11_h__
#define __c22_DiSC_ToolboxOpal_V11_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sXgiQ0K2zU5uHJ7gdbD52xC
#define struct_sXgiQ0K2zU5uHJ7gdbD52xC

struct sXgiQ0K2zU5uHJ7gdbD52xC
{
  real_T vBase;
  real_T pRated;
  real_T sMax;
  real_T wMin;
  real_T wMax;
  real_T wRated;
  real_T rfTau;
  real_T PF;
  real_T Ts;
};

#endif                                 /*struct_sXgiQ0K2zU5uHJ7gdbD52xC*/

#ifndef typedef_c22_sXgiQ0K2zU5uHJ7gdbD52xC
#define typedef_c22_sXgiQ0K2zU5uHJ7gdbD52xC

typedef struct sXgiQ0K2zU5uHJ7gdbD52xC c22_sXgiQ0K2zU5uHJ7gdbD52xC;

#endif                                 /*typedef_c22_sXgiQ0K2zU5uHJ7gdbD52xC*/

#ifndef struct_sH1Kify8ZxEOY46vFTteWED
#define struct_sH1Kify8ZxEOY46vFTteWED

struct sH1Kify8ZxEOY46vFTteWED
{
  real_T p_c;
  real_T q_c;
  real_T pAva_c;
  real_T t_c;
  real_T pOld;
  real_T avgFilterTime;
  real_T avgFilterBuf[10];
  real_T Qmode;
  real_T kWT;
};

#endif                                 /*struct_sH1Kify8ZxEOY46vFTteWED*/

#ifndef typedef_c22_sH1Kify8ZxEOY46vFTteWED
#define typedef_c22_sH1Kify8ZxEOY46vFTteWED

typedef struct sH1Kify8ZxEOY46vFTteWED c22_sH1Kify8ZxEOY46vFTteWED;

#endif                                 /*typedef_c22_sH1Kify8ZxEOY46vFTteWED*/

#ifndef typedef_SFc22_DiSC_ToolboxOpal_V11InstanceStruct
#define typedef_SFc22_DiSC_ToolboxOpal_V11InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_DiSC_ToolboxOpal_V11;
  c22_sH1Kify8ZxEOY46vFTteWED c22_var;
  boolean_T c22_var_not_empty;
  real_T *c22_p;
  real_T *c22_wind;
  real_T *c22_vMeas;
  real_T *c22_dP;
  real_T *c22_dPlim;
  real_T *c22_qRef;
  real_T *c22_qMode;
  real_T *c22_vRef;
  real_T *c22_time;
  real_T *c22_q;
  real_T *c22_pAva;
} SFc22_DiSC_ToolboxOpal_V11InstanceStruct;

#endif                                 /*typedef_SFc22_DiSC_ToolboxOpal_V11InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c22_DiSC_ToolboxOpal_V11_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_DiSC_ToolboxOpal_V11_get_check_sum(mxArray *plhs[]);
extern void c22_DiSC_ToolboxOpal_V11_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
