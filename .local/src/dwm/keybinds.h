//
//  keybinds.h
//  dwm
//
//  Created by Yigit Colakoglu on 04/12/21.
//  Copyright 2021. Yigit Colakoglu. All rights reserved.
//
//

#include <X11/XF86keysym.h>
#include "movestack.c"

#ifndef keybinds_h
#define keybinds_h


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "/home/yigit/.local/bin/dmenu_run_history", "-m", dmenumon, "-z", "1900", "-x", "10", "-y", "10"};
static const char *termcmd[]  = { "/usr/local/bin/st", NULL };
static const char *tmuxcmd[]  = { "/usr/local/bin/st","-e", "/home/yigit/.local/bin/st_tmux", NULL };
static const char *upvol[]   = { "/home/yigit/.local/bin/pacontrol.sh", "up",     NULL };
static const char *downvol[]   = { "/home/yigit/.local/bin/pacontrol.sh", "down",     NULL };
static const char *mutevol[]   = { "/home/yigit/.local/bin/pacontrol.sh", "toggle-mute",     NULL };

static const char *upbright[] = {"/usr/bin/xbacklight","-inc","10",NULL};
static const char *downbright[] = {"/usr/bin/xbacklight","-dec","10",NULL};

static const char *lock[] = {"/usr/local/bin/slock",NULL};
static const char *clipmenu[] = {"/usr/bin/clipmenu","-i",NULL};
static const char *play[] = {"/usr/bin/playerctl","play-pause",NULL};
static const char *prev[] = {"/usr/bin/playerctl","previous",NULL};
static const char *next[] = {"/usr/bin/playerctl","next",NULL};
static const char *outmenu[] = {"/home/yigit/.local/bin/dmenu-logout", NULL};
static const char *refresh[] = {"/home/yigit/.local/bin/dmenu-refresh", NULL};
static const char *keyboard[] = {"/home/yigit/.local/bin/kbmap_toggle", NULL};

static const char *screenshot[] = { "scrot", "/tmp/%Y-%m-%d-%s_$wx$h.png", "-e","xclip -selection clipboard -target image/png -i $f; cp $f ~/Pictures/Screenshots;notify-send \"SNAP\" \"$f\"", NULL };
static const char *windowshot[] = { "scrot", "-u", "/tmp/%Y-%m-%d-%s_$wx$h.png", "-e","xclip -selection clipboard -target image/png -i $f; cp $f ~/Pictures/Screenshots;notify-send \"SNAP\" \"$f\"", NULL };
static const char *simcrop[] = {"simcrop","-fc","-sc", "-g", "900x500",NULL};

static const char *notification[] = {"/home/yigit/.local/bin/dunst_toggle.sh", "-t",NULL};

static const char *screensaver[] = {"/home/yigit/.local/bin/screensaver_toggle", "-t",NULL};

static const char *online_class[] = {"/home/yigit/.local/bin/tedportal",NULL};

static const char *bwmenu[] = {"/home/yigit/.local/bin/password_manager", NULL};


static const char *wallabag[] = {"/home/yigit/.local/bin/dmenu-wallabag", "-s", NULL};
static const char *wiki[] = {"/home/yigit/.local/bin/dmenu-arch", NULL};

static const char *grabcolor[] = {"/home/yigit/.local/bin/grabcolor", NULL};
static const char *network_manager[] = {"/home/yigit/.local/bin/connman_dmenu", NULL};
static const char *killall[] = {"/home/yigit/.local/bin/dmenu-killall", NULL};
static const char *mconnect[] = {"/home/yigit/.local/bin/dmenu-mconnect"};
static const char *udevil[] = {"/home/yigit/.local/bin/dmenu-udevil"};
static const char *udevil_umount[] = {"/home/yigit/.local/bin/dmenu-udevil", "-u"};
static const char *genpwd[] = {"/home/yigit/.local/bin/genpwd", NULL};
static const char *trackpad[] = {"/home/yigit/.local/bin/toggle_touchpad.sh"};
static const char *bluetooth[] = {"/home/yigit/.local/bin/dmenu-bluetooth", NULL};
static const char *url[] = {"/home/yigit/.local/bin/dmenu_surf", NULL};
static const char *edit[] = {"/home/yigit/.local/bin/dmenu-edit", NULL};
static const char *surf[] = {"/home/yigit/.local/bin/tabbed_surf", NULL};
static const char *google[] = {"/home/yigit/.local/bin/menu-surfraw", "google", NULL};
static const char *youtube[] = {"/home/yigit/.local/bin/ytfzf_dmenu", NULL};

