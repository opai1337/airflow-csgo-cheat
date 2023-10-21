#pragma once
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <thread>
#include <mutex>

#include "../../base/other/color.h"
#include "../../base/tools/render.h"

class ImDrawList;
struct ImVec2;

struct key_binds_t
{
  int key = -1;
  int type = -1;

  bool toggled{ };

  std::string name{ };
};

extern std::vector< std::string > key_strings;

struct tab_animation_t
{
  float hovered_alpha{ };
  float alpha{ };

  bool hovered{ };
  bool selected{ };
};

struct item_animation_t
{
  bool active{ };

  float hovered_alpha{ };
  float alpha{ };

  __forceinline void reset( )
  {
    active = false;

    hovered_alpha = 0.f;
    alpha = 0.f;
  }
};

struct menu_key_binds_t
{
  std::string name{ };

  int type = -1;

  float time{ };
  float alpha{ };

  __forceinline void reset( float time )
  {
    this->name = "";

    this->type = -1;

    this->time = time;
  }
};

struct menu_bomb_t
{
  bool filled{ };

  int time{ };
  int health{ };

  std::string bomb_site = xor_c( "A" );

  __forceinline void reset( )
  {
    if( !filled )
      return;

    time = 0;
    health = 0;

    bomb_site = xor_c( "A" );

    filled = false;
  }
};

class c_float_color
{
private:
  float color_base [ 4 ]{ };

public:
  __forceinline c_float_color( )
  {
    color_base [ 0 ] = 1.f;
    color_base [ 1 ] = 1.f;
    color_base [ 2 ] = 1.f;
    color_base [ 3 ] = 1.f;
  }

  __forceinline c_float_color( color& clr )
  {
    color_base [ 0 ] = clr.r( ) / 255.f;
    color_base [ 1 ] = clr.g( ) / 255.f;
    color_base [ 2 ] = clr.b( ) / 255.f;
    color_base [ 3 ] = clr.a( ) / 255.f;
  }

  __forceinline c_float_color( int r = 255, int g = 255, int b = 255, int a = 255 )
  {
    color_base [ 0 ] = r / 255.f;
    color_base [ 1 ] = g / 255.f;
    color_base [ 2 ] = b / 255.f;
    color_base [ 3 ] = a / 255.f;
  }

  __forceinline float* float_base( )
  {
    return color_base;
  }

  __forceinline float& operator[]( int idx )
  {
    return color_base [ idx ];
  }

  __forceinline color& base( )
  {
    color out = color( color_base [ 0 ] * 255.f, color_base [ 1 ] * 255.f, color_base [ 2 ] * 255.f, color_base [ 3 ] * 255.f );
    return out;
  }
};