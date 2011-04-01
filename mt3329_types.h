#ifndef _MT3329_TYPES_H
#define _MT3329_TYPES_H

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef double u64;

typedef u8 uint8;
typedef s8 sint8;
typedef s16 sint16;
typedef u16 uint16;
typedef u32 uint32;

typedef uint8 GPS_svid_t8;

typedef u8 boolean;
#define FALSE    0
#define TRUE     1

typedef u32 date_time_t32;
typedef s32 scnd_t32;

typedef struct
{
    u8 month;
    u8 day;
    u8 year;
} date_type;

typedef struct
{
    s16 hour;
    u8 minute;
    u8 second;
} time_type;

typedef struct
{
    s32 wn;
    s32 tow;
} UTL_gps_time_type;

typedef struct
{
    u64 lat;
    u64 lon;
} posn_type;

typedef struct
{
    u32 vel_lon;
    u32 vel_lat;
    u32 vel_alt;
} vf3;

struct new_date_type
{
    u8 month;
    u8 day;
    u16 year;
};

struct new_time_type
{
    u16 hour;
    u8 minute;
    u8 second;
};

struct GPS_Date_Time_type
{
    struct new_date_type date;
    struct new_time_type time;
};

typedef struct
{
    u16 leap_scnds;
    u16 fix;
    u32 rem_rcnt;
    s32 wn;
    posn_type posn;
    double tow;
    double last_valid_tow;
    vf3 vel;
    float alt;
    float speed;
    float trk;
    float eph;
    float epv;
    float epe;
    float hdop;
    float vdop;
    float pdop;
    float tdop;
    float vel_thrsh;
    float cbias;
    float cdrift;
    s32 wn_lng;
    boolean tp_actv;
    u8 sats_used;
    u16 raw_fix;
    u16 clk_freq;
    u16 reserved;
    posn_type wgs84_posn;
} __attribute__ ((packed)) GPS_remote_state_type;

typedef struct
{
    u16 leap_scnds;
    u16 fix;
    u32 rem_rcnt;
    s32 wn;
    u64 posn_lat;
    u64 posn_lon;
    double tow;
    double last_valid_tow;
    u32 vel_lon;
    u32 vel_lat;
    u32 vel_alt;
    float alt;
    float speed;
    float trk;
    float eph;
    float epv;
    float epe;
    float hdop;
    float vdop;
    float pdop;
    float tdop;
    float vel_thrsh;
    float cbias;
    float cdrift;
    s32 wn_lng;
    boolean tp_actv;
    u8 sats_used;
    u16 raw_fix;
    u16 clk_freq;
    u16 reserved;
    u64 wgs84_lat;
    u64 wgs84_lon;
} __attribute__ ((packed)) GPS_packed_remote_state_type;

typedef struct
{
    u8 svid;
    u8 reserved1;
    s16 snr;
    s16 elev;
    s16 azim;
    s8 sgnl;
    boolean diff;
    boolean eph;
    u8 reserved2;
    float cno;
    boolean cp_vld;
    u8 eph_age;
    boolean used_in_fix;
    u8 reserved5;
} __attribute__ ((packed)) GPS_packed_sat_sts_type;

typedef struct                  /* Satellite Data Record            */
{
    GPS_svid_t8 svid;           /* satellite svid                   */
    uint8 reserved1;            /* reserved                         */
    sint16 snr;                 /* satellite signal to noise ratio  */
    sint16 elev;                /* elevation                        */
    sint16 azim;                /* azimuth                          */
    sint8 sgnl;                 /* satellite signal quality (-1..8) */
    boolean diff;               /* differential corrections status  */
    boolean eph;                /* ephemeris availability status    */
    uint8 reserved2;            /* reserved                         */
    float cno;                  /* satellite tracking c/n0          */
    boolean cp_vld;             /* integrated carrier phase valid   */
    uint8 eph_age;              /* age of ephemeris in days         */
    uint8 reserved4;            /* reserved                         */
    uint8 reserved5;            /* reserved                         */
} GPS_sat_sts_type;

typedef struct                  /* almanac data record for IOP                  */
{
    uint8 space;                /* for backwards compatibility with IOP         */
    uint8 svid;                 /* space vehicle identification                 */
    sint16 wn;                  /* week number                          (weeks) */
    float toa;                  /* almanac data reference time              (s) */
    float af0;                  /* clock correction coefficient             (s) */
    float af1;                  /* clock correction coefficient           (s/s) */
    float e;                    /* eccentricity                             (-) */
    float sqrta;                /* square root of semi-major axis (a)  (m**1/2) */
    float m0;                   /* mean anomaly at reference time           (r) */
    float w;                    /* argument of perigee                      (r) */
    float omg0;                 /* right ascension                          (r) */
    float odot;                 /* rate of right ascension                (r/s) */
    float i;                    /* inclination angle                        (r) */
    uint8 hlth;                 /* almanac health bits 17:24            (coded) */
    uint8 pad;
    uint16 pad2;
} GPS_alm_type;

typedef struct
{                               /* almanac data record for IOP                  */
    uint8 space;                /* for backwards compatibility with IOP         */
    uint8 svid;                 /* space vehicle identification                 */
    sint16 wn;                  /* week number                          (weeks) */
    uint32 toa;                 /* float   toa;                                 */
    uint32 af0;                 /* float   af0;                                 */
    uint32 af1;                 /* float   af1;                                 */
    uint32 e;                   /* float   e;                                   */
    uint32 sqrta;               /* float   sqrta;                               */
    uint32 m0;                  /* float   m0;                                  */
    uint32 w;                   /* float   w;                                   */
    uint32 omg0;                /* float   omg0;                                */
    uint32 odot;                /* float   odot;                                */
    uint32 i;                   /* float   i;                                   */
    uint8 hlth;                 /* almanac health bits 17:24            (coded) */
    uint8 pad;
    uint16 pad2;
} __attribute__ ((packed)) GPS_packed_alm_type;

#define GPS_WEEK_SCND       (604800.0)
#define GPS_TO_GRM_WKS      (521)
#define GPS_NUMR_ALM        (32)
#define GPS_NUMR_CHNLS      (24)
#define GPS_NUMR_EPH        (12)
#define GPS_NUMR_SVID       (32)
#define GPS_INVALID_SVID    (0xFF)
#define GPS_FIRST_WAAS_SVID (120-1)
#define GPS_LAST_WAAS_SVID  (138-1)
#define GPS_NMBR_EPH        (12)
#define GPS_is_waas_sv(_svid) \
        (((_svid) >= GPS_FIRST_WAAS_SVID) && ((_svid) <= GPS_LAST_WAAS_SVID) ? TRUE:FALSE)
#define GPS_waas_index(svid) \
        (svid - GPS_FIRST_WAAS_SVID)
#define cnt_of_array(n) \
        (sizeof(n)/sizeof((n)[0]))

#define GPS_PI 3.1415926535897

typedef struct
{
    u8 sat_count;
    u8 sat_list_table[GPS_NUMR_CHNLS];
    GPS_packed_sat_sts_type sat_status_table[GPS_NUMR_CHNLS];
} GPS_Sat_Table;

typedef struct
{
    unsigned char id;
    unsigned char size;
    unsigned char start;
    unsigned char end;
} IOP_packet;

#define BASE_YEAR 1990

#define START    TRUE
#define STOP     FALSE

#define STATE_DATA      0
#define STATE_START     1
#define STATE_ID        2
#define STATE_SIZE      3
#define STATE_END       4

#endif
