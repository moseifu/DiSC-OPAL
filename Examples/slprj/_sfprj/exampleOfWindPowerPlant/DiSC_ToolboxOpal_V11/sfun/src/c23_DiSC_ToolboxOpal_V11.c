/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DiSC_ToolboxOpal_V11_sfun.h"
#include "c23_DiSC_ToolboxOpal_V11.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DiSC_ToolboxOpal_V11_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c23_debug_family_names[16] = { "param", "varNew", "nargin",
  "nargout", "wind", "vMeas", "dP", "dPlim", "qRef", "qMode", "vRef", "time",
  "p", "q", "pAva", "var" };

static const char * c23_b_debug_family_names[6] = { "nargin", "nargout", "var",
  "w", "wOut", "varNew" };

static const char * c23_c_debug_family_names[11] = { "pW", "nargin", "nargout",
  "param", "var", "w", "dP", "dPlim", "p", "pAva", "varNew" };

static const char * c23_d_debug_family_names[9] = { "vMax", "vMin", "k",
  "nargin", "nargout", "param", "v", "vRef", "qRef" };

static const char * c23_e_debug_family_names[7] = { "qFun", "nargin", "nargout",
  "param", "v", "vRef", "qRef" };

static const char * c23_f_debug_family_names[10] = { "qMax", "nargin", "nargout",
  "param", "var", "p", "v", "qRef", "vRef", "q" };

static const char * c23_g_debug_family_names[7] = { "nargin", "nargout", "param",
  "var", "u", "p", "varNew" };

static const char * c23_h_debug_family_names[14] = { "nargin", "nargout", "obj",
  "var", "wt", "v", "dP", "dPlim", "qRef", "vRef", "p", "q", "pAva", "varNew" };

/* Function Declarations */
static void initialize_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void initialize_params_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void enable_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void disable_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void set_sim_state_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance, const mxArray
   *c23_st);
static void finalize_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void sf_gateway_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void mdl_start_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void c23_chartstep_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void initSimStructsc23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance);
static void c23_sampleWT(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
  c23_sXgiQ0K2zU5uHJ7gdbD52xC *c23_obj, c23_sH1Kify8ZxEOY46vFTteWED *c23_b_var,
  real_T c23_wt, real_T c23_v, real_T c23_b_dP, real_T c23_b_dPlim, real_T
  c23_b_qRef, real_T c23_b_vRef, real_T *c23_b_p, real_T *c23_b_q, real_T
  *c23_b_pAva, c23_sH1Kify8ZxEOY46vFTteWED *c23_varNew);
static void c23_pCtrlWT(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
  c23_sXgiQ0K2zU5uHJ7gdbD52xC *c23_param, c23_sH1Kify8ZxEOY46vFTteWED *c23_b_var,
  real_T c23_w, real_T c23_b_dP, real_T c23_b_dPlim, real_T *c23_b_p, real_T
  *c23_b_pAva, c23_sH1Kify8ZxEOY46vFTteWED *c23_varNew);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_b_var, const char_T *c23_identifier,
  c23_sH1Kify8ZxEOY46vFTteWED *c23_y);
static void c23_b_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_sH1Kify8ZxEOY46vFTteWED *c23_y);
static real_T c23_c_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_d_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[10]);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_e_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_b_pAva, const char_T *c23_identifier);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_f_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_sH1Kify8ZxEOY46vFTteWED *c23_y);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_g_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_sXgiQ0K2zU5uHJ7gdbD52xC *c23_y);
static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_info_helper(const mxArray **c23_info);
static const mxArray *c23_emlrt_marshallOut(const char * c23_u);
static const mxArray *c23_b_emlrt_marshallOut(const uint32_T c23_u);
static void c23_b_info_helper(const mxArray **c23_info);
static real_T c23_mpower(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
  real_T c23_a);
static void c23_eml_scalar_eg(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance);
static real_T c23_sum(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
                      real_T c23_x[10]);
static void c23_eml_error(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance);
static real_T c23_b_mpower(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, real_T c23_a);
static void c23_b_eml_error(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance);
static const mxArray *c23_f_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_h_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_i_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_DiSC_ToolboxOpal_V11, const
  char_T *c23_identifier);
static uint8_T c23_j_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_var_not_empty = false;
  chartInstance->c23_is_active_c23_DiSC_ToolboxOpal_V11 = 0U;
}

static void initialize_params_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c23_update_debugger_state_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_b_hoistedGlobal;
  real_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  real_T c23_c_hoistedGlobal;
  real_T c23_c_u;
  const mxArray *c23_d_y = NULL;
  const mxArray *c23_e_y = NULL;
  real_T c23_d_u;
  const mxArray *c23_f_y = NULL;
  real_T c23_e_u;
  const mxArray *c23_g_y = NULL;
  real_T c23_f_u;
  const mxArray *c23_h_y = NULL;
  real_T c23_g_u;
  const mxArray *c23_i_y = NULL;
  real_T c23_h_u;
  const mxArray *c23_j_y = NULL;
  real_T c23_i_u;
  const mxArray *c23_k_y = NULL;
  int32_T c23_i0;
  real_T c23_j_u[10];
  const mxArray *c23_l_y = NULL;
  real_T c23_k_u;
  const mxArray *c23_m_y = NULL;
  real_T c23_l_u;
  const mxArray *c23_n_y = NULL;
  uint8_T c23_d_hoistedGlobal;
  uint8_T c23_m_u;
  const mxArray *c23_o_y = NULL;
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(5, 1), false);
  c23_hoistedGlobal = *chartInstance->c23_p;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_hoistedGlobal = *chartInstance->c23_pAva;
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  c23_c_hoistedGlobal = *chartInstance->c23_q;
  c23_c_u = c23_c_hoistedGlobal;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 2, c23_d_y);
  c23_e_y = NULL;
  if (!chartInstance->c23_var_not_empty) {
    sf_mex_assign(&c23_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_e_y, sf_mex_createstruct("structure", 2, 1, 1), false);
    c23_d_u = chartInstance->c23_var.p_c;
    c23_f_y = NULL;
    sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_d_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_f_y, "p_c", "p_c", 0);
    c23_e_u = chartInstance->c23_var.q_c;
    c23_g_y = NULL;
    sf_mex_assign(&c23_g_y, sf_mex_create("y", &c23_e_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_g_y, "q_c", "q_c", 0);
    c23_f_u = chartInstance->c23_var.pAva_c;
    c23_h_y = NULL;
    sf_mex_assign(&c23_h_y, sf_mex_create("y", &c23_f_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_h_y, "pAva_c", "pAva_c", 0);
    c23_g_u = chartInstance->c23_var.t_c;
    c23_i_y = NULL;
    sf_mex_assign(&c23_i_y, sf_mex_create("y", &c23_g_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_i_y, "t_c", "t_c", 0);
    c23_h_u = chartInstance->c23_var.pOld;
    c23_j_y = NULL;
    sf_mex_assign(&c23_j_y, sf_mex_create("y", &c23_h_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_j_y, "pOld", "pOld", 0);
    c23_i_u = chartInstance->c23_var.avgFilterTime;
    c23_k_y = NULL;
    sf_mex_assign(&c23_k_y, sf_mex_create("y", &c23_i_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_k_y, "avgFilterTime", "avgFilterTime", 0);
    for (c23_i0 = 0; c23_i0 < 10; c23_i0++) {
      c23_j_u[c23_i0] = chartInstance->c23_var.avgFilterBuf[c23_i0];
    }

    c23_l_y = NULL;
    sf_mex_assign(&c23_l_y, sf_mex_create("y", c23_j_u, 0, 0U, 1U, 0U, 1, 10),
                  false);
    sf_mex_addfield(c23_e_y, c23_l_y, "avgFilterBuf", "avgFilterBuf", 0);
    c23_k_u = chartInstance->c23_var.Qmode;
    c23_m_y = NULL;
    sf_mex_assign(&c23_m_y, sf_mex_create("y", &c23_k_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_m_y, "Qmode", "Qmode", 0);
    c23_l_u = chartInstance->c23_var.kWT;
    c23_n_y = NULL;
    sf_mex_assign(&c23_n_y, sf_mex_create("y", &c23_l_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_e_y, c23_n_y, "kWT", "kWT", 0);
  }

  sf_mex_setcell(c23_y, 3, c23_e_y);
  c23_d_hoistedGlobal = chartInstance->c23_is_active_c23_DiSC_ToolboxOpal_V11;
  c23_m_u = c23_d_hoistedGlobal;
  c23_o_y = NULL;
  sf_mex_assign(&c23_o_y, sf_mex_create("y", &c23_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 4, c23_o_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance, const mxArray
   *c23_st)
{
  const mxArray *c23_u;
  c23_sH1Kify8ZxEOY46vFTteWED c23_r0;
  chartInstance->c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  *chartInstance->c23_p = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 0)), "p");
  *chartInstance->c23_pAva = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 1)), "pAva");
  *chartInstance->c23_q = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 2)), "q");
  c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 3)),
                       "var", &c23_r0);
  chartInstance->c23_var = c23_r0;
  chartInstance->c23_is_active_c23_DiSC_ToolboxOpal_V11 = c23_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 4)),
     "is_active_c23_DiSC_ToolboxOpal_V11");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_DiSC_ToolboxOpal_V11(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c23_sfEvent);
  chartInstance->c23_sfEvent = CALL_EVENT;
  c23_chartstep_c23_DiSC_ToolboxOpal_V11(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DiSC_ToolboxOpal_V11MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_p, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_wind, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_vMeas, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_dP, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_dPlim, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_qRef, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_qMode, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_vRef, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_time, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_q, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_pAva, 10U);
}

