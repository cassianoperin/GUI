#pragma once
#include <SDL2/SDL.h>


// Boolean Type for Vanilla C
typedef int bool;
#define true 1
#define false 0

// --------------------------------- External Variables --------------------------------- //
// Main
extern SDL_Window *window;
extern char *filename;
// Display
extern unsigned char display_FPS;
extern unsigned char Memory[4096];
extern unsigned int  display_pixels[8192];
extern unsigned int  display_pixel_ON_color;
// extern unsigned int frame;
// CPU
extern unsigned int CPU_CLOCK;
extern void cpu_reset(void);
extern bool cpu_rom_loaded;
extern bool cpu_draw_flag;
extern bool quirk_display_wait;
// GUI
extern bool gui_show_menu;
extern bool gui_menu_quirks_inactive;
extern char gui_statusbar_msg[100];
// Font
extern const int font_logo[165];
// Input
extern unsigned int display_pixel_ON_color_alt;
extern unsigned int display_pixel_OFF_color_alt;
extern unsigned int display_pixel_ON_color_tmp;
extern unsigned int display_pixel_OFF_color_tmp;

// --------------------------------- External Functions --------------------------------- //
// Display
extern void display_update_theme(void);

// ---------------------------------- Global Variables ---------------------------------- //
char *game_signature;           // Game signature to apply quirks
extern bool rom_format_hex;

// -------------------------------------- Functions ------------------------------------- //

// Ticker - Use with actions that should be executed each second = 1hz
bool ticker_second(long lastTime, long currentTime);

// Ticker - Use with actions that should be executed 60 times per second = 60hz
bool ticker_fps(long lastTime, long currentTime);

// Ticker - se with actions that should be executed 500 times per second = 500hz
bool ticker_cpu(long lastTime, long currentTime);

// Load rom into memory
void load_rom(char *filename, unsigned char *mem, unsigned int mem_size);

// Get Game Signature
char *get_game_signature(char *filename);

// Time measurement
long getMicrotime(void);

// Print Frames and Cycles per second on screen
// void showCPS(long long unsigned int number);
// void showFPS(int number);
// void showCPU_CPS(int number);

// Check if a string contains in another
uint8_t strContains(char* string, char* toFind);

// Print the binary representation of a byte
void print_bin(unsigned char value);

// File Open Dialog
int lib_gui_loadrom(void);

// Show Logo
void showLogo(void);
