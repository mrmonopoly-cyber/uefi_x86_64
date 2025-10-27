#pragma once

//INFO: Protocol Handler Services, Section 7.3

#include <input_vars_attributes.h>

#include "../../../protocols/protocols.h"
#include "protocol_handler_types.h"

typedef enum
{
 EFI_STATUS_EFI_INSTALL_PROTOCOL_INTERFACE_EFI_SUCCESS, //INFO: The protocol interface was installed.
 EFI_STATUS_EFI_INSTALL_PROTOCOL_INTERFACE_EFI_OUT_OF_RESOURCES, //INFO: Space for a new handle could not be allocated.
 EFI_STATUS_EFI_INSTALL_PROTOCOL_INTERFACE_EFI_INVALID_PARAMETER, /* //INFO: 
                                                                   *
                                                                   * HandLe is NULL 
                                                                   * |
                                                                   * ProtocoL is NULL.
                                                                   * |
                                                                   * InterfaceType is not EFI_NATIVE_INTERFACE.
                                                                   * |
                                                                   * ProtocoL is already installed on the handle specified by HandLe.
                                                                   */
}EFI_STATUS_EFI_INSTALL_PROTOCOL_INTERFACE;
typedef EFI_STATUS_EFI_INSTALL_PROTOCOL_INTERFACE(*EFI_INSTALL_PROTOCOL_INTERFACE) (
    EFI_HANDLE *Handle,
    EFI_GUID *Protocol,
    EFI_INTERFACE_TYPE InterfaceType,
    VOID *Interface
    );

typedef enum
{
 EFI_STATUS_EFI_UNINSTALL_PROTOCOL_INTERFACE_EFI_SUCCESS, //INFO: The interface was removed.
 EFI_STATUS_EFI_UNINSTALL_PROTOCOL_INTERFACE_EFI_NOT_FOUND, //INFO: The interface was not found.
 EFI_STATUS_EFI_UNINSTALL_PROTOCOL_INTERFACE_EFI_ACCESS_DENIED, //INFO: The interface was not removed because the interface is still being used by a driver.
 EFI_STATUS_EFI_UNINSTALL_PROTOCOL_INTERFACE_EFI_INVALID_PARAMETER, //INFO: HandLe is NULL. | ProtocoL is NULL.
}EFI_STATUS_EFI_UNINSTALL_PROTOCOL_INTERFACE;
typedef EFI_STATUS_EFI_UNINSTALL_PROTOCOL_INTERFACE(*EFI_UNINSTALL_PROTOCOL_INTERFACE) (
    EFI_HANDLE Handle,
    EFI_GUID *Protocol,
    VOID *Interface);

typedef enum
{
 EFI_STATUS_EFI_REINSTALL_PROTOCOL_INTERFACE_EFI_SUCCESS, //INFO: The protocol interface was reinstalled.
 EFI_STATUS_EFI_REINSTALL_PROTOCOL_INTERFACE_EFI_NOT_FOUND, //INFO: The OldInterface on the handle was not found.
 EFI_STATUS_EFI_REINSTALL_PROTOCOL_INTERFACE_EFI_ACCESS_DENIED, //INFO: The protocol interface could not be reinstalled, because OldInterface is still being used by a driver that will not release it.
 EFI_STATUS_EFI_REINSTALL_PROTOCOL_INTERFACE_EFI_INVALID_PARAMETER, //INFO: HandLe is NULL. | ProtocoL is NULL.
}EFI_STATUS_EFI_REINSTALL_PROTOCOL_INTERFACE;
typedef EFI_STATUS_EFI_REINSTALL_PROTOCOL_INTERFACE(*EFI_REINSTALL_PROTOCOL_INTERFACE) (
    EFI_HANDLE Handle,
    EFI_GUID *Protocol,
    VOID *OldInterface,
    VOID *NewInterface
    );


