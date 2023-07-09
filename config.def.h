/* See LICENSE file for copyright and license details. */

/*
 *  You obviously need the X11 development package installed, but here is the upstream copy
 *  of this header if you can't bother using the contents of your own hard drive. ;-P
 *  https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h
 */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 8;        /* 2 is the default spacing around the bar's font */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 10;        /* vertical padding for statusbar */
static const char *fonts[]          = { 
	"SFMono Nerd Font Mono:style=Medium:pixelsize=16:antialias=true:autohint=true",
	"Phosphor:style=regular:pixelsize=20:antialias=true:autohint=true",
  "JetBrainsMono Nerd Font:style=Medium:pixelsize=16:antialias=true:autohint=true",
  "Fira Code:style=Medium:pixelsize=20:antialias=true:autohint=true",
  "VictorMono Nerd Font:style=Medium:pixelsize=20:antialias=true:autohint=true",
	"Ubuntu Nerd Font:size=12",
  "monospace:size=10"
};
static const char dmenufont[]       = "Fira Code:style=Medium:pixelsize=18:antialias=true:autohint=true";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

static const char sel_fg[]          = "#ffffff";
static const char sel_bg[]          = "#000000";
static const char sel_border[]      = "#00FFFF";
static const char norm_fg[]         = "#777777";
static const char norm_bg[]         = "#000000";
static const char norm_border[]     = "#444444";
static const unsigned int baralpha = 0x00U;
// static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]  = { norm_fg,   norm_bg,   norm_border},
	[SchemeSel] = { sel_fg,    sel_bg,    sel_border },
};
// static const char *colors[][3]      = {
// 	/*               fg         bg         border   */
// 	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
// 	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
// };

static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "", "", "", "", "", "", "", "", ""};

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   monitor */
	{ "Gimp",               NULL,        NULL,           0,            0,           1,           -1 },
	{ "St",                 NULL,        NULL,           0,            1,           0,           -1 },
	{ "kitty",              NULL,        NULL,           0,            1,           0,           -1 },
	{ "Spotify",            NULL,        NULL,           1 << 8,       1,           0,           -1 },
	{ "Sxiv",               NULL,        NULL,           0,            1,           1,           -1 },
	{ "Blueman-manager",    NULL,        NULL,           0,            1,           1,           -1 },
	{ "zoom",               NULL,        NULL,           0,            1,           1,           -1 },
	{ "xpad",               NULL,        NULL,           0,            1,           1,           -1 },
	{ "gnome-calculator",   NULL,        NULL,           0,            1,           1,           -1 },
	{ "KeePassXC",          NULL,        NULL,           0,            1,           1,           -1 },
	{ "Lxappearance",       NULL,        NULL,           0,            1,           1,           -1 },
	{ NULL,                 NULL,        "System Logout",0,            1,           1,           -1 },
	{ "Skype",              NULL,        NULL,           1 << 5,       1,           1,           -1 },
	{ "firefox",            NULL,        NULL,           1 << 1,       1,           0,           -1 },
	{ "TelegramDesktop",    NULL,        NULL,           1 << 2,       1,           0,           -1 },
	{ "Whatsapp-for-linux", NULL,        NULL,           1 << 2,       1,           0,           -1 },
	{ "discord",            NULL,        NULL,           1 << 3,       1,           0,           -1 },
	{ "VirtualBox Manager", NULL,        NULL,           1 << 7,       1,           1,           -1 },
	{ "qBittorrent",        NULL,        NULL,           1 << 7,       1,           0,           -1 },
	{ "sp_term",            NULL,        NULL,           0,            1,           1,           -1 },
	{ "sp_btop",            NULL,        NULL,           0,            1,           1,           -1 },
	{ "sp_music",           NULL,        NULL,           0,            1,           1,           -1 },
	{ "sp_pulse",           NULL,        NULL,           0,            1,           1,           -1 },
	{ "sp_ranger",          NULL,        NULL,           0,            1,           1,           -1 },
	// { "mpv",                NULL,        NULL,           0,            1,           1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	// { "[]=",      tile },    /* first entry is default */
	// { "><>",      NULL },    /* no layout function means floating behavior */
	// { "[M]",      monocle },
	// { "|M|",      centeredmaster },
	// { ">M>",      centeredfloatingmaster },
	// { NULL,       NULL },
	{ " ",      tile },    /* first entry is default */
	{ " ",      NULL },    /* no layout function means floating behavior */
	{ " ",      monocle },
	{ " ",      centeredmaster },
	{ " ",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	// "j4-dmenu-desktop",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", col_gray1,
	"-nf", col_gray3,
	"-sb", col_cyan,
	"-sf", col_gray4,
  "-l" , "15",
  "-c" , NULL,
	NULL
};

