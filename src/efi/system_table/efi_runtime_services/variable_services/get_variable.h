#pragma once

#include "../../../basic_data_types.h"

//******************************************************
// Variable Attributes
//******************************************************
#define EFI_VARIABLE_NON_VOLATILE 0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS 0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD 0x00000008 //INFO: This attribute is identified by the mnemonic 'HR' elsewhere in this specification.
//Reserved 0x00000010
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 0x00000020
#define EFI_VARIABLE_APPEND_WRITE 0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS 0x00000080
//This attribute indicates that the variable payload begins
//with an EFI_VARIABLE_AUTHENTICATION_3 structure, and
//potentially more structures as indicated by fields of this
//structure. See definition below and in SetVariable().

//
// EFI_VARIABLE_AUTHENTICATION_3_CERT_ID descriptor
//
// An extensible structure to identify a unique x509 cert
// associated with a given variable
//
#define EFI_VARIABLE_AUTHENTICATION_3_CERT_ID_SHA256 1
typedef struct {
  UINT8 Type;
  UINT32 IdSize;
  // UINT8 Id[IdSize];
}EFI_VARIABLE_AUTHENTICATION_3_CERT_ID;

typedef enum
{
  EFI_SUCCESS, //INFO: The function completed successfully.
  EFI_NOT_FOUND, //INFO: The variable was not found.
  EFI_BUFFER_TOO_SMALL, //INFO: The DataSize is too small for the result. DataSize has been updated with the size needed to complete the request. If Attributes is not NULL, then the attributes bitmask for the variable has been stored to the memory location pointed-to by Attributes.
  EFI_INVALID_PARAMETER, //INFO: VariableName is NULL. | VendorGuid is NULL. | DataSize is NULL.
  EFI_DEVICE_ERROR, //INFO: The variable could not be retrieved due to a hardware error.
  EFI_SECURITY_VIOLATION, //INFO: The variable could not be retrieved due to an authentication failure.
  EFI_UNSUPPORTED, //INFO: After ExitBootServices() has been called, this return code may be returned if no variable storage is supported. The platform should describe this runtime service as unsupported at runtime via an EFI_RT_PROPERTIES_TABLE configuration table.
}EFI_STATUS_EFI_GET_VARIABLE;

typedef EFI_STATUS_EFI_GET_VARIABLE (*EFI_GET_VARIABLE) (CHAR16 *VariableName,
    EFI_GUID *VendorGuid,
    UINT32 *Attributes,
    UINTN *DataSize,
    VOID *Data
    );
