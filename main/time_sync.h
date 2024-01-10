#ifndef TIME_SYNC_H
#define TIME_SYNC_H

/*-----------------------------------------------------------*/

#define SNTP_SERVER_FQDN                                "pool.ntp.org"

/*-----------------------------------------------------------*/

// Function to initialize SNTP and synchronize time
void initialize_sntp(void);

// Function to get current time
void get_current_time(void);

#endif // TIME_SYNC_H
