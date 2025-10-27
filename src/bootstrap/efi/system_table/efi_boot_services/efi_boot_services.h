#pragma once

//INFO: EFI_BOOT_SERVICES, Section 4.4.1

#include "../../basic_data_types.h"

#include "event_timer_task_priority_settings/event_timer_task_priority_settings.h"
#include "memory_services/memory_services.h"
#include "protocol_handler/protocol_handler.h"
#include "miscellaneous_boot_services/miscellaneous_boot_services.h"
#include "image_services/image_services.h"

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

typedef struct {
EFI_TABLE_HEADER Hdr;

//
// Task Priority Services
//
EFI_RAISE_TPL RaiseTPL; // EFI 1.0+
EFI_RESTORE_TPL RestoreTPL; // EFI 1.0+

//
// Memory Services
//
EFI_ALLOCATE_PAGES AllocatePages;
EFI_FREE_PAGES FreePages;
EFI_GET_MEMORY_MAP GetMemoryMap;
EFI_ALLOCATE_POOL AllocatePool;
EFI_FREE_POOL FreePool;// EFI 1.0+

//
// Event & Timer Services
//
EFI_CREATE_EVENT CreateEvent;// EFI 1.0+
EFI_SET_TIMER SetTimer;// EFI 1.0+
EFI_WAIT_FOR_EVENT WaitForEvent;// EFI 1.0+
EFI_SIGNAL_EVENT SignalEvent;// EFI 1.0+
EFI_CLOSE_EVENT CloseEvent;// EFI 1.0+
EFI_CHECK_EVENT CheckEvent;// EFI 1.0+

//
// Protocol Handler Services
//
EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface; // EFI 1.0+
EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface; // EFI 1.0+
EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface; // EFI 1.0+
EFI_HANDLE_PROTOCOL HandleProtocol; // EFI 1.0+
VOID* Reserved; // EFI 1.0+

//
//Miscellaneous Boot Services
//
EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify; // EFI 1.0+
EFI_LOCATE_HANDLE LocateHandle; // EFI 1.0+
EFI_LOCATE_DEVICE_PATH LocateDevicePath; // EFI 1.0+
EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable; // EFI 1.0+

//
// Image Services
//
EFI_IMAGE_LOAD LoadImage; // EFI 1.0+
EFI_IMAGE_START StartImage; // EFI 1.0+
EFI_EXIT Exit; // EFI 1.0+
EFI_IMAGE_UNLOAD UnloadImage; // EFI 1.0+
EFI_EXIT_BOOT_SERVICES ExitBootServices; // EFI 1.0+

//
// Miscellaneous Services
//
EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount; // EFI 1.0+
EFI_STALL Stall;  // EFI 1.0+
EFI_SET_WATCHDOG_TIMER SetWatchdogTimer; // EFI 1.0+

//
// DriverSupport Services
//
EFI_CONNECT_CONTROLLER ConnectController; // EFI 1.1
EFI_DISCONNECT_CONTROLLER DisconnectController; // EFI 1.1+

//
// Open and Close Protocol Services
//
EFI_OPEN_PROTOCOL OpenProtocol; // EFI 1.1+
EFI_CLOSE_PROTOCOL CloseProtocol; // EFI 1.1+
EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;// EFI 1.1+

//
// Library Services
//
EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle; // EFI 1.1+
EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer; // EFI 1.1+
EFI_LOCATE_PROTOCOL LocateProtocol; // EFI 1.1+
EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;// EFI 1.1+
EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces; // EFI 1.1+*

//
// 32-bit CRC Services
//
EFI_CALCULATE_CRC32 CalculateCrc32;

//
// Miscellaneous Services
//
EFI_COPY_MEM CopyMem;
EFI_SET_MEM SetMem;
EFI_CREATE_EVENT_EX CreateEventEx;
}EFI_BOOT_SERVICES;