typedef enum
{
 EFI_STATUS_EFI_REGISTER_PROTOCOL_NOTIFY_EFI_SUCCESS, //INFO: The notification event has been registered.
 EFI_STATUS_EFI_REGISTER_PROTOCOL_NOTIFY_EFI_OUT_OF_RESOURCES, //INFO: Space for the notification event could not be allocated.
 EFI_STATUS_EFI_REGISTER_PROTOCOL_NOTIFY_EFI_INVALID_PARAMETER, //INFO: Protocol is NULL. | Event is NULL. | Registration is NULL.
}EFI_STATUS_EFI_REGISTER_PROTOCOL_NOTIFY;
typedef EFI_STATUS_EFI_REGISTER_PROTOCOL_NOTIFY(*EFI_REGISTER_PROTOCOL_NOTIFY) (
    EFI_GUID *Protocol,
    EFI_EVENT Event,
    VOID **Registration
    );

typedef enum
{
 EFI_STATUS_EFI_LOCATE_HANDLE_EFI_SUCCESS, //INFO: The array of handles was returned.
 EFI_STATUS_EFI_LOCATE_HANDLE_EFI_NOT_FOUND, //INFO: No handles match the search.
 EFI_STATUS_EFI_LOCATE_HANDLE_EFI_BUFFER_TOO_SMALL, //INFO: The BufferSize is too small for the result. BufferSize has been updated with the size needed to complete the request.
 EFI_STATUS_EFI_LOCATE_HANDLE_EFI_INVALID_PARAMETER, /* //INFO:
                                                      *
                                                      * SearchType is not a member of EFI_LOCATE_SEARCH_TYPE.
                                                      * |
                                                      * SearchType is ByRegisterNotify and SearchKey is NULL.
                                                      * |
                                                      * SearchType is ByProtocol and ProtocoL is NULL.
                                                      * |
                                                      * One or more matches are found and BufferSize is NULL.
                                                      * |
                                                      * BufferSize is large enough for the result and Buffer is NULL.
                                                      */
}EFI_STATUS_EFI_LOCATE_HANDLE;
typedef EFI_STATUS_EFI_LOCATE_HANDLE(*EFI_LOCATE_HANDLE) (EFI_LOCATE_SEARCH_TYPE SearchType,
    EFI_GUID *Protocol,
    VOID *SearchKey,
    UINTN *BufferSize,
    EFI_HANDLE *Buffer
    );

typedef enum
{
  EFI_STATUS_EFI_HANDLE_PROTOCOL_EFI_SUCCESS, //INFO: The interface information for the specified protocol was returned.
  EFI_STATUS_EFI_HANDLE_PROTOCOL_EFI_UNSUPPORTED, //INFO: The device does not support the specified protocol.
  EFI_STATUS_EFI_HANDLE_PROTOCOL_EFI_INVALID_PARAMETER,//INFO: Handle is NULL. | Protocol is NULL. | Interface is NULL.
}EFI_STATUS_EFI_HANDLE_PROTOCOL;
typedef EFI_STATUS_EFI_HANDLE_PROTOCOL(*EFI_HANDLE_PROTOCOL) (EFI_HANDLE Handle,
    EFI_GUID *Protocol,
    VOID **Interface);

