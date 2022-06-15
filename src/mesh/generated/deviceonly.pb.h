/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_DEVICEONLY_PB_H_INCLUDED
#define PB_DEVICEONLY_PB_H_INCLUDED
#include <pb.h>
#include "channel.pb.h"
#include "mesh.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* TODO: REPLACE */
typedef enum _ScreenFonts { 
    /* TODO: REPLACE */
    ScreenFonts_FONT_SMALL = 0, 
    /* TODO: REPLACE */
    ScreenFonts_FONT_MEDIUM = 1, 
    /* TODO: REPLACE */
    ScreenFonts_FONT_LARGE = 2 
} ScreenFonts;

/* Struct definitions */
/* The on-disk saved channels */
typedef struct _ChannelFile { 
    /* The channels our node knows about */
    pb_size_t channels_count;
    Channel channels[8]; 
    /* A version integer used to invalidate old save files when we make
 incompatible changes This integer is set at build time and is private to
 NodeDB.cpp in the device code. */
    uint32_t version; 
} ChannelFile;

/* This message is never sent over the wire, but it is used for serializing DB
 state to flash in the device code
 FIXME, since we write this each time we enter deep sleep (and have infinite
 flash) it would be better to use some sort of append only data structure for
 the receive queue and use the preferences store for the other stuff */
typedef struct _DeviceState { 
    /* Read only settings/info about this node */
    bool has_my_node;
    MyNodeInfo my_node; 
    /* My owner info */
    bool has_owner;
    User owner; 
    /* TODO: REPLACE */
    pb_size_t node_db_count;
    NodeInfo node_db[80]; 
    /* Received packets saved for delivery to the phone */
    pb_size_t receive_queue_count;
    MeshPacket receive_queue[1]; 
    /* A version integer used to invalidate old save files when we make
 incompatible changes This integer is set at build time and is private to
 NodeDB.cpp in the device code. */
    bool has_rx_text_message;
    MeshPacket rx_text_message; 
    /* We keep the last received text message (only) stored in the device flash,
 so we can show it on the screen.
 Might be null */
    uint32_t version; 
    /* Used only during development.
 Indicates developer is testing and changes should never be saved to flash. */
    bool no_save; 
    /* Some GPSes seem to have bogus settings from the factory, so we always do one factory reset. */
    bool did_gps_reset; 
} DeviceState;

typedef PB_BYTES_ARRAY_T(2048) OEMStore_oem_icon_bits_t;
/* This can be used for customizing the firmware distribution. If populated,
 show a secondary bootup screen with cuatom logo and text for 2.5 seconds. */
typedef struct _OEMStore { 
    /* The Logo width in Px */
    uint32_t oem_icon_width; 
    /* The Logo height in Px */
    uint32_t oem_icon_height; 
    /* The Logo in xbm bytechar format */
    OEMStore_oem_icon_bits_t oem_icon_bits; 
    /* Use this font for the OEM text. */
    ScreenFonts oem_font; 
    /* Use this font for the OEM text. */
    char oem_text[40]; 
} OEMStore;


/* Helper constants for enums */
#define _ScreenFonts_MIN ScreenFonts_FONT_SMALL
#define _ScreenFonts_MAX ScreenFonts_FONT_LARGE
#define _ScreenFonts_ARRAYSIZE ((ScreenFonts)(ScreenFonts_FONT_LARGE+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define DeviceState_init_default                 {false, MyNodeInfo_init_default, false, User_init_default, 0, {NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default}, 0, {MeshPacket_init_default}, false, MeshPacket_init_default, 0, 0, 0}
#define ChannelFile_init_default                 {0, {Channel_init_default, Channel_init_default, Channel_init_default, Channel_init_default, Channel_init_default, Channel_init_default, Channel_init_default, Channel_init_default}, 0}
#define OEMStore_init_default                    {0, 0, {0, {0}}, _ScreenFonts_MIN, ""}
#define DeviceState_init_zero                    {false, MyNodeInfo_init_zero, false, User_init_zero, 0, {NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero}, 0, {MeshPacket_init_zero}, false, MeshPacket_init_zero, 0, 0, 0}
#define ChannelFile_init_zero                    {0, {Channel_init_zero, Channel_init_zero, Channel_init_zero, Channel_init_zero, Channel_init_zero, Channel_init_zero, Channel_init_zero, Channel_init_zero}, 0}
#define OEMStore_init_zero                       {0, 0, {0, {0}}, _ScreenFonts_MIN, ""}

/* Field tags (for use in manual encoding/decoding) */
#define ChannelFile_channels_tag                 1
#define ChannelFile_version_tag                  2
#define DeviceState_my_node_tag                  2
#define DeviceState_owner_tag                    3
#define DeviceState_node_db_tag                  4
#define DeviceState_receive_queue_tag            5
#define DeviceState_rx_text_message_tag          7
#define DeviceState_version_tag                  8
#define DeviceState_no_save_tag                  9
#define DeviceState_did_gps_reset_tag            11
#define OEMStore_oem_icon_width_tag              1
#define OEMStore_oem_icon_height_tag             2
#define OEMStore_oem_icon_bits_tag               3
#define OEMStore_oem_font_tag                    4
#define OEMStore_oem_text_tag                    5

/* Struct field encoding specification for nanopb */
#define DeviceState_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  my_node,           2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  owner,             3) \
X(a, STATIC,   REPEATED, MESSAGE,  node_db,           4) \
X(a, STATIC,   REPEATED, MESSAGE,  receive_queue,     5) \
X(a, STATIC,   OPTIONAL, MESSAGE,  rx_text_message,   7) \
X(a, STATIC,   SINGULAR, UINT32,   version,           8) \
X(a, STATIC,   SINGULAR, BOOL,     no_save,           9) \
X(a, STATIC,   SINGULAR, BOOL,     did_gps_reset,    11)
#define DeviceState_CALLBACK NULL
#define DeviceState_DEFAULT NULL
#define DeviceState_my_node_MSGTYPE MyNodeInfo
#define DeviceState_owner_MSGTYPE User
#define DeviceState_node_db_MSGTYPE NodeInfo
#define DeviceState_receive_queue_MSGTYPE MeshPacket
#define DeviceState_rx_text_message_MSGTYPE MeshPacket

#define ChannelFile_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, MESSAGE,  channels,          1) \
X(a, STATIC,   SINGULAR, UINT32,   version,           2)
#define ChannelFile_CALLBACK NULL
#define ChannelFile_DEFAULT NULL
#define ChannelFile_channels_MSGTYPE Channel

#define OEMStore_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   oem_icon_width,    1) \
X(a, STATIC,   SINGULAR, UINT32,   oem_icon_height,   2) \
X(a, STATIC,   SINGULAR, BYTES,    oem_icon_bits,     3) \
X(a, STATIC,   SINGULAR, UENUM,    oem_font,          4) \
X(a, STATIC,   SINGULAR, STRING,   oem_text,          5)
#define OEMStore_CALLBACK NULL
#define OEMStore_DEFAULT NULL

extern const pb_msgdesc_t DeviceState_msg;
extern const pb_msgdesc_t ChannelFile_msg;
extern const pb_msgdesc_t OEMStore_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define DeviceState_fields &DeviceState_msg
#define ChannelFile_fields &ChannelFile_msg
#define OEMStore_fields &OEMStore_msg

/* Maximum encoded size of messages (where known) */
#define ChannelFile_size                         630
#define DeviceState_size                         23728
#define OEMStore_size                            2106

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
