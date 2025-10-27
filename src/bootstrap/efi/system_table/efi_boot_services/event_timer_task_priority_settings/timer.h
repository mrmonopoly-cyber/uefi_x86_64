#pragma once

#include "../../../basic_data_types.h"
#include "event_types.h"

//******************************************************
//EFI_TIMER_DELAY
//******************************************************
typedef enum {
  TimerCancel,
  TimerPeriodic,
  TimerRelative
} EFI_TIMER_DELAY;

typedef enum
{
 EFI_STATUS_EFI_SET_TIMER_EFI_SUCCESS, //INFO: The event has been set to be signaled at the requested time.
 EFI_STATUS_EFI_SET_TIMER_EFI_INVALID_PARAMETER, //INFO:  Event or Type is not valid.
}EFI_STATUS_EFI_SET_TIMER;
typedef EFI_STATUS_EFI_SET_TIMER(*EFI_SET_TIMER) (EFI_EVENT Event,
    EFI_TIMER_DELAY Type,
    UINT64 TriggerTime);