static void mdl_start_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c23_chartstep_c23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  real_T c23_hoistedGlobal;
  real_T c23_b_hoistedGlobal;
  real_T c23_c_hoistedGlobal;
  real_T c23_d_hoistedGlobal;
  real_T c23_e_hoistedGlobal;
  real_T c23_f_hoistedGlobal;
  real_T c23_g_hoistedGlobal;
  real_T c23_h_hoistedGlobal;
  real_T c23_b_wind;
  real_T c23_b_vMeas;
  real_T c23_b_dP;
  real_T c23_b_dPlim;
  real_T c23_b_qRef;
  real_T c23_b_qMode;
  real_T c23_b_vRef;
  real_T c23_b_time;
  uint32_T c23_debug_family_var_map[16];
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_param;
  c23_sH1Kify8ZxEOY46vFTteWED c23_varNew;
  real_T c23_nargin = 8.0;
  real_T c23_nargout = 3.0;
  real_T c23_b_p;
  real_T c23_b_q;
  real_T c23_b_pAva;
  int32_T c23_i1;
  real_T c23_A;
  real_T c23_B;
  real_T c23_x;
  real_T c23_y;
  real_T c23_b_x;
  real_T c23_b_y;
  real_T c23_c_x;
  real_T c23_c_y;
  real_T c23_d_y;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_b_param;
  c23_sH1Kify8ZxEOY46vFTteWED c23_r1;
  c23_sH1Kify8ZxEOY46vFTteWED c23_b_varNew;
  real_T c23_c_pAva;
  real_T c23_c_q;
  real_T c23_c_p;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_c_param;
  c23_sH1Kify8ZxEOY46vFTteWED c23_r2;
  real_T c23_d_pAva;
  real_T c23_d_q;
  real_T c23_d_p;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c23_sfEvent);
  c23_hoistedGlobal = *chartInstance->c23_wind;
  c23_b_hoistedGlobal = *chartInstance->c23_vMeas;
  c23_c_hoistedGlobal = *chartInstance->c23_dP;
  c23_d_hoistedGlobal = *chartInstance->c23_dPlim;
  c23_e_hoistedGlobal = *chartInstance->c23_qRef;
  c23_f_hoistedGlobal = *chartInstance->c23_qMode;
  c23_g_hoistedGlobal = *chartInstance->c23_vRef;
  c23_h_hoistedGlobal = *chartInstance->c23_time;
  c23_b_wind = c23_hoistedGlobal;
  c23_b_vMeas = c23_b_hoistedGlobal;
  c23_b_dP = c23_c_hoistedGlobal;
  c23_b_dPlim = c23_d_hoistedGlobal;
  c23_b_qRef = c23_e_hoistedGlobal;
  c23_b_qMode = c23_f_hoistedGlobal;
  c23_b_vRef = c23_g_hoistedGlobal;
  c23_b_time = c23_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_param, 0U, c23_d_sf_marshallOut,
    c23_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_varNew, 1U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 2U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 3U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_wind, 4U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_vMeas, 5U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_dP, 6U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_dPlim, 7U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_qRef, 8U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_qMode, 9U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_vRef, 10U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_b_time, 11U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_p, 12U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_q, 13U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_pAva, 14U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c23_var, 15U,
    c23_sf_marshallOut, c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 22);
  c23_param.vBase = 20000.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 23);
  c23_param.pRated = 100000.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 24);
  c23_param.sMax = 100000.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 25);
  c23_param.wMin = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 26);
  c23_param.wMax = 25.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 27);
  c23_param.wRated = 12.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 28);
  c23_param.rfTau = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 29);
  c23_param.PF = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 30);
  c23_param.Ts = 60.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 33);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 34);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c23_var_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 35);
    chartInstance->c23_var.p_c = 0.0;
    chartInstance->c23_var_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 36);
    chartInstance->c23_var.q_c = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 37);
    chartInstance->c23_var.pAva_c = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 38);
    chartInstance->c23_var.t_c = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 39);
    chartInstance->c23_var.pOld = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 41);
    chartInstance->c23_var.avgFilterTime = 600.0;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 42);
    for (c23_i1 = 0; c23_i1 < 10; c23_i1++) {
      chartInstance->c23_var.avgFilterBuf[c23_i1] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 43);
    chartInstance->c23_var.Qmode = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 44);
    chartInstance->c23_var.kWT = 1736.1111111111111;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 48);
  c23_A = c23_param.pRated;
  c23_B = c23_mpower(chartInstance, c23_param.wRated);
  c23_x = c23_A;
  c23_y = c23_B;
  c23_b_x = c23_x;
  c23_b_y = c23_y;
  c23_c_x = c23_b_x;
  c23_c_y = c23_b_y;
  c23_d_y = c23_c_x / c23_c_y;
  chartInstance->c23_var.kWT = c23_d_y;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 52);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c23_param.Ts, 0.0, -1, 4U,
        c23_param.Ts > 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 53);
    if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1, c23_b_time,
          chartInstance->c23_var.t_c + c23_param.Ts, -1, 4U, c23_b_time >
          chartInstance->c23_var.t_c + c23_param.Ts))) {
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 54);
      c23_b_param = c23_param;
      c23_r1 = chartInstance->c23_var;
      c23_sampleWT(chartInstance, &c23_b_param, &c23_r1, c23_b_wind, c23_b_vMeas,
                   c23_b_dP, c23_b_dPlim, c23_b_qRef, c23_b_vRef, &c23_c_p,
                   &c23_c_q, &c23_c_pAva, &c23_b_varNew);
      c23_b_p = c23_c_p;
      c23_b_q = c23_c_q;
      c23_b_pAva = c23_c_pAva;
      c23_varNew = c23_b_varNew;
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 55);
      c23_varNew.p_c = c23_b_p;
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 56);
      c23_varNew.q_c = c23_b_q;
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 57);
      c23_varNew.pAva_c = c23_b_pAva;
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 58);
      c23_varNew.t_c = c23_b_time;
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 59);
      c23_varNew.Qmode = c23_b_qMode;
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 60);
      chartInstance->c23_var = c23_varNew;
    }

    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 62);
    c23_b_p = chartInstance->c23_var.p_c;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 63);
    c23_b_q = chartInstance->c23_var.q_c;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 64);
    c23_b_pAva = chartInstance->c23_var.pAva_c;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 66);
    c23_c_param = c23_param;
    c23_r2 = chartInstance->c23_var;
    c23_sampleWT(chartInstance, &c23_c_param, &c23_r2, c23_b_wind, c23_b_vMeas,
                 c23_b_dP, c23_b_dPlim, c23_b_qRef, c23_b_vRef, &c23_d_p,
                 &c23_d_q, &c23_d_pAva, &c23_b_varNew);
    c23_b_p = c23_d_p;
    c23_b_q = c23_d_q;
    c23_b_pAva = c23_d_pAva;
    c23_varNew = c23_b_varNew;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 67);
    chartInstance->c23_var = c23_varNew;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -67);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c23_p = c23_b_p;
  *chartInstance->c23_q = c23_b_q;
  *chartInstance->c23_pAva = c23_b_pAva;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c23_sfEvent);
}