/* commands */
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = bwmenu } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = tmuxcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,	            XK_i,      spawn,          {.v = screensaver} },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          {.v = notification } },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_z, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|Mod1Mask,              XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_s,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_t,      setlayout,      {.v = &layouts[0]} }, /*tiled*/
	{ MODKEY|Mod1Mask,              XK_f,      setlayout,      {.v = &layouts[1]} }, /*Spiral*/
	{ MODKEY|Mod1Mask,              XK_g,      setlayout,      {.v = &layouts[2]} }, /*Grid*/
	{ MODKEY|Mod1Mask,              XK_c,      setlayout,      {.v = &layouts[3]} }, /*center*/
	{ MODKEY|Mod1Mask,              XK_space,  setlayout,      {.v = &layouts[4]} }, /*Center floating*/
	{ MODKEY|Mod1Mask,              XK_m,      setlayout,      {.v = &layouts[5]} }, /*monocle*/
	{ MODKEY|Mod1Mask,             	XK_d,      setlayout,      {.v = &layouts[6]} }, /*Deck*/
	{ MODKEY|ShiftMask,            	XK_space,  togglefloating, {0} }, /* [>float<] */
	{ MODKEY,			            			XK_f,    	 togglefullscr,  {0} }, /*[>Fullscreen<] */
	{ MODKEY|Mod1Mask,              XK_comma,  cyclelayout,    {.i = -1 } }, /*Ciclar layouts*/
	{ MODKEY|Mod1Mask,              XK_period, cyclelayout,    {.i = +1 } }, /*Ciclar layouts*/
	{ MODKEY,                       XK_a,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_a,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q, 			spawn, {.v = outmenu} },
	{ MODKEY|ShiftMask,             XK_t, 			spawn, {.v = trackpad} },
	{ MODKEY,                       XK_x, 			spawn, {.v = lock } },
	{ MODKEY|ShiftMask,             XK_x, 			spawn, {.v = killall } },
	{ MODKEY,                       XK_c, 			spawn, {.v = clipmenu } },
	{ MODKEY|ShiftMask,             XK_p,			  spawn, {.v = genpwd} },
	{ MODKEY|ShiftMask,             XK_b,			  spawn, {.v = bluetooth } },
	{ MODKEY|Mod1Mask,              XK_n, 			spawn, {.v = network_manager} }, /*Spiral*/
	{ MODKEY|Mod1Mask,              XK_k,       spawn,      {.v = keyboard} }, /*tiled*/
	{ MODKEY|ShiftMask,              XK_r,       spawn,      {.v = refresh} }, /*tiled*/
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                            XF86XK_MonBrightnessUp, spawn, {.v = upbright } },
	{ 0,                            XF86XK_MonBrightnessDown, spawn, {.v = downbright } },
	{ 0,                            XF86XK_AudioMute, spawn, {.v = mutevol } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
	{ 0,                            XF86XK_AudioPrev, spawn, {.v = prev  } },
	{ 0,                            XF86XK_AudioPlay, spawn, {.v = play  } },
	{ 0,                            XF86XK_AudioNext, spawn, {.v = next  } },
	{ 0,                            XK_Print, spawn, {.v = screenshot  } },
	{ MODKEY,                       XK_Print, spawn, {.v = windowshot  } },
	{ MODKEY|ShiftMask, 						XK_e, spawn, {.v = simcrop } },
	{ MODKEY,                       XK_e, spawn, {.v = edit} },
	{ MODKEY,                       XK_u, spawn, {.v = url} },
	{ MODKEY|ShiftMask,             XK_w, spawn, {.v = wallabag} },
	{ MODKEY,            					  XK_w, spawn, {.v = wiki} },
	{ MODKEY,                       XK_g, spawn, {.v = google} },
	{ MODKEY,        	 							XK_t, spawn, {.v = online_class} },
	{ MODKEY|ShiftMask,							XK_m, spawn, {.v = mconnect} },
	{ MODKEY|ShiftMask,							XK_d, spawn, {.v = udevil} },
	{ MODKEY|ShiftMask,							XK_u, spawn, {.v = udevil_umount} },
	{ MODKEY,                       XK_y, spawn, {.v = youtube} },
	{ MODKEY|ShiftMask,             XK_g, spawn, {.v = grabcolor} },
	{ MODKEY,                       XK_s,      togglescratch,          {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_s,      togglescratch,					 {.ui = 1 } },
	{ MODKEY,                       XK_m,      togglescratch,          {.ui = 2 } },
	{ MODKEY|ShiftMask,             XK_f, 		 togglescratch,          {.ui = 3} },
	{ MODKEY,   					          XK_n, 		 togglescratch,          {.ui = 4} },
	{ MODKEY|ShiftMask,             XK_c, 		 togglescratch,          {.ui = 5} },
	/* FloatPos Patch Keybinds */
	{ Mod3Mask,                     XK_u,            floatpos,               {.v = "-26x -26y" } }, // ↖
	{ Mod3Mask,                     XK_i,            floatpos,               {.v = "  0x -26y" } }, // ↑
	{ Mod3Mask,                     XK_o,            floatpos,               {.v = " 26x -26y" } }, // ↗
	{ Mod3Mask,                     XK_j,            floatpos,               {.v = "-26x   0y" } }, // ←
	{ Mod3Mask,                     XK_l,            floatpos,               {.v = " 26x   0y" } }, // →
	{ Mod3Mask,                     XK_m,            floatpos,               {.v = "-26x  26y" } }, // ↙
	{ Mod3Mask,                     XK_comma,        floatpos,               {.v = "  0x  26y" } }, // ↓
	{ Mod3Mask,                     XK_period,       floatpos,               {.v = " 26x  26y" } }, // ↘
	/* Resize client, client center position is fixed which means that client expands in all directions */
	{ Mod3Mask|ShiftMask,           XK_u,            floatpos,               {.v = "-26w -26h" } }, // ↖
	{ Mod3Mask|ShiftMask,           XK_i,            floatpos,               {.v = "  0w -26h" } }, // ↑
	{ Mod3Mask|ShiftMask,           XK_o,            floatpos,               {.v = " 26w -26h" } }, // ↗
	{ Mod3Mask|ShiftMask,           XK_j,            floatpos,               {.v = "-26w   0h" } }, // ←
	{ Mod3Mask|ShiftMask,           XK_k,            floatpos,               {.v = "800W 800H" } }, // ·
	{ Mod3Mask|ShiftMask,           XK_l,            floatpos,               {.v = " 26w   0h" } }, // →
	{ Mod3Mask|ShiftMask,           XK_m,            floatpos,               {.v = "-26w  26h" } }, // ↙
	{ Mod3Mask|ShiftMask,           XK_comma,        floatpos,               {.v = "  0w  26h" } }, // ↓
	{ Mod3Mask|ShiftMask,           XK_period,       floatpos,               {.v = " 26w  26h" } }, // ↘
};

#endif /* keybinds_h */
