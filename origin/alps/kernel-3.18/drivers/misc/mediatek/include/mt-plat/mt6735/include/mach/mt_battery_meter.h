#ifndef _CUST_BATTERY_METER_H
#define _CUST_BATTERY_METER_H

#if defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F5B_JF)
	#include "mt_battery_meter_default.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F5B_FM)
	#include "mt_battery_meter_default_f5b_fm.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F5BP_GQ)
	#include "mt_battery_meter_default_f5bp_gq.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F1C_GQ)
	#include "mt_battery_meter_default_f1c_gq.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_NAME_FACTORY)
	#include "mt_battery_meter_default.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_A1)
	#include "mt_battery_meter_default_f200c_hz_a.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_B1) || defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_B2)
	#include "mt_battery_meter_default_f200c_hz_b.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_B3) && defined(LYCONFIG_AUTO_PLATFORM_NAME_F200C)
	#include "mt_battery_meter_default_f200c_hz_b3.h"
#elif defined(LYCONFIG_AUTO_PLATFORM_NAME_F200CS)
	#include "mt_battery_meter_default_f200c_hz_b3s.h"

#else
	#include "mt_battery_meter_default.h"
	//#error "PLEASE CONFIG LYCONFIG_COMB_CUST_PROJECT_NAME RIGHT!"
#endif

#if defined(CAR_TUNE_VALUE)
#undef CAR_TUNE_VALUE
#endif

#if defined(LYCONFIG_AUTO_PLATFORM_NAME_F5B) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5BP)|| defined(LYCONFIG_AUTO_PLATFORM_NAME_F5BS) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5BPS)
	#if defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F5B_FM)
	#define CAR_TUNE_VALUE		75
	#else
	#define CAR_TUNE_VALUE		85
	#endif
#elif defined(LYCONFIG_AUTO_PLATFORM_NAME_F1C) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F1CS)
	#define CAR_TUNE_VALUE		88
#else
	#define CAR_TUNE_VALUE		85
#endif

#define DISABLE_RFG_EXIST_CHECK

#endif	/*#ifndef _CUST_BATTERY_METER_H*/