typedef enum
{
 EFI_STATUS_EFI_LOCATE_DEVICE_PATH_EFI_SUCCESS, //INFO: The resulting handle was returned.
 EFI_STATUS_EFI_LOCATE_DEVICE_PATH_EFI_NOT_FOUND, //INFO: No handles matched the search.
 EFI_STATUS_EFI_LOCATE_DEVICE_PATH_EFI_INVALID_PARAMETER, //INFO: Protocol is NULL | DevicePath is NULL. | A handle matched the search and Device is NULL.
}EFI_STATUS_EFI_LOCATE_DEVICE_PATH;
typedef EFI_STATUS_EFI_LOCATE_DEVICE_PATH(*EFI_LOCATE_DEVICE_PATH) ( EFI_GUID *Protocol,
    EFI_DEVICE_PATH_PROTOCOL **DevicePath,
    EFI_HANDLE *Device);

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL 0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL 0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL 0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER 0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE 0x00000020
typedef enum
{
EFI_STATUS_EFI_OPEN_PROTOCOL_EFI_SUCCESS, //INFO: An item was added to the open list for the protocol interface, and the protocol interface was returned in Interface.
EFI_STATUS_EFI_OPEN_PROTOCOL_EFI_INVALID_PARAMETER, /* //INFO:
                                                     * 
                                                     * Protocol is NULL.
                                                     * |
                                                     * Interface is NULL, and Attributes is not TEST_PROTOCOL.
                                                     * |
                                                     * Handle is NULL.
                                                     * |
                                                     * Attributes is not a legal value.
                                                     * |
                                                     * Attributes is BY_CHILD_CONTROLLER and AgentHandle is NULL.
                                                     * |
                                                     * Attributes is BY_DRIVER and AgentHandle is NULL.
                                                     * |
                                                     * Attribute is BY_DRIVEREXCLUSIVE and AgentHandle is NULL.
                                                     * |
                                                     * Attributes is EXCLUSIVE and AgentHandle is NULL.
                                                     * |
                                                     * Attributes is BY_CHILD_CONTROLLER and ControllerHandle is NULL.
                                                     * |
                                                     * Attributes is BY_DRIVER and ControllerHandle is NULL.
                                                     * |
                                                     * Attributes is BY_DRIVEREXCLUSIVE and ControllerHandle is NULL.
                                                     * |
                                                     * Attributes is BY_CHILD_CONTROLLER and Handle is identical to Con-trollerHand.
                                                     */
EFI_STATUS_EFI_OPEN_PROTOCOL_EFI_UNSUPPORTED, //INFO: Handle does not support Protocol.
EFI_STATUS_EFI_OPEN_PROTOCOL_EFI_ACCESS_DENIED, /* //INFO:
                                                 *
                                                 * Attributes is BY_DRIVER and there is an item on the open list with an attribute of BY_DRIVEREXCLUSIVE or EXCLUSIVE.
                                                 * |
                                                 * Attributes is BY_DRIVEREXCLUSIVE and there is an item on the open list with an attribute of EXCLUSIVE.
                                                 * |
                                                 * Attributes is EXCLUSIVE and there is an item on the open list with an attribute of BY_DRIVEREXCLUSIVE or EXCLUSIVE.
                                                 * |
                                                 * Attributes is BY_DRIVER and there is an item on the open list with an attribute of BY_DRIVER whose agent handle is different than AgentHandle.
                                                 * |
                                                 * Attributes is BY_DRIVEREXCLUSIVE and there is an item on the openlist with an attribute of BY_DRIVEREXCLUSIVE whose agent handle is different than AgentHandle.
                                                 * | 
                                                 * Attributes is BY_DRIVEREXCLSUIVE or EXCLUSIVE and there are items in the open list with an attribute of BY_DRIVER that could not be removed when EFI_BOOT_SERVICES.DisconnectController() was called for that open item.
                                                 */
EFI_STATUS_EFI_OPEN_PROTOCOL_EFI_ALREADY_STARTED,/* //INFO:
                                                  *
                                                  * Attributes is BY_DRIVER and there is an item on the open list with an attribute of BY_DRIVER whose agent handle is the same as AgentHandle.
                                                  * |
                                                  * Attributes is BY_DRIVEREXCLUSIVE and there is an item on the open list with an attribute of BY_DRIVEREXCLUSIVE whose agent handle is the same as AgentHandle.
                                                  */
}EFI_STATUS_EFI_OPEN_PROTOCOL;
typedef EFI_STATUS_EFI_OPEN_PROTOCOL(*EFI_OPEN_PROTOCOL) (EFI_HANDLE Handle,
    EFI_GUID *Protocol,
    VOID **Interface,
    EFI_HANDLE AgentHandle,
    EFI_HANDLE ControllerHandle,
    UINT32 Attributes);

typedef enum
{
 EFI_STATUS_EFI_CLOSE_PROTOCOL_EFI_SUCCESS, //INFO: The protocol instance was closed.
 EFI_STATUS_EFI_CLOSE_PROTOCOL_EFI_INVALID_PARAMETER, //INFO: Handle is NULL. | AgentHandle is NULL. | ControllerHandle is not NULL and ControllerHandle is NULL. | Protocol is NULL.
 EFI_STATUS_EFI_CLOSE_PROTOCOL_EFI_NOT_FOUND, //INFO: Handle does not support the protocol specified by Protocol. | The protocol interface specified by Handle and Protocol is not currently open by AgentHandle and ControllerHandle.
}EFI_STATUS_EFI_CLOSE_PROTOCOL;
typedef EFI_STATUS_EFI_CLOSE_PROTOCOL (*EFI_CLOSE_PROTOCOL) (
    EFI_HANDLE Handle,
    EFI_GUID *Protocol,
    EFI_HANDLE AgentHandle,
    EFI_HANDLE ControllerHandle);

