static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
// static const char col_gray3[]       = "#bbbbbb";
// static const char col_gray4[]       = "#eeeeee";
// static const char col_cyan[]        = "#005577";
static const char col_gray3[]       = "#FF9100";
static const char col_gray4[]       = "#FF9100";
// static const char col_purple[]        = "#9D5CF1";
// static const char col_purple[]        = "#1D5CF1";
static const char selbordercolor[]        = "#008ECF";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  selbordercolor },
};
