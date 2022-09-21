static const unsigned int borderpx  = 0;
static const unsigned int gapppx    = 10;
static const unsigned int snap      = 0;
static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft = 0;
static const unsigned int systrayspacing = 0;   
static const int systraypinningfailfirst = 0;
static const int showsystray        = 1;
static const int showbar            = 1;
static const int topbar             = 0;
static const char *fonts[]          = { "Cousine:size=9", "fontawesome:size=9" };

static const char col_gray1[]       = "#161616";
static const char col_gray2[]       = "#060606";
static const char col_gray3[]       = "#beaa9b";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray3, col_gray2, col_gray1 },
};

static const char *const autostart[] = {
	"dunst", NULL,
	"slstatus", NULL,
	"pasystray", NULL,
	"xrdb", "/home/make/.Xresources", NULL,
	"xautolock", "-time", "15", "-locker", "slock", NULL,
//	"nm-applet", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

static const Rule rules[] = {
		{ "Steam",			NULL,      NULL,		1 << 8,       1,           -1 },
}; 

static const float mfact     = 0.50;
static const int nmaster     = 1;
static const int resizehints = 0;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
	{ "",		NULL },
	{ "",		tile },
	{ "",		monocle },
};

#define ALT Mod1Mask
#define MOD Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MOD,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MOD|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MOD|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \

// binds and shit
static const char *dmenu[] = { "dmenu_run", NULL };
static const char *term[]  = { "alacritty", NULL };
static const char *browser[] = { "chromium", NULL };
static const char *pavucontrol[] = { "pavucontrol", NULL };
static const char *pcmanfm[] = { "pcmanfm", NULL };
static const char *spotify[] = { "spotify", NULL };
static const char *eng[] = { "setxkbmap", "us", NULL };
static const char *fin[] = { "setxkbmap", "fi", NULL };
static const char *high[] = { "xbacklight", "-inc", "5", NULL };
static const char *low[] = { "xbacklight", "-dec", "5", NULL };
static const char *poweroff[] = { "doas", "poweroff", NULL };
static const char *reboot[] = { "doas", "reboot", NULL };
static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *mutevol[] = { "amixer", "set", "Master", "toggle", NULL };
static const char *mutemic[] = { "amixer", "set", "Capture", "toggle", NULL };
static const char *play[] = { "playerctl", "-a", "play-pause",	NULL, };
static const char *prev[] = { "playerctl", "-a", "previous",	NULL, };
static const char *next[] = { "playerctl", "-a", "next", 	NULL, };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MOD,                       XK_p,      spawn,          {.v = dmenu } },
	{ MOD,			    			 XK_Return, spawn,          {.v = term } },
	{ MOD,                       XK_n,	spawn,          {.v = browser } },
	{ MOD,                       XK_v,      spawn,          {.v = pavucontrol } },
	{ MOD,                       XK_b,	spawn,          {.v = pcmanfm } },
	{ MOD,                       XK_F5,     spawn,          {.v = spotify } },
	{ MOD,                       XK_F6,     spawn,          {.v = eng } },
	{ MOD,                       XK_F7,     spawn,          {.v = fin } },
	{ MOD|ShiftMask,             XK_F10,    spawn,          {.v = poweroff } },
	{ MOD|ShiftMask|ControlMask,	 XK_F12,    spawn,		{.v = reboot } },
	{ MOD,                       XK_F3,      togglebar,      {0} },
	{ MOD,                       XK_j,      focusstack,     {.i = +1 } },
	{ MOD,                       XK_k,      focusstack,     {.i = -1 } },
	{ MOD,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MOD,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MOD|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MOD|ShiftMask,				XK_k,      movestack,      {.i = -1 } },
	{ MOD,						XK_Return, zoom,           {0} },
	{ ALT,                       XK_Tab,    view,           {0} },
	{ MOD,	       		     		XK_q,      killclient,    	{0} },
	{ MOD,                       XK_F1,      setlayout,      {.v = &layouts[0]} },
	{ MOD,                       XK_F2,      setlayout,      {.v = &layouts[1]} },
	{ MOD,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MOD,                       XK_F4,      setlayout,      {.v = &layouts[3]} },
	{ MOD,                       XK_space,  setlayout,      {0} },
	{ MOD|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MOD,                       XK_A,      view,           {.ui = ~0 } },
	{ MOD|ShiftMask,             XK_A,      tag,            {.ui = ~0 } },
	{ MOD,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MOD,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MOD|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ 0,	XF86XK_AudioRaiseVolume,     spawn,          {.v = upvol   } },
	{ 0,	XF86XK_AudioLowerVolume,     spawn,          {.v = downvol   } },
	{ 0,	XF86XK_AudioMute,            spawn,          {.v = mutevol   } },
	{ 0,    XF86XK_AudioMicMute,         spawn,          {.v = mutemic   } },
	{ 0,	XF86XK_MonBrightnessDown,    spawn,	     {.v = low } },
	{ 0,	XF86XK_MonBrightnessUp,      spawn,          {.v = high } },
	{ 0, 	XF86XK_AudioPlay,	     spawn,	     {.v = play } },
	{ 0,	XF86XK_AudioNext,	     spawn,	     {.v = next } },
	{ 0,    XF86XK_AudioPrev,	     spawn, 	     {.v = prev } },
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

/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,				0,				Button1,        setlayout,      {0} },
	{ ClkLtSymbol,				0,				Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,			0,				Button2,        spawn,          {.v = term } },
	{ ClkClientWin,				MOD,				Button1,        movemouse,      {0} },
	{ ClkClientWin,				MOD,				Button2,        togglefloating, {0} },
	{ ClkClientWin,				MOD,				Button3,        resizemouse,    {0} },
	{ ClkTagBar,				0,				Button1,        view,           {0} },
	{ ClkTagBar,				0,				Button3,        toggleview,     {0} },
	{ ClkTagBar,				MOD,				Button1,        tag,            {0} },
};