//== st
static const char *termcmd[]  = { "kitty", NULL };
//== alacritty
static const char *term2cmd[]  = { "alacritty", NULL };
//== kitty
static const char *term3cmd[]  = { "st", NULL };
//== firefox
static const char *browser_cmd[]  = { "${BROWSER}", NULL };
//== File manager
static const char *filemgr_cmd[]  = { "thunar", NULL };
//== discord
static const char *discord_cmd[]  = { "discord", NULL };
//== spotify
// static const char *spotify_cmd[]  = { "spotify", NULL };
//== sxiv to change background and dwm's colorscheme:
// After app runs, choose the new background and then type
// Ctrl-x + Ctrl-w
// This calls a script that calls pywall and sets background with xwallpaper.
// After that, press MODKEY+Fn+F5 to reload color scheme based on xrbd
// static const char *sxiv_cmd[]  = { "sxiv -t /home/selan/Pictures/wallpapers", NULL };

/* scratchpads */
static const char *sp_btop[]    = { "scratch.sh", "btop"   , NULL };
static const char *sp_keepass[] = { "scratch.sh", "keepass", NULL };
static const char *sp_music[]   = { "scratch.sh", "music"  , NULL };
static const char *sp_pulse[]   = { "scratch.sh", "pulse"  , NULL };
static const char *sp_ranger[]  = { "scratch.sh", "ranger" , NULL };
static const char *sp_term[]    = { "scratch.sh", "pad"    , NULL };



