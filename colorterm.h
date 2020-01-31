#ifndef COLORTERM
#define COLORTERM 1

/*ANSI color code to display on terminal*/

const char *FG_BLACK = "\x1b[30m";
const char *FG_BLUE = "\x1b[34m";
const char *FG_CYAN = "\x1b[36m";
const char *FG_GREEN = "\x1b[32m";
const char *FG_LIGHTBLACK_EX = "\x1b[90m";
const char *FG_LIGHTBLUE_EX = "\x1b[94m";
const char *FG_LIGHTCYAN_EX = "\x1b[96m";
const char *FG_LIGHTGREEN_EX = "\x1b[92m";
const char *FG_LIGHTMAGENTA_EX = "\x1b[95m";
const char *FG_LIGHTRED_EX = "\x1b[91m";
const char *FG_LIGHTWHITE_EX = "\x1b[97m";
const char *FG_LIGHTYELLOW_EX = "\x1b[93m";
const char *FG_MAGENTA = "\x1b[35m";
const char *FG_RED = "\x1b[31m";
const char *FG_RESET = "\x1b[39m";
const char *FG_WHITE = "\x1b[37m";
const char *FG_YELLOW = "\x1b[33m";

const char *BG_BLACK = "\x1b[40m";
const char *BG_BLUE = "\x1b[44m";
const char *BG_CYAN = "\x1b[46m";
const char *BG_GREEN = "\x1b[42m";
const char *BG_LIGHTBLACK_EX = "\x1b[100m";
const char *BG_LIGHTBLUE_EX = "\x1b[104m";
const char *BG_LIGHTCYAN_EX = "\x1b[106m";
const char *BG_LIGHTGREEN_EX = "\x1b[102m";
const char *BG_LIGHTMAGENTA_EX = "\x1b[105m";
const char *BG_LIGHTRED_EX = "\x1b[101m";
const char *BG_LIGHTWHITE_EX = "\x1b[107m";
const char *BG_LIGHTYELLOW_EX = "\x1b[103m";
const char *BG_MAGENTA = "\x1b[45m";
const char *BG_RED = "\x1b[41m";
const char *BG_RESET = "\x1b[49m";
const char *BG_WHITE = "\x1b[47m";
const char *BG_YELLOW = "\x1b[43m";

const char *STYLE_BRIGHT = "\x1b[1m";
const char *STYLE_DIM = "\x1b[2m";
const char *STYLE_NORMAL = "\x1b[22m";
const char *STYLE_RESET_ALL = "\x1b[0m";

const char *ERROR = "\x1b[31m\x1b[1mError\x1b[0m";
const char *WARNING = "\x1b[35m\x1b[1mWarning\x1b[0m";

#endif //COLORTERM
