#include <cstdarg>
#include "logging.h"

FILE *braveLog::logfile = fopen("Logs/Game.log", "w");