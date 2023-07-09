static const char col_gray1[]       = "#1d2021";
static const char col_gray2[]       = "#665c54";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#ebdbb2";
static const char selbordercolor[]  = "#cc241d";
static const char col_cyan[]        = "#458588";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray4, col_cyan,  selbordercolor  },
};
