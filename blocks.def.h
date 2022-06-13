//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" CPU ", "sensors | awk '/^CPU/ {print $2}'",                                                      5,  1},
	{"FAN ",  "sensors | awk '/^fan1/ {print $2 $3}'",                                                  5,  2},
	{"RAM ",  "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",                                10, 3},
	{"BRI ",  "echo \"$(brillo -G)%\"",                                                                 0,  7},
	{"BAT ",  "upower -i /org/freedesktop/UPower/devices/battery_BAT0 | awk '/percentage/ {print $2}'", 30, 4},
	{"VOL ",  "pamixer --get-volume-human",                                                             0,  5},
	{"",      "date '+%A %d %b %Y %H:%M '",                                                           60, 6},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
