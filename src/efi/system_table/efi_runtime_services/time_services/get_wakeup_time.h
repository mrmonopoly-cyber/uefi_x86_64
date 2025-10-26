#pragma once

#include "time_def.h"

typedef enum
{
 EFI_STATUS_EFI_GET_WAKEUP_TIME_EFI_SUCCESS, //INFO: The alarm settings were returned.
 EFI_STATUS_EFI_GET_WAKEUP_TIME_EFI_INVALID_PARAMETER, //INFO: Enabled is NULL. | Pending is NULL. | Time is NULL.
 EFI_STATUS_EFI_GET_WAKEUP_TIME_EFI_DEVICE_ERROR, //INFO: The wakeup time could not be retrieved due to a hardware error.
 EFI_STATUS_EFI_GET_WAKEUP_TIME_EFI_UNSUPPORTED, //INFO: This call is not supported by this platform at the time the call is made. The platform should describe this runtime service as unsupported at runtime via an EFI_RT_PROPERTIES_TABLE configuration table.
}EFI_STATUS_EFI_GET_WAKEUP_TIME;
typedef EFI_STATUS_EFI_GET_WAKEUP_TIME (*EFI_GET_WAKEUP_TIME) (BOOLEAN *Enabled,
    BOOLEAN *Pending, 
    EFI_TIME *Time);
