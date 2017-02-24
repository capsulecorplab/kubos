#ifndef CNC_H
#define CNC_H

#include <stdint.h>

#define DEFAULT_STR_LEN 20

#ifdef YOTTA_CFG_CSP_MTU
#define MTU      YOTTA_CFG_CSP_MTU
#else
#define MTU      250
#endif

#ifdef YOTTA_CFG_CNC_CMD_MAX_NUM_ARGS
#define CMD_MAX_NUM_ARGS          YOTTA_CFG_CNC_CMD_MAX_NUM_ARGS
#else
#define CMD_MAX_NUM_ARGS          10
#endif

#ifdef YOTTA_CFG_CNC_CMD_MAX_ARG_LEN
#define CMD_MAX_ARG_LEN          YOTTA_CFG_CNC_CMD_MAX_ARG_LEN
#else
#define CMD_MAX_ARG_LEN           DEFAULT_STR_LEN
#endif

#ifdef YOTTA_CFG_CNC_CMD_PACKET_CMD_NAME_LEN
#define CMD_PACKET_CMD_NAME_LEN   YOTTA_CFG_CNC_CMD_PACKET_CMD_NAME_LEN
#else
#define CMD_PACKET_CMD_NAME_LEN   DEFAULT_STR_LEN
#endif

#ifdef YOTTA_CFG_CNC_CMD_PACKET_ARG_LEN
#define CMD_PACKET_ARG_LEN        YOTTA_CFG_CNC_CMD_PACKET_ARG_LEN
#else
#define CMD_PACKET_ARG_LEN        DEFAULT_STR_LEN
#endif

#ifdef YOTTA_CFG_CNC_RES_PACKET_STDOUT_LEN
#define RES_PACKET_STDOUT_LEN        YOTTA_CFG_CNC_CMD_PACKET_ARG_LEN
#else
#define RES_PACKET_STDOUT_LEN     MTU - 33 //TODO: define constant for response packet overhead
#endif


typedef enum
{
    execute = 0,
    status,
    version,
    help
} cnc_action;


typedef struct arguments
{
    int arg_count;
    cnc_action action;
    char cmd_name[CMD_PACKET_CMD_NAME_LEN];
    char * args[CMD_PACKET_ARG_LEN];
} cnc_command_packet;


typedef struct
{
    uint8_t return_code;
    double  execution_time;
    char    output[RES_PACKET_STDOUT_LEN]; //TODO: Figure out optimal size
} cnc_response_packet;

#endif
