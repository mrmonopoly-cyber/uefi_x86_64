#pragma once

#include "../../../basic_data_types.h"

typedef enum
{
 EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME_EFI_SUCCESS, //INFO: The function completed successfully.
 EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME_EFI_NOT_FOUND, //INFO: The next variable was not found.
 EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME_EFI_BUFFER_TOO_SMALL, ///INFO: The VariableNameSize is too small for the result. VariableNameSize has been updated with the size needed to complete the request.
 EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME_EFI_INVALID_PARAMETER, //INFO: VariableNameSize is NULL. | VariableName is NULL. | VendorGuid is NULL. | The input values of VariableName and VendorGuid are not a name and GUID of an existing variable. | Null-terminator is not found in the first VariableNameSize bytes of the input VariableName buffer.
 EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME_EFI_DEVICE_ERROR, //INFO: The variable name could not be retrieved due to a hardware error.
 EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME_EFI_UNSUPPORTED, //INFO:  After ExitBootServices() has been called, this return code may be returned if no variable storage is supported. The platform should describe this runtime service as unsupported at runtime via an EFI_RT_PROPERTIES_TABLE configuration table.
}EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME;
typedef EFI_STATUS_EFI_GET_NEXT_VARIABLE_NAME (*EFI_GET_NEXT_VARIABLE_NAME)(
    UINTN *VariableNameSize,
    CHAR16 *VariableName,
    EFI_GUID *VendorGuid);


