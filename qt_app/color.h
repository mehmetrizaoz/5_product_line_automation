/**
 * @file   color.h
 * @author Mehmet Rıza Öz - mehmetrizaoz@gmail.com
 * @brief  color class used for agent, path, wall etc. color
 * @date   13.05.2021
*/

#pragma once

#define BLACK   color(0,0,0)
#define BLUE    color(0,0,1)
#define GREEN   color(0,1,0)
#define CYAN    color(0,1,1)
#define RED     color(1,0,0)
#define YELLOW  color(1,1,0)
#define MAGENDA color(1,0,1)
#define WHITE   color(1,1,1)

using namespace std;

class color{
public:
   color(float r, float g, float b);
   float R;
   float G;
   float B;
};