static void initSimStructsc23_DiSC_ToolboxOpal_V11
  (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c23_sampleWT(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
  c23_sXgiQ0K2zU5uHJ7gdbD52xC *c23_obj, c23_sH1Kify8ZxEOY46vFTteWED *c23_b_var,
  real_T c23_wt, real_T c23_v, real_T c23_b_dP, real_T c23_b_dPlim, real_T
  c23_b_qRef, real_T c23_b_vRef, real_T *c23_b_p, real_T *c23_b_q, real_T
  *c23_b_pAva, c23_sH1Kify8ZxEOY46vFTteWED *c23_varNew)
{
  uint32_T c23_debug_family_var_map[14];
  real_T c23_nargin = 8.0;
  real_T c23_nargout = 4.0;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_b_obj;
  c23_sH1Kify8ZxEOY46vFTteWED c23_c_var;
  c23_sH1Kify8ZxEOY46vFTteWED c23_b_varNew;
  real_T c23_c_pAva;
  real_T c23_c_p;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_param;
  c23_sH1Kify8ZxEOY46vFTteWED c23_d_var;
  real_T c23_d_p;
  real_T c23_b_v;
  real_T c23_c_qRef;
  real_T c23_c_vRef;
  uint32_T c23_b_debug_family_var_map[10];
  real_T c23_qMax;
  real_T c23_b_nargin = 6.0;
  real_T c23_b_nargout = 1.0;
  real_T c23_x;
  real_T c23_b_x;
  real_T c23_c_x;
  real_T c23_d_x;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_b_param;
  real_T c23_c_v;
  real_T c23_d_vRef;
  uint32_T c23_c_debug_family_var_map[7];
  real_T c23_c_nargin = 5.0;
  real_T c23_c_nargout = 1.0;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_c_param;
  real_T c23_d_v;
  real_T c23_e_vRef;
  uint32_T c23_d_debug_family_var_map[9];
  real_T c23_vMax;
  real_T c23_vMin;
  real_T c23_k;
  real_T c23_d_nargin = 4.0;
  real_T c23_d_nargout = 1.0;
  real_T c23_B;
  real_T c23_y;
  real_T c23_b_y;
  real_T c23_c_y;
  int32_T c23_i2;
  static char_T c23_varargin_1[40] = { 'I', 'n', 'v', 'a', 'l', 'i', 'd', ' ',
    'm', 'o', 'd', 'e', ' ', 'f', 'o', 'r', ' ', 'r', 'e', 'a', 'c', 't', 'i',
    'v', 'e', ' ', 'p', 'o', 'w', 'e', 'r', ' ', 'c', 'o', 'n', 't', 'r', 'o',
    'l', '.' };

  char_T c23_u[40];
  const mxArray *c23_d_y = NULL;
  real_T c23_e_x;
  real_T c23_f_x;
  real_T c23_g_x;
  real_T c23_h_x;
  real_T c23_d0;
  real_T c23_i_x;
  real_T c23_j_x;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_d_param;
  c23_sH1Kify8ZxEOY46vFTteWED c23_e_var;
  real_T c23_b_u;
  real_T c23_e_nargin = 3.0;
  real_T c23_e_nargout = 2.0;
  real_T c23_e_p;
  c23_sH1Kify8ZxEOY46vFTteWED c23_c_varNew;
  real_T c23_A;
  real_T c23_b_B;
  real_T c23_k_x;
  real_T c23_e_y;
  real_T c23_l_x;
  real_T c23_f_y;
  real_T c23_m_x;
  real_T c23_g_y;
  real_T c23_h_y;
  real_T c23_b_A;
  real_T c23_c_B;
  real_T c23_n_x;
  real_T c23_i_y;
  real_T c23_o_x;
  real_T c23_j_y;
  real_T c23_p_x;
  real_T c23_k_y;
  real_T c23_l_y;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c23_h_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_obj, 2U, c23_d_sf_marshallOut,
    c23_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_var, 3U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_wt, 4U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_v, 5U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_dP, 6U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_dPlim, 7U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_qRef, 8U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_vRef, 9U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_p, 10U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_q, 11U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_pAva, 12U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_varNew, 13U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 21);
  c23_b_obj = *c23_obj;
  c23_c_var = *c23_b_var;
  c23_pCtrlWT(chartInstance, &c23_b_obj, &c23_c_var, c23_wt, c23_b_dP,
              c23_b_dPlim, &c23_c_p, &c23_c_pAva, &c23_b_varNew);
  *c23_b_p = c23_c_p;
  *c23_b_pAva = c23_c_pAva;
  *c23_varNew = c23_b_varNew;
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 22);
  *c23_b_var = *c23_varNew;
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 25);
  c23_param = *c23_obj;
  c23_d_var = *c23_b_var;
  c23_d_p = *c23_b_p;
  c23_b_v = c23_v;
  c23_c_qRef = c23_b_qRef;
  c23_c_vRef = c23_b_vRef;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c23_f_debug_family_names,
    c23_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_qMax, 0U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargin, 1U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargout, 2U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_param, 3U, c23_d_sf_marshallOut,
    c23_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_var, 4U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_p, 5U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_v, 6U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_qRef, 7U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_vRef, 8U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_q, 9U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 4);
  if (CV_SCRIPT_IF(3, 0, CV_RELATIONAL_EVAL(14U, 3U, 0, c23_d_var.Qmode, 0.0, -1,
        0U, c23_d_var.Qmode == 0.0))) {
    _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 5);
    c23_x = c23_param.PF;
    c23_b_x = c23_x;
    guard1 = false;
    if (c23_b_x < -1.0) {
      guard1 = true;
    } else {
      if (1.0 < c23_b_x) {
        guard1 = true;
      }
    }

    if (guard1 == true) {
      c23_eml_error(chartInstance);
    }

    c23_b_x = muDoubleScalarAcos(c23_b_x);
    c23_c_x = c23_b_x;
    c23_d_x = c23_c_x;
    c23_d_x = muDoubleScalarTan(c23_d_x);
    c23_c_qRef = c23_d_p * c23_d_x;
  } else {
    _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 6);
    if (CV_SCRIPT_IF(3, 1, CV_RELATIONAL_EVAL(14U, 3U, 1, c23_d_var.Qmode, 1.0,
          -1, 0U, c23_d_var.Qmode == 1.0))) {
      _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 7);
    } else {
      _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 8);
      if (CV_SCRIPT_IF(3, 2, CV_RELATIONAL_EVAL(14U, 3U, 2, c23_d_var.Qmode, 2.0,
            -1, 0U, c23_d_var.Qmode == 2.0))) {
        _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 9);
        c23_b_param = c23_param;
        c23_c_v = c23_b_v;
        c23_d_vRef = c23_c_vRef;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c23_e_debug_family_names,
          c23_c_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U, c23_e_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargin, 1U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargout, 2U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_param, 3U,
          c23_d_sf_marshallOut, c23_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_v, 4U, c23_b_sf_marshallOut,
          c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_vRef, 5U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_qRef, 6U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        CV_SCRIPT_FCN(4, 0);
        _SFD_SCRIPT_CALL(4U, chartInstance->c23_sfEvent, 4);
        CV_SCRIPT_SWITCH(4, 0, 0);
        _SFD_SCRIPT_CALL(4U, chartInstance->c23_sfEvent, 10);
        c23_c_param = c23_b_param;
        c23_d_v = c23_c_v;
        c23_e_vRef = c23_d_vRef;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c23_d_debug_family_names,
          c23_d_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_vMax, 0U, c23_b_sf_marshallOut,
          c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_vMin, 1U, c23_b_sf_marshallOut,
          c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_k, 2U, c23_b_sf_marshallOut,
          c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargin, 3U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargout, 4U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_param, 5U,
          c23_d_sf_marshallOut, c23_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_v, 6U, c23_b_sf_marshallOut,
          c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_vRef, 7U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_qRef, 8U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        CV_SCRIPT_FCN(5, 0);
        _SFD_SCRIPT_CALL(5U, chartInstance->c23_sfEvent, 11);
        c23_vMax = c23_c_param.vBase * 1.1;
        _SFD_SCRIPT_CALL(5U, chartInstance->c23_sfEvent, 12);
        c23_vMin = c23_c_param.vBase * 0.9;
        _SFD_SCRIPT_CALL(5U, chartInstance->c23_sfEvent, 13);
        c23_B = c23_vMax - c23_vMin;
        c23_y = c23_B;
        c23_b_y = c23_y;
        c23_c_y = c23_b_y;
        c23_k = -2.0 / c23_c_y;
        _SFD_SCRIPT_CALL(5U, chartInstance->c23_sfEvent, 14);
        c23_c_qRef = c23_c_param.sMax * c23_k * (c23_d_v - c23_e_vRef);
        _SFD_SCRIPT_CALL(5U, chartInstance->c23_sfEvent, -14);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_SCRIPT_CALL(4U, chartInstance->c23_sfEvent, -10);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 11);
        for (c23_i2 = 0; c23_i2 < 40; c23_i2++) {
          c23_u[c23_i2] = c23_varargin_1[c23_i2];
        }

        c23_d_y = NULL;
        sf_mex_assign(&c23_d_y, sf_mex_create("y", c23_u, 10, 0U, 1U, 0U, 2, 1,
          40), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          c23_d_y);
      }
    }
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 14);
  c23_e_x = c23_b_mpower(chartInstance, c23_param.sMax) - c23_b_mpower
    (chartInstance, c23_d_p);
  c23_qMax = c23_e_x;
  if (c23_qMax < 0.0) {
    c23_b_eml_error(chartInstance);
  }

  c23_f_x = c23_qMax;
  c23_qMax = c23_f_x;
  c23_qMax = muDoubleScalarSqrt(c23_qMax);
  _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 15);
  c23_g_x = c23_c_qRef;
  c23_h_x = c23_g_x;
  c23_d0 = muDoubleScalarAbs(c23_h_x);
  if (CV_SCRIPT_IF(3, 3, CV_RELATIONAL_EVAL(14U, 3U, 3, c23_d0, c23_qMax, -1, 4U,
        c23_d0 > c23_qMax))) {
    _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 16);
    c23_i_x = c23_c_qRef;
    c23_j_x = c23_i_x;
    c23_j_x = muDoubleScalarSign(c23_j_x);
    *c23_b_q = c23_j_x * c23_qMax;
  } else {
    _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, 18);
    *c23_b_q = c23_c_qRef;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c23_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 27);
  c23_d_param = *c23_obj;
  c23_e_var = *c23_b_var;
  c23_b_u = *c23_b_p;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c23_g_debug_family_names,
    c23_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargin, 0U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargout, 1U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_param, 2U, c23_d_sf_marshallOut,
    c23_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_var, 3U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_u, 4U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_p, 5U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_varNew, 6U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c23_sfEvent, 3);
  c23_A = c23_d_param.Ts;
  c23_b_B = c23_d_param.rfTau + c23_d_param.Ts;
  c23_k_x = c23_A;
  c23_e_y = c23_b_B;
  c23_l_x = c23_k_x;
  c23_f_y = c23_e_y;
  c23_m_x = c23_l_x;
  c23_g_y = c23_f_y;
  c23_h_y = c23_m_x / c23_g_y;
  c23_b_A = c23_d_param.rfTau;
  c23_c_B = c23_d_param.rfTau + c23_d_param.Ts;
  c23_n_x = c23_b_A;
  c23_i_y = c23_c_B;
  c23_o_x = c23_n_x;
  c23_j_y = c23_i_y;
  c23_p_x = c23_o_x;
  c23_k_y = c23_j_y;
  c23_l_y = c23_p_x / c23_k_y;
  c23_e_p = c23_b_u * c23_h_y + c23_e_var.pOld * c23_l_y;
  _SFD_SCRIPT_CALL(6U, chartInstance->c23_sfEvent, 4);
  c23_e_var.pOld = c23_e_p;
  _SFD_SCRIPT_CALL(6U, chartInstance->c23_sfEvent, 5);
  c23_c_varNew = c23_e_var;
  _SFD_SCRIPT_CALL(6U, chartInstance->c23_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  *c23_b_p = c23_e_p;
  *c23_varNew = c23_c_varNew;
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 28);
  *c23_b_var = *c23_varNew;
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c23_pCtrlWT(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
  c23_sXgiQ0K2zU5uHJ7gdbD52xC *c23_param, c23_sH1Kify8ZxEOY46vFTteWED *c23_b_var,
  real_T c23_w, real_T c23_b_dP, real_T c23_b_dPlim, real_T *c23_b_p, real_T
  *c23_b_pAva, c23_sH1Kify8ZxEOY46vFTteWED *c23_varNew)
{
  uint32_T c23_debug_family_var_map[11];
  real_T c23_pW;
  real_T c23_nargin = 5.0;
  real_T c23_nargout = 3.0;
  real_T c23_varargin_1;
  real_T c23_varargin_2;
  real_T c23_b_varargin_2;
  real_T c23_varargin_3;
  real_T c23_x;
  real_T c23_y;
  real_T c23_b_x;
  real_T c23_b_y;
  real_T c23_xk;
  real_T c23_yk;
  real_T c23_c_x;
  real_T c23_c_y;
  c23_sH1Kify8ZxEOY46vFTteWED c23_c_var;
  real_T c23_b_w;
  uint32_T c23_b_debug_family_var_map[6];
  real_T c23_b_nargin = 3.0;
  real_T c23_b_nargout = 2.0;
  real_T c23_c_w;
  c23_sH1Kify8ZxEOY46vFTteWED c23_b_varNew;
  int32_T c23_i3;
  real_T c23_d_var[9];
  int32_T c23_i4;
  int32_T c23_i5;
  real_T c23_e_var[10];
  real_T c23_A;
  real_T c23_d_x;
  real_T c23_e_x;
  real_T c23_f_x;
  real_T c23_c_varargin_2;
  real_T c23_b_varargin_3;
  real_T c23_d_y;
  real_T c23_e_y;
  real_T c23_b_yk;
  real_T c23_f_y;
  real_T c23_b_varargin_1;
  real_T c23_d_varargin_2;
  real_T c23_g_x;
  real_T c23_h_x;
  real_T c23_b_xk;
  real_T c23_i_x;
  real_T c23_e_varargin_2;
  real_T c23_c_varargin_3;
  real_T c23_g_y;
  real_T c23_h_y;
  real_T c23_c_yk;
  real_T c23_i_y;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c23_c_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_pW, 0U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 1U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 2U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_param, 3U, c23_d_sf_marshallOut,
    c23_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_var, 4U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_w, 5U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_dP, 6U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_dPlim, 7U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_p, 8U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_pAva, 9U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_varNew, 10U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 4);
  c23_pW = c23_b_var->kWT * c23_param->PF * c23_mpower(chartInstance, c23_w);
  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 6);
  if (CV_SCRIPT_IF(1, 0, CV_RELATIONAL_EVAL(14U, 1U, 0, c23_pW,
        c23_param->pRated, -1, 5U, c23_pW >= c23_param->pRated))) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 7);
    *c23_b_pAva = c23_param->pRated;
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 8);
    if (CV_SCRIPT_IF(1, 1, CV_RELATIONAL_EVAL(14U, 1U, 1, c23_pW, 0.0, -1, 3U,
          c23_pW <= 0.0))) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 9);
      *c23_b_pAva = 0.0;
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 11);
      *c23_b_pAva = c23_pW;
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 14);
  c23_varargin_1 = c23_b_dP;
  c23_varargin_2 = c23_b_dPlim;
  c23_b_varargin_2 = c23_varargin_1;
  c23_varargin_3 = c23_varargin_2;
  c23_x = c23_b_varargin_2;
  c23_y = c23_varargin_3;
  c23_b_x = c23_x;
  c23_b_y = c23_y;
  c23_eml_scalar_eg(chartInstance);
  c23_xk = c23_b_x;
  c23_yk = c23_b_y;
  c23_c_x = c23_xk;
  c23_c_y = c23_yk;
  c23_eml_scalar_eg(chartInstance);
  c23_b_dP = muDoubleScalarMin(c23_c_x, c23_c_y);
  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 17);
  c23_c_var = *c23_b_var;
  c23_b_w = c23_w;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c23_b_debug_family_names,
    c23_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargin, 0U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargout, 1U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_var, 2U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_w, 3U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_w, 4U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_varNew, 5U, c23_c_sf_marshallOut,
    c23_c_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c23_sfEvent, 5);
  for (c23_i3 = 0; c23_i3 < 9; c23_i3++) {
    c23_d_var[c23_i3] = c23_c_var.avgFilterBuf[c23_i3];
  }

  for (c23_i4 = 0; c23_i4 < 9; c23_i4++) {
    c23_c_var.avgFilterBuf[c23_i4 + 1] = c23_d_var[c23_i4];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c23_sfEvent, 6);
  c23_c_var.avgFilterBuf[0] = c23_b_w;
  _SFD_SCRIPT_CALL(2U, chartInstance->c23_sfEvent, 7);
  for (c23_i5 = 0; c23_i5 < 10; c23_i5++) {
    c23_e_var[c23_i5] = c23_c_var.avgFilterBuf[c23_i5];
  }

  c23_A = c23_sum(chartInstance, c23_e_var);
  c23_d_x = c23_A;
  c23_e_x = c23_d_x;
  c23_f_x = c23_e_x;
  c23_c_w = c23_f_x / 10.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c23_sfEvent, 8);
  c23_b_varNew = c23_c_var;
  _SFD_SCRIPT_CALL(2U, chartInstance->c23_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  c23_w = c23_c_w;
  *c23_varNew = c23_b_varNew;
  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 20);
  guard1 = false;
  if (CV_SCRIPT_COND(1, 0, CV_RELATIONAL_EVAL(14U, 1U, 2, c23_w, c23_param->wMin,
        -1, 2U, c23_w < c23_param->wMin))) {
    guard1 = true;
  } else if (CV_SCRIPT_COND(1, 1, CV_RELATIONAL_EVAL(14U, 1U, 3, c23_w,
               c23_param->wMax, -1, 4U, c23_w > c23_param->wMax))) {
    guard1 = true;
  } else {
    CV_SCRIPT_MCDC(1, 0, false);
    CV_SCRIPT_IF(1, 2, false);
    _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 22);
    if (CV_SCRIPT_IF(1, 3, CV_RELATIONAL_EVAL(14U, 1U, 4, c23_pW,
          (c23_param->pRated + c23_b_dP) - c23_b_dPlim, -1, 5U, c23_pW >=
          (c23_param->pRated + c23_b_dP) - c23_b_dPlim))) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 23);
      c23_c_varargin_2 = (c23_param->pRated + c23_b_dP) - c23_b_dPlim;
      c23_b_varargin_3 = c23_c_varargin_2;
      c23_d_y = c23_b_varargin_3;
      c23_e_y = c23_d_y;
      c23_eml_scalar_eg(chartInstance);
      c23_b_yk = c23_e_y;
      c23_f_y = c23_b_yk;
      c23_eml_scalar_eg(chartInstance);
      *c23_b_p = muDoubleScalarMax(0.0, c23_f_y);
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 25);
      c23_b_varargin_1 = c23_b_dP;
      c23_d_varargin_2 = c23_b_varargin_1;
      c23_g_x = c23_d_varargin_2;
      c23_h_x = c23_g_x;
      c23_eml_scalar_eg(chartInstance);
      c23_b_xk = c23_h_x;
      c23_i_x = c23_b_xk;
      c23_eml_scalar_eg(chartInstance);
      c23_b_dP = muDoubleScalarMin(c23_i_x, 0.0);
      _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 26);
      c23_e_varargin_2 = c23_pW + c23_b_dP;
      c23_c_varargin_3 = c23_e_varargin_2;
      c23_g_y = c23_c_varargin_3;
      c23_h_y = c23_g_y;
      c23_eml_scalar_eg(chartInstance);
      c23_c_yk = c23_h_y;
      c23_i_y = c23_c_yk;
      c23_eml_scalar_eg(chartInstance);
      *c23_b_p = muDoubleScalarMax(0.0, c23_i_y);
    }
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(1, 0, true);
    CV_SCRIPT_IF(1, 2, true);
    _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 21);
    *c23_b_p = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 0U,
    sf_debug_get_script_id(
    "\\\\ES.AAU.DK\\Users\\seifu\\Documents\\Project_Triumphant_Career\\Astonishing_Remote_Grid\\SC2net_Benchmark_Grid_Simulink_Model\\DiSC_Op"
    "al_Toolbox\\Prelim_Models\\DiSC_Opal_Toolbox\\models\\WindPowerPlantDO\\sampleWT.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 1U,
    sf_debug_get_script_id(
    "\\\\ES.AAU.DK\\Users\\seifu\\Documents\\Project_Triumphant_Career\\Astonishing_Remote_Grid\\SC2net_Benchmark_Grid_Simulink_Model\\DiSC_Op"
    "al_Toolbox\\Prelim_Models\\DiSC_Opal_Toolbox\\models\\WindPowerPlantDO\\pCtrlWT.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 2U,
    sf_debug_get_script_id(
    "\\\\ES.AAU.DK\\Users\\seifu\\Documents\\Project_Triumphant_Career\\Astonishing_Remote_Grid\\SC2net_Benchmark_Grid_Simulink_Model\\DiSC_Op"
    "al_Toolbox\\Prelim_Models\\DiSC_Opal_Toolbox\\models\\WindPowerPlantDO\\avgFilterWT.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 3U,
    sf_debug_get_script_id(
    "\\\\ES.AAU.DK\\Users\\seifu\\Documents\\Project_Triumphant_Career\\Astonishing_Remote_Grid\\SC2net_Benchmark_Grid_Simulink_Model\\DiSC_Op"
    "al_Toolbox\\Prelim_Models\\DiSC_Opal_Toolbox\\models\\WindPowerPlantDO\\qCtrlWT.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 4U,
    sf_debug_get_script_id(
    "\\\\ES.AAU.DK\\Users\\seifu\\Documents\\Project_Triumphant_Career\\Astonishing_Remote_Grid\\SC2net_Benchmark_Grid_Simulink_Model\\DiSC_Op"
    "al_Toolbox\\Prelim_Models\\DiSC_Opal_Toolbox\\models\\WindPowerPlantDO\\droopWT.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 5U,
    sf_debug_get_script_id(
    "\\\\ES.AAU.DK\\Users\\seifu\\Documents\\Project_Triumphant_Career\\Astonishing_Remote_Grid\\SC2net_Benchmark_Grid_Simulink_Model\\DiSC_Op"
    "al_Toolbox\\Prelim_Models\\DiSC_Opal_Toolbox\\models\\WindPowerPlantDO\\defaultDroopWT.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 6U,
    sf_debug_get_script_id(
    "\\\\ES.AAU.DK\\Users\\seifu\\Documents\\Project_Triumphant_Career\\Astonishing_Remote_Grid\\SC2net_Benchmark_Grid_Simulink_Model\\DiSC_Op"
    "al_Toolbox\\Prelim_Models\\DiSC_Opal_Toolbox\\models\\WindPowerPlantDO\\rotorFilterWT.m"));
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData;
  c23_sH1Kify8ZxEOY46vFTteWED c23_u;
  const mxArray *c23_y = NULL;
  real_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_c_u;
  const mxArray *c23_c_y = NULL;
  real_T c23_d_u;
  const mxArray *c23_d_y = NULL;
  real_T c23_e_u;
  const mxArray *c23_e_y = NULL;
  real_T c23_f_u;
  const mxArray *c23_f_y = NULL;
  real_T c23_g_u;
  const mxArray *c23_g_y = NULL;
  int32_T c23_i6;
  real_T c23_h_u[10];
  const mxArray *c23_h_y = NULL;
  real_T c23_i_u;
  const mxArray *c23_i_y = NULL;
  real_T c23_j_u;
  const mxArray *c23_j_y = NULL;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_mxArrayOutData = NULL;
  c23_u = *(c23_sH1Kify8ZxEOY46vFTteWED *)c23_inData;
  c23_y = NULL;
  if (!chartInstance->c23_var_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_createstruct("structure", 2, 1, 1), false);
    c23_b_u = c23_u.p_c;
    c23_b_y = NULL;
    sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_b_y, "p_c", "p_c", 0);
    c23_c_u = c23_u.q_c;
    c23_c_y = NULL;
    sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_c_y, "q_c", "q_c", 0);
    c23_d_u = c23_u.pAva_c;
    c23_d_y = NULL;
    sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_d_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_d_y, "pAva_c", "pAva_c", 0);
    c23_e_u = c23_u.t_c;
    c23_e_y = NULL;
    sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_e_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_e_y, "t_c", "t_c", 0);
    c23_f_u = c23_u.pOld;
    c23_f_y = NULL;
    sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_f_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_f_y, "pOld", "pOld", 0);
    c23_g_u = c23_u.avgFilterTime;
    c23_g_y = NULL;
    sf_mex_assign(&c23_g_y, sf_mex_create("y", &c23_g_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_g_y, "avgFilterTime", "avgFilterTime", 0);
    for (c23_i6 = 0; c23_i6 < 10; c23_i6++) {
      c23_h_u[c23_i6] = c23_u.avgFilterBuf[c23_i6];
    }

    c23_h_y = NULL;
    sf_mex_assign(&c23_h_y, sf_mex_create("y", c23_h_u, 0, 0U, 1U, 0U, 1, 10),
                  false);
    sf_mex_addfield(c23_y, c23_h_y, "avgFilterBuf", "avgFilterBuf", 0);
    c23_i_u = c23_u.Qmode;
    c23_i_y = NULL;
    sf_mex_assign(&c23_i_y, sf_mex_create("y", &c23_i_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_i_y, "Qmode", "Qmode", 0);
    c23_j_u = c23_u.kWT;
    c23_j_y = NULL;
    sf_mex_assign(&c23_j_y, sf_mex_create("y", &c23_j_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_addfield(c23_y, c23_j_y, "kWT", "kWT", 0);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_b_var, const char_T *c23_identifier,
  c23_sH1Kify8ZxEOY46vFTteWED *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_var), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_var);
}

static void c23_b_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_sH1Kify8ZxEOY46vFTteWED *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[9] = { "p_c", "q_c", "pAva_c", "t_c",
    "pOld", "avgFilterTime", "avgFilterBuf", "Qmode", "kWT" };

  c23_thisId.fParent = c23_parentId;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_var_not_empty = false;
  } else {
    chartInstance->c23_var_not_empty = true;
    sf_mex_check_struct(c23_parentId, c23_u, 9, c23_fieldNames, 0U, NULL);
    c23_thisId.fIdentifier = "p_c";
    c23_y->p_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "p_c", "p_c", 0)), &c23_thisId);
    c23_thisId.fIdentifier = "q_c";
    c23_y->q_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "q_c", "q_c", 0)), &c23_thisId);
    c23_thisId.fIdentifier = "pAva_c";
    c23_y->pAva_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "pAva_c", "pAva_c", 0)), &c23_thisId);
    c23_thisId.fIdentifier = "t_c";
    c23_y->t_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "t_c", "t_c", 0)), &c23_thisId);
    c23_thisId.fIdentifier = "pOld";
    c23_y->pOld = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "pOld", "pOld", 0)), &c23_thisId);
    c23_thisId.fIdentifier = "avgFilterTime";
    c23_y->avgFilterTime = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "avgFilterTime", "avgFilterTime", 0)), &c23_thisId);
    c23_thisId.fIdentifier = "avgFilterBuf";
    c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u,
      "avgFilterBuf", "avgFilterBuf", 0)), &c23_thisId, c23_y->avgFilterBuf);
    c23_thisId.fIdentifier = "Qmode";
    c23_y->Qmode = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "Qmode", "Qmode", 0)), &c23_thisId);
    c23_thisId.fIdentifier = "kWT";
    c23_y->kWT = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c23_u, "kWT", "kWT", 0)), &c23_thisId);
  }

  sf_mex_destroy(&c23_u);
}

