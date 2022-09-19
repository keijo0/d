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
static const char dmenufont[]       = "Cousine:size=9";

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
	"xrdb", "/home/make/.Xresources", NULL, /* change this shit unless ur name is make */
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

static const Rule rules[] = {
        { "Steam",       NULL,      NULL,	1 << 8,       1,           -1 },
	{ "lutris",       NULL,      NULL,       1 << 7,       1,           -1 },
}; 

static const float mfact     = 0.50;
static const int nmaster     = 1;
static const int resizehints = 0;
static const int lockfullscreen = 1;

#include "horizgrid.c"
static const Layout layouts[] = {
        { "",      NULL },
        { "",    tile },
	{ "",      monocle },
	{ "",    horizgrid },
};

#define ALT Mod1Mask
#define MOD Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MOD,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MOD|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MOD|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MOD|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
        { MOD|ALT,                       KEY,      focusnthmon,    {.i  = TAG } }, \
        { MOD|ALT|ShiftMask,             KEY,      tagnthmon,      {.i  = TAG } },


#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray2, "-nf", col_gray3, "-sb", col_gray2, "-sf", col_gray3, "-b", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *crmcmd[] = { "chromium", NULL };


/* shit */
static const char *vrmcmd[] = { "pavucontrol", NULL };
static const char *bcmd[] = { "pcmanfm", NULL };
static const char *scmd[] = { "spotify", NULL };
static const char *sscmd[] = { "flameshot", "gui", NULL };
static const char *eng[] = { "setxkbmap", "us", NULL };
static const char *fin[] = { "setxkbmap", "fi", NULL };
static const char *high[] = { "xbacklight", "-inc", "5", NULL };
static const char *low[] = { "xbacklight", "-dec", "5", NULL };
static const char *poweroff[] = { "doas", "poweroff", NULL };
static const char *reboot[] = { "doas", "reboot", NULL };
//volume things
static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *mutevol[] = { "amixer", "set", "Master", "toggle", NULL };



#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MOD,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MOD,	                	XK_Return, spawn,          {.v = termcmd } },
        { MOD,                       XK_n,	   spawn,          {.v = crmcmd } },
        { MOD,                       XK_v,      spawn,          {.v = vrmcmd } },
        { MOD,                       XK_b,	   spawn,          {.v = bcmd } },
        { MOD,                       XK_F5,     spawn,          {.v = scmd } },
	{ MOD,                       XK_F6,     spawn,          {.v = eng } },
        { MOD,                       XK_F7,     spawn,          {.v = fin } },
        { MOD,                       XK_s,     spawn,          {.v = sscmd } },
        { MOD|ShiftMask,             XK_F10,     spawn,          {.v = poweroff } },
	{ MOD|ShiftMask|ControlMask, XK_F12,    spawn,	   {.v = reboot } },
	{ MOD,                       XK_F3,      togglebar,      {0} },
	{ MOD,                       XK_j,      focusstack,     {.i = +1 } },
	{ MOD,                       XK_k,      focusstack,     {.i = -1 } },
	{ MOD,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MOD,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MOD|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MOD|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MOD,                       XK_Return, zoom,           {0} },
	{ ALT,                       XK_Tab,    view,           {0} },
	{ MOD,	       		XK_q,      killclient,     {0} },
	{ MOD,                       XK_F1,      setlayout,      {.v = &layouts[0]} },
	{ MOD,                       XK_F2,      setlayout,      {.v = &layouts[1]} },
	{ MOD,                       XK_f,      setlayout,      {.v = &layouts[2]} },
        { MOD,                       XK_F4,      setlayout,      {.v = &layouts[3]} },
	{ MOD,                       XK_space,  setlayout,      {0} },
	{ MOD|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MOD,                       XK_0,      view,           {.ui = ~0 } },
	{ MOD|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MOD|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MOD|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        { MOD,                       XK_minus,  setgaps,        {.i = -5 } },
        { MOD,                       XK_equal,  setgaps,        {.i = +5 } },
        { MOD|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
 	{ 0,	XF86XK_AudioRaiseVolume,     spawn,          {.v = upvol   } },
        { 0,	XF86XK_AudioLowerVolume,     spawn,          {.v = downvol   } },
        { 0,	XF86XK_AudioMute,            spawn,          {.v = mutevol   } },
	{ 0,	XK_F11,      spawn,	     {.v = low } },
	{ 0,	XK_F12,      spawn,          {.v = high } },
 	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MOD|ShiftMask,             	XK_r,      quit,           {0} },
};

/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MOD,         	Button1,        movemouse,      {0} },
	{ ClkClientWin,         MOD,         	Button2,        togglefloating, {0} },
	{ ClkClientWin,         MOD,         	Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MOD,         	Button1,        tag,            {0} },
	{ ClkTagBar,            MOD,         	Button3,        toggletag,      {0} },
};
