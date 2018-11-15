#ifndef GUARD_FIELD_SPECIAL_SCENE_H
#define GUARD_FIELD_SPECIAL_SCENE_H

#include <gba/gba.h>

s16 GetTruckCameraBobbingY(int a1);
s16 GetTruckBoxMovement(int a1);
void Task_Truck1(u8 taskId);
void Task_Truck2(u8 taskId);
void Task_Truck3(u8 taskId);
void Task_HandleTruckSequence(u8 taskId);
void ExecuteTruckSequence(void);
void EndTruckSequence(u8);
void sub_80C791C(void);

#endif // GUARD_FIELD_SPECIAL_SCENE_H
