#ifndef MESSAGE_ID_H
#define MESSAGE_ID_H

#define ESTOP_RANGE_START 1024
#define ESTOP_RANGE_END 2047
//if (rx_frame.MsgID >= ESTOP_RANGE_START && rx_frame.MsgID <= ESTOP_RANGE_END) set queue to canToEStop
#define HOUSE_RANGE_START 2048
#define HOUSE_RANGE_END 3071
#define WATCH_RANGE_START 3072
#define WATCH_RANGE_END 4095
enum es_actions {e_stop = ESTOP_RANGE_START, last_estop_action = ESTOP_RANGE_END};
enum h_actions {first_h_action = HOUSE_RANGE_START};
enum w_actions {first_w_action = WATCH_RANGE_START};
//Within Estoptask
//es_actions temp = rx_frame.MsgID;
//switch(temp){case e_stop: ...}
//get the message id and see if it lies in a certain range. Estop task looks at the number and matches it to some action. 


#endif