static real_T c23_c_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d1;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d1, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d1;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_d_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[10])
{
  real_T c23_dv0[10];
  int32_T c23_i7;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv0, 1, 0, 0U, 1, 0U, 1, 10);
  for (c23_i7 = 0; c23_i7 < 10; c23_i7++) {
    c23_y[c23_i7] = c23_dv0[c23_i7];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_var;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  c23_sH1Kify8ZxEOY46vFTteWED c23_y;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_b_var = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_var), &c23_thisId,
    &c23_y);
  sf_mex_destroy(&c23_b_var);
  *(c23_sH1Kify8ZxEOY46vFTteWED *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_e_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_b_pAva, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_pAva),
    &c23_thisId);
  sf_mex_destroy(&c23_b_pAva);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_pAva;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_b_pAva = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_pAva),
    &c23_thisId);
  sf_mex_destroy(&c23_b_pAva);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  c23_sH1Kify8ZxEOY46vFTteWED c23_u;
  const mxArray *c23_y = NULL;
  real_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_c_u;
  const mxArray *c23_c_y = NULL;
  real_T c23_d_u;
  const mxArray *c23_d_y = NULL;
  real_T c23_e_u;
  const mxArray *c23_e_y = NULL;
  real_T c23_f_u;
  const mxArray *c23_f_y = NULL;
  real_T c23_g_u;
  const mxArray *c23_g_y = NULL;
  int32_T c23_i8;
  real_T c23_h_u[10];
  const mxArray *c23_h_y = NULL;
  real_T c23_i_u;
  const mxArray *c23_i_y = NULL;
  real_T c23_j_u;
  const mxArray *c23_j_y = NULL;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(c23_sH1Kify8ZxEOY46vFTteWED *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_b_u = c23_u.p_c;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_b_y, "p_c", "p_c", 0);
  c23_c_u = c23_u.q_c;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_c_y, "q_c", "q_c", 0);
  c23_d_u = c23_u.pAva_c;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_d_y, "pAva_c", "pAva_c", 0);
  c23_e_u = c23_u.t_c;
  c23_e_y = NULL;
  sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_e_y, "t_c", "t_c", 0);
  c23_f_u = c23_u.pOld;
  c23_f_y = NULL;
  sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_f_y, "pOld", "pOld", 0);
  c23_g_u = c23_u.avgFilterTime;
  c23_g_y = NULL;
  sf_mex_assign(&c23_g_y, sf_mex_create("y", &c23_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_g_y, "avgFilterTime", "avgFilterTime", 0);
  for (c23_i8 = 0; c23_i8 < 10; c23_i8++) {
    c23_h_u[c23_i8] = c23_u.avgFilterBuf[c23_i8];
  }

  c23_h_y = NULL;
  sf_mex_assign(&c23_h_y, sf_mex_create("y", c23_h_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c23_y, c23_h_y, "avgFilterBuf", "avgFilterBuf", 0);
  c23_i_u = c23_u.Qmode;
  c23_i_y = NULL;
  sf_mex_assign(&c23_i_y, sf_mex_create("y", &c23_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_i_y, "Qmode", "Qmode", 0);
  c23_j_u = c23_u.kWT;
  c23_j_y = NULL;
  sf_mex_assign(&c23_j_y, sf_mex_create("y", &c23_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_j_y, "kWT", "kWT", 0);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_f_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_sH1Kify8ZxEOY46vFTteWED *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[9] = { "p_c", "q_c", "pAva_c", "t_c",
    "pOld", "avgFilterTime", "avgFilterBuf", "Qmode", "kWT" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 9, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "p_c";
  c23_y->p_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "p_c", "p_c", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "q_c";
  c23_y->q_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "q_c", "q_c", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "pAva_c";
  c23_y->pAva_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "pAva_c", "pAva_c", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "t_c";
  c23_y->t_c = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "t_c", "t_c", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "pOld";
  c23_y->pOld = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "pOld", "pOld", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "avgFilterTime";
  c23_y->avgFilterTime = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "avgFilterTime", "avgFilterTime", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "avgFilterBuf";
  c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c23_u,
    "avgFilterBuf", "avgFilterBuf", 0)), &c23_thisId, c23_y->avgFilterBuf);
  c23_thisId.fIdentifier = "Qmode";
  c23_y->Qmode = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "Qmode", "Qmode", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "kWT";
  c23_y->kWT = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "kWT", "kWT", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_varNew;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  c23_sH1Kify8ZxEOY46vFTteWED c23_y;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_varNew = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_varNew), &c23_thisId,
    &c23_y);
  sf_mex_destroy(&c23_varNew);
  *(c23_sH1Kify8ZxEOY46vFTteWED *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_u;
  const mxArray *c23_y = NULL;
  real_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_c_u;
  const mxArray *c23_c_y = NULL;
  real_T c23_d_u;
  const mxArray *c23_d_y = NULL;
  real_T c23_e_u;
  const mxArray *c23_e_y = NULL;
  real_T c23_f_u;
  const mxArray *c23_f_y = NULL;
  real_T c23_g_u;
  const mxArray *c23_g_y = NULL;
  real_T c23_h_u;
  const mxArray *c23_h_y = NULL;
  real_T c23_i_u;
  const mxArray *c23_i_y = NULL;
  real_T c23_j_u;
  const mxArray *c23_j_y = NULL;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(c23_sXgiQ0K2zU5uHJ7gdbD52xC *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c23_b_u = c23_u.vBase;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_b_y, "vBase", "vBase", 0);
  c23_c_u = c23_u.pRated;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_c_y, "pRated", "pRated", 0);
  c23_d_u = c23_u.sMax;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_d_y, "sMax", "sMax", 0);
  c23_e_u = c23_u.wMin;
  c23_e_y = NULL;
  sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_e_y, "wMin", "wMin", 0);
  c23_f_u = c23_u.wMax;
  c23_f_y = NULL;
  sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_f_y, "wMax", "wMax", 0);
  c23_g_u = c23_u.wRated;
  c23_g_y = NULL;
  sf_mex_assign(&c23_g_y, sf_mex_create("y", &c23_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_g_y, "wRated", "wRated", 0);
  c23_h_u = c23_u.rfTau;
  c23_h_y = NULL;
  sf_mex_assign(&c23_h_y, sf_mex_create("y", &c23_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_h_y, "rfTau", "rfTau", 0);
  c23_i_u = c23_u.PF;
  c23_i_y = NULL;
  sf_mex_assign(&c23_i_y, sf_mex_create("y", &c23_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_i_y, "PF", "PF", 0);
  c23_j_u = c23_u.Ts;
  c23_j_y = NULL;
  sf_mex_assign(&c23_j_y, sf_mex_create("y", &c23_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c23_y, c23_j_y, "Ts", "Ts", 0);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_g_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  c23_sXgiQ0K2zU5uHJ7gdbD52xC *c23_y)
{
  emlrtMsgIdentifier c23_thisId;
  static const char * c23_fieldNames[9] = { "vBase", "pRated", "sMax", "wMin",
    "wMax", "wRated", "rfTau", "PF", "Ts" };

  c23_thisId.fParent = c23_parentId;
  sf_mex_check_struct(c23_parentId, c23_u, 9, c23_fieldNames, 0U, NULL);
  c23_thisId.fIdentifier = "vBase";
  c23_y->vBase = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "vBase", "vBase", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "pRated";
  c23_y->pRated = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "pRated", "pRated", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "sMax";
  c23_y->sMax = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "sMax", "sMax", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "wMin";
  c23_y->wMin = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "wMin", "wMin", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "wMax";
  c23_y->wMax = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c23_u, "wMax", "wMax", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "wRated";
  c23_y->wRated = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "wRated", "wRated", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "rfTau";
  c23_y->rfTau = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c23_u, "rfTau", "rfTau", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "PF";
  c23_y->PF = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "PF", "PF", 0)), &c23_thisId);
  c23_thisId.fIdentifier = "Ts";
  c23_y->Ts = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c23_u, "Ts", "Ts", 0)), &c23_thisId);
  sf_mex_destroy(&c23_u);
}