typedef enum
{
 EFI_STATUS_EFI_OPEN_PROTOCOL_INFORMATION_EFI_SUCCESS, //INFO: The open protocol information was returned in EntryBuffer, and the number of entries was returned EntryCount.
 EFI_STATUS_EFI_OPEN_PROTOCOL_INFORMATION_EFI_NOT_FOUND, //INFO: Handle does not support the protocol specified by Protocol.
 EFI_STATUS_EFI_OPEN_PROTOCOL_INFORMATION_EFI_OUT_OF_RESOURCES, //INFO: There are not enough resources available to allocate EntryBuffer.
}EFI_STATUS_EFI_OPEN_PROTOCOL_INFORMATION;
typedef EFI_STATUS_EFI_OPEN_PROTOCOL_INFORMATION(*EFI_OPEN_PROTOCOL_INFORMATION) (
    EFI_HANDLE Handle,
    EFI_GUID *Protocol,
    EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
    UINTN *EntryCount
    );

typedef enum
{
 EFI_STATUS_EFI_CONNECT_CONTROLLER_EFI_SUCCESS, //INFO: One or more drivers were connected to ControllerHandle. | No drivers were connected to ControllerHandle, but RemainingDevicePath is not NULL, and it is an End Device Path Node.
 EFI_STATUS_EFI_CONNECT_CONTROLLER_EFI_INVALID_PARAMETER, //INFO: ControllerHandle is NULL.
 EFI_STATUS_EFI_CONNECT_CONTROLLER_EFI_NOT_FOUND, //INFO: There are no EFI_DRIVER_BINDING_PROTOCOL instances present in the system. | No drivers were connected to ControllerHandle.
 EFI_STATUS_EFI_CONNECT_CONTROLLER_EFI_SECURITY_VIOLATION, //INFO: The user has no permission to start UEFI device drivers on the device path associated with the ControllerHandle or specified by the RemainingDevicePath.
}EFI_STATUS_EFI_CONNECT_CONTROLLER;
typedef EFI_STATUS_EFI_CONNECT_CONTROLLER(*EFI_CONNECT_CONTROLLER) (
    EFI_HANDLE ControllerHandle, 
    EFI_HANDLE *DriverImageHandle,
    EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath,
    BOOLEAN Recursive);


typedef enum
{
  EFI_STATUS_EFI_DISCONNECT_CONTROLLER_EFI_SUCCESS,/* //INFO:
                                                    *
                                                    * One or more drivers were disconnected from the controller.
                                                    * |
                                                    * On entry, no drivers are managing ControllerHandle.
                                                    * |
                                                    * DriverImageHandle is not NULL, and on entry DriverImageHandle is not managing ControllerHandle.
                                                    */
  EFI_STATUS_EFI_DISCONNECT_CONTROLLER_EFI_INVALID_PARAMETER, /* //INFO: 
                                                               * 
                                                               * ControllerHandle is NULL.
                                                               * | 
                                                               * DriverImageHandle is not NULL, and it is not a valid EFI_HANDLE.
                                                               * |
                                                               * ChildHandle is not NULL, and it is not a valid EFI_HANDLE.
                                                               * |
                                                               * DriverImageHandle does not support the EFI_DRIVER_BINDING_PROTOCOL.
                                                               */
  EFI_STATUS_EFI_DISCONNECT_CONTROLLER_EFI_OUT_OF_RESOURCES, //INFO: There are not enough resources available to disconnect any drivers from ControllerHandle.
  EFI_STATUS_EFI_DISCONNECT_CONTROLLER_EFI_DEVICE_ERROR, //INFO: The controller could not be disconnected because of a device error.
}EFI_STATUS_EFI_DISCONNECT_CONTROLLER;
typedef EFI_STATUS_EFI_DISCONNECT_CONTROLLER(*EFI_DISCONNECT_CONTROLLER) (
    EFI_HANDLE ControllerHandle,
    EFI_HANDLE DriverImageHandle,
    EFI_HANDLE ChildHandle);

