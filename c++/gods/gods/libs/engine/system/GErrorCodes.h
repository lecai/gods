//
// Created by lecai on 14-6-5 上午10:20.
//
// To change the template use AppCode | Preferences | File Templates.
//

#include "GError.h"

G_DEFINE_ERROR( G_FAIL )
G_DEFINE_ERROR( G_APP_EXIT )

G_DEFINE_ERROR( G_ERR_SYS_MEMORY_ALLOC_FAIL )
G_DEFINE_ERROR( G_ERR_SYS_CONFIG_FILE_READ_FAIL )
G_DEFINE_ERROR( G_ERR_SYS_LOG_SYSTEM_INITIALIZE_FAIL )
G_DEFINE_ERROR( G_ERR_SYS_PROFILE_INITIALIZE_FAIL )
G_DEFINE_ERROR( G_ERR_SYS_INPUT_PARAMETER_WRONG )
G_DEFINE_ERROR( G_ERR_SYS_OBJECT_ALREADY_CREATED )
G_DEFINE_ERROR( G_ERR_SYS_TYPE_CASTING_FAIL )
G_DEFINE_ERROR( G_ERR_SYS_OPTION_FILE_READ_FAIL )

G_DEFINE_ERROR( G_ERR_DBC_HANDLE_ALREADY_ALLOCATED )
G_DEFINE_ERROR( G_ERR_DBC_HANDLE_IS_INVALID )
G_DEFINE_ERROR( G_ERR_DBC_ENVIRONMENT_ALLOC_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_ENVIRONMENT_SETATT_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_CONNECTION_ALLOC_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_CONNECTION_CONNECT_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_STATEMENT_ALLOC_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_STATEMENT_PREPARE_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_BIND_PAREMTER_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_BIND_COLUMN_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_CALL_SQLEXECUTE_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_CALL_SQLFETCH_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_CALL_SQLMORERESULT_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_DATABASE_FIND_FAIL )
G_DEFINE_ERROR( G_ERR_DBC_DATABASE_SQL_PRECREATE_FAIL )

G_DEFINE_ERROR( G_ERR_NET_NETWORK_ALREADY_CREATED )
G_DEFINE_ERROR( G_ERR_NET_NETWORK_NOT_CREATED )
G_DEFINE_ERROR( G_ERR_NET_ACCEPTOR_ALREADY_CREATED )
G_DEFINE_ERROR( G_ERR_NET_ACCEPTOR_ASSOCIATE_FAIL )
G_DEFINE_ERROR( G_ERR_NET_CONNECTOR_ALREADY_CREATED )
G_DEFINE_ERROR( G_ERR_NET_CONNECTOR_ASSOICATE_FAIL )
G_DEFINE_ERROR( G_ERR_NET_INVALID_COMPLETE_IO_MODE )
G_DEFINE_ERROR( G_ERR_NET_INVALID_COMPLETE_IO_HANDLE )

G_DEFINE_ERROR( G_ERR_NET_CONNECTION_CREATE_FAIL )
G_DEFINE_ERROR( G_ERR_NET_CONNECTION_POOL_ALLOC_FAIL )
G_DEFINE_ERROR( G_ERR_NET_CONNECTION_ADD_FAIL )
G_DEFINE_ERROR( G_ERR_NET_CONNECTION_REMOVE_FAIL )
G_DEFINE_ERROR( G_ERR_NET_CONNECTION_NOT_EXIST )
G_DEFINE_ERROR( G_ERR_NET_CONNECTION_IO_NOT_COMPLETED )
G_DEFINE_ERROR( G_ERR_NET_CONNECTION_STATUS_WRONG )
G_DEFINE_ERROR( G_ERR_NET_CONNECTION_SEND_FAIL )

G_DEFINE_ERROR( G_ERR_NET_SESSION_RECV_BUFFER_OVERFLOW )
G_DEFINE_ERROR( G_ERR_NET_SESSION_SEND_BUFFER_OVERFLOW )
G_DEFINE_ERROR( G_ERR_NET_SESSION_CREATE_FAIL )
G_DEFINE_ERROR( G_ERR_NET_SESSION_CLOSED )
G_DEFINE_ERROR( G_ERR_NET_SESSION_ADD_FAIL )

G_DEFINE_ERROR( G_ERR_NET_PACKET_INVALID )
G_DEFINE_ERROR( G_ERR_NET_PACKET_OPCODE_WRONG )
G_DEFINE_ERROR( G_ERR_NET_PACKET_ENCRYPT_FAIL )
G_DEFINE_ERROR( G_ERR_NET_PACKET_DECRYPT_FAIL )
G_DEFINE_ERROR( G_ERR_NET_PACKET_CHECKSUM_FAIL )
G_DEFINE_ERROR( G_ERR_NET_PACKET_SEQUENCE_FAIL )
G_DEFINE_ERROR( G_ERR_NET_PACKET_PENDING_HEADER )
G_DEFINE_ERROR( G_ERR_NET_PACKET_PENDING_DATA )
G_DEFINE_ERROR( G_ERR_NET_PACKET_EXCEED_ALLOWED_SIZE )

G_DEFINE_ERROR( G_ERR_NET_THREAD_CREATE_FAIL )
G_DEFINE_ERROR( G_ERR_THREAD_CREATE_FAIL )
G_DEFINE_ERROR( G_ERR_THREAD_POOL_CREATE_FAIL )
