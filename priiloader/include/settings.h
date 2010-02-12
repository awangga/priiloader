/*

priiloader/preloader 0.30 - A tool which allows to change the default boot up sequence on the Wii console

Copyright (C) 2008-2009  crediar

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation version 2.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.


*/


#define VERSION		03
//#define BETAVERSION	0x00000004
#define BETAVERSION	0

typedef struct {
	u32 autoboot;
	u32 version;
	u32 ReturnTo;
	u8 ShutdownToPreloader;
	u8 StopDisc;
	u8 LidSlotOnError;
	u8 IgnoreShutDownMode;
	u32 BetaVersion;
	u8 SystemMenuIOS;
	u8 UseSystemMenuIOS;
	u8 BlackBackground;
	u8 ShowDebugText;
	u8 PasscheckPriiloader;
	u8 PasscheckMenu;
} Settings;
enum {
		SETTING_AUTBOOT,
		SETTING_RETURNTO,
		SETTING_SHUTDOWNTOPRELOADER,
		SETTING_STOPDISC,
		SETTING_SHOWBETAUPDATE,
		SETTING_LIDSLOTONERROR,
		SETTING_IGNORESHUTDOWNMODE,
		SETTING_BETAVERSION,
		SETTING_SYSTEMMENUIOS,
		SETTING_USESYSTEMMENUIOS,
		SETTING_BLACKBACKGROUND,
		SETTING_SHOWDEBUGTEXT,
		SETTING_PASSCHECKPRII,
		SETTING_PASSCHECKMENU,
};

enum {
		AUTOBOOT_DISABLED,
		AUTOBOOT_HBC,
		AUTOBOOT_BOOTMII_IOS,
		AUTOBOOT_SYS,
		AUTOBOOT_FILE,
		AUTOBOOT_ERROR
};
enum {	
		RETURNTO_SYSMENU,
		RETURNTO_PRELOADER,
		RETURNTO_AUTOBOOT,
};



u32 GetSysMenuVersion( void );
u32 GetSysMenuIOS( void );
u32 SGetSetting( u32 s );
void LoadSettings( void );
int SaveSettings( void );

//patch to libogc was submitted for the following struct. but for now we'll place it here since its needed in settings and main
typedef struct _tmd_view_content_t
{
  uint32_t cid;
  uint16_t index;
  uint16_t type;
  uint64_t size;
} __attribute__((packed)) tmd_view_content_t;

typedef struct _tmd_view_t
{
	uint8_t version; // 0x0000;
	uint8_t filler[3];
	uint64_t sys_version; //0x0004
	uint64_t title_id; // 0x00c
	uint32_t title_type; //0x0014
	uint16_t group_id; //0x0018
	uint8_t reserved[0x3e]; //0x001a this is the same reserved 0x3e bytes from the tmd
	uint16_t title_version; //0x0058
	uint16_t num_contents; //0x005a
	tmd_view_content_t contents[]; //0x005c
}__attribute__((packed)) tmd_view;