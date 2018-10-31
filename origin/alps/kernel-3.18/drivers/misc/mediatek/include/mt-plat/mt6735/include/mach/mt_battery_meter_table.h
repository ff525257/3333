#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#if defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F5B_JF)
	#include "mt_battery_meter_table_default.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F5BP_GQ)
	#include "mt_battery_meter_table_default_f5bp_gq.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F5B_FM)
	#include "mt_battery_meter_table_default_f5b_fm.h"		
#elif defined(LYCONFIG_COMB_CUST_PROJECT_NAME_F1C_GQ)
	#include "mt_battery_meter_table_default_f1c_gq.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_B3)	&&	defined(LYCONFIG_AUTO_PLATFORM_NAME_F200C)	//hjp add 11-15
	#include "mt_battery_meter_table_default_f200c_hz_b3.h"
	
#elif defined(LYCONFIG_AUTO_PLATFORM_NAME_F200CS)
	#include "mt_battery_meter_table_default_f200c_hz_b3s.h"

#elif defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_A1)
	#include "mt_battery_meter_table_default_f200c_hz_copy.h"
#elif defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_B1) || defined(LYCONFIG_COMB_CUST_PROJECT_SUB_NAME_F200C_HZ_B2)
	#include "mt_battery_meter_table_default_f200c_hz_copy.h"
#else 
	#include "mt_battery_meter_table_default.h"
#endif

#endif	/*#ifndef _CUST_BATTERY_METER_TABLE_H*/

