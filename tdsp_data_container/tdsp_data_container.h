#pragma once
#include <stdint.h>
#include <assert.h>

#define DATA_CONTAINER_SIZE (13 * 4)  // number of vars * 4, all vars must be 32 bit


typedef struct tdsp_data_container {

    /* DSP -> HOST */
    // status flags
    uint32_t isr_ready;          // isr on tdsp registered
    uint32_t isr_count;          // number of isr calls
    uint32_t last_time_stamp;    // time_stamp of last data set taken over by tdsp
    

    /* HOST -> DSP */
    // model configuration
    uint32_t channel_select;    // L or R channel selection
    uint32_t source_select;     // select hrtf signal source
    uint32_t model_select;      // select simulink model

    // sensor data platzhalter
    int32_t imu_x_acc;         // IMU x-axis acceleration
    int32_t imu_y_acc;         // IMU y-axis acceleration
    int32_t imu_z_acc;         // IMU z-axis acceleration
    int32_t imu_x_gyro;        // IMU x-axis gyroscope
    int32_t imu_y_gyro;        // IMU y-axis gyroscope
    int32_t imu_z_gyro;        // IMU z-axis gyroscope

    // data sync
    uint32_t time_stamp;        // timestamp for data sync, is set when new data is sent to tdsp
    
} tdsp_data_container;

static_assert(sizeof(tdsp_data_container) == DATA_CONTAINER_SIZE, "datacontainer: unexpected size");