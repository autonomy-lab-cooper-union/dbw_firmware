#ifndef MESSAGE_ID_H
#define MESSAGE_ID_H

//if (rx_frame.MsgID >= ESTOP_RANGE_START && rx_frame.MsgID <= ESTOP_RANGE_END) set queue to canToEStop

enum taskID  {
    SPCL_RANGE_START = 0x000,
    #ifdef BRAKE
        //brake specific task names here
    #elif STEERING
        //steering specific task names here
    #elif SPEED
        //speed specific task names here
    #elif MISC
        //miscellaneous specific task names here
    #endif
    SPCL_RANGE_END = 0x3FF,
    ESTOP_RANGE_START   = 0x400,
    e_stop,
    ESTOP_RANGE_END     = 0x7FF,
    HOUSE_RANGE_START   = 0x800,
    HOUSE_RANGE_END     = 0xBFF,
    WATCH_RANGE_START   = 0xC00,
    WATCH_RANGE_END     = 0xFFF
};
//Within Estoptask
//es_actions temp = rx_frame.MsgID;
//switch(temp){case e_stop: ...}
//get the message id and see if it lies in a certain range. Estop task looks at the number and matches it to some action. 
enum nodeID {
    BRK_RANGE_START = 0x000,
    BRK_RANGE_END = 0x3FF,
    STR_RANGE_START = 0x400,
    STR_RANGE_END = 0x7FF,
    SPD_RANGE_START = 0x800,
    SPD_RANGE_END = 0xBFF,
    MSC_RANGE_START = 0xC00,
    MSC_RANGE_END = 0xFFF
};


#endif