#ifndef __c21_DiSC_ToolboxOpal_V11_h__
#define __c21_DiSC_ToolboxOpal_V11_h__

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

#ifndef typedef_c21_sXgiQ0K2zU5uHJ7gdbD52xC
#define typedef_c21_sXgiQ0K2zU5uHJ7gdbD52xC

typedef struct sXgiQ0K2zU5uHJ7gdbD52xC c21_sXgiQ0K2zU5uHJ7gdbD52xC;

#endif                                 /*typedef_c21_sXgiQ0K2zU5uHJ7gdbD52xC*/

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

#ifndef typedef_c21_sH1Kify8ZxEOY46vFTteWED
#define typedef_c21_sH1Kify8ZxEOY46vFTteWED

typedef struct sH1Kify8ZxEOY46vFTteWED c21_sH1Kify8ZxEOY46vFTteWED;

#endif                                 /*typedef_c21_sH1Kify8ZxEOY46vFTteWED*/

#ifndef typedef_SFc21_DiSC_ToolboxOpal_V11InstanceStruct
#define typedef_SFc21_DiSC_ToolboxOpal_V11InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_isStable;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_DiSC_ToolboxOpal_V11;
  c21_sH1Kify8ZxEOY46vFTteWED c21_var;
  boolean_T c21_var_not_empty;
  real_T *c21_p;
  real_T *c21_wind;
  real_T *c21_vMeas;
  real_T *c21_dP;
  real_T *c21_dPlim;
  real_T *c21_qRef;
  real_T *c21_qMode;
  real_T *c21_vRef;
  real_T *c21_time;
  real_T *c21_q;
  real_T *c21_pAva;
} SFc21_DiSC_ToolboxOpal_V11InstanceStruct;

#endif                                 /*typedef_SFc21_DiSC_ToolboxOpal_V11InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c21_DiSC_ToolboxOpal_V11_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_DiSC_ToolboxOpal_V11_get_check_sum(mxArray *plhs[]);
extern void c21_DiSC_ToolboxOpal_V11_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
