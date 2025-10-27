#pragma once

#include "time_def.h"

typedef enum
{
 EFI_STATUS_EFI_SET_WAKEUP_TIME_EFI_SUCCESS, //INFO: If Enable is TRUE, then the wakeup alarm was enabled. If Enable is FALSE, then the wakeup alarm was disabled.
 EFI_STATUS_EFI_SET_WAKEUP_TIME_EFI_INVALID_PARAMETER, //INFO: A time field is out of range.
 EFI_STATUS_EFI_SET_WAKEUP_TIME_EFI_DEVICE_ERROR, //INFO: The wakeup time could not be set due to a hardware error.
 EFI_STATUS_EFI_SET_WAKEUP_TIME_EFI_UNSUPPORTED, //INFO: This call is not supported by this platform at the time the call is made. The platform should describe this runtime service as unsupported at runtime via an EFI_RT_PROPERTIES_TABLE configuration table.
}EFI_STATUS_EFI_SET_WAKEUP_TIME;
typedef EFI_STATUS_EFI_SET_WAKEUP_TIME (*EFI_SET_WAKEUP_TIME) (BOOLEAN *Enabled, EFI_TIME *Time);
