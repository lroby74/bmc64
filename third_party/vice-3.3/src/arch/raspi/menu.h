/*
 * menu.h
 *
 * Written by
 *  Randy Rossi <randy.rossi@gmail.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "ui.h"

#ifndef VICE_MENU_H
#define VICE_MENU_H

// Never used as values. Can be reorged.
typedef enum {
   MENU_ABOUT,
   MENU_LICENSE,
   MENU_ATTACH_DISK_8,
   MENU_ATTACH_DISK_9,
   MENU_ATTACH_DISK_10,
   MENU_ATTACH_DISK_11,

   MENU_DETACH_DISK_8,
   MENU_DETACH_DISK_9,
   MENU_DETACH_DISK_10,
   MENU_DETACH_DISK_11,

   MENU_SOFT_RESET,
   MENU_HARD_RESET,

   MENU_ATTACH_CART,
   MENU_ATTACH_CART_8K,
   MENU_ATTACH_CART_16K,
   MENU_ATTACH_CART_ULTIMAX,
   MENU_DETACH_CART,

   MENU_ATTACH_TAPE,
   MENU_DETACH_TAPE,

   MENU_DISK_FILE,
   MENU_TAPE_FILE,
   MENU_CART_FILE,
   MENU_CART_8K_FILE,
   MENU_CART_16K_FILE,
   MENU_CART_ULTIMAX_FILE,

   // A menu item with on action associated with it. Just text.
   MENU_TEXT,

   MENU_SWAP_JOYSTICKS,

   MENU_JOYSTICK_PORT_1,
   MENU_JOYSTICK_PORT_2,

   MENU_CONFIG_GP_1,
   MENU_CONFIG_GP_2,

   MENU_WARP_MODE,

   MENU_AUTOSTART,
   MENU_AUTOSTART_FILE,

   MENU_IECDEVICE_8,
   MENU_IECDEVICE_9,
   MENU_IECDEVICE_10,
   MENU_IECDEVICE_11,

   MENU_COLOR_PALETTE,

   MENU_USB_0_PREF,
   MENU_USB_1_PREF,

   MENU_SAVE_SETTINGS,
   MENU_KEYBOARD_TYPE,

   MENU_TAPE_START,
   MENU_TAPE_STOP,
   MENU_TAPE_REWIND,
   MENU_TAPE_FASTFWD,
   MENU_TAPE_RESET,
   MENU_TAPE_RESET_COUNTER,
   MENU_TAPE_RECORD,

   MENU_DRIVE_SOUND_EMULATION,
   MENU_DRIVE_SOUND_EMULATION_VOLUME,

   MENU_CONFIGURE_USB_0,
   MENU_CONFIGURE_USB_1,
   MENU_USB_0_X_AXIS,
   MENU_USB_0_Y_AXIS,
   MENU_USB_1_X_AXIS,
   MENU_USB_1_Y_AXIS,
   MENU_USB_0_WATCH_RAW,
   MENU_USB_1_WATCH_RAW,
   MENU_USB_0_BTN_ASSIGN,
   MENU_USB_1_BTN_ASSIGN,

   MENU_SID_ENGINE,
   MENU_SID_MODEL,
   MENU_SID_FILTER,

   MENU_ERROR_DIALOG,
   MENU_INFO_DIALOG,

   MENU_SAVE_SNAP,
   MENU_SAVE_SNAP_FILE,
   MENU_LOAD_SNAP,
   MENU_LOAD_SNAP_FILE,

   MENU_DEMO_MODE,
   MENU_OVERLAY,

   MENU_DRIVE_TYPE_8,
   MENU_DRIVE_TYPE_9,
   MENU_DRIVE_TYPE_10,
   MENU_DRIVE_TYPE_11,
   MENU_TAPE_RESET_WITH_MACHINE,

   MENU_COLOR_BRIGHTNESS,
   MENU_COLOR_CONTRAST,
   MENU_COLOR_GAMMA,
   MENU_COLOR_TINT,
   MENU_COLOR_RESET,

   MENU_DRIVE_SELECT,
   MENU_DRIVE_CHANGE_MODEL_8,
   MENU_DRIVE_CHANGE_MODEL_9,
   MENU_DRIVE_CHANGE_MODEL_10,
   MENU_DRIVE_CHANGE_MODEL_11,

   MENU_MAKE_CART_DEFAULT,
   MENU_LOAD_KERNAL,
   MENU_KERNAL_FILE,
   MENU_LOAD_BASIC,
   MENU_BASIC_FILE,
   MENU_LOAD_CHARGEN,
   MENU_CHARGEN_FILE,

   MENU_CALC_TIMING,
   MENU_START_CALC_TIMING,

   MENU_POTX_HIGH,
   MENU_POTX_LOW,
   MENU_POTY_HIGH,
   MENU_POTY_LOW,

   MENU_HOTKEY_CF1,
   MENU_HOTKEY_CF3,
   MENU_HOTKEY_CF5,
   MENU_HOTKEY_CF7,

   MENU_SAVE_EASYFLASH,
   MENU_CART_FREEZE,

   MENU_USB_0_X_THRESH,
   MENU_USB_0_Y_THRESH,
   MENU_USB_1_X_THRESH,
   MENU_USB_1_Y_THRESH,

   MENU_CONFIRM_OK,
   MENU_CONFIRM_CANCEL,
   MENU_RESET_CONFIRM,

   MENU_USE_PCB,
} MenuID;

typedef enum {
   MENU_SUB_NONE,
   MENU_SUB_PICK_FILE,
   MENU_SUB_UP_DIR,
   MENU_SUB_ENTER_DIR,
} MenuSubID;

// Used as saved values. Don't reorg.
typedef enum {
   KEYBOARD_TYPE_US = 0,
   KEYBOARD_TYPE_UK,
} MenuKeyboardType;

// Used as indices
typedef enum {
   MENU_SID_ENGINE_FAST = 0,
   MENU_SID_ENGINE_RESID,
} MenuSidEngine;

// Used as indices
typedef enum {
   MENU_SID_MODEL_6581 = 0,
   MENU_SID_MODEL_8580,
} MenuSidModel;

// Used as indices
typedef enum {
   OVERLAY_NEVER = 0,
   OVERLAY_ALWAYS,
   OVERLAY_ON_ACTIVITY
} MenuOverlayOption;

// Used as both indices and values. Don't reorg.
typedef enum {
   HOTKEY_CHOICE_NONE = 0,
   HOTKEY_CHOICE_MENU,
   HOTKEY_CHOICE_WARP,
   HOTKEY_CHOICE_STATUS_TOGGLE,
   HOTKEY_CHOICE_SWAP_PORTS,
   HOTKEY_CHOICE_TAPE_MENU,
   HOTKEY_CHOICE_CART_MENU,
   HOTKEY_CHOICE_CART_FREEZE,
   HOTKEY_CHOICE_RESET_HARD,
   HOTKEY_CHOICE_RESET_SOFT,
} HotKeyChoice;

extern int osd_active;

// Called at initialzation
void build_menu(struct menu_item *root);

int menu_get_keyboard_type(void);
void menu_swap_joysticks(void);
int overlay_enabled(void);
int overlay_forced(void);

void menu_about_to_activate(void);
void menu_about_to_deactivate(void);

void menu_quick_func(int button_assignment);

#endif
