#ifndef BRAVEHERO_LOGGING_H
#define BRAVEHERO_LOGGING_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cstdarg>

#define braveEnsure(condition, msg, ...) if (!(condition)) printf(msg, __VA_ARGS__);

#define braveAssertMsg(condition, msg, ...) if (!(condition)) { \
                                            braveLog::braveLogAlways("In file '%s' in function '%s' on line %d:", __FILE__, __PRETTY_FUNCTION__, __LINE__);\
                                            braveLog::braveLogAlways(msg, __VA_ARGS__);\
                                            assert(0); }
#define braveEnsureMsg(condition, msg, ...) if (!(condition)) { \
                                            braveLog::braveLogAlways("In file '%s' in function '%s' on line %d:", __FILE__, __PRETTY_FUNCTION__, __LINE__);\
                                            braveLog::braveLogAlways(msg, __VA_ARGS__); \
                                            braveEnsure(condition, msg, __VA_ARGS__); }

class braveLog {
public:
    static braveLog &Instance() {
        static braveLog theLog;
        return theLog;
    }

    static inline void braveLogAlways(const char *msg, ...) {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[255];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S", timeinfo);
        fprintf(logfile, "<%s>\t", buffer);

        va_list args;
        va_start (args, msg);
        if (args) {
            vsprintf(buffer, msg, args);
            fprintf(logfile, "%s", buffer);
        }

        fprintf(logfile, "\n");
    }

private:
    static FILE *logfile;

    braveLog() {};

    braveLog(braveLog const &);

    braveLog &operator=(braveLog const &);
};

#endif //BRAVEHERO_LOGGING_H
