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


typedef mama_status
(*entitlementBridge_create) (entitlementBridge* bridge);
typedef mama_status
(*entitlementBridge_destroy) (entitlementBridge* bridge);
typedef mama_status
(*entitlementBridge_registerSubjectContext) (SubjectContext* ctx);
typedef mama_status
(*entitlementBridge_handleNewSubscription) (entitlementBridge* bridge, SubjectContext* ctx);


typedef struct mamaEntitlementBridge_
{ 
    entitlementBridge   mImpl; /* pointer to implementation bridge struct */

    /* pure functions, defined in entitlement.c */  //TODO: should these even be here??
    entitlementBridge_create                    entitlementCreate;
    entitlementBridge_destroy                   entitlmentDestroy;

    /* implementation functions*/
    entitlementBridge_registerSubjectContext    registerSubjectContext;
    entitlementBridge_handleNewSubscription     handleNewSubscription;

    void*   mClosure;
} mamaEntitlementBridge;


typedef struct mamaEntitlementSubscription_
{
    mamaEntitlementBridge*    mEntitlementBridge;
} mamaEntitlementSubscription;

mama_status
mamaEntitlementBridge_create(mamaEntitlementBridge** bridge);

mama_status
mamaEntitlementBridge_destroy(mamaEntitlementBridge* bridge);


#endif /* EntitlementH__ */
