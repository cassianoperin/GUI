#pragma once
#include "typedef.h"

/* Nuklear Flags */
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_STANDARD_VARARGS
// #define NK_INCLUDE_DEFAULT_ALLOCATOR
// #define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
// #define NK_INCLUDE_FONT_BAKING
// #define NK_INCLUDE_DEFAULT_FONT
// #define NK_IMPLEMENTATION
// #define NK_SDL_RENDERER_IMPLEMENTATION
#include "nuklear.h"
#include "nuklear_sdl_renderer.h"

/* Nuklear Colors*/
const struct nk_color nk_red = {255,0,0,255};
const struct nk_color nk_green = {0,255,0,255};
const struct nk_color nk_blue = {0,0,255,255};
const struct nk_color nk_white = {255,255,255,255};
const struct nk_color nk_black = {0,0,0,255};
const struct nk_color nk_gray = {120,120,120,255};
const struct nk_color nk_yellow = {255,255,0,255};

// --------------------------------- External Variables --------------------------------- //
// Main
extern bool quit;
extern bool rom_format_hex;
// SDL Video
extern SDL_Window   *window;
extern SDL_Renderer *renderer;
extern SDL_Texture  *texture;
// GUI
extern struct nk_context *ctx;
extern float font_scale; // GUI Font
extern bool cpu_rom_loaded;
// CPU
extern bool cpu_debug_mode;
extern unsigned int CPU_CLOCK;
// Sound
extern bool sound_enabled;
// Display
extern unsigned int display_WINDOW_WIDTH_X;
extern unsigned int display_WINDOW_HEIGHT_Y;
extern unsigned char display_EMULATOR_RES_X;
extern unsigned char display_EMULATOR_RES_Y;
extern unsigned int display_EMULATOR_RES_SCALE;
extern bool display_fullscreen;
// Quirks
extern bool quirk_VF_Reset_8xy1_8xy2_8xy3;
extern bool quirk_Memory_legacy_Fx55_Fx65;
extern bool quirk_display_wait;
extern bool quirk_Clipping_Dxyn;
extern bool quirk_Shifting_legacy_8xy6_8xyE;
extern bool quirk_Jump_with_offset_Bnnn;

// --------------------------------- External Functions --------------------------------- //
// NFD Extended
extern int lib_gui_loadrom(void);
// Display
extern void display_updateWindowSize(unsigned int pixel_scale);
// CPU
extern void cpu_reset(void);
// Font
extern void showLogo(void);

// ---------------------------------- Global Variables ---------------------------------- //
bool gui_menu_quirks_inactive; // Enable/Disable Quirks Menu
char gui_statusbar_msg[100];
unsigned int gui_pixels_logo[2048];
unsigned int gui_pixel_logo_ON_color;
unsigned int gui_pixel_logo_OFF_color;

// -------------------------------------- Functions ------------------------------------- //
void gui_init(void);
int menu(struct nk_context *ctx);
int status_bar(struct nk_context *ctx);

