/* $Id$
 *
 * OpenMAMA: The open middleware agnostic messaging API
 * Copyright (C) 2011 NYSE Technologies, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */
#include "imagerequest.h"

#ifndef EntitlementH__
#define EntitlementH__

typedef void* entitlementBridge;
typedef void* entitlementSubscriptionHandle;

typedef struct mamaEntitlementBridge_* mamaEntitlementBridge;
typedef struct mamaEntitlementSubscription_ mamaEntitlementSubscription;

typedef mama_status
(*entitlementBridge_create) (entitlementBridge* bridge);
typedef mama_status
(*entitlementBridge_destroy) (entitlementBridge* bridge);
typedef mama_status
(*entitlementBridge_init) (mamaEntitlementBridge bridge);
typedef mama_status
(*entitlementBridge_registerSubjectContext) (SubjectContext* ctx);
typedef mama_status
(*entitlementBridge_handleNewSubscription) (SubjectContext* ctx);
typedef mama_status
(*entitlementBridge_setIsSnapshot) (mamaEntitlementSubscription* handle, int isSnapshot);
typedef int
(*entitlementBridge_isAllowed) (mamaEntitlementSubscription* handle, char* subject);

typedef struct mamaEntitlementBridge_
{ 
    entitlementBridge   mImpl; /* pointer to implementation bridge struct */

    /* pure functions, defined in entitlement.c */
    entitlementBridge_create                    entitlementCreate;
    entitlementBridge_destroy                   entitlementDestroy;

    /* implementation functions*/
    entitlementBridge_registerSubjectContext    registerSubjectContext;
    entitlementBridge_handleNewSubscription     handleNewSubscription;
    entitlementBridge_setIsSnapshot             setIsSnapshot;
    entitlementBridge_isAllowed                 isAllowed;

    void*   mClosure;
};


typedef struct mamaEntitlementSubscription_
{
    mamaEntitlementBridge*    mEntitlementBridge;
};

/*Called when loading/creating a bridge */

mama_status
mamaEntitlementSubscription_create (mamaEntitlementSubscription* subscription);
mama_status
mamaEntitlementSubscription_destroy (mamaEntitlementSubscription* subscription);

mama_status
mamaEntitlementBridge_create (mamaEntitlementBridge* bridge);

mama_status
mamaEntitlementBridge_destroy (mamaEntitlementBridge bridge);


#endif /* EntitlementH__ */