static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_param;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  c23_sXgiQ0K2zU5uHJ7gdbD52xC c23_y;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_param = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_param), &c23_thisId,
    &c23_y);
  sf_mex_destroy(&c23_param);
  *(c23_sXgiQ0K2zU5uHJ7gdbD52xC *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  const mxArray *c23_y = NULL;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  (void)c23_inData;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 10, 0U, 1U, 0U, 2, 1, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

const mxArray *sf_c23_DiSC_ToolboxOpal_V11_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_createstruct("structure", 2, 83, 1),
                false);
  c23_info_helper(&c23_nameCaptureInfo);
  c23_b_info_helper(&c23_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c23_nameCaptureInfo);
  return c23_nameCaptureInfo;
}

static void c23_info_helper(const mxArray **c23_info)
{
  const mxArray *c23_rhs0 = NULL;
  const mxArray *c23_lhs0 = NULL;
  const mxArray *c23_rhs1 = NULL;
  const mxArray *c23_lhs1 = NULL;
  const mxArray *c23_rhs2 = NULL;
  const mxArray *c23_lhs2 = NULL;
  const mxArray *c23_rhs3 = NULL;
  const mxArray *c23_lhs3 = NULL;
  const mxArray *c23_rhs4 = NULL;
  const mxArray *c23_lhs4 = NULL;
  const mxArray *c23_rhs5 = NULL;
  const mxArray *c23_lhs5 = NULL;
  const mxArray *c23_rhs6 = NULL;
  const mxArray *c23_lhs6 = NULL;
  const mxArray *c23_rhs7 = NULL;
  const mxArray *c23_lhs7 = NULL;
  const mxArray *c23_rhs8 = NULL;
  const mxArray *c23_lhs8 = NULL;
  const mxArray *c23_rhs9 = NULL;
  const mxArray *c23_lhs9 = NULL;
  const mxArray *c23_rhs10 = NULL;
  const mxArray *c23_lhs10 = NULL;
  const mxArray *c23_rhs11 = NULL;
  const mxArray *c23_lhs11 = NULL;
  const mxArray *c23_rhs12 = NULL;
  const mxArray *c23_lhs12 = NULL;
  const mxArray *c23_rhs13 = NULL;
  const mxArray *c23_lhs13 = NULL;
  const mxArray *c23_rhs14 = NULL;
  const mxArray *c23_lhs14 = NULL;
  const mxArray *c23_rhs15 = NULL;
  const mxArray *c23_lhs15 = NULL;
  const mxArray *c23_rhs16 = NULL;
  const mxArray *c23_lhs16 = NULL;
  const mxArray *c23_rhs17 = NULL;
  const mxArray *c23_lhs17 = NULL;
  const mxArray *c23_rhs18 = NULL;
  const mxArray *c23_lhs18 = NULL;
  const mxArray *c23_rhs19 = NULL;
  const mxArray *c23_lhs19 = NULL;
  const mxArray *c23_rhs20 = NULL;
  const mxArray *c23_lhs20 = NULL;
  const mxArray *c23_rhs21 = NULL;
  const mxArray *c23_lhs21 = NULL;
  const mxArray *c23_rhs22 = NULL;
  const mxArray *c23_lhs22 = NULL;
  const mxArray *c23_rhs23 = NULL;
  const mxArray *c23_lhs23 = NULL;
  const mxArray *c23_rhs24 = NULL;
  const mxArray *c23_lhs24 = NULL;
  const mxArray *c23_rhs25 = NULL;
  const mxArray *c23_lhs25 = NULL;
  const mxArray *c23_rhs26 = NULL;
  const mxArray *c23_lhs26 = NULL;
  const mxArray *c23_rhs27 = NULL;
  const mxArray *c23_lhs27 = NULL;
  const mxArray *c23_rhs28 = NULL;
  const mxArray *c23_lhs28 = NULL;
  const mxArray *c23_rhs29 = NULL;
  const mxArray *c23_lhs29 = NULL;
  const mxArray *c23_rhs30 = NULL;
  const mxArray *c23_lhs30 = NULL;
  const mxArray *c23_rhs31 = NULL;
  const mxArray *c23_lhs31 = NULL;
  const mxArray *c23_rhs32 = NULL;
  const mxArray *c23_lhs32 = NULL;
  const mxArray *c23_rhs33 = NULL;
  const mxArray *c23_lhs33 = NULL;
  const mxArray *c23_rhs34 = NULL;
  const mxArray *c23_lhs34 = NULL;
  const mxArray *c23_rhs35 = NULL;
  const mxArray *c23_lhs35 = NULL;
  const mxArray *c23_rhs36 = NULL;
  const mxArray *c23_lhs36 = NULL;
  const mxArray *c23_rhs37 = NULL;
  const mxArray *c23_lhs37 = NULL;
  const mxArray *c23_rhs38 = NULL;
  const mxArray *c23_lhs38 = NULL;
  const mxArray *c23_rhs39 = NULL;
  const mxArray *c23_lhs39 = NULL;
  const mxArray *c23_rhs40 = NULL;
  const mxArray *c23_lhs40 = NULL;
  const mxArray *c23_rhs41 = NULL;
  const mxArray *c23_lhs41 = NULL;
  const mxArray *c23_rhs42 = NULL;
  const mxArray *c23_lhs42 = NULL;
  const mxArray *c23_rhs43 = NULL;
  const mxArray *c23_lhs43 = NULL;
  const mxArray *c23_rhs44 = NULL;
  const mxArray *c23_lhs44 = NULL;
  const mxArray *c23_rhs45 = NULL;
  const mxArray *c23_lhs45 = NULL;
  const mxArray *c23_rhs46 = NULL;
  const mxArray *c23_lhs46 = NULL;
  const mxArray *c23_rhs47 = NULL;
  const mxArray *c23_lhs47 = NULL;
  const mxArray *c23_rhs48 = NULL;
  const mxArray *c23_lhs48 = NULL;
  const mxArray *c23_rhs49 = NULL;
  const mxArray *c23_lhs49 = NULL;
  const mxArray *c23_rhs50 = NULL;
  const mxArray *c23_lhs50 = NULL;
  const mxArray *c23_rhs51 = NULL;
  const mxArray *c23_lhs51 = NULL;
  const mxArray *c23_rhs52 = NULL;
  const mxArray *c23_lhs52 = NULL;
  const mxArray *c23_rhs53 = NULL;
  const mxArray *c23_lhs53 = NULL;
  const mxArray *c23_rhs54 = NULL;
  const mxArray *c23_lhs54 = NULL;
  const mxArray *c23_rhs55 = NULL;
  const mxArray *c23_lhs55 = NULL;
  const mxArray *c23_rhs56 = NULL;
  const mxArray *c23_lhs56 = NULL;
  const mxArray *c23_rhs57 = NULL;
  const mxArray *c23_lhs57 = NULL;
  const mxArray *c23_rhs58 = NULL;
  const mxArray *c23_lhs58 = NULL;
  const mxArray *c23_rhs59 = NULL;
  const mxArray *c23_lhs59 = NULL;
  const mxArray *c23_rhs60 = NULL;
  const mxArray *c23_lhs60 = NULL;
  const mxArray *c23_rhs61 = NULL;
  const mxArray *c23_lhs61 = NULL;
  const mxArray *c23_rhs62 = NULL;
  const mxArray *c23_lhs62 = NULL;
  const mxArray *c23_rhs63 = NULL;
  const mxArray *c23_lhs63 = NULL;
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c23_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c23_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c23_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c23_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c23_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c23_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c23_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("ceil"), "name", "name", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c23_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c23_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_ceil"), "name",
                  "name", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_ceil.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818720U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c23_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mpower"), "name", "name", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c23_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c23_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("ismatrix"), "name", "name",
                  12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c23_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("power"), "name", "name", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395328506U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c23_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c23_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c23_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c23_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c23_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c23_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("floor"), "name", "name", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c23_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c23_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c23_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c23_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("sampleWT"), "name", "name",
                  23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/sampleWT.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1431812332U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c23_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/sampleWT.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("pCtrlWT"), "name", "name",
                  24);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/pCtrlWT.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1432045132U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c23_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/pCtrlWT.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mpower"), "name", "name", 25);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c23_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/pCtrlWT.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("min"), "name", "name", 26);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c23_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 27);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c23_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 28);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 28);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c23_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 29);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 29);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c23_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 30);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 30);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c23_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 31);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 31);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c23_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 32);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c23_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/pCtrlWT.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("avgFilterWT"), "name",
                  "name", 33);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/avgFilterWT.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1432045202U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c23_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/avgFilterWT.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("sum"), "name", "name", 34);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395930306U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c23_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 35);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c23_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("sumprod"), "name", "name",
                  36);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395930302U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c23_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 37);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c23_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 38);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c23_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("process_sumprod_inputs"),
                  "name", "name", 39);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395930302U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c23_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.narginchk"),
                  "name", "name", 40);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363714558U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c23_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("floor"), "name", "name", 41);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c23_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 42);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c23_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 43);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c23_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 44);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c23_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 45);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c23_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("isequal"), "name", "name",
                  46);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818758U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c23_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 47);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818786U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c23_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("combine_vector_elements"),
                  "name", "name", 48);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395930302U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c23_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 49);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c23_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 50);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("isfi"), "name", "name", 50);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c23_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 51);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c23_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 52);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("intmax"), "name", "name", 52);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c23_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 53);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c23_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 54);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("intmin"), "name", "name", 54);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c23_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 55);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c23_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/avgFilterWT.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("length"), "name", "name", 56);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1303146206U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c23_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/avgFilterWT.m"),
                  "context", "context", 57);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mrdivide"), "name", "name",
                  57);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c23_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/pCtrlWT.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("max"), "name", "name", 58);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1311255316U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c23_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 59);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c23_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/sampleWT.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("qCtrlWT"), "name", "name",
                  60);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1432045112U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c23_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("acos"), "name", "name", 61);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395328492U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c23_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_error"), "name", "name",
                  62);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c23_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "context",
                  "context", 63);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_acos"), "name",
                  "name", 63);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1343830376U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c23_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c23_rhs0);
  sf_mex_destroy(&c23_lhs0);
  sf_mex_destroy(&c23_rhs1);
  sf_mex_destroy(&c23_lhs1);
  sf_mex_destroy(&c23_rhs2);
  sf_mex_destroy(&c23_lhs2);
  sf_mex_destroy(&c23_rhs3);
  sf_mex_destroy(&c23_lhs3);
  sf_mex_destroy(&c23_rhs4);
  sf_mex_destroy(&c23_lhs4);
  sf_mex_destroy(&c23_rhs5);
  sf_mex_destroy(&c23_lhs5);
  sf_mex_destroy(&c23_rhs6);
  sf_mex_destroy(&c23_lhs6);
  sf_mex_destroy(&c23_rhs7);
  sf_mex_destroy(&c23_lhs7);
  sf_mex_destroy(&c23_rhs8);
  sf_mex_destroy(&c23_lhs8);
  sf_mex_destroy(&c23_rhs9);
  sf_mex_destroy(&c23_lhs9);
  sf_mex_destroy(&c23_rhs10);
  sf_mex_destroy(&c23_lhs10);
  sf_mex_destroy(&c23_rhs11);
  sf_mex_destroy(&c23_lhs11);
  sf_mex_destroy(&c23_rhs12);
  sf_mex_destroy(&c23_lhs12);
  sf_mex_destroy(&c23_rhs13);
  sf_mex_destroy(&c23_lhs13);
  sf_mex_destroy(&c23_rhs14);
  sf_mex_destroy(&c23_lhs14);
  sf_mex_destroy(&c23_rhs15);
  sf_mex_destroy(&c23_lhs15);
  sf_mex_destroy(&c23_rhs16);
  sf_mex_destroy(&c23_lhs16);
  sf_mex_destroy(&c23_rhs17);
  sf_mex_destroy(&c23_lhs17);
  sf_mex_destroy(&c23_rhs18);
  sf_mex_destroy(&c23_lhs18);
  sf_mex_destroy(&c23_rhs19);
  sf_mex_destroy(&c23_lhs19);
  sf_mex_destroy(&c23_rhs20);
  sf_mex_destroy(&c23_lhs20);
  sf_mex_destroy(&c23_rhs21);
  sf_mex_destroy(&c23_lhs21);
  sf_mex_destroy(&c23_rhs22);
  sf_mex_destroy(&c23_lhs22);
  sf_mex_destroy(&c23_rhs23);
  sf_mex_destroy(&c23_lhs23);
  sf_mex_destroy(&c23_rhs24);
  sf_mex_destroy(&c23_lhs24);
  sf_mex_destroy(&c23_rhs25);
  sf_mex_destroy(&c23_lhs25);
  sf_mex_destroy(&c23_rhs26);
  sf_mex_destroy(&c23_lhs26);
  sf_mex_destroy(&c23_rhs27);
  sf_mex_destroy(&c23_lhs27);
  sf_mex_destroy(&c23_rhs28);
  sf_mex_destroy(&c23_lhs28);
  sf_mex_destroy(&c23_rhs29);
  sf_mex_destroy(&c23_lhs29);
  sf_mex_destroy(&c23_rhs30);
  sf_mex_destroy(&c23_lhs30);
  sf_mex_destroy(&c23_rhs31);
  sf_mex_destroy(&c23_lhs31);
  sf_mex_destroy(&c23_rhs32);
  sf_mex_destroy(&c23_lhs32);
  sf_mex_destroy(&c23_rhs33);
  sf_mex_destroy(&c23_lhs33);
  sf_mex_destroy(&c23_rhs34);
  sf_mex_destroy(&c23_lhs34);
  sf_mex_destroy(&c23_rhs35);
  sf_mex_destroy(&c23_lhs35);
  sf_mex_destroy(&c23_rhs36);
  sf_mex_destroy(&c23_lhs36);
  sf_mex_destroy(&c23_rhs37);
  sf_mex_destroy(&c23_lhs37);
  sf_mex_destroy(&c23_rhs38);
  sf_mex_destroy(&c23_lhs38);
  sf_mex_destroy(&c23_rhs39);
  sf_mex_destroy(&c23_lhs39);
  sf_mex_destroy(&c23_rhs40);
  sf_mex_destroy(&c23_lhs40);
  sf_mex_destroy(&c23_rhs41);
  sf_mex_destroy(&c23_lhs41);
  sf_mex_destroy(&c23_rhs42);
  sf_mex_destroy(&c23_lhs42);
  sf_mex_destroy(&c23_rhs43);
  sf_mex_destroy(&c23_lhs43);
  sf_mex_destroy(&c23_rhs44);
  sf_mex_destroy(&c23_lhs44);
  sf_mex_destroy(&c23_rhs45);
  sf_mex_destroy(&c23_lhs45);
  sf_mex_destroy(&c23_rhs46);
  sf_mex_destroy(&c23_lhs46);
  sf_mex_destroy(&c23_rhs47);
  sf_mex_destroy(&c23_lhs47);
  sf_mex_destroy(&c23_rhs48);
  sf_mex_destroy(&c23_lhs48);
  sf_mex_destroy(&c23_rhs49);
  sf_mex_destroy(&c23_lhs49);
  sf_mex_destroy(&c23_rhs50);
  sf_mex_destroy(&c23_lhs50);
  sf_mex_destroy(&c23_rhs51);
  sf_mex_destroy(&c23_lhs51);
  sf_mex_destroy(&c23_rhs52);
  sf_mex_destroy(&c23_lhs52);
  sf_mex_destroy(&c23_rhs53);
  sf_mex_destroy(&c23_lhs53);
  sf_mex_destroy(&c23_rhs54);
  sf_mex_destroy(&c23_lhs54);
  sf_mex_destroy(&c23_rhs55);
  sf_mex_destroy(&c23_lhs55);
  sf_mex_destroy(&c23_rhs56);
  sf_mex_destroy(&c23_lhs56);
  sf_mex_destroy(&c23_rhs57);
  sf_mex_destroy(&c23_lhs57);
  sf_mex_destroy(&c23_rhs58);
  sf_mex_destroy(&c23_lhs58);
  sf_mex_destroy(&c23_rhs59);
  sf_mex_destroy(&c23_lhs59);
  sf_mex_destroy(&c23_rhs60);
  sf_mex_destroy(&c23_lhs60);
  sf_mex_destroy(&c23_rhs61);
  sf_mex_destroy(&c23_lhs61);
  sf_mex_destroy(&c23_rhs62);
  sf_mex_destroy(&c23_lhs62);
  sf_mex_destroy(&c23_rhs63);
  sf_mex_destroy(&c23_lhs63);
}

