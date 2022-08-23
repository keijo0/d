static const unsigned int borderpx  = 1;
static const unsigned int gapppx    = 10;
static const unsigned int snap      = 0;
static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft = 0;
static const unsigned int systrayspacing = 0;   
static const int systraypinningfailfirst = 0;
static const int showsystray        = 1;
static const int showbar            = 1;
static const int topbar             = 0;
static const char *fonts[]          = { "Space Mono:size=9", "fontawesome:size=9" };
static const char dmenufont[]       = "Space Mono:size=9";

static const char col_gray1[]       = "#161616";
static const char col_gray2[]       = "#060606";
static const char col_gray3[]       = "#beaa9b";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray3, col_gray2, col_gray1 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

static const Rule rules[] = {
        { "Steam",       NULL,      NULL,	1 << 8,       1,           -1 },
}; 

static const float mfact     = 0.50;
static const int nmaster     = 1;
static const int resizehints = 0;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
        { "floating",      NULL },
        { "tiling",      tile },
	{ "monocle",      monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray2, "-nf", col_gray3, "-sb", col_gray2, "-sf", col_gray3, "-b", NULL };
static const char *termcmd[]  = { "tabbed", "alacritty", "--embed", NULL };
static const char *crmcmd[] = { "firefox", "--disable-pinch", NULL };

// shit
static const char *vrmcmd[] = { "pavucontrol", NULL };
static const char *bcmd[] = { "pcmanfm", NULL };
static const char *scmd[] = { "spotify", NULL };
static const char *dcmd[] = { "discord-chromium", NULL };
static const char *sscmd[] = { "flameshot", "gui", NULL };

//power managerment stuff
static const char *shutdowncmd[] = { "doas", "poweroff", NULL };

//volume things
static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *mutevol[] = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *volup[] = { "notify-send", "-t", "1000", "VOLUME", "", NULL };
static const char *voldown[] = { "notify-send", "-t", "1000", "VOLUME", "", NULL };
static const char *volmute[] = { "notify-send", "-t", "1000", "VOLUME", "", NULL };

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,                       XK_m,	   spawn,          {.v = crmcmd } },
        { MODKEY,                       XK_v,      spawn,          {.v = vrmcmd } },
        { MODKEY,                       XK_b,	   spawn,          {.v = bcmd } },
        { MODKEY,                       XK_z,     spawn,          {.v = dcmd } },
        { MODKEY,                       XK_F5,     spawn,          {.v = scmd } },
        { MODKEY,                       XK_s,     spawn,          {.v = sscmd } },
        { MODKEY,                       XK_F9,     spawn,          {.v = shutdowncmd } },
	{ MODKEY,                       XK_F3,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY, 	                XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_F1,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_F2,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        { MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
        { MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
        { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
 	{ MODKEY,                       XK_F12,     spawn,          {.v = upvol   } },
 	{ MODKEY,                       XK_F11,     spawn,          {.v = downvol } },
 	{ MODKEY,                       XK_F10,     spawn,          {.v = mutevol } },
	{ MODKEY,                       XK_F12,     spawn,          {.v = volup  } },
        { MODKEY,                       XK_F11,     spawn,          {.v = voldown  } },
        { MODKEY,                       XK_F10,     spawn,          {.v = volmute  } },
 	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_r,      quit,           {0} },
};

/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
