#pragma once

#include "../../../basic_data_types.h"
#include "../time_services/time_def.h"
#include "../../../digital_signature/digital_signature.h"

//
// EFI_VARIABLE_AUTHENTICATION_2 descriptor
//
// A time-based authentication method descriptor template
//
typedef struct {
EFI_TIME TimeStamp;
WIN_CERTIFICATE_UEFI_GUID AuthInfo;
} EFI_VARIABLE_AUTHENTICATION_2;

//
// EFI_VARIABLE_AUTHENTICATION_3 descriptor
//
// An extensible implementation of the Variable Authentication
// structure.
//
#define EFI_VARIABLE_AUTHENTICATION_3_TIMESTAMP_TYPE 1
#define EFI_VARIABLE_AUTHENTICATION_3_NONCE_TYPE 2
typedef struct {
  UINT8 Version;
  UINT8 Type;
  UINT32 MetadataSize;
  UINT32 Flags;
} EFI_VARIABLE_AUTHENTICATION_3;

//
// EFI_VARIABLE_AUTHENTICATION_3_NONCE descriptor
//
// A nonce-based authentication method descriptor template. This
// structure will always be followed by a
// WIN_CERTIFICATE_UEFI_GUID structure.
//
typedef struct {
  UINT32 NonceSize;
  // UINT8 Nonce[NonceSize];
} EFI_VARIABLE_AUTHENTICATION_3_NONCE;

typedef enum
{
 EFI_STATUS_EFI_SET_VARIABLE_EFI_SUCCESS, //INFO: The firmware has successfully stored the variable and its data as defined by the Attributes
 EFI_STATUS_EFI_SET_VARIABLE_EFI_INVALID_PARAMETER, //INFO: An invalid combination of attribute bits, name, and GUID was supplied, or the DataSize exceeds the maximum allowed. | VariableName is an empty string.
 EFI_STATUS_EFI_SET_VARIABLE_EFI_OUT_OF_RESOURCES, //INFO: Not enough storage is available to hold the variable and its data.
 EFI_STATUS_EFI_SET_VARIABLE_EFI_DEVICE_ERROR, //INFO: The variable could not be saved due to a hardware failure.
 EFI_STATUS_EFI_SET_VARIABLE_EFI_WRITE_PROTECTED, //INFO: The variable in question is read-only. | The variable in question cannot be deleted.
 EFI_STATUS_EFI_SET_VARIABLE_EFI_SECURITY_VIOLATION, /* //INFO: 
                           * The variable could not be written due to
                           * EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS or
                           * EFI_VARI ABLE_TIME_BASED_AUTHENTICATED_WRITE_ACESS
                           * being set, but the payload does NOT pass the validation check carried out
                           * by the firmware.
                           */
  EFI_STATUS_EFI_SET_VARIABLE_EFI_NOT_FOUND, //INFO: The variable trying to be updated or deleted was not found.
  EFI_STATUS_EFI_SET_VARIABLE_EFI_UNSUPPORTED,/* //INFO: 
                   * This call is not supported by this platform at the time the call is made. The
                   * platform should describe this runtime service as unsupported at runtime via
                   * an EFI_RT_PROPERTIES_TABLE configuration table.
                   */
}EFI_STATUS_EFI_SET_VARIABLE;

typedef EFI_STATUS_EFI_SET_VARIABLE (*EFI_SET_VARIABLE) (CHAR16 *VariableName,
    EFI_GUID *VendorGuid,
    UINT32 Attributes,
    UINTN DataSize,
    VOID *Data
    );
