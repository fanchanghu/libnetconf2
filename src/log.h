/**
 * \file log.h
 * \author Radek Krejci <rkrejci@cesnet.cz>
 * \brief libnetconf2 logger
 *
 * Copyright (c) 2015 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 */

#ifndef NC_LOG_H_
#define NC_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Verbosity levels.
 */
typedef enum NC_VERB_LEVEL {
    NC_VERB_ERROR,   /**< Print only error messages. */
    NC_VERB_WARNING, /**< Print error and warning messages. */
    NC_VERB_VERBOSE, /**< Besides errors and warnings, print some other verbose messages. */
    NC_VERB_DEBUG    /**< Print all messages including some development debug messages. */
} NC_VERB_LEVEL;

/**
 * @brief Set libnetconf's verbosity level.
 * @param[in] level Enabled verbosity level (includes all the levels with higher priority).
 */
void nc_verbosity(NC_VERB_LEVEL level);

#ifdef NC_TRANSAPI_H_
/* Allow the following functions only in transAPI modules (via #include <transapi.h> */

/**
 * @brief Function for logging error messages.
 * @param[in] format	printf's format string
 * @param[in] ...	list of arguments specified in format
 */
void nc_verb_error(const char * format, ...);

/**
 * @brief Function for logging warning messages.
 * @param[in] format	printf's format string
 * @param[in] ...	list of arguments specified in format
 */
void nc_verb_warning(const char * format, ...);

/**
 * @brief Function for logging verbose messages.
 * @param[in] format	printf's format string
 * @param[in] ...	list of arguments specified in format
 */
void nc_verb_verbose(const char * format, ...);

#endif

#ifdef __cplusplus
}
#endif

#endif /* NC_LOG_H_ */