static const mxArray *c23_emlrt_marshallOut(const char * c23_u)
{
  const mxArray *c23_y = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c23_u)), false);
  return c23_y;
}

static const mxArray *c23_b_emlrt_marshallOut(const uint32_T c23_u)
{
  const mxArray *c23_y = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 7, 0U, 0U, 0U, 0), false);
  return c23_y;
}

static void c23_b_info_helper(const mxArray **c23_info)
{
  const mxArray *c23_rhs64 = NULL;
  const mxArray *c23_lhs64 = NULL;
  const mxArray *c23_rhs65 = NULL;
  const mxArray *c23_lhs65 = NULL;
  const mxArray *c23_rhs66 = NULL;
  const mxArray *c23_lhs66 = NULL;
  const mxArray *c23_rhs67 = NULL;
  const mxArray *c23_lhs67 = NULL;
  const mxArray *c23_rhs68 = NULL;
  const mxArray *c23_lhs68 = NULL;
  const mxArray *c23_rhs69 = NULL;
  const mxArray *c23_lhs69 = NULL;
  const mxArray *c23_rhs70 = NULL;
  const mxArray *c23_lhs70 = NULL;
  const mxArray *c23_rhs71 = NULL;
  const mxArray *c23_lhs71 = NULL;
  const mxArray *c23_rhs72 = NULL;
  const mxArray *c23_lhs72 = NULL;
  const mxArray *c23_rhs73 = NULL;
  const mxArray *c23_lhs73 = NULL;
  const mxArray *c23_rhs74 = NULL;
  const mxArray *c23_lhs74 = NULL;
  const mxArray *c23_rhs75 = NULL;
  const mxArray *c23_lhs75 = NULL;
  const mxArray *c23_rhs76 = NULL;
  const mxArray *c23_lhs76 = NULL;
  const mxArray *c23_rhs77 = NULL;
  const mxArray *c23_lhs77 = NULL;
  const mxArray *c23_rhs78 = NULL;
  const mxArray *c23_lhs78 = NULL;
  const mxArray *c23_rhs79 = NULL;
  const mxArray *c23_lhs79 = NULL;
  const mxArray *c23_rhs80 = NULL;
  const mxArray *c23_lhs80 = NULL;
  const mxArray *c23_rhs81 = NULL;
  const mxArray *c23_lhs81 = NULL;
  const mxArray *c23_rhs82 = NULL;
  const mxArray *c23_lhs82 = NULL;
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("tan"), "name", "name", 64);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/tan.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c23_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/tan.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_tan"), "name",
                  "name", 65);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_tan.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c23_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("droopWT"), "name", "name",
                  66);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/droopWT.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1432045172U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c23_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/droopWT.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 67);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c23_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/droopWT.m"),
                  "context", "context", 68);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("defaultDroopWT"), "name",
                  "name", 68);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/defaultDroopWT.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1432045182U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c23_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/defaultDroopWT.m"),
                  "context", "context", 69);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mrdivide"), "name", "name",
                  69);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c23_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 70);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("error"), "name", "name", 70);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/error.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1319729966U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c23_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 71);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mpower"), "name", "name", 71);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c23_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 72);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("sqrt"), "name", "name", 72);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c23_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_error"), "name", "name",
                  73);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c23_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 74);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c23_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 75);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("abs"), "name", "name", 75);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c23_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 76);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c23_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 77);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c23_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/qCtrlWT.m"),
                  "context", "context", 78);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("sign"), "name", "name", 78);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 78);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c23_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 79);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 79);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c23_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 80);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 80);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1356541494U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c23_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/sampleWT.m"),
                  "context", "context", 81);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("rotorFilterWT"), "name",
                  "name", 81);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/rotorFilterWT.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1432045104U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c23_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]//ES.AAU.DK/Users/seifu/Documents/Project_Triumphant_Career/Astonishing_Remote_Grid/SC2net_Benchmark_Grid_Simulink_Model/DiSC"
    "_Opal_Toolbox/Prelim_Models/DiSC_Opal_Toolbox/models/WindPowerPlantDO/rotorFilterWT.m"),
                  "context", "context", 82);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mrdivide"), "name", "name",
                  82);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c23_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs82), "lhs", "lhs",
                  82);
  sf_mex_destroy(&c23_rhs64);
  sf_mex_destroy(&c23_lhs64);
  sf_mex_destroy(&c23_rhs65);
  sf_mex_destroy(&c23_lhs65);
  sf_mex_destroy(&c23_rhs66);
  sf_mex_destroy(&c23_lhs66);
  sf_mex_destroy(&c23_rhs67);
  sf_mex_destroy(&c23_lhs67);
  sf_mex_destroy(&c23_rhs68);
  sf_mex_destroy(&c23_lhs68);
  sf_mex_destroy(&c23_rhs69);
  sf_mex_destroy(&c23_lhs69);
  sf_mex_destroy(&c23_rhs70);
  sf_mex_destroy(&c23_lhs70);
  sf_mex_destroy(&c23_rhs71);
  sf_mex_destroy(&c23_lhs71);
  sf_mex_destroy(&c23_rhs72);
  sf_mex_destroy(&c23_lhs72);
  sf_mex_destroy(&c23_rhs73);
  sf_mex_destroy(&c23_lhs73);
  sf_mex_destroy(&c23_rhs74);
  sf_mex_destroy(&c23_lhs74);
  sf_mex_destroy(&c23_rhs75);
  sf_mex_destroy(&c23_lhs75);
  sf_mex_destroy(&c23_rhs76);
  sf_mex_destroy(&c23_lhs76);
  sf_mex_destroy(&c23_rhs77);
  sf_mex_destroy(&c23_lhs77);
  sf_mex_destroy(&c23_rhs78);
  sf_mex_destroy(&c23_lhs78);
  sf_mex_destroy(&c23_rhs79);
  sf_mex_destroy(&c23_lhs79);
  sf_mex_destroy(&c23_rhs80);
  sf_mex_destroy(&c23_lhs80);
  sf_mex_destroy(&c23_rhs81);
  sf_mex_destroy(&c23_lhs81);
  sf_mex_destroy(&c23_rhs82);
  sf_mex_destroy(&c23_lhs82);
}

static real_T c23_mpower(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
  real_T c23_a)
{
  real_T c23_b_a;
  real_T c23_c_a;
  real_T c23_ak;
  real_T c23_d_a;
  real_T c23_ar;
  c23_b_a = c23_a;
  c23_c_a = c23_b_a;
  c23_eml_scalar_eg(chartInstance);
  c23_ak = c23_c_a;
  c23_d_a = c23_ak;
  c23_eml_scalar_eg(chartInstance);
  c23_ar = c23_d_a;
  return muDoubleScalarPower(c23_ar, 3.0);
}

static void c23_eml_scalar_eg(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c23_sum(SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance,
                      real_T c23_x[10])
{
  real_T c23_y;
  int32_T c23_k;
  int32_T c23_b_k;
  (void)chartInstance;
  c23_y = c23_x[0];
  for (c23_k = 2; c23_k < 11; c23_k++) {
    c23_b_k = c23_k;
    c23_y += c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c23_b_k), 1, 10, 1, 0) - 1];
  }

  return c23_y;
}

static void c23_eml_error(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance)
{
  int32_T c23_i9;
  static char_T c23_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c23_u[30];
  const mxArray *c23_y = NULL;
  int32_T c23_i10;
  static char_T c23_cv1[4] = { 'a', 'c', 'o', 's' };

  char_T c23_b_u[4];
  const mxArray *c23_b_y = NULL;
  (void)chartInstance;
  for (c23_i9 = 0; c23_i9 < 30; c23_i9++) {
    c23_u[c23_i9] = c23_cv0[c23_i9];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c23_i10 = 0; c23_i10 < 4; c23_i10++) {
    c23_b_u[c23_i10] = c23_cv1[c23_i10];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c23_y, 14, c23_b_y));
}

static real_T c23_b_mpower(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, real_T c23_a)
{
  real_T c23_b_a;
  real_T c23_c_a;
  real_T c23_ak;
  real_T c23_d_a;
  c23_b_a = c23_a;
  c23_c_a = c23_b_a;
  c23_eml_scalar_eg(chartInstance);
  c23_ak = c23_c_a;
  c23_d_a = c23_ak;
  c23_eml_scalar_eg(chartInstance);
  return c23_d_a * c23_d_a;
}

static void c23_b_eml_error(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance)
{
  int32_T c23_i11;
  static char_T c23_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c23_u[30];
  const mxArray *c23_y = NULL;
  int32_T c23_i12;
  static char_T c23_cv3[4] = { 's', 'q', 'r', 't' };

  char_T c23_b_u[4];
  const mxArray *c23_b_y = NULL;
  (void)chartInstance;
  for (c23_i11 = 0; c23_i11 < 30; c23_i11++) {
    c23_u[c23_i11] = c23_cv2[c23_i11];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c23_i12 = 0; c23_i12 < 4; c23_i12++) {
    c23_b_u[c23_i12] = c23_cv3[c23_i12];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c23_y, 14, c23_b_y));
}

static const mxArray *c23_f_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_h_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i13;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i13, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i13;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_i_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_DiSC_ToolboxOpal_V11, const
  char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_DiSC_ToolboxOpal_V11), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_DiSC_ToolboxOpal_V11);
  return c23_y;
}

static uint8_T c23_j_emlrt_marshallIn(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc23_DiSC_ToolboxOpal_V11InstanceStruct
  *chartInstance)
{
  chartInstance->c23_p = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c23_wind = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c23_vMeas = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c23_dP = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c23_dPlim = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c23_qRef = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c23_qMode = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c23_vRef = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c23_time = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c23_q = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c23_pAva = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c23_DiSC_ToolboxOpal_V11_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(324735913U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3864733219U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2485318806U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4090194479U);
}

mxArray* sf_c23_DiSC_ToolboxOpal_V11_get_post_codegen_info(void);
mxArray *sf_c23_DiSC_ToolboxOpal_V11_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SAC3nPFsQjwkWSIDBhz82");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c23_DiSC_ToolboxOpal_V11_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_DiSC_ToolboxOpal_V11_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_DiSC_ToolboxOpal_V11_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c23_DiSC_ToolboxOpal_V11_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c23_DiSC_ToolboxOpal_V11_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c23_DiSC_ToolboxOpal_V11(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"p\",},{M[1],M[15],T\"pAva\",},{M[1],M[14],T\"q\",},{M[4],M[0],T\"var\",S'l','i','p'{{M1x2[1661 1664],M[0],}}},{M[8],M[0],T\"is_active_c23_DiSC_ToolboxOpal_V11\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_DiSC_ToolboxOpal_V11_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DiSC_ToolboxOpal_V11MachineNumber_,
           23,
           1,
           1,
           0,
           11,
           0,
           0,
           0,
           0,
           7,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_DiSC_ToolboxOpal_V11MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DiSC_ToolboxOpal_V11MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DiSC_ToolboxOpal_V11MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"p");
          _SFD_SET_DATA_PROPS(1,1,1,0,"wind");
          _SFD_SET_DATA_PROPS(2,1,1,0,"vMeas");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dP");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dPlim");
          _SFD_SET_DATA_PROPS(5,1,1,0,"qRef");
          _SFD_SET_DATA_PROPS(6,1,1,0,"qMode");
          _SFD_SET_DATA_PROPS(7,1,1,0,"vRef");
          _SFD_SET_DATA_PROPS(8,1,1,0,"time");
          _SFD_SET_DATA_PROPS(9,2,0,1,"q");
          _SFD_SET_DATA_PROPS(10,2,0,1,"pAva");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3154);
        _SFD_CV_INIT_EML_IF(0,1,0,1671,1686,-1,2229);
        _SFD_CV_INIT_EML_IF(0,1,1,2402,2417,2880,3015);
        _SFD_CV_INIT_EML_IF(0,1,2,2433,2461,-1,2783);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,2406,2416,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,2437,2460,-1,4);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"sampleWT",38,-1,1196);
        _SFD_CV_INIT_SCRIPT(1,1,4,0,0,0,0,0,2,1);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"pCtrlWT",39,-1,1232);
        _SFD_CV_INIT_SCRIPT_IF(1,0,277,298,348,448);
        _SFD_CV_INIT_SCRIPT_IF(1,1,348,362,401,448);
        _SFD_CV_INIT_SCRIPT_IF(1,2,719,751,879,1219);
        _SFD_CV_INIT_SCRIPT_IF(1,3,879,912,1036,1219);

        {
          static int condStart[] = { 722, 738 };

          static int condEnd[] = { 734, 750 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,0,722,750,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,0,280,298,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,1,355,362,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,2,722,734,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,3,738,750,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,4,886,911,-1,5);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"avgFilterWT",103,-1,383);
        _SFD_CV_INIT_SCRIPT(3,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"qCtrlWT",41,-1,730);
        _SFD_CV_INIT_SCRIPT_IF(3,0,148,166,225,464);
        _SFD_CV_INIT_SCRIPT_IF(3,1,225,247,289,464);
        _SFD_CV_INIT_SCRIPT_IF(3,2,289,311,377,464);
        _SFD_CV_INIT_SCRIPT_IF(3,3,604,622,672,718);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(3,0,151,165,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(3,1,232,246,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(3,2,296,310,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(3,3,607,621,-1,4);
        _SFD_CV_INIT_SCRIPT(4,1,0,0,0,1,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"droopWT",49,-1,452);

        {
          static int caseStart[] = { 301 };

          static int caseExprEnd[] = { 310 };

          _SFD_CV_INIT_SCRIPT_SWITCH(4,0,147,159,451,1,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_SCRIPT(5,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"defaultDroopWT",49,-1,570);
        _SFD_CV_INIT_SCRIPT(6,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(6,0,"rotorFilterWT",64,-1,275);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)
          c23_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)
          c23_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)
          c23_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c23_p);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c23_wind);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c23_vMeas);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c23_dP);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c23_dPlim);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c23_qRef);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c23_qMode);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c23_vRef);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c23_time);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c23_q);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c23_pAva);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DiSC_ToolboxOpal_V11MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "6jJ1mksM3w01ww8Vm6qWPC";
}

static void sf_opaque_initialize_c23_DiSC_ToolboxOpal_V11(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_DiSC_ToolboxOpal_V11
    ((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*) chartInstanceVar);
  initialize_c23_DiSC_ToolboxOpal_V11((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c23_DiSC_ToolboxOpal_V11(void *chartInstanceVar)
{
  enable_c23_DiSC_ToolboxOpal_V11((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_DiSC_ToolboxOpal_V11(void *chartInstanceVar)
{
  disable_c23_DiSC_ToolboxOpal_V11((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_DiSC_ToolboxOpal_V11(void *chartInstanceVar)
{
  sf_gateway_c23_DiSC_ToolboxOpal_V11((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c23_DiSC_ToolboxOpal_V11(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c23_DiSC_ToolboxOpal_V11
    ((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c23_DiSC_ToolboxOpal_V11(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c23_DiSC_ToolboxOpal_V11
    ((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c23_DiSC_ToolboxOpal_V11(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DiSC_ToolboxOpal_V11_optimization_info();
    }

    finalize_c23_DiSC_ToolboxOpal_V11((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_DiSC_ToolboxOpal_V11
    ((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_DiSC_ToolboxOpal_V11(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c23_DiSC_ToolboxOpal_V11
      ((SFc23_DiSC_ToolboxOpal_V11InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_DiSC_ToolboxOpal_V11(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DiSC_ToolboxOpal_V11_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4188991907U));
  ssSetChecksum1(S,(2843201590U));
  ssSetChecksum2(S,(676492956U));
  ssSetChecksum3(S,(2798309138U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_DiSC_ToolboxOpal_V11(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_DiSC_ToolboxOpal_V11(SimStruct *S)
{
  SFc23_DiSC_ToolboxOpal_V11InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_DiSC_ToolboxOpal_V11InstanceStruct *)utMalloc(sizeof
    (SFc23_DiSC_ToolboxOpal_V11InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_DiSC_ToolboxOpal_V11InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_DiSC_ToolboxOpal_V11;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c23_DiSC_ToolboxOpal_V11_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_DiSC_ToolboxOpal_V11(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_DiSC_ToolboxOpal_V11(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_DiSC_ToolboxOpal_V11(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_DiSC_ToolboxOpal_V11_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