static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,             XK_p,          spawn,             SHCMD("dmenu_run_customized.sh") }, 
	{ MODKEY|ShiftMask,   XK_d,          spawn,             {.v = dmenucmd } },
	{ MODKEY,             XK_Return,     spawn,             {.v = termcmd } },
	{ MODKEY|ShiftMask,   XK_Return,     spawn,             {.v = term2cmd } },
	{ MODKEY|ALTKEY,      XK_Return,     spawn,             {.v = term3cmd } },
  { MODKEY,             XK_c,          spawn,             SHCMD("toggle_dark_conky") },
	{ MODKEY|ShiftMask,   XK_c,          spawn,             SHCMD("toggle_light_conky") },
	{ MODKEY,             XK_t,          spawn,             SHCMD("toggle_picom") },
	{ MODKEY,             XK_a,          spawn,             SHCMD("toggle_systray") },
	{ MODKEY,             XK_z,          spawn,             {.v = sp_term} },

  //== Keybindings for programs using the format SUPER + ALT + "key"
	{ MODKEY|ALTKEY,      XK_b,           spawn,            {.v = browser_cmd} }, //SHCMD("$BROWSER") },
	{ MODKEY|ALTKEY,      XK_c,           spawn,            SHCMD("scapture -s $HOME/Pictures/screenshots/") },
	{ MODKEY|ALTKEY,      XK_d,           spawn,            {.v = discord_cmd} },
	{ MODKEY|ALTKEY,      XK_e,           spawn,            SHCMD("flameshot gui -p $HOME/Pictures/screenshots/") },
	{ MODKEY|ALTKEY,      XK_f,           spawn,            {.v = filemgr_cmd} },
	{ MODKEY|ALTKEY,      XK_k,           spawn,            {.v = sp_keepass} },
	{ MODKEY|ALTKEY,      XK_l,           spawn,            SHCMD("i3lock") },
	{ MODKEY|ALTKEY,      XK_o,           spawn,            SHCMD("openboard") },
	{ MODKEY|ALTKEY,      XK_p,           spawn,            SHCMD("system-config-printer") },
 	{ MODKEY|ALTKEY,      XK_r,           spawn,            {.v = sp_ranger} }, 
	{ MODKEY|ALTKEY,      XK_m,           spawn,            {.v = sp_music} }, 
	{ MODKEY|ALTKEY,      XK_n,           spawn,            SHCMD("dunstctl history-pop") }, 
	{ MODKEY|ALTKEY,      XK_s,           spawn,            SHCMD("spotify") },
	{ MODKEY|ALTKEY,      XK_t,           spawn,            {.v = sp_btop} }, 
	{ MODKEY|ALTKEY,      XK_a,           spawn,            {.v = sp_pulse} }, 
	{ MODKEY|ALTKEY,      XK_v,           spawn,            SHCMD("pavucontrol") },
	{ MODKEY|ALTKEY,      XK_w,           spawn,            SHCMD("sxiv -t $HOME/Pictures/wallpapers") },

  //== Brightness and volume control
  { 0,        XF86XK_AudioLowerVolume,  spawn,            SHCMD("vol_lower") },
  { 0,        XF86XK_AudioRaiseVolume,  spawn,            SHCMD("vol_raise") },
  { 0,        XF86XK_AudioMute,         spawn,            SHCMD("toggle_vol_mute") },
  { 0,        XF86XK_MonBrightnessUp,   spawn,            SHCMD("mon_brightness_up") },
  { 0,        XF86XK_MonBrightnessDown, spawn,            SHCMD("mon_brightness_down") },
  { 0,        XF86XK_KbdBrightnessUp,   spawn,            SHCMD("kbd_brightness_up") },
  { 0,        XF86XK_KbdBrightnessDown, spawn,            SHCMD("kbd_brightness_down") },
  { 0,        XF86XK_AudioPlay,         spawn,            SHCMD("playerctl --all-players play-pause") },
  { 0,        XF86XK_AudioPrev,         spawn,            SHCMD("playerctl prev") },
  { 0,        XF86XK_AudioNext,         spawn,            SHCMD("playerctl next") },


	//== Window management
	{ MODKEY,             XK_b,           togglebar,        {0} },
	{ MODKEY,             XK_j,           focusstack,       {.i = +1 } },
	{ MODKEY,             XK_k,           focusstack,       {.i = -1 } },
	{ MODKEY,             XK_h,           focusdir,         {.i = 0 } }, // left
	{ MODKEY,             XK_l,           focusdir,         {.i = 1 } }, // right
	{ MODKEY,             XK_Left,        focusdir,         {.i = 0 } }, // left
	{ MODKEY,             XK_Right,       focusdir,         {.i = 1 } }, // right
	{ MODKEY,             XK_Up,          focusdir,         {.i = 2 } }, // up
	{ MODKEY,             XK_Down,        focusdir,         {.i = 3 } }, // down
	{ MODKEY,             XK_i,           incnmaster,       {.i = +1 } },
	{ MODKEY,             XK_d,           incnmaster,       {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_h,           setmfact,         {.f = -0.05} },
	{ MODKEY|ShiftMask,   XK_l,           setmfact,         {.f = +0.05} },
	{ MODKEY|ShiftMask,   XK_j,           pushdown,         {0} },
	{ MODKEY|ShiftMask,   XK_k,           pushup,           {0} },
	{ MODKEY,             XK_Tab,         view,             {0} },
  { MODKEY,             XK_m,           zoom,             {0} },
	{ MODKEY,             XK_q,           killclient,       {0} },
	{ MODKEY|ShiftMask,   XK_q,           spawn,            SHCMD("dmenu_logout") },
	{ MODKEY,             XK_space,       cyclelayout,      {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_space,       cyclelayout,      {.i = +1 } },
	{ MODKEY,             XK_BackSpace,   togglefloating,   {0} },
	{ MODKEY|ShiftMask,   XK_f,           togglefullscreen, {0} },
	{ MODKEY,             XK_comma,       focusmon,         {.i = -1 } },
	{ MODKEY,             XK_period,      focusmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,   XK_comma,       tagmon,           {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_period,      tagmon,           {.i = +1 } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

  //== Fn Keys.
  { MODKEY,             XK_F1,          spawn,            SHCMD("toggle_help") },
  { MODKEY,             XK_F2,          spawn,            SHCMD("toggle_lockscreen") },
  { MODKEY,             XK_F3,          spawn,            SHCMD("blueman-manager") },
  { MODKEY,             XK_F4,          spawn,            SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
  { MODKEY,             XK_F5,          spawn,            SHCMD("dmenu_keymap") },
  { MODKEY,             XK_F6,          spawn,            SHCMD("dmenu_displayselect") },
  { MODKEY,             XK_F7,          spawn,            SHCMD("dmenu_networkmanager") },
  { MODKEY,             XK_F8,          spawn,            SHCMD("toggle_dunst") },
  { MODKEY,             XK_F9,          spawn,            SHCMD("toggle_wifi") },
  { MODKEY,             XK_F10,         spawn,            SHCMD("toggle_bluetooth") },
  { MODKEY,             XK_F11,         spawn,            SHCMD("toggle_screenkey") },
  { MODKEY,             XK_F12,         spawn,            SHCMD("single_monitor") },

	//== Gaps and quitting
	{ MODKEY,            XK_minus,        setgaps,          {.i = -2 } },
	{ MODKEY,            XK_equal,        setgaps,          {.i = +2 } },
	{ MODKEY|ShiftMask,  XK_minus,        setgaps,          {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,  XK_equal,        setgaps,          {.i = GAP_TOGGLE} },
	{ MODKEY|ALTKEY,     XK_q,            quit,             {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q, quit,             {1} }, 

	TAGKEYS( XK_1, 0)
	TAGKEYS( XK_2, 1)
	TAGKEYS( XK_3, 2)
	TAGKEYS( XK_4, 3)
	TAGKEYS( XK_5, 4)
	TAGKEYS( XK_6, 5)
	TAGKEYS( XK_7, 6) 
	TAGKEYS( XK_8, 7)
	TAGKEYS( XK_9, 8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY|ALTKEY,  Button1,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,Button1,       resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

