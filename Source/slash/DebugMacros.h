#pragma once
#include "DrawDebugHelpers.h"  


#define THIRTY 30
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 100.f, THIRTY, FColor::Green, true);
#define DRAW_SPHERE_SingleFrame(Location)   if (GetWorld())  DrawDebugSphere(GetWorld(), Location, 100.f, THIRTY, FColor::Green, false, -1.f); 
#define DRAW_SPHERE_COLOR(Location,Color) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 8.f, 12, Color, false,5.f);

//用来绘制单帧的球
#define DRAW_LINE(Start, End) if(GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, -1.f);