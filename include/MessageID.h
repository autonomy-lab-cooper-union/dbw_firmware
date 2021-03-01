#ifndef MESSAGE_ID_H
#define MESSAGE_ID_H

//if (rx_frame.MsgID >= ESTOP_RANGE_START && rx_frame.MsgID <= ESTOP_RANGE_END) set queue to canToEStop

// this should be moved somewhere else
#define NODE_BRAKE 0
#define NODE_STEER 1
#define NODE_ACCEL 2
#define NODE_MISC  3
#define THIS_NODE NODE_BRAKE

enum canmsg_ID  {
    ADMIN_RANGE_START   = 0x0000,
    ADMIN_RANGE_END     = 0x03FF,
    ESTOP_RANGE_START   = 0x0400,
        MSG_ESTOP,
    ESTOP_RANGE_END     = 0x07FF,
    HOUSE_RANGE_START   = 0x0800,
    HOUSE_RANGE_END     = 0x0BFF,
    WATCH_RANGE_START   = 0x0C00,
    WATCH_RANGE_END     = 0x0FFF,
    BRK_RANGE_START     = 0x1000,
    BRK_RANGE_END       = 0x13FF,
    STR_RANGE_START     = 0x1400,
    STR_RANGE_END       = 0x17FF,
    SPD_RANGE_START     = 0x1800,
    SPD_RANGE_END       = 0x1BFF,
    MSC_RANGE_START     = 0x1C00,
    MSC_RANGE_END       = 0x1FFF
};

#endif

