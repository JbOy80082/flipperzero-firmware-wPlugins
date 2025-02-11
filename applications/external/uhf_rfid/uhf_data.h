#pragma once

#include <stdint.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 64

typedef struct UHFData {
    uint8_t data[MAX_DATA_SIZE];
    size_t length;
    bool start;
    bool end;
    struct UHFData* next;
} UHFData;

typedef struct UHFResponseData {
    UHFData* head;
    UHFData* tail;
    size_t size;

} UHFResponseData;

UHFData* uhf_data_alloc();
int uhf_data_append(UHFData* uhf_data, uint8_t data);
void uhf_data_reset(UHFData* uhf_data);
void uhf_data_free(UHFData* uhf_data);

UHFResponseData* uhf_response_data_alloc();
UHFData* uhf_response_data_add_new_uhf_data(UHFResponseData* uhf_response_data);
UHFData* uhf_response_data_get_uhf_data(UHFResponseData* uhf_response_data, uint index);
void uhf_response_data_reset(UHFResponseData* uhf_response_data);
void uhf_response_data_free(UHFResponseData* uhf_response_data);