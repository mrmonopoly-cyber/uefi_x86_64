#pragma once

#include "../../../basic_data_types.h"

#include "event_types.h"

//******************************************************\*
// EFI_EVENT_NOTIFY
//******************************************************\*
typedef VOID (*EFI_EVENT_NOTIFY) (
    EFI_EVENT Event,
    VOID *Context
    );


typedef enum
{
  EFI_STATUS_EFI_CREATE_EVENT_EFI_SUCCESS, //INFO: The event structure was created.
  EFI_STATUS_EFI_CREATE_EVENT_EFI_INVALID_PARAMETER, /* //INFO:
                          * One of the parameters has an invalid value. 
                          * |
                          * Event is NULL.
                          * |
                          * Type has an unsupported bit set.
                          * |
                          * Type has both EVT_NOTIFY_SIGNAL and EVT_NOTIFY_WAIT set.
                          * |
                          * Type has either EVT_NOTIFY_SIGNAL or EVT_NOTIFY_WAIT set and NotifyFunction is NULL.
                          * | 
                          * Type has either EVT_NOTIFY_SIGNAL or EVT_NOTIFY_WAIT set and
                          * NotifyTpl is not a supported TPL level.
                          */
  EFI_STATUS_EFI_CREATE_EVENT_EFI_OUT_OF_RESOURCES, //INFO: The event could not be allocated.
}EFI_STATUS_EFI_CREATE_EVENT;
typedef EFI_STATUS_EFI_CREATE_EVENT (*EFI_CREATE_EVENT) (
    UINT32 Type,
    EFI_TPL NotifyTpl,
    EFI_EVENT_NOTIFY NotifyFunction,
    VOID *NotifyContext,
    EFI_EVENT *Event
    );

typedef enum
{
 EFI_STATUS_EFI_CREATE_EVENT_EX_EFI_SUCCESS, //INFO: The event structure was created.
 EFI_STATUS_EFI_CREATE_EVENT_EX_EFI_INVALID_PARAMETER, /* //INFO:
                                                        *
                                                        * One of the parameters has an invalid value.
                                                        * |
                                                        * Event is NULL.
                                                        * |
                                                        * Type has an unsupported bit set.
                                                        * |
                                                        * Type has both EVT_NOTIFY_SIGNAL and EVT_NOTIFY_WAIT set.
                                                        * |
                                                        * Type has either EVT_NOTIFY_SIGNAL or EVT_NOTIFY_WAIT set and
                                                        * Notiis NULL.
                                                        * |
                                                        * Type has either EVT_NOTIFY_SIGNAL or EVT_NOTIFY_WAIT set and
                                                        * NotifyTpl is not a supported TPL level.
                                                        */
 EFI_STATUS_EFI_CREATE_EVENT_EX_EFI_OUT_OF_RESOURCES, //INFO: The event could not be allocated.
}EFI_STATUS_EFI_CREATE_EVENT_EX;
typedef EFI_STATUS_EFI_CREATE_EVENT_EX (*EFI_CREATE_EVENT_EX) (
    UINT32 Type,
    EFI_TPL NotifyTpl,
    EFI_EVENT_NOTIFY NotifyFunction,
    const VOID *NotifyContext,
    const EFI_GUID *EventGroup,
    EFI_EVENT *Event
    );

typedef enum
{
  EFI_STATUS_EFI_CLOSE_EVENT_EFI_SUCCESS //INFO: The event has been closed.
}EFI_STATUS_EFI_CLOSE_EVENT;
typedef EFI_STATUS_EFI_CLOSE_EVENT(*EFI_CLOSE_EVENT) (EFI_EVENT Event);


typedef enum
{
  EFI_STATUS_EFI_SIGNAL_EVENT_EFI_SUCCESS //INFO: The event was signaled.
}EFI_STATUS_EFI_SIGNAL_EVENT;
typedef EFI_STATUS_EFI_SIGNAL_EVENT(*EFI_SIGNAL_EVENT) (EFI_EVENT Event);

typedef enum
{
  EFI_STATUS_EFI_WAIT_FOR_EVENT_EFI_SUCCESS, //INFO: The event indicated by Index was signaled.
  EFI_STATUS_EFI_WAIT_FOR_EVENT_EFI_UNSUPPORTED /* //INFO:
                                                 * NumberOfEvents is 0. 
                                                 * |
                                                 * The event indicated by Index is of type EVT_NOTIFY_SIGNAL.
                                                 * |
                                                 * The current TPL is not TPL_APPLICATION.
                                                 */
}EFI_STATUS_EFI_WAIT_FOR_EVENT;
typedef EFI_STATUS_EFI_WAIT_FOR_EVENT(*EFI_WAIT_FOR_EVENT) (UINTN NumberOfEventsw, EFI_EVENT *Event, UINTN *Index);

typedef enum
{
 EFI_STATUS_EFI_CHECK_EVENT_EFI_SUCCESS, //INFO: The event is in the signaled state.
 EFI_STATUS_EFI_CHECK_EVENT_EFI_NOT_READY, //INFO: The event is not in the signaled state.
 EFI_STATUS_EFI_CHECK_EVENT_EFI_INVALID_PARAMETER, //INFO: Event is of type EVT_NOTIFY_SIGNAL.
}EFI_STATUS_EFI_CHECK_EVENT;
typedef EFI_STATUS_EFI_CHECK_EVENT (*EFI_CHECK_EVENT) (EFI_EVENT Event);
