static const unsigned int borderpx  = 1;
static const unsigned int gapppx    = 10;
static const unsigned int snap      = 0;
static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft = 0;
static const unsigned int systrayspacing = 0;   
static const int systraypinningfailfirst = 0;
static const unsigned int tabModKey            = 0x40;
static const unsigned int tabCycleKey          = 0x17;
static const unsigned int tabPosY              = 1;    /* axis, 0 = bottom, 1 ER, 2 = top */
static const unsigned int tabPosX              = 1;    /* n X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab              = 300;  /* tab menu width */
static const unsigned int maxHTab              = 150;  /* tab menu height */
static const int showsystray        = 1;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = { "Azeret Mono:size=7", "fontawesome:size=7" };
static const char col_gray1[]       = "#000000";
static const char col_gray2[]       = "#101010";
static const char col_gray3[]       = "#beaa9b";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray2, 0},
	[SchemeSel]  = { col_gray3, col_gray1, col_gray2},
};

static const char *const autostart[] = {
	//"xautolock", "-time", "15", "-locker", "slock", NULL,
	//"nm-applet", NULL,
	"dunst", NULL,
	"slstatus", NULL,
	//"xrdb", "/m/.Xresources", NULL,
	//"feh", "--bg-scale", "--no-fehbg", "/m/Documents/cb.jpg", NULL,
	//"startnginx", NULL,
	//"syncthing", "--no-browser", NULL,
	NULL
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

static const Rule rules[] = {
		{ "Steam",			NULL,      NULL,		1 << 9,       1,           -1 },

}; 

static const float mfact     = 0.60;
static const int nmaster     = 1;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
	{ "",		NULL },
	{ "",		tile },
};

#define ALT Mod1Mask
#define MOD Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MOD,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MOD|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MOD|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

static const char *term[]  = { "alacritty", 0};
static const char *dmenu[] = { "dmenu_run", 0};
static const char *ss[] = { "screenshot", 0};
static const char *browser[] = { "firefox", "--allow-downgrade", 0};
static const char *pcmanfm[] = { "pcmanfm", 0};
static const char *pavu[] = { "pavucontrol", 0};

static const char *eng[] = { "setxkbmap", "us", 0};
static const char *fin[] = { "setxkbmap", "fi", 0};
static const char *high[] = { "xbacklight", "-inc", "10", 0};
static const char *low[] = { "xbacklight", "-dec", "10", 0};
static const char *play[] = { "playerctl", "-a", "play-pause",  0};
static const char *prev[] = { "playerctl", "-a", "previous",    0};
static const char *next[] = { "playerctl", "-a", "next",        0};
static const char *lock[] = { "slock", 0};
static const char *daily[] = { "alacritty", "-e", "vim", "daily", 0};

static const char *upvol[] = { "volume", "up", 0};
static const char *downvol[] = { "volume", "down", 0};
static const char *mutevol[] = { "volume", "mute", 0};
static const char *mutemic[] = { "volume", "mic", 0};

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MOD,                       XK_p,      spawn,          {.v = dmenu } },
	{ MOD,			     XK_s,	spawn,		{.v = ss } },
	{ MOD,			     XK_Return, spawn,          {.v = term } },
	{ MOD,                       XK_m,	spawn,          {.v = browser } },
	{ MOD,                       XK_b,	spawn,          {.v = pcmanfm } },
	{ MOD,                       XK_v,      spawn,          {.v = pavu } },
	{ MOD,                       XK_x,      spawn,          {.v = daily } },
	{ MOD|ShiftMask,                       XK_l,      spawn,          {.v = lock } },
	{ MOD,             	     XK_f,     togglefullscr,  		{0} },
	{ ALT,                       XK_z,     spawn,          {.v = eng } },
	{ ALT,                       XK_x,     spawn,          {.v = fin } },
	{ ALT,                       XK_F1,      togglebar,      {0} },
	{ MOD,                       XK_j,      focusstack,     {.i = +1 } },
	{ MOD,                       XK_k,      focusstack,     {.i = -1 } },
	{ MOD,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MOD,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MOD|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MOD|ShiftMask,	     XK_k,      movestack,      {.i = -1 } },
	{ MOD,			     XK_Return, zoom,           {0} },
	{ MOD,                       XK_Tab,    view,           {0} },
	{ MOD,	       		     XK_q,      killclient,    	{0} },
	{ MOD,                       XK_F1,      setlayout,      {.v = &layouts[0]} },
	{ MOD,                       XK_F2,      setlayout,      {.v = &layouts[1]} },
	{ MOD,                       XK_space,  setlayout,      {0} },
	{ MOD|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MOD,                       XK_a,      view,           {.ui = ~0 } },
	{ MOD|ShiftMask,             XK_a,      tag,            {.ui = ~0 } },
	{ MOD,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MOD,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MOD|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ ALT,			     XK_Tab, 	altTabStart,	{0} },
	{ 0,    XF86XK_AudioRaiseVolume,     spawn,          {.v = upvol   } },
        { 0,    XF86XK_AudioLowerVolume,     spawn,          {.v = downvol   } },
        { 0,    XF86XK_AudioMute,            spawn,          {.v = play } },
        { 0,    XF86XK_AudioMicMute,         spawn,          {.v = mutemic   } },
        { 0,    XF86XK_MonBrightnessDown,    spawn,          {.v = low } },
        { 0,    XF86XK_MonBrightnessUp,      spawn,          {.v = high } },
        { 0,    XF86XK_AudioPlay,            spawn,          {.v = mutevol } },
        { 0,    XF86XK_AudioNext,            spawn,          {.v = next } },
        { 0,    XF86XK_AudioPrev,            spawn,          {.v = prev } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	{ MOD|ShiftMask,             	XK_r,      quit,           {0} },
};

static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkStatusText,			0,				Button2,        spawn,          {.v = term } },
	{ ClkClientWin,				MOD,				Button1,        movemouse,      {0} },
	{ ClkClientWin,				MOD,				Button2,        togglefloating, {0} },
	{ ClkClientWin,				MOD,				Button3,        resizemouse,    {0} },
	{ ClkTagBar,				0,				Button1,        view,           {0} },
	{ ClkTagBar,				0,				Button3,        toggleview,     {0} },
};