typedef enum
{
 EFI_STATUS_EFI_PROTOCOLS_PER_HANDLE_EFI_SUCCESS, //INFO: The list of protocol interface GUIDs installed on Handle was returned in ProtocolBuffer. The number of protocol interface GUIDs was returned in ProtocolBufferCount.
 EFI_STATUS_EFI_PROTOCOLS_PER_HANDLE_EFI_INVALID_PARAMETER, //INFO: Handle is NULL. | ProtocolBuffer is NULL. | ProtocolBufferCount is NULL.
 EFI_STATUS_EFI_PROTOCOLS_PER_HANDLE_EFI_OUT_OF_RESOURCES, //INFO: There is not enough pool memory to store the results.
}EFI_STATUS_EFI_PROTOCOLS_PER_HANDLE;
typedef EFI_STATUS_EFI_PROTOCOLS_PER_HANDLE(*EFI_PROTOCOLS_PER_HANDLE) (
    EFI_HANDLE Handle,
    EFI_GUID ***ProtocolBuffer,
    UINTN *ProtocolBufferCount
    );

typedef enum
{
 EFI_STATUS_EFI_LOCATE_HANDLE_BUFFER_EFI_SUCCESS, //INFO: The array of handles was returned in Buffer, and the number of handles in Buffer was returned in NoHandles.
 EFI_STATUS_EFI_LOCATE_HANDLE_BUFFER_EFI_INVALID_PARAMETER, //INFO: NoHandles is NULL | Buffer is NULL
 EFI_STATUS_EFI_LOCATE_HANDLE_BUFFER_EFI_NOT_FOUND, //INFO: No handles match the search.
 EFI_STATUS_EFI_LOCATE_HANDLE_BUFFER_EFI_OUT_OF_RESOURCES, //INFO: There is not enough pool memory to store the matching results.
}EFI_STATUS_EFI_LOCATE_HANDLE_BUFFER;
typedef EFI_STATUS_EFI_LOCATE_HANDLE_BUFFER(*EFI_LOCATE_HANDLE_BUFFER) (
    EFI_LOCATE_SEARCH_TYPE SearchType,
    EFI_GUID *Protocol OPTIONAL,
    VOID *SearchKey OPTIONAL,
    UINTN *NoHandles,
    EFI_HANDLE **Buffer
    );

typedef enum
{
 EFI_STATUS_EFI_LOCATE_PROTOCOL_EFI_SUCCESS, //INFO: A protocol instance matching Protocol was found and returned in Interface.
 EFI_STATUS_EFI_LOCATE_PROTOCOL_EFI_INVALID_PARAMETER, //INFO: Interface is NULL. Protocol is NULL.
 EFI_STATUS_EFI_LOCATE_PROTOCOL_EFI_NOT_FOUND, //INFO: No protocol instances were found that match Protocol and Registration.
}EFI_STATUS_EFI_LOCATE_PROTOCOL;
typedef EFI_STATUS_EFI_LOCATE_PROTOCOL(*EFI_LOCATE_PROTOCOL) (
    EFI_GUID *Protocol,
    VOID *Registration OPTIONAL,
    VOID **Interface);

typedef enum
{
 EFI_STATUS_EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES_EFI_SUCCESS, //INFO: All the protocol interfaces were installed.
 EFI_STATUS_EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES_EFI_ALREADY_STARTED, //INFO: A Device Path Protocol instance was passed in that is already present in the handle database.
 EFI_STATUS_EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES_EFI_OUT_OF_RESOURCES, //INFO: There was not enough memory in pool to install all the protocols.
 EFI_STATUS_EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES_EFI_INVALID_PARAMETER, //INFO: Handle is NULL. | Protocol is already installed on the handle specified by Handle.
}EFI_STATUS_EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES;
typedef EFI_STATUS_EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES(*EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
EFI_HANDLE *Handle, ...);

typedef enum
{
 EFI_STATUS_EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES_EFI_SUCCESS, //INFO: All the protocol interfaces were removed.
 EFI_STATUS_EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES_EFI_INVALID_PARAMETER, //INFO: One of the protocol interfaces was not previously installed on Handle.
}EFI_STATUS_EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES;
typedef EFI_STATUS_EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES(*EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
EFI_HANDLE *Handle, ...